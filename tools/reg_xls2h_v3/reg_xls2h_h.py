########################################################################################
# "header" class definition
########################################################################################

from common.legalexception import *
from reg_xls2h_xls import *
from os.path import basename
from os.path import splitext

def translate(name):
    # by default, just uppercase
    result = name.upper()

    # if the entire name is already uppercase, do not do anything
    if result != name:
        # first letter has to be uppercase
        result = name[0].upper()
        # loop on the remaining letters
        for i in range(1, len(name)):
            c = name[i]
            # check if current char is uppercase
            if c.isupper():
                # if it is uppercase:
                #   - if previous char is lower, add _ ; example: CamelKase -> _ before K
                #   - if next char is lower, add _ ; example: DTIMKill -> _ before K
                if name[i-1].islower() \
                   or (i < (len(name)-1) and name[i+1].islower()):
                    result += '_'
                result += c
            # check if current char is digit
            elif c.isdigit():
                # add underscore unless previous char is not digit
                if name[i-1].isdigit() == False:
                    # then add underscore before digit
                    result += '_'
                result += c
            # finally, char is not upper and is not digit, just make it upper
            else:
                result += c.upper()
    return result


class header:
    "class of header file"
    def __init__(self, prefix, regaddr, outfile):
        "constructor"

        # save the prefix
        self.prefix = prefix

        # check the values
        try:
            self.regaddr = int(regaddr, 0)
        except ValueError:
            raise LegalException("""ERROR: regaddr "%s", format is not parsable"""%(regaddr, ))

        self.outfile = outfile

    def generate(self, xls, forsimu, longname, gendoc):
        "method to generate the header file"

        # only one block containing all the registers in the xls sheet
        block = xls.blocks[0]

        # open the file
        try:
            fout = open(self.outfile, "wb")
        except:
            raise LegalException("""Error: can not create file "%s" """ %(self.outfile, ), 1)

        (fname, fext) = splitext(basename(self.outfile))
        blockname = fname.upper()
        groupname = fname.lower()

        # disclaimer and documentation
        if gendoc:
            fout.write(("/**\n").encode())
            fout.write((" * @file fw/%s\n"%(basename(self.outfile), )).encode())
            fout.write((" * @brief Register map and register access functions.\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * This module provides the following definitions and functions.\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * <h3>Register definitions</h3>\n").encode())
            fout.write((" * <h4>{REGNAME}_REG</h4>\n").encode())
            fout.write((" * A dereferenced pointer to the register.  This can be used to read or write the register\n").encode())
            fout.write((" * as if it were a ordinary variable.  Examples:\n").encode())
            fout.write((" * <pre>uint32_t local_reg;\n").encode())
            fout.write(("\n").encode())
            fout.write(("local_reg = ARB_REG2_REG; // read\n").encode())
            fout.write(("local_reg |= 0x1;         // modify\n").encode())
            fout.write(("ARB_REG2_REG = local_reg; // write</pre>\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * These registers should not be accessed directly.  Instead the wrapper functions\n").encode())
            fout.write((" * provided herein should be used.\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * <h4>{REGNAME}_ADDR</h4>\n").encode())
            fout.write((" * This is simply the address of the register.  Avoid using this.\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * <h3>Atomic Register Access Functions</h3>\n").encode())
            fout.write((" * Get/set functions are provided for every register which is readable or writable,\n").encode())
            fout.write((" * respectively.\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * <h4>{regname}_get()</h4>\n").encode())
            fout.write((" * These functions return the value of the register.\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * <h4>{regname}_set(value)</h4>\n").encode())
            fout.write((" * These functions simply set the register to an integer value.\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * <h3>Register Packing and Unpacking Functions</h3>\n").encode())
            fout.write((" * <h4>{regname}_pack(f1, f2, ...)</h4>\n").encode())
            fout.write((" * This function takes as arguments a value for each field within the register\n").encode())
            fout.write((" * and write the packed value to the register.  Example usage:\n").encode())
            fout.write((" * <pre>local_val = arb_reg2_pack(1, 0, 3);</pre>\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * <h4>{regname}_unpack(&f1, &f2, ...)</h4>\n").encode())
            fout.write((" * This function takes as arguments pointers to integers; these integers will be populated\n").encode())
            fout.write((" * with the value of their corresponding field from the current value of the register.  Example:\n").encode())
            fout.write((" * <pre>uint8_t fpga_en, override_en, override_cnt;\n").encode())
            fout.write(("arb_reg2_unpack(&fpga_en, &override_en, &override_cnt);\n").encode())
            fout.write(("\n").encode())
            fout.write(("if(fpga_en) { ... }\n").encode())
            fout.write((" * </pre>\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * <h3>Register Field Access Functions</h3>\n").encode())
            if longname:
                fout.write((" * <h4>{regname}_{fieldname}_getf()</h4>\n").encode())
                fout.write((" * This function works similar to the unpack functions except they extract only the value\n").encode())
                fout.write((" * of a single field from a register.  Example:\n").encode())
                fout.write((" *<pre>uint8_t fpga_en = arb_reg2_fpga_en_getf();</pre>\n").encode())
                fout.write((" *\n").encode())
                fout.write((" * <h4>{regname}_{fieldname}_setf(fieldValue)</h4>\n").encode())
                fout.write((" * This function takes a value for a field, read the current value of the\n").encode())
                fout.write((" * register, modify with the new field value, and write the result back\n").encode())
                fout.write((" * to the register.  Example:\n").encode())
                fout.write((" * <pre>arb_reg2_fpga_en_setf(0);</pre>\n").encode())
            else:
                fout.write((" * <h4>{fieldname}_getf()</h4>\n").encode())
                fout.write((" * This function works similar to the unpack functions except they extract only the value\n").encode())
                fout.write((" * of a single field from a register.  Example:\n").encode())
                fout.write((" *<pre>uint8_t fpga_en = fpga_en_getf();</pre>\n").encode())
                fout.write((" *\n").encode())
                fout.write((" * <h4>{fieldname}_setf(fieldValue)</h4>\n").encode())
                fout.write((" * This function takes a value for a field, read the current value of the\n").encode())
                fout.write((" * register, modify with the new field value, and write the result back\n").encode())
                fout.write((" * to the register.  Example:\n").encode())
                fout.write((" * <pre>fpga_en_setf(0);</pre>\n").encode())
            fout.write((" *\n").encode())
            fout.write((" * @defgroup registers Registers\n").encode())
            fout.write((" * @defgroup %s %s\n"%(groupname, groupname)).encode())
            fout.write((" * @ingroup registers\n").encode())
            fout.write((" *\n").encode())
            fout.write((" */\n").encode())

        # generate the lines in the file
        define = "_" + basename(self.outfile).upper().replace(".", "_") + "_"
        fout.write(("#ifndef %s\n"%define).encode())
        fout.write(("#define %s\n\n"%define).encode())
        fout.write(("#include <stdint.h>\n").encode())
        fout.write(("#include \"compiler.h\"\n").encode())
        fout.write(("#include \"arch.h\"\n").encode())
        if forsimu:
            fout.write(("#include \"reg_sim.h\"\n").encode())
        fout.write(("\n").encode())

        if xls.type == 'RF':
            fout.write(("static void phy_reg_write(uint32_t addr, uint32_t ch, uint32_t value);\n\n").encode())

        if gendoc:
            fout.write(("/** @brief Base address of the %s peripheral from CPU's point of view.\n"%(blockname, )).encode())
            fout.write((" * @ingroup %s\n"%(groupname, )).encode())
            fout.write((" */\n").encode())
        fout.write(("#define %s_BASE_ADDR 0x%08X\n\n"%(blockname, self.regaddr)).encode())
        if gendoc:
            fout.write(("/** @brief Number of registers in the %s peripheral.\n"%(blockname, )).encode())
            fout.write((" * @ingroup %s\n"%(groupname, )).encode())
            fout.write((" */\n").encode())
        fout.write(("#define %s_COUNT %d\n\n"%(blockname, block.num_regs)).encode())
        if gendoc:
            fout.write(("/** @brief Decoding mask of the %s peripheral registers from the CPU point of view.\n"%(blockname, )).encode())
            fout.write((" * @ingroup %s\n"%(groupname, )).encode())
            fout.write((" */\n").encode())
        fout.write(("#define %s_DECODING_MASK 0x%08X\n\n"%(blockname, block.decode_mask)).encode())

        # loop on all the registers
        for reg in block.registers:
            # if the regname is a noregister do not put it
            if reg.name.upper().find("NOREGISTER") != -1:
                continue

            # do the initial name translation and creation before generation
            #  - remove register trailing Reg
            regname = re.sub("Reg$", '', reg.name)
            cs_regname = re.sub("Reg$", '', reg.cs_name)
            #  - translate into our naming standard
            cs_regname = translate(cs_regname)
            regname = translate(regname)

            if longname and (len(reg.fields) != 1 or reg.fields[0].name != cs_regname):
                field_prefix = cs_regname + '_'
            else:
                field_prefix = reg.short_name

            #  - generate the names required for the parameters
            for field in reg.fields:
                # in parameter name, remove underscore
                field.h_param = field.name.lower().replace('_', '')
                field.h_name = translate(field.name)

            #  - longest field name (append a zero to prevent problems in no field registers)
            max_fieldhname = max([len(x.h_name) for x in reg.fields] + [0]) + 6

            # add a potential prefix to the register name
            regname = self.prefix + regname
            cs_regname = self.prefix + cs_regname

            # generate description
            fout.write(("/**\n").encode())
            fout.write((" * @brief %s register definition\n"%(regname,)).encode())
            if len(reg.fields) != 0:
                fout.write((" * <pre>\n").encode())
                fout.write((" *   Bits           Field Name   Reset Value\n").encode())
                fout.write((" *  -----   ------------------   -----------\n").encode())
                for field in reg.fields:
                    if field.width == 1:
                        fout.write((" *     %02d   %s   %d\n"%\
                                   (field.low_bitpos,
                                    " "*(18 - len(field.name)) + field.name,
                                    field.reset)).encode())
                    else:
                        fout.write((" *  %02d:%02d   %s   0x%X\n"%\
                                   (field.high_bitpos, field.low_bitpos,
                                    " "*(18 - len(field.name)) + field.name,
                                    field.reset)).encode())

                fout.write((" * </pre>\n").encode())
            if gendoc:
                fout.write((" * @ingroup %s\n"%(groupname,)).encode())
            fout.write((" */\n").encode())

            if not reg.rf:
                if not forsimu:
                    if reg.multi:
                        fout.write((  (  "#define %s_REG(i)    "
                                      + "(* (((volatile uint32_t *)0x%08X) + i) )\n")
                                   % (regname, (reg.addr + self.regaddr))).encode())
                    else:
                        fout.write((  "#define %s_REG    (*(volatile uint32_t *)(0x%08X))\n"
                                   % (regname, (reg.addr + self.regaddr))).encode())

                    fout.write(("#define %s_ADDR   0x%08X\n"%(regname, (reg.addr + self.regaddr))).encode())
                    fout.write(("#define %s_OFFSET 0x%08X\n"%(regname, (reg.addr))).encode())
                fout.write(("#define %s_INDEX  0x%08X\n"%(regname, int((reg.addr/4)))).encode())
                if reg.multi:
                    fout.write(("#define %s_COUNT  %d\n\n"%(regname, reg.max - reg.min + 1)).encode())
                else:
                    fout.write(("\n").encode())
            else:
                # RF reg
                fout.write(("#define %s_RF_ADDR 0x%02X\n"%(regname, reg.addr)).encode())
                fout.write(("#define %s_RF_CH   %d\n\n"%(regname, reg.rf)).encode())

            if reg.multi:
                param_beg = "uint32_t idx, "
                param_one = "uint32_t idx"
            else:
                param_beg = ""
                param_one = "void"

            if reg.rf:
                if reg.rf == 7:
                    param_beg = "uint32_t ch, "
                    param_one = "uint32_t ch"
                    param_ch = "ch"
                else:
                    param_beg = ""
                    param_one = "void"
                    param_ch = "1"

                # RF reg read/write macro setup
                #reg_rd = "rf_raw_read(%s_INDEX)"%(sim_read, regname)
                reg_wr_beg = "phy_reg_write(%s_RF_ADDR, %s, "%(regname, param_ch)
                reg_wr_end = ")"


            elif not forsimu:
                # normal reg read/write macro setup
                if reg.multi:
                    reg_rd = "%s_REG(idx)"%(regname)
                    reg_wr_beg = "%s_REG(idx) = "%(regname)
                else:
                    reg_rd = "%s_REG"%(regname)
                    reg_wr_beg = "%s_REG = "%(regname)

                reg_wr_end = ""

            else:
                # simu reg read/write macro setup
                sim_read = "sim_"+fname.lower()+"_rd"
                sim_write = "sim_"+fname.lower()+"_wr"

                if reg.multi:
                    reg_rd = "%s(%s_INDEX + idx)"%(sim_read, regname)
                    reg_wr_beg = "%s(%s_INDEX + idx, "%(sim_write, regname)
                else:
                    reg_rd = "%s(%s_INDEX)"%(sim_read, regname)
                    reg_wr_beg = "%s(%s_INDEX, "%(sim_write, regname)

                reg_wr_end = ")"


            if reg.multi:
                func_beg = "{\n    ASSERT_ERR(idx <= %d);\n" % (reg.max)
            else:
                func_beg = "{\n"
            func_end = "}\n\n"

            if reg.sw == 'C':
                func_set_name = "clear"
            else:
                func_set_name = "set"

            # REG_get function
            if reg.sw != 'W' and reg.gen_read and not reg.rf:
                if gendoc:
                    fout.write(("/**\n").encode())
                    fout.write((" * @brief Returns the current value of the %s register.\n"%(regname,)).encode())
                    fout.write((" * The %s register will be read and its value returned.\n"%(regname,)).encode())
                    fout.write((" * @return The current value of the %s register.\n"%(regname,)).encode())
                    fout.write((" */\n").encode())
                fout.write(("__INLINE uint32_t %s_get(%s)\n"%(cs_regname.lower(), param_one)).encode())
                fout.write((func_beg).encode())
                fout.write(("    return %s;\n" % (reg_rd)).encode())
                fout.write((func_end).encode())

            # REG_set function
            if reg.sw != 'R' or forsimu:
                if gendoc:
                    fout.write(("/**\n").encode())
                    fout.write((" * @brief Sets the %s register to a value.\n"%(regname,)).encode())
                    fout.write((" * The %s register will be written.\n"%(regname,)).encode())
                    fout.write((" * @param value - The value to write.\n").encode())
                    fout.write((" */\n").encode())

                fout.write(("__INLINE void %s_%s(%suint32_t value)\n"%(cs_regname.lower(), func_set_name, param_beg)).encode())
                fout.write((func_beg).encode())
                fout.write(("    %svalue%s;\n"%(reg_wr_beg, reg_wr_end)).encode())
                fout.write((func_end).encode())

            if len(reg.fields) != 0:
                if reg.gen_field:
                    fout.write(("// field definitions\n").encode())

                    str_def_hex = "#define %-" + str(max_fieldhname) + "s  0x%08X\n"
                    str_def_dec = "#define %-" + str(max_fieldhname) + "s  %d\n"

                    for field in reg.fields:
                        if field.width == 1:
                            fout.write((str_def_hex % (field.h_name + "_BIT  ", field.mask)).encode())
                            fout.write((str_def_dec % (field.h_name + "_POS  ", field.low_bitpos)).encode())
                        else:
                            fout.write((str_def_hex % (field.h_name + "_MASK ",  field.mask)).encode())
                            fout.write((str_def_dec % (field.h_name + "_LSB  ", field.low_bitpos)).encode())
                            fout.write((str_def_hex % (field.h_name + "_WIDTH", field.width)).encode())

                    fout.write(("\n").encode())

                    str_def_hex = "#define %-" + str(max_fieldhname) + "s  0x%X\n"
                    for field in reg.fields:
                        fout.write((str_def_hex % (field.h_name + "_RST", field.reset)).encode())

                    fout.write(("\n").encode())
                else:
                    fout.write(("// fields defined in symmetrical set/clear register\n").encode())

                # only provide pack writable registers that have a writable field
                if reg.writable and len(reg.writable_fields) > 1:

                    # REG_pack function
                    if gendoc:
                        fout.write(("/**\n").encode())
                        fout.write((" * @brief Constructs a value for the %s register given values for its fields\n"%(regname, )).encode())
                        fout.write((" * and writes the value to the register.\n").encode())
                        fout.write((" *\n").encode())
                        for field in reg.writable_fields:
                            fout.write((" * @param[in] %s - The value to use for the %s field.\n"%(field.h_param, field.name)).encode())
                        fout.write((" */\n").encode())
                    fout.write(("__INLINE void %s_pack(%s"%(regname.lower(),param_beg)).encode())
                    for field in reg.writable_fields:
                        fout.write(("%s %s"%(field.type, field.h_param)).encode())
                        # check if it is the last element
                        if field == reg.writable_fields[-1]:
                            fout.write((")\n").encode())
                        else:
                            fout.write((", ").encode())
                    fout.write((func_beg).encode())
                    for field in reg.writable_fields:
                        fout.write(("    ASSERT_ERR(((%s << %d) & ~0x%08X) == 0);\n"%(field.h_param, field.low_bitpos, field.mask)).encode())

                    fout.write(("    %s"%(reg_wr_beg)).encode())

                    for field in reg.writable_fields:
                        fout.write((" (%s << %d)"%(field.h_param, field.low_bitpos)).encode())
                        # check if it is the last element
                        if field != reg.writable_fields[-1]:
                            fout.write((" |").encode())
                        else:
                            fout.write(("%s;\n" % reg_wr_end).encode())

                    fout.write((func_end).encode())

                # REG_unpack function
                if reg.sw != 'W' and reg.gen_read and len(reg.fields) > 1:
                    if gendoc:
                        fout.write(("/**\n").encode())
                        fout.write((" * @brief Unpacks %s's fields from current value of the %s register.\n"%(regname, regname)).encode())
                        fout.write((" *\n").encode())
                        fout.write((" * Reads the %s register and populates all the _field variables with the corresponding\n"%(regname,)).encode())
                        fout.write((" * values from the register.\n").encode())
                        fout.write((" *\n").encode())
                        for field in reg.fields:
                            fout.write((" * @param[out] %s - Will be populated with the current value of this field from the register.\n"%(field.h_param,)).encode())
                        fout.write((" */\n").encode())

                    fout.write(("__INLINE void %s_unpack(%s"%(cs_regname.lower(), param_beg)).encode())
                    for field in reg.fields:
                        fout.write(("%s* %s"%(field.type, field.h_param)).encode())
                        # check if it is the last element
                        if reg.fields.index(field) == len(reg.fields)-1:
                            fout.write((")\n").encode())
                        else:
                            fout.write((", ").encode())
                    fout.write((func_beg).encode())
                    fout.write(("    uint32_t localVal = %s;\n"%(reg_rd)).encode())
                    fout.write(("\n").encode())
                    for field in reg.fields:
                        if len(reg.fields) == 1:
                            fout.write(("    ASSERT_ERR((localVal & ~0x%08X) == 0);\n"%(field.mask,)).encode())
                            fout.write(("    *%s = localVal >> %d;\n"%(field.h_param, field.low_bitpos)).encode())
                        else:
                            fout.write(("    *%s = (localVal & 0x%08X) >> %d;\n"%(field.h_param, field.mask, field.low_bitpos)).encode())
                    fout.write((func_end).encode())

            # loop on all the fields to generate the field related
            for field in reg.fields:
                if field.sw != 'W' and reg.gen_read and not reg.rf:
                    if gendoc:
                        fout.write(("/**\n").encode())
                        fout.write((" * @brief Returns the current value of the %s field in the %s register.\n"%(field.name, regname)).encode())
                        fout.write((" *\n").encode())
                        fout.write((" * The %s register will be read and the %s field's value will be returned.\n"%(regname, field.name)).encode())
                        fout.write((" *\n").encode())
                        fout.write((" * @return The current value of the %s field in the %s register.\n"%(field.name, regname)).encode())
                        fout.write((" */\n").encode())
                    fout.write(("__INLINE %s %s%s_getf(%s)\n"%(field.type, field_prefix.lower(), field.h_name.lower(), param_one )).encode())
                    fout.write((func_beg).encode())
                    fout.write(("    uint32_t localVal = %s;\n"%(reg_rd)).encode())

                    # do not mask for single field
                    if len(reg.fields) == 1:
                        fout.write(("    ASSERT_ERR((localVal & ~0x%08X) == 0);\n"%(field.mask,)).encode())
                        fout.write(("    return (localVal >> %d);\n"%(field.low_bitpos,)).encode())
                    else:
                        fout.write(("    return ((localVal & 0x%08X) >> %d);\n"%(field.mask, field.low_bitpos)).encode())
                    fout.write((func_end).encode())


                # only provide set functionality to writable fields
                if field.writable and not reg.rf:
                    if gendoc:
                        fout.write(("/**\n").encode())
                        fout.write((" * @brief Sets the %s field of the %s register.\n"%(field.name, regname)).encode())
                        fout.write((" *\n").encode())
                        fout.write((" * The %s register will be read, modified to contain the new field value, and written.\n"%(regname, )).encode())
                        fout.write((" *\n").encode())
                        fout.write((" * @param[in] %s - The value to set the field to.\n"%(field.h_param,)).encode())
                        fout.write((" */\n").encode())
                    fout.write((  "__INLINE void %s%s_%sf(%s%s %s)\n"
                               % (field_prefix.lower(), field.h_name.lower(), func_set_name,
                                  param_beg, field.type, field.h_param)).encode())
                    fout.write((func_beg).encode())
                    fout.write(("    ASSERT_ERR(((%s << %d) & ~0x%08X) == 0);\n"%(field.h_param, field.low_bitpos, field.mask)).encode())

                    # generate direct accesses for set/clear registers or single writable field field
                    if (reg.sw in ('S', 'C')) or (len(reg.writable_fields) == 1):
                        fout.write(("    %s%s << %d%s;\n"%(reg_wr_beg, field.h_param, field.low_bitpos, reg_wr_end)).encode())
                    else:
                        fout.write((  "    %s(%s & ~0x%08X) | (%s << %d)%s;\n"
                                   % (reg_wr_beg, reg_rd, field.mask, field.h_param, field.low_bitpos, reg_wr_end)).encode())
                    fout.write((func_end).encode())

        fout.write(("\n#endif // %s\n\n"%define).encode())

        fout.close()



