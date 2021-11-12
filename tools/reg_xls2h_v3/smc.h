#ifndef _SMC_H_
#define _SMC_H_

#include <stdint.h>
#include "compiler.h"
#include "arch.h"

#define SMC_BASE_ADDR 0x01000000

#define SMC_COUNT 33

#define SMC_DECODING_MASK 0x000000FF

/**
 * @brief SMC_SETUP0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:24         NCS_RD_SETUP   0x0
 *  21:16            NRD_SETUP   0x0
 *  13:08         NCS_WR_SETUP   0x0
 *  05:00            NWE_SETUP   0x0
 * </pre>
 */
#define SMC_SETUP0_REG    (*(volatile uint32_t *)(0x01000000))
#define SMC_SETUP0_ADDR   0x01000000
#define SMC_SETUP0_OFFSET 0x00000000
#define SMC_SETUP0_INDEX  0x00000000

__INLINE uint32_t smc_setup0_get(void)
{
    return SMC_SETUP0_REG;
}

__INLINE void smc_setup0_set(uint32_t value)
{
    SMC_SETUP0_REG = value;
}

// field definitions
#define NCS_RD_SETUP_MASK   0x3F000000
#define NCS_RD_SETUP_LSB    24
#define NCS_RD_SETUP_WIDTH  0x00000006
#define NRD_SETUP_MASK      0x003F0000
#define NRD_SETUP_LSB       16
#define NRD_SETUP_WIDTH     0x00000006
#define NCS_WR_SETUP_MASK   0x00003F00
#define NCS_WR_SETUP_LSB    8
#define NCS_WR_SETUP_WIDTH  0x00000006
#define NWE_SETUP_MASK      0x0000003F
#define NWE_SETUP_LSB       0
#define NWE_SETUP_WIDTH     0x00000006

#define NCS_RD_SETUP_RST    0x0
#define NRD_SETUP_RST       0x0
#define NCS_WR_SETUP_RST    0x0
#define NWE_SETUP_RST       0x0

__INLINE void smc_setup0_pack(uint8_t ncsrdsetup, uint8_t nrdsetup, uint8_t ncswrsetup, uint8_t nwesetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP0_REG =  (ncsrdsetup << 24) | (nrdsetup << 16) | (ncswrsetup << 8) | (nwesetup << 0);
}

__INLINE void smc_setup0_unpack(uint8_t* ncsrdsetup, uint8_t* nrdsetup, uint8_t* ncswrsetup, uint8_t* nwesetup)
{
    uint32_t localVal = SMC_SETUP0_REG;

    *ncsrdsetup = (localVal & 0x3F000000) >> 24;
    *nrdsetup = (localVal & 0x003F0000) >> 16;
    *ncswrsetup = (localVal & 0x00003F00) >> 8;
    *nwesetup = (localVal & 0x0000003F) >> 0;
}

__INLINE uint8_t smc_setup0_ncs_rd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP0_REG;
    return ((localVal & 0x3F000000) >> 24);
}

__INLINE void smc_setup0_ncs_rd_setup_setf(uint8_t ncsrdsetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    SMC_SETUP0_REG = (SMC_SETUP0_REG & ~0x3F000000) | (ncsrdsetup << 24);
}

__INLINE uint8_t smc_setup0_nrd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP0_REG;
    return ((localVal & 0x003F0000) >> 16);
}

__INLINE void smc_setup0_nrd_setup_setf(uint8_t nrdsetup)
{
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    SMC_SETUP0_REG = (SMC_SETUP0_REG & ~0x003F0000) | (nrdsetup << 16);
}

__INLINE uint8_t smc_setup0_ncs_wr_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP0_REG;
    return ((localVal & 0x00003F00) >> 8);
}

__INLINE void smc_setup0_ncs_wr_setup_setf(uint8_t ncswrsetup)
{
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    SMC_SETUP0_REG = (SMC_SETUP0_REG & ~0x00003F00) | (ncswrsetup << 8);
}

__INLINE uint8_t smc_setup0_nwe_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP0_REG;
    return ((localVal & 0x0000003F) >> 0);
}

__INLINE void smc_setup0_nwe_setup_setf(uint8_t nwesetup)
{
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP0_REG = (SMC_SETUP0_REG & ~0x0000003F) | (nwesetup << 0);
}

/**
 * @brief SMC_PULSE0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  30:24         NCS_RD_PULSE   0x0
 *  22:16            NRD_PULSE   0x0
 *  14:08         NCS_WR_PULSE   0x0
 *  06:00            NWE_PULSE   0x0
 * </pre>
 */
#define SMC_PULSE0_REG    (*(volatile uint32_t *)(0x01000004))
#define SMC_PULSE0_ADDR   0x01000004
#define SMC_PULSE0_OFFSET 0x00000004
#define SMC_PULSE0_INDEX  0x00000001

__INLINE uint32_t smc_pulse0_get(void)
{
    return SMC_PULSE0_REG;
}

__INLINE void smc_pulse0_set(uint32_t value)
{
    SMC_PULSE0_REG = value;
}

// field definitions
#define NCS_RD_PULSE_MASK   0x7F000000
#define NCS_RD_PULSE_LSB    24
#define NCS_RD_PULSE_WIDTH  0x00000007
#define NRD_PULSE_MASK      0x007F0000
#define NRD_PULSE_LSB       16
#define NRD_PULSE_WIDTH     0x00000007
#define NCS_WR_PULSE_MASK   0x00007F00
#define NCS_WR_PULSE_LSB    8
#define NCS_WR_PULSE_WIDTH  0x00000007
#define NWE_PULSE_MASK      0x0000007F
#define NWE_PULSE_LSB       0
#define NWE_PULSE_WIDTH     0x00000007

#define NCS_RD_PULSE_RST    0x0
#define NRD_PULSE_RST       0x0
#define NCS_WR_PULSE_RST    0x0
#define NWE_PULSE_RST       0x0

__INLINE void smc_pulse0_pack(uint8_t ncsrdpulse, uint8_t nrdpulse, uint8_t ncswrpulse, uint8_t nwepulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE0_REG =  (ncsrdpulse << 24) | (nrdpulse << 16) | (ncswrpulse << 8) | (nwepulse << 0);
}

__INLINE void smc_pulse0_unpack(uint8_t* ncsrdpulse, uint8_t* nrdpulse, uint8_t* ncswrpulse, uint8_t* nwepulse)
{
    uint32_t localVal = SMC_PULSE0_REG;

    *ncsrdpulse = (localVal & 0x7F000000) >> 24;
    *nrdpulse = (localVal & 0x007F0000) >> 16;
    *ncswrpulse = (localVal & 0x00007F00) >> 8;
    *nwepulse = (localVal & 0x0000007F) >> 0;
}

__INLINE uint8_t smc_pulse0_ncs_rd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE0_REG;
    return ((localVal & 0x7F000000) >> 24);
}

__INLINE void smc_pulse0_ncs_rd_pulse_setf(uint8_t ncsrdpulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    SMC_PULSE0_REG = (SMC_PULSE0_REG & ~0x7F000000) | (ncsrdpulse << 24);
}

__INLINE uint8_t smc_pulse0_nrd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE0_REG;
    return ((localVal & 0x007F0000) >> 16);
}

__INLINE void smc_pulse0_nrd_pulse_setf(uint8_t nrdpulse)
{
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    SMC_PULSE0_REG = (SMC_PULSE0_REG & ~0x007F0000) | (nrdpulse << 16);
}

__INLINE uint8_t smc_pulse0_ncs_wr_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE0_REG;
    return ((localVal & 0x00007F00) >> 8);
}

__INLINE void smc_pulse0_ncs_wr_pulse_setf(uint8_t ncswrpulse)
{
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    SMC_PULSE0_REG = (SMC_PULSE0_REG & ~0x00007F00) | (ncswrpulse << 8);
}

__INLINE uint8_t smc_pulse0_nwe_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE0_REG;
    return ((localVal & 0x0000007F) >> 0);
}

__INLINE void smc_pulse0_nwe_pulse_setf(uint8_t nwepulse)
{
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE0_REG = (SMC_PULSE0_REG & ~0x0000007F) | (nwepulse << 0);
}

/**
 * @brief SMC_CYCLE0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16            NRD_CYCLE   0x0
 *  08:00            NWE_CYCLE   0x0
 * </pre>
 */
#define SMC_CYCLE0_REG    (*(volatile uint32_t *)(0x01000008))
#define SMC_CYCLE0_ADDR   0x01000008
#define SMC_CYCLE0_OFFSET 0x00000008
#define SMC_CYCLE0_INDEX  0x00000002

__INLINE uint32_t smc_cycle0_get(void)
{
    return SMC_CYCLE0_REG;
}

__INLINE void smc_cycle0_set(uint32_t value)
{
    SMC_CYCLE0_REG = value;
}

// field definitions
#define NRD_CYCLE_MASK   0x01FF0000
#define NRD_CYCLE_LSB    16
#define NRD_CYCLE_WIDTH  0x00000009
#define NWE_CYCLE_MASK   0x000001FF
#define NWE_CYCLE_LSB    0
#define NWE_CYCLE_WIDTH  0x00000009

#define NRD_CYCLE_RST    0x0
#define NWE_CYCLE_RST    0x0

__INLINE void smc_cycle0_pack(uint16_t nrdcycle, uint16_t nwecycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE0_REG =  (nrdcycle << 16) | (nwecycle << 0);
}

__INLINE void smc_cycle0_unpack(uint16_t* nrdcycle, uint16_t* nwecycle)
{
    uint32_t localVal = SMC_CYCLE0_REG;

    *nrdcycle = (localVal & 0x01FF0000) >> 16;
    *nwecycle = (localVal & 0x000001FF) >> 0;
}

__INLINE uint16_t smc_cycle0_nrd_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE0_REG;
    return ((localVal & 0x01FF0000) >> 16);
}

__INLINE void smc_cycle0_nrd_cycle_setf(uint16_t nrdcycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    SMC_CYCLE0_REG = (SMC_CYCLE0_REG & ~0x01FF0000) | (nrdcycle << 16);
}

__INLINE uint16_t smc_cycle0_nwe_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE0_REG;
    return ((localVal & 0x000001FF) >> 0);
}

__INLINE void smc_cycle0_nwe_cycle_setf(uint16_t nwecycle)
{
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE0_REG = (SMC_CYCLE0_REG & ~0x000001FF) | (nwecycle << 0);
}

/**
 * @brief SMC_MODE0 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28                   PS   0x0
 *     24                 PMEN   0
 *     20             TDF_MODE   0
 *  19:16           TDF_CYCLES   0x0
 *  13:12                  DBW   0x0
 *     08                  BAT   0
 *  05:04            EXNW_MODE   0x0
 *     01           WRITE_MODE   0
 *     00            READ_MODE   0
 * </pre>
 */
#define SMC_MODE0_REG    (*(volatile uint32_t *)(0x0100000C))
#define SMC_MODE0_ADDR   0x0100000C
#define SMC_MODE0_OFFSET 0x0000000C
#define SMC_MODE0_INDEX  0x00000003

__INLINE uint32_t smc_mode0_get(void)
{
    return SMC_MODE0_REG;
}

__INLINE void smc_mode0_set(uint32_t value)
{
    SMC_MODE0_REG = value;
}

// field definitions
#define PS_MASK           0x30000000
#define PS_LSB            28
#define PS_WIDTH          0x00000002
#define PMEN_BIT          0x01000000
#define PMEN_POS          24
#define TDF_MODE_BIT      0x00100000
#define TDF_MODE_POS      20
#define TDF_CYCLES_MASK   0x000F0000
#define TDF_CYCLES_LSB    16
#define TDF_CYCLES_WIDTH  0x00000004
#define DBW_MASK          0x00003000
#define DBW_LSB           12
#define DBW_WIDTH         0x00000002
#define BAT_BIT           0x00000100
#define BAT_POS           8
#define EXNW_MODE_MASK    0x00000030
#define EXNW_MODE_LSB     4
#define EXNW_MODE_WIDTH   0x00000002
#define WRITE_MODE_BIT    0x00000002
#define WRITE_MODE_POS    1
#define READ_MODE_BIT     0x00000001
#define READ_MODE_POS     0

#define PS_RST            0x0
#define PMEN_RST          0x0
#define TDF_MODE_RST      0x0
#define TDF_CYCLES_RST    0x0
#define DBW_RST           0x0
#define BAT_RST           0x0
#define EXNW_MODE_RST     0x0
#define WRITE_MODE_RST    0x0
#define READ_MODE_RST     0x0

__INLINE void smc_mode0_pack(uint8_t ps, uint8_t pmen, uint8_t tdfmode, uint8_t tdfcycles, uint8_t dbw, uint8_t bat, uint8_t exnwmode, uint8_t writemode, uint8_t readmode)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE0_REG =  (ps << 28) | (pmen << 24) | (tdfmode << 20) | (tdfcycles << 16) | (dbw << 12) | (bat << 8) | (exnwmode << 4) | (writemode << 1) | (readmode << 0);
}

__INLINE void smc_mode0_unpack(uint8_t* ps, uint8_t* pmen, uint8_t* tdfmode, uint8_t* tdfcycles, uint8_t* dbw, uint8_t* bat, uint8_t* exnwmode, uint8_t* writemode, uint8_t* readmode)
{
    uint32_t localVal = SMC_MODE0_REG;

    *ps = (localVal & 0x30000000) >> 28;
    *pmen = (localVal & 0x01000000) >> 24;
    *tdfmode = (localVal & 0x00100000) >> 20;
    *tdfcycles = (localVal & 0x000F0000) >> 16;
    *dbw = (localVal & 0x00003000) >> 12;
    *bat = (localVal & 0x00000100) >> 8;
    *exnwmode = (localVal & 0x00000030) >> 4;
    *writemode = (localVal & 0x00000002) >> 1;
    *readmode = (localVal & 0x00000001) >> 0;
}

__INLINE uint8_t smc_mode0_ps_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x30000000) >> 28);
}

__INLINE void smc_mode0_ps_setf(uint8_t ps)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x30000000) | (ps << 28);
}

__INLINE uint8_t smc_mode0_pmen_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x01000000) >> 24);
}

__INLINE void smc_mode0_pmen_setf(uint8_t pmen)
{
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x01000000) | (pmen << 24);
}

__INLINE uint8_t smc_mode0_tdf_mode_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x00100000) >> 20);
}

__INLINE void smc_mode0_tdf_mode_setf(uint8_t tdfmode)
{
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x00100000) | (tdfmode << 20);
}

__INLINE uint8_t smc_mode0_tdf_cycles_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x000F0000) >> 16);
}

__INLINE void smc_mode0_tdf_cycles_setf(uint8_t tdfcycles)
{
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x000F0000) | (tdfcycles << 16);
}

__INLINE uint8_t smc_mode0_dbw_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x00003000) >> 12);
}

__INLINE void smc_mode0_dbw_setf(uint8_t dbw)
{
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x00003000) | (dbw << 12);
}

__INLINE uint8_t smc_mode0_bat_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x00000100) >> 8);
}

__INLINE void smc_mode0_bat_setf(uint8_t bat)
{
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x00000100) | (bat << 8);
}

__INLINE uint8_t smc_mode0_exnw_mode_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x00000030) >> 4);
}

__INLINE void smc_mode0_exnw_mode_setf(uint8_t exnwmode)
{
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x00000030) | (exnwmode << 4);
}

__INLINE uint8_t smc_mode0_write_mode_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x00000002) >> 1);
}

__INLINE void smc_mode0_write_mode_setf(uint8_t writemode)
{
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x00000002) | (writemode << 1);
}

__INLINE uint8_t smc_mode0_read_mode_getf(void)
{
    uint32_t localVal = SMC_MODE0_REG;
    return ((localVal & 0x00000001) >> 0);
}

__INLINE void smc_mode0_read_mode_setf(uint8_t readmode)
{
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE0_REG = (SMC_MODE0_REG & ~0x00000001) | (readmode << 0);
}

/**
 * @brief SMC_SETUP1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:24         NCS_RD_SETUP   0x0
 *  21:16            NRD_SETUP   0x0
 *  13:08         NCS_WR_SETUP   0x0
 *  05:00            NWE_SETUP   0x0
 * </pre>
 */
#define SMC_SETUP1_REG    (*(volatile uint32_t *)(0x01000010))
#define SMC_SETUP1_ADDR   0x01000010
#define SMC_SETUP1_OFFSET 0x00000010
#define SMC_SETUP1_INDEX  0x00000004

__INLINE uint32_t smc_setup1_get(void)
{
    return SMC_SETUP1_REG;
}

__INLINE void smc_setup1_set(uint32_t value)
{
    SMC_SETUP1_REG = value;
}

// field definitions
#define NCS_RD_SETUP_MASK   0x3F000000
#define NCS_RD_SETUP_LSB    24
#define NCS_RD_SETUP_WIDTH  0x00000006
#define NRD_SETUP_MASK      0x003F0000
#define NRD_SETUP_LSB       16
#define NRD_SETUP_WIDTH     0x00000006
#define NCS_WR_SETUP_MASK   0x00003F00
#define NCS_WR_SETUP_LSB    8
#define NCS_WR_SETUP_WIDTH  0x00000006
#define NWE_SETUP_MASK      0x0000003F
#define NWE_SETUP_LSB       0
#define NWE_SETUP_WIDTH     0x00000006

#define NCS_RD_SETUP_RST    0x0
#define NRD_SETUP_RST       0x0
#define NCS_WR_SETUP_RST    0x0
#define NWE_SETUP_RST       0x0

__INLINE void smc_setup1_pack(uint8_t ncsrdsetup, uint8_t nrdsetup, uint8_t ncswrsetup, uint8_t nwesetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP1_REG =  (ncsrdsetup << 24) | (nrdsetup << 16) | (ncswrsetup << 8) | (nwesetup << 0);
}

__INLINE void smc_setup1_unpack(uint8_t* ncsrdsetup, uint8_t* nrdsetup, uint8_t* ncswrsetup, uint8_t* nwesetup)
{
    uint32_t localVal = SMC_SETUP1_REG;

    *ncsrdsetup = (localVal & 0x3F000000) >> 24;
    *nrdsetup = (localVal & 0x003F0000) >> 16;
    *ncswrsetup = (localVal & 0x00003F00) >> 8;
    *nwesetup = (localVal & 0x0000003F) >> 0;
}

__INLINE uint8_t smc_setup1_ncs_rd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP1_REG;
    return ((localVal & 0x3F000000) >> 24);
}

__INLINE void smc_setup1_ncs_rd_setup_setf(uint8_t ncsrdsetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    SMC_SETUP1_REG = (SMC_SETUP1_REG & ~0x3F000000) | (ncsrdsetup << 24);
}

__INLINE uint8_t smc_setup1_nrd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP1_REG;
    return ((localVal & 0x003F0000) >> 16);
}

__INLINE void smc_setup1_nrd_setup_setf(uint8_t nrdsetup)
{
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    SMC_SETUP1_REG = (SMC_SETUP1_REG & ~0x003F0000) | (nrdsetup << 16);
}

__INLINE uint8_t smc_setup1_ncs_wr_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP1_REG;
    return ((localVal & 0x00003F00) >> 8);
}

__INLINE void smc_setup1_ncs_wr_setup_setf(uint8_t ncswrsetup)
{
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    SMC_SETUP1_REG = (SMC_SETUP1_REG & ~0x00003F00) | (ncswrsetup << 8);
}

__INLINE uint8_t smc_setup1_nwe_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP1_REG;
    return ((localVal & 0x0000003F) >> 0);
}

__INLINE void smc_setup1_nwe_setup_setf(uint8_t nwesetup)
{
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP1_REG = (SMC_SETUP1_REG & ~0x0000003F) | (nwesetup << 0);
}

/**
 * @brief SMC_PULSE1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  30:24         NCS_RD_PULSE   0x0
 *  22:16            NRD_PULSE   0x0
 *  14:08         NCS_WR_PULSE   0x0
 *  06:00            NWE_PULSE   0x0
 * </pre>
 */
#define SMC_PULSE1_REG    (*(volatile uint32_t *)(0x01000014))
#define SMC_PULSE1_ADDR   0x01000014
#define SMC_PULSE1_OFFSET 0x00000014
#define SMC_PULSE1_INDEX  0x00000005

__INLINE uint32_t smc_pulse1_get(void)
{
    return SMC_PULSE1_REG;
}

__INLINE void smc_pulse1_set(uint32_t value)
{
    SMC_PULSE1_REG = value;
}

// field definitions
#define NCS_RD_PULSE_MASK   0x7F000000
#define NCS_RD_PULSE_LSB    24
#define NCS_RD_PULSE_WIDTH  0x00000007
#define NRD_PULSE_MASK      0x007F0000
#define NRD_PULSE_LSB       16
#define NRD_PULSE_WIDTH     0x00000007
#define NCS_WR_PULSE_MASK   0x00007F00
#define NCS_WR_PULSE_LSB    8
#define NCS_WR_PULSE_WIDTH  0x00000007
#define NWE_PULSE_MASK      0x0000007F
#define NWE_PULSE_LSB       0
#define NWE_PULSE_WIDTH     0x00000007

#define NCS_RD_PULSE_RST    0x0
#define NRD_PULSE_RST       0x0
#define NCS_WR_PULSE_RST    0x0
#define NWE_PULSE_RST       0x0

__INLINE void smc_pulse1_pack(uint8_t ncsrdpulse, uint8_t nrdpulse, uint8_t ncswrpulse, uint8_t nwepulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE1_REG =  (ncsrdpulse << 24) | (nrdpulse << 16) | (ncswrpulse << 8) | (nwepulse << 0);
}

__INLINE void smc_pulse1_unpack(uint8_t* ncsrdpulse, uint8_t* nrdpulse, uint8_t* ncswrpulse, uint8_t* nwepulse)
{
    uint32_t localVal = SMC_PULSE1_REG;

    *ncsrdpulse = (localVal & 0x7F000000) >> 24;
    *nrdpulse = (localVal & 0x007F0000) >> 16;
    *ncswrpulse = (localVal & 0x00007F00) >> 8;
    *nwepulse = (localVal & 0x0000007F) >> 0;
}

__INLINE uint8_t smc_pulse1_ncs_rd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE1_REG;
    return ((localVal & 0x7F000000) >> 24);
}

__INLINE void smc_pulse1_ncs_rd_pulse_setf(uint8_t ncsrdpulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    SMC_PULSE1_REG = (SMC_PULSE1_REG & ~0x7F000000) | (ncsrdpulse << 24);
}

__INLINE uint8_t smc_pulse1_nrd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE1_REG;
    return ((localVal & 0x007F0000) >> 16);
}

__INLINE void smc_pulse1_nrd_pulse_setf(uint8_t nrdpulse)
{
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    SMC_PULSE1_REG = (SMC_PULSE1_REG & ~0x007F0000) | (nrdpulse << 16);
}

__INLINE uint8_t smc_pulse1_ncs_wr_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE1_REG;
    return ((localVal & 0x00007F00) >> 8);
}

__INLINE void smc_pulse1_ncs_wr_pulse_setf(uint8_t ncswrpulse)
{
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    SMC_PULSE1_REG = (SMC_PULSE1_REG & ~0x00007F00) | (ncswrpulse << 8);
}

__INLINE uint8_t smc_pulse1_nwe_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE1_REG;
    return ((localVal & 0x0000007F) >> 0);
}

__INLINE void smc_pulse1_nwe_pulse_setf(uint8_t nwepulse)
{
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE1_REG = (SMC_PULSE1_REG & ~0x0000007F) | (nwepulse << 0);
}

/**
 * @brief SMC_CYCLE1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16            NRD_CYCLE   0x0
 *  08:00            NWE_CYCLE   0x0
 * </pre>
 */
#define SMC_CYCLE1_REG    (*(volatile uint32_t *)(0x01000018))
#define SMC_CYCLE1_ADDR   0x01000018
#define SMC_CYCLE1_OFFSET 0x00000018
#define SMC_CYCLE1_INDEX  0x00000006

__INLINE uint32_t smc_cycle1_get(void)
{
    return SMC_CYCLE1_REG;
}

__INLINE void smc_cycle1_set(uint32_t value)
{
    SMC_CYCLE1_REG = value;
}

// field definitions
#define NRD_CYCLE_MASK   0x01FF0000
#define NRD_CYCLE_LSB    16
#define NRD_CYCLE_WIDTH  0x00000009
#define NWE_CYCLE_MASK   0x000001FF
#define NWE_CYCLE_LSB    0
#define NWE_CYCLE_WIDTH  0x00000009

#define NRD_CYCLE_RST    0x0
#define NWE_CYCLE_RST    0x0

__INLINE void smc_cycle1_pack(uint16_t nrdcycle, uint16_t nwecycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE1_REG =  (nrdcycle << 16) | (nwecycle << 0);
}

__INLINE void smc_cycle1_unpack(uint16_t* nrdcycle, uint16_t* nwecycle)
{
    uint32_t localVal = SMC_CYCLE1_REG;

    *nrdcycle = (localVal & 0x01FF0000) >> 16;
    *nwecycle = (localVal & 0x000001FF) >> 0;
}

__INLINE uint16_t smc_cycle1_nrd_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE1_REG;
    return ((localVal & 0x01FF0000) >> 16);
}

__INLINE void smc_cycle1_nrd_cycle_setf(uint16_t nrdcycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    SMC_CYCLE1_REG = (SMC_CYCLE1_REG & ~0x01FF0000) | (nrdcycle << 16);
}

__INLINE uint16_t smc_cycle1_nwe_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE1_REG;
    return ((localVal & 0x000001FF) >> 0);
}

__INLINE void smc_cycle1_nwe_cycle_setf(uint16_t nwecycle)
{
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE1_REG = (SMC_CYCLE1_REG & ~0x000001FF) | (nwecycle << 0);
}

/**
 * @brief SMC_MODE1 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28                   PS   0x0
 *     24                 PMEN   0
 *     20             TDF_MODE   0
 *  19:16           TDF_CYCLES   0x0
 *  13:12                  DBW   0x0
 *     08                  BAT   0
 *  05:04            EXNW_MODE   0x0
 *     01           WRITE_MODE   0
 *     00            READ_MODE   0
 * </pre>
 */
#define SMC_MODE1_REG    (*(volatile uint32_t *)(0x0100001C))
#define SMC_MODE1_ADDR   0x0100001C
#define SMC_MODE1_OFFSET 0x0000001C
#define SMC_MODE1_INDEX  0x00000007

__INLINE uint32_t smc_mode1_get(void)
{
    return SMC_MODE1_REG;
}

__INLINE void smc_mode1_set(uint32_t value)
{
    SMC_MODE1_REG = value;
}

// field definitions
#define PS_MASK           0x30000000
#define PS_LSB            28
#define PS_WIDTH          0x00000002
#define PMEN_BIT          0x01000000
#define PMEN_POS          24
#define TDF_MODE_BIT      0x00100000
#define TDF_MODE_POS      20
#define TDF_CYCLES_MASK   0x000F0000
#define TDF_CYCLES_LSB    16
#define TDF_CYCLES_WIDTH  0x00000004
#define DBW_MASK          0x00003000
#define DBW_LSB           12
#define DBW_WIDTH         0x00000002
#define BAT_BIT           0x00000100
#define BAT_POS           8
#define EXNW_MODE_MASK    0x00000030
#define EXNW_MODE_LSB     4
#define EXNW_MODE_WIDTH   0x00000002
#define WRITE_MODE_BIT    0x00000002
#define WRITE_MODE_POS    1
#define READ_MODE_BIT     0x00000001
#define READ_MODE_POS     0

#define PS_RST            0x0
#define PMEN_RST          0x0
#define TDF_MODE_RST      0x0
#define TDF_CYCLES_RST    0x0
#define DBW_RST           0x0
#define BAT_RST           0x0
#define EXNW_MODE_RST     0x0
#define WRITE_MODE_RST    0x0
#define READ_MODE_RST     0x0

__INLINE void smc_mode1_pack(uint8_t ps, uint8_t pmen, uint8_t tdfmode, uint8_t tdfcycles, uint8_t dbw, uint8_t bat, uint8_t exnwmode, uint8_t writemode, uint8_t readmode)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE1_REG =  (ps << 28) | (pmen << 24) | (tdfmode << 20) | (tdfcycles << 16) | (dbw << 12) | (bat << 8) | (exnwmode << 4) | (writemode << 1) | (readmode << 0);
}

__INLINE void smc_mode1_unpack(uint8_t* ps, uint8_t* pmen, uint8_t* tdfmode, uint8_t* tdfcycles, uint8_t* dbw, uint8_t* bat, uint8_t* exnwmode, uint8_t* writemode, uint8_t* readmode)
{
    uint32_t localVal = SMC_MODE1_REG;

    *ps = (localVal & 0x30000000) >> 28;
    *pmen = (localVal & 0x01000000) >> 24;
    *tdfmode = (localVal & 0x00100000) >> 20;
    *tdfcycles = (localVal & 0x000F0000) >> 16;
    *dbw = (localVal & 0x00003000) >> 12;
    *bat = (localVal & 0x00000100) >> 8;
    *exnwmode = (localVal & 0x00000030) >> 4;
    *writemode = (localVal & 0x00000002) >> 1;
    *readmode = (localVal & 0x00000001) >> 0;
}

__INLINE uint8_t smc_mode1_ps_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x30000000) >> 28);
}

__INLINE void smc_mode1_ps_setf(uint8_t ps)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x30000000) | (ps << 28);
}

__INLINE uint8_t smc_mode1_pmen_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x01000000) >> 24);
}

__INLINE void smc_mode1_pmen_setf(uint8_t pmen)
{
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x01000000) | (pmen << 24);
}

__INLINE uint8_t smc_mode1_tdf_mode_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x00100000) >> 20);
}

__INLINE void smc_mode1_tdf_mode_setf(uint8_t tdfmode)
{
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x00100000) | (tdfmode << 20);
}

__INLINE uint8_t smc_mode1_tdf_cycles_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x000F0000) >> 16);
}

__INLINE void smc_mode1_tdf_cycles_setf(uint8_t tdfcycles)
{
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x000F0000) | (tdfcycles << 16);
}

__INLINE uint8_t smc_mode1_dbw_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x00003000) >> 12);
}

__INLINE void smc_mode1_dbw_setf(uint8_t dbw)
{
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x00003000) | (dbw << 12);
}

__INLINE uint8_t smc_mode1_bat_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x00000100) >> 8);
}

__INLINE void smc_mode1_bat_setf(uint8_t bat)
{
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x00000100) | (bat << 8);
}

__INLINE uint8_t smc_mode1_exnw_mode_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x00000030) >> 4);
}

__INLINE void smc_mode1_exnw_mode_setf(uint8_t exnwmode)
{
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x00000030) | (exnwmode << 4);
}

__INLINE uint8_t smc_mode1_write_mode_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x00000002) >> 1);
}

__INLINE void smc_mode1_write_mode_setf(uint8_t writemode)
{
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x00000002) | (writemode << 1);
}

__INLINE uint8_t smc_mode1_read_mode_getf(void)
{
    uint32_t localVal = SMC_MODE1_REG;
    return ((localVal & 0x00000001) >> 0);
}

__INLINE void smc_mode1_read_mode_setf(uint8_t readmode)
{
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE1_REG = (SMC_MODE1_REG & ~0x00000001) | (readmode << 0);
}

/**
 * @brief SMC_SETUP2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:24         NCS_RD_SETUP   0x0
 *  21:16            NRD_SETUP   0x0
 *  13:08         NCS_WR_SETUP   0x0
 *  05:00            NWE_SETUP   0x0
 * </pre>
 */
#define SMC_SETUP2_REG    (*(volatile uint32_t *)(0x01000020))
#define SMC_SETUP2_ADDR   0x01000020
#define SMC_SETUP2_OFFSET 0x00000020
#define SMC_SETUP2_INDEX  0x00000008

__INLINE uint32_t smc_setup2_get(void)
{
    return SMC_SETUP2_REG;
}

__INLINE void smc_setup2_set(uint32_t value)
{
    SMC_SETUP2_REG = value;
}

// field definitions
#define NCS_RD_SETUP_MASK   0x3F000000
#define NCS_RD_SETUP_LSB    24
#define NCS_RD_SETUP_WIDTH  0x00000006
#define NRD_SETUP_MASK      0x003F0000
#define NRD_SETUP_LSB       16
#define NRD_SETUP_WIDTH     0x00000006
#define NCS_WR_SETUP_MASK   0x00003F00
#define NCS_WR_SETUP_LSB    8
#define NCS_WR_SETUP_WIDTH  0x00000006
#define NWE_SETUP_MASK      0x0000003F
#define NWE_SETUP_LSB       0
#define NWE_SETUP_WIDTH     0x00000006

#define NCS_RD_SETUP_RST    0x0
#define NRD_SETUP_RST       0x0
#define NCS_WR_SETUP_RST    0x0
#define NWE_SETUP_RST       0x0

__INLINE void smc_setup2_pack(uint8_t ncsrdsetup, uint8_t nrdsetup, uint8_t ncswrsetup, uint8_t nwesetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP2_REG =  (ncsrdsetup << 24) | (nrdsetup << 16) | (ncswrsetup << 8) | (nwesetup << 0);
}

__INLINE void smc_setup2_unpack(uint8_t* ncsrdsetup, uint8_t* nrdsetup, uint8_t* ncswrsetup, uint8_t* nwesetup)
{
    uint32_t localVal = SMC_SETUP2_REG;

    *ncsrdsetup = (localVal & 0x3F000000) >> 24;
    *nrdsetup = (localVal & 0x003F0000) >> 16;
    *ncswrsetup = (localVal & 0x00003F00) >> 8;
    *nwesetup = (localVal & 0x0000003F) >> 0;
}

__INLINE uint8_t smc_setup2_ncs_rd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP2_REG;
    return ((localVal & 0x3F000000) >> 24);
}

__INLINE void smc_setup2_ncs_rd_setup_setf(uint8_t ncsrdsetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    SMC_SETUP2_REG = (SMC_SETUP2_REG & ~0x3F000000) | (ncsrdsetup << 24);
}

__INLINE uint8_t smc_setup2_nrd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP2_REG;
    return ((localVal & 0x003F0000) >> 16);
}

__INLINE void smc_setup2_nrd_setup_setf(uint8_t nrdsetup)
{
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    SMC_SETUP2_REG = (SMC_SETUP2_REG & ~0x003F0000) | (nrdsetup << 16);
}

__INLINE uint8_t smc_setup2_ncs_wr_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP2_REG;
    return ((localVal & 0x00003F00) >> 8);
}

__INLINE void smc_setup2_ncs_wr_setup_setf(uint8_t ncswrsetup)
{
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    SMC_SETUP2_REG = (SMC_SETUP2_REG & ~0x00003F00) | (ncswrsetup << 8);
}

__INLINE uint8_t smc_setup2_nwe_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP2_REG;
    return ((localVal & 0x0000003F) >> 0);
}

__INLINE void smc_setup2_nwe_setup_setf(uint8_t nwesetup)
{
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP2_REG = (SMC_SETUP2_REG & ~0x0000003F) | (nwesetup << 0);
}

/**
 * @brief SMC_PULSE2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  30:24         NCS_RD_PULSE   0x0
 *  22:16            NRD_PULSE   0x0
 *  14:08         NCS_WR_PULSE   0x0
 *  06:00            NWE_PULSE   0x0
 * </pre>
 */
#define SMC_PULSE2_REG    (*(volatile uint32_t *)(0x01000024))
#define SMC_PULSE2_ADDR   0x01000024
#define SMC_PULSE2_OFFSET 0x00000024
#define SMC_PULSE2_INDEX  0x00000009

__INLINE uint32_t smc_pulse2_get(void)
{
    return SMC_PULSE2_REG;
}

__INLINE void smc_pulse2_set(uint32_t value)
{
    SMC_PULSE2_REG = value;
}

// field definitions
#define NCS_RD_PULSE_MASK   0x7F000000
#define NCS_RD_PULSE_LSB    24
#define NCS_RD_PULSE_WIDTH  0x00000007
#define NRD_PULSE_MASK      0x007F0000
#define NRD_PULSE_LSB       16
#define NRD_PULSE_WIDTH     0x00000007
#define NCS_WR_PULSE_MASK   0x00007F00
#define NCS_WR_PULSE_LSB    8
#define NCS_WR_PULSE_WIDTH  0x00000007
#define NWE_PULSE_MASK      0x0000007F
#define NWE_PULSE_LSB       0
#define NWE_PULSE_WIDTH     0x00000007

#define NCS_RD_PULSE_RST    0x0
#define NRD_PULSE_RST       0x0
#define NCS_WR_PULSE_RST    0x0
#define NWE_PULSE_RST       0x0

__INLINE void smc_pulse2_pack(uint8_t ncsrdpulse, uint8_t nrdpulse, uint8_t ncswrpulse, uint8_t nwepulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE2_REG =  (ncsrdpulse << 24) | (nrdpulse << 16) | (ncswrpulse << 8) | (nwepulse << 0);
}

__INLINE void smc_pulse2_unpack(uint8_t* ncsrdpulse, uint8_t* nrdpulse, uint8_t* ncswrpulse, uint8_t* nwepulse)
{
    uint32_t localVal = SMC_PULSE2_REG;

    *ncsrdpulse = (localVal & 0x7F000000) >> 24;
    *nrdpulse = (localVal & 0x007F0000) >> 16;
    *ncswrpulse = (localVal & 0x00007F00) >> 8;
    *nwepulse = (localVal & 0x0000007F) >> 0;
}

__INLINE uint8_t smc_pulse2_ncs_rd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE2_REG;
    return ((localVal & 0x7F000000) >> 24);
}

__INLINE void smc_pulse2_ncs_rd_pulse_setf(uint8_t ncsrdpulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    SMC_PULSE2_REG = (SMC_PULSE2_REG & ~0x7F000000) | (ncsrdpulse << 24);
}

__INLINE uint8_t smc_pulse2_nrd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE2_REG;
    return ((localVal & 0x007F0000) >> 16);
}

__INLINE void smc_pulse2_nrd_pulse_setf(uint8_t nrdpulse)
{
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    SMC_PULSE2_REG = (SMC_PULSE2_REG & ~0x007F0000) | (nrdpulse << 16);
}

__INLINE uint8_t smc_pulse2_ncs_wr_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE2_REG;
    return ((localVal & 0x00007F00) >> 8);
}

__INLINE void smc_pulse2_ncs_wr_pulse_setf(uint8_t ncswrpulse)
{
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    SMC_PULSE2_REG = (SMC_PULSE2_REG & ~0x00007F00) | (ncswrpulse << 8);
}

__INLINE uint8_t smc_pulse2_nwe_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE2_REG;
    return ((localVal & 0x0000007F) >> 0);
}

__INLINE void smc_pulse2_nwe_pulse_setf(uint8_t nwepulse)
{
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE2_REG = (SMC_PULSE2_REG & ~0x0000007F) | (nwepulse << 0);
}

/**
 * @brief SMC_CYCLE2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16            NRD_CYCLE   0x0
 *  08:00            NWE_CYCLE   0x0
 * </pre>
 */
#define SMC_CYCLE2_REG    (*(volatile uint32_t *)(0x01000028))
#define SMC_CYCLE2_ADDR   0x01000028
#define SMC_CYCLE2_OFFSET 0x00000028
#define SMC_CYCLE2_INDEX  0x0000000A

__INLINE uint32_t smc_cycle2_get(void)
{
    return SMC_CYCLE2_REG;
}

__INLINE void smc_cycle2_set(uint32_t value)
{
    SMC_CYCLE2_REG = value;
}

// field definitions
#define NRD_CYCLE_MASK   0x01FF0000
#define NRD_CYCLE_LSB    16
#define NRD_CYCLE_WIDTH  0x00000009
#define NWE_CYCLE_MASK   0x000001FF
#define NWE_CYCLE_LSB    0
#define NWE_CYCLE_WIDTH  0x00000009

#define NRD_CYCLE_RST    0x0
#define NWE_CYCLE_RST    0x0

__INLINE void smc_cycle2_pack(uint16_t nrdcycle, uint16_t nwecycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE2_REG =  (nrdcycle << 16) | (nwecycle << 0);
}

__INLINE void smc_cycle2_unpack(uint16_t* nrdcycle, uint16_t* nwecycle)
{
    uint32_t localVal = SMC_CYCLE2_REG;

    *nrdcycle = (localVal & 0x01FF0000) >> 16;
    *nwecycle = (localVal & 0x000001FF) >> 0;
}

__INLINE uint16_t smc_cycle2_nrd_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE2_REG;
    return ((localVal & 0x01FF0000) >> 16);
}

__INLINE void smc_cycle2_nrd_cycle_setf(uint16_t nrdcycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    SMC_CYCLE2_REG = (SMC_CYCLE2_REG & ~0x01FF0000) | (nrdcycle << 16);
}

__INLINE uint16_t smc_cycle2_nwe_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE2_REG;
    return ((localVal & 0x000001FF) >> 0);
}

__INLINE void smc_cycle2_nwe_cycle_setf(uint16_t nwecycle)
{
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE2_REG = (SMC_CYCLE2_REG & ~0x000001FF) | (nwecycle << 0);
}

/**
 * @brief SMC_MODE2 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28                   PS   0x0
 *     24                 PMEN   0
 *     20             TDF_MODE   0
 *  19:16           TDF_CYCLES   0x0
 *  13:12                  DBW   0x0
 *     08                  BAT   0
 *  05:04            EXNW_MODE   0x0
 *     01           WRITE_MODE   0
 *     00            READ_MODE   0
 * </pre>
 */
#define SMC_MODE2_REG    (*(volatile uint32_t *)(0x0100002C))
#define SMC_MODE2_ADDR   0x0100002C
#define SMC_MODE2_OFFSET 0x0000002C
#define SMC_MODE2_INDEX  0x0000000B

__INLINE uint32_t smc_mode2_get(void)
{
    return SMC_MODE2_REG;
}

__INLINE void smc_mode2_set(uint32_t value)
{
    SMC_MODE2_REG = value;
}

// field definitions
#define PS_MASK           0x30000000
#define PS_LSB            28
#define PS_WIDTH          0x00000002
#define PMEN_BIT          0x01000000
#define PMEN_POS          24
#define TDF_MODE_BIT      0x00100000
#define TDF_MODE_POS      20
#define TDF_CYCLES_MASK   0x000F0000
#define TDF_CYCLES_LSB    16
#define TDF_CYCLES_WIDTH  0x00000004
#define DBW_MASK          0x00003000
#define DBW_LSB           12
#define DBW_WIDTH         0x00000002
#define BAT_BIT           0x00000100
#define BAT_POS           8
#define EXNW_MODE_MASK    0x00000030
#define EXNW_MODE_LSB     4
#define EXNW_MODE_WIDTH   0x00000002
#define WRITE_MODE_BIT    0x00000002
#define WRITE_MODE_POS    1
#define READ_MODE_BIT     0x00000001
#define READ_MODE_POS     0

#define PS_RST            0x0
#define PMEN_RST          0x0
#define TDF_MODE_RST      0x0
#define TDF_CYCLES_RST    0x0
#define DBW_RST           0x0
#define BAT_RST           0x0
#define EXNW_MODE_RST     0x0
#define WRITE_MODE_RST    0x0
#define READ_MODE_RST     0x0

__INLINE void smc_mode2_pack(uint8_t ps, uint8_t pmen, uint8_t tdfmode, uint8_t tdfcycles, uint8_t dbw, uint8_t bat, uint8_t exnwmode, uint8_t writemode, uint8_t readmode)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE2_REG =  (ps << 28) | (pmen << 24) | (tdfmode << 20) | (tdfcycles << 16) | (dbw << 12) | (bat << 8) | (exnwmode << 4) | (writemode << 1) | (readmode << 0);
}

__INLINE void smc_mode2_unpack(uint8_t* ps, uint8_t* pmen, uint8_t* tdfmode, uint8_t* tdfcycles, uint8_t* dbw, uint8_t* bat, uint8_t* exnwmode, uint8_t* writemode, uint8_t* readmode)
{
    uint32_t localVal = SMC_MODE2_REG;

    *ps = (localVal & 0x30000000) >> 28;
    *pmen = (localVal & 0x01000000) >> 24;
    *tdfmode = (localVal & 0x00100000) >> 20;
    *tdfcycles = (localVal & 0x000F0000) >> 16;
    *dbw = (localVal & 0x00003000) >> 12;
    *bat = (localVal & 0x00000100) >> 8;
    *exnwmode = (localVal & 0x00000030) >> 4;
    *writemode = (localVal & 0x00000002) >> 1;
    *readmode = (localVal & 0x00000001) >> 0;
}

__INLINE uint8_t smc_mode2_ps_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x30000000) >> 28);
}

__INLINE void smc_mode2_ps_setf(uint8_t ps)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x30000000) | (ps << 28);
}

__INLINE uint8_t smc_mode2_pmen_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x01000000) >> 24);
}

__INLINE void smc_mode2_pmen_setf(uint8_t pmen)
{
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x01000000) | (pmen << 24);
}

__INLINE uint8_t smc_mode2_tdf_mode_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x00100000) >> 20);
}

__INLINE void smc_mode2_tdf_mode_setf(uint8_t tdfmode)
{
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x00100000) | (tdfmode << 20);
}

__INLINE uint8_t smc_mode2_tdf_cycles_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x000F0000) >> 16);
}

__INLINE void smc_mode2_tdf_cycles_setf(uint8_t tdfcycles)
{
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x000F0000) | (tdfcycles << 16);
}

__INLINE uint8_t smc_mode2_dbw_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x00003000) >> 12);
}

__INLINE void smc_mode2_dbw_setf(uint8_t dbw)
{
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x00003000) | (dbw << 12);
}

__INLINE uint8_t smc_mode2_bat_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x00000100) >> 8);
}

__INLINE void smc_mode2_bat_setf(uint8_t bat)
{
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x00000100) | (bat << 8);
}

__INLINE uint8_t smc_mode2_exnw_mode_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x00000030) >> 4);
}

__INLINE void smc_mode2_exnw_mode_setf(uint8_t exnwmode)
{
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x00000030) | (exnwmode << 4);
}

__INLINE uint8_t smc_mode2_write_mode_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x00000002) >> 1);
}

__INLINE void smc_mode2_write_mode_setf(uint8_t writemode)
{
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x00000002) | (writemode << 1);
}

__INLINE uint8_t smc_mode2_read_mode_getf(void)
{
    uint32_t localVal = SMC_MODE2_REG;
    return ((localVal & 0x00000001) >> 0);
}

__INLINE void smc_mode2_read_mode_setf(uint8_t readmode)
{
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE2_REG = (SMC_MODE2_REG & ~0x00000001) | (readmode << 0);
}

/**
 * @brief SMC_SETUP3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:24         NCS_RD_SETUP   0x0
 *  21:16            NRD_SETUP   0x0
 *  13:08         NCS_WR_SETUP   0x0
 *  05:00            NWE_SETUP   0x0
 * </pre>
 */
#define SMC_SETUP3_REG    (*(volatile uint32_t *)(0x01000030))
#define SMC_SETUP3_ADDR   0x01000030
#define SMC_SETUP3_OFFSET 0x00000030
#define SMC_SETUP3_INDEX  0x0000000C

__INLINE uint32_t smc_setup3_get(void)
{
    return SMC_SETUP3_REG;
}

__INLINE void smc_setup3_set(uint32_t value)
{
    SMC_SETUP3_REG = value;
}

// field definitions
#define NCS_RD_SETUP_MASK   0x3F000000
#define NCS_RD_SETUP_LSB    24
#define NCS_RD_SETUP_WIDTH  0x00000006
#define NRD_SETUP_MASK      0x003F0000
#define NRD_SETUP_LSB       16
#define NRD_SETUP_WIDTH     0x00000006
#define NCS_WR_SETUP_MASK   0x00003F00
#define NCS_WR_SETUP_LSB    8
#define NCS_WR_SETUP_WIDTH  0x00000006
#define NWE_SETUP_MASK      0x0000003F
#define NWE_SETUP_LSB       0
#define NWE_SETUP_WIDTH     0x00000006

#define NCS_RD_SETUP_RST    0x0
#define NRD_SETUP_RST       0x0
#define NCS_WR_SETUP_RST    0x0
#define NWE_SETUP_RST       0x0

__INLINE void smc_setup3_pack(uint8_t ncsrdsetup, uint8_t nrdsetup, uint8_t ncswrsetup, uint8_t nwesetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP3_REG =  (ncsrdsetup << 24) | (nrdsetup << 16) | (ncswrsetup << 8) | (nwesetup << 0);
}

__INLINE void smc_setup3_unpack(uint8_t* ncsrdsetup, uint8_t* nrdsetup, uint8_t* ncswrsetup, uint8_t* nwesetup)
{
    uint32_t localVal = SMC_SETUP3_REG;

    *ncsrdsetup = (localVal & 0x3F000000) >> 24;
    *nrdsetup = (localVal & 0x003F0000) >> 16;
    *ncswrsetup = (localVal & 0x00003F00) >> 8;
    *nwesetup = (localVal & 0x0000003F) >> 0;
}

__INLINE uint8_t smc_setup3_ncs_rd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP3_REG;
    return ((localVal & 0x3F000000) >> 24);
}

__INLINE void smc_setup3_ncs_rd_setup_setf(uint8_t ncsrdsetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    SMC_SETUP3_REG = (SMC_SETUP3_REG & ~0x3F000000) | (ncsrdsetup << 24);
}

__INLINE uint8_t smc_setup3_nrd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP3_REG;
    return ((localVal & 0x003F0000) >> 16);
}

__INLINE void smc_setup3_nrd_setup_setf(uint8_t nrdsetup)
{
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    SMC_SETUP3_REG = (SMC_SETUP3_REG & ~0x003F0000) | (nrdsetup << 16);
}

__INLINE uint8_t smc_setup3_ncs_wr_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP3_REG;
    return ((localVal & 0x00003F00) >> 8);
}

__INLINE void smc_setup3_ncs_wr_setup_setf(uint8_t ncswrsetup)
{
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    SMC_SETUP3_REG = (SMC_SETUP3_REG & ~0x00003F00) | (ncswrsetup << 8);
}

__INLINE uint8_t smc_setup3_nwe_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP3_REG;
    return ((localVal & 0x0000003F) >> 0);
}

__INLINE void smc_setup3_nwe_setup_setf(uint8_t nwesetup)
{
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP3_REG = (SMC_SETUP3_REG & ~0x0000003F) | (nwesetup << 0);
}

/**
 * @brief SMC_PULSE3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  30:24         NCS_RD_PULSE   0x0
 *  22:16            NRD_PULSE   0x0
 *  14:08         NCS_WR_PULSE   0x0
 *  06:00            NWE_PULSE   0x0
 * </pre>
 */
#define SMC_PULSE3_REG    (*(volatile uint32_t *)(0x01000034))
#define SMC_PULSE3_ADDR   0x01000034
#define SMC_PULSE3_OFFSET 0x00000034
#define SMC_PULSE3_INDEX  0x0000000D

__INLINE uint32_t smc_pulse3_get(void)
{
    return SMC_PULSE3_REG;
}

__INLINE void smc_pulse3_set(uint32_t value)
{
    SMC_PULSE3_REG = value;
}

// field definitions
#define NCS_RD_PULSE_MASK   0x7F000000
#define NCS_RD_PULSE_LSB    24
#define NCS_RD_PULSE_WIDTH  0x00000007
#define NRD_PULSE_MASK      0x007F0000
#define NRD_PULSE_LSB       16
#define NRD_PULSE_WIDTH     0x00000007
#define NCS_WR_PULSE_MASK   0x00007F00
#define NCS_WR_PULSE_LSB    8
#define NCS_WR_PULSE_WIDTH  0x00000007
#define NWE_PULSE_MASK      0x0000007F
#define NWE_PULSE_LSB       0
#define NWE_PULSE_WIDTH     0x00000007

#define NCS_RD_PULSE_RST    0x0
#define NRD_PULSE_RST       0x0
#define NCS_WR_PULSE_RST    0x0
#define NWE_PULSE_RST       0x0

__INLINE void smc_pulse3_pack(uint8_t ncsrdpulse, uint8_t nrdpulse, uint8_t ncswrpulse, uint8_t nwepulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE3_REG =  (ncsrdpulse << 24) | (nrdpulse << 16) | (ncswrpulse << 8) | (nwepulse << 0);
}

__INLINE void smc_pulse3_unpack(uint8_t* ncsrdpulse, uint8_t* nrdpulse, uint8_t* ncswrpulse, uint8_t* nwepulse)
{
    uint32_t localVal = SMC_PULSE3_REG;

    *ncsrdpulse = (localVal & 0x7F000000) >> 24;
    *nrdpulse = (localVal & 0x007F0000) >> 16;
    *ncswrpulse = (localVal & 0x00007F00) >> 8;
    *nwepulse = (localVal & 0x0000007F) >> 0;
}

__INLINE uint8_t smc_pulse3_ncs_rd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE3_REG;
    return ((localVal & 0x7F000000) >> 24);
}

__INLINE void smc_pulse3_ncs_rd_pulse_setf(uint8_t ncsrdpulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    SMC_PULSE3_REG = (SMC_PULSE3_REG & ~0x7F000000) | (ncsrdpulse << 24);
}

__INLINE uint8_t smc_pulse3_nrd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE3_REG;
    return ((localVal & 0x007F0000) >> 16);
}

__INLINE void smc_pulse3_nrd_pulse_setf(uint8_t nrdpulse)
{
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    SMC_PULSE3_REG = (SMC_PULSE3_REG & ~0x007F0000) | (nrdpulse << 16);
}

__INLINE uint8_t smc_pulse3_ncs_wr_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE3_REG;
    return ((localVal & 0x00007F00) >> 8);
}

__INLINE void smc_pulse3_ncs_wr_pulse_setf(uint8_t ncswrpulse)
{
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    SMC_PULSE3_REG = (SMC_PULSE3_REG & ~0x00007F00) | (ncswrpulse << 8);
}

__INLINE uint8_t smc_pulse3_nwe_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE3_REG;
    return ((localVal & 0x0000007F) >> 0);
}

__INLINE void smc_pulse3_nwe_pulse_setf(uint8_t nwepulse)
{
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE3_REG = (SMC_PULSE3_REG & ~0x0000007F) | (nwepulse << 0);
}

/**
 * @brief SMC_CYCLE3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16            NRD_CYCLE   0x0
 *  08:00            NWE_CYCLE   0x0
 * </pre>
 */
#define SMC_CYCLE3_REG    (*(volatile uint32_t *)(0x01000038))
#define SMC_CYCLE3_ADDR   0x01000038
#define SMC_CYCLE3_OFFSET 0x00000038
#define SMC_CYCLE3_INDEX  0x0000000E

__INLINE uint32_t smc_cycle3_get(void)
{
    return SMC_CYCLE3_REG;
}

__INLINE void smc_cycle3_set(uint32_t value)
{
    SMC_CYCLE3_REG = value;
}

// field definitions
#define NRD_CYCLE_MASK   0x01FF0000
#define NRD_CYCLE_LSB    16
#define NRD_CYCLE_WIDTH  0x00000009
#define NWE_CYCLE_MASK   0x000001FF
#define NWE_CYCLE_LSB    0
#define NWE_CYCLE_WIDTH  0x00000009

#define NRD_CYCLE_RST    0x0
#define NWE_CYCLE_RST    0x0

__INLINE void smc_cycle3_pack(uint16_t nrdcycle, uint16_t nwecycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE3_REG =  (nrdcycle << 16) | (nwecycle << 0);
}

__INLINE void smc_cycle3_unpack(uint16_t* nrdcycle, uint16_t* nwecycle)
{
    uint32_t localVal = SMC_CYCLE3_REG;

    *nrdcycle = (localVal & 0x01FF0000) >> 16;
    *nwecycle = (localVal & 0x000001FF) >> 0;
}

__INLINE uint16_t smc_cycle3_nrd_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE3_REG;
    return ((localVal & 0x01FF0000) >> 16);
}

__INLINE void smc_cycle3_nrd_cycle_setf(uint16_t nrdcycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    SMC_CYCLE3_REG = (SMC_CYCLE3_REG & ~0x01FF0000) | (nrdcycle << 16);
}

__INLINE uint16_t smc_cycle3_nwe_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE3_REG;
    return ((localVal & 0x000001FF) >> 0);
}

__INLINE void smc_cycle3_nwe_cycle_setf(uint16_t nwecycle)
{
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE3_REG = (SMC_CYCLE3_REG & ~0x000001FF) | (nwecycle << 0);
}

/**
 * @brief SMC_MODE3 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28                   PS   0x0
 *     24                 PMEN   0
 *     20             TDF_MODE   0
 *  19:16           TDF_CYCLES   0x0
 *  13:12                  DBW   0x0
 *     08                  BAT   0
 *  05:04            EXNW_MODE   0x0
 *     01           WRITE_MODE   0
 *     00            READ_MODE   0
 * </pre>
 */
#define SMC_MODE3_REG    (*(volatile uint32_t *)(0x0100003C))
#define SMC_MODE3_ADDR   0x0100003C
#define SMC_MODE3_OFFSET 0x0000003C
#define SMC_MODE3_INDEX  0x0000000F

__INLINE uint32_t smc_mode3_get(void)
{
    return SMC_MODE3_REG;
}

__INLINE void smc_mode3_set(uint32_t value)
{
    SMC_MODE3_REG = value;
}

// field definitions
#define PS_MASK           0x30000000
#define PS_LSB            28
#define PS_WIDTH          0x00000002
#define PMEN_BIT          0x01000000
#define PMEN_POS          24
#define TDF_MODE_BIT      0x00100000
#define TDF_MODE_POS      20
#define TDF_CYCLES_MASK   0x000F0000
#define TDF_CYCLES_LSB    16
#define TDF_CYCLES_WIDTH  0x00000004
#define DBW_MASK          0x00003000
#define DBW_LSB           12
#define DBW_WIDTH         0x00000002
#define BAT_BIT           0x00000100
#define BAT_POS           8
#define EXNW_MODE_MASK    0x00000030
#define EXNW_MODE_LSB     4
#define EXNW_MODE_WIDTH   0x00000002
#define WRITE_MODE_BIT    0x00000002
#define WRITE_MODE_POS    1
#define READ_MODE_BIT     0x00000001
#define READ_MODE_POS     0

#define PS_RST            0x0
#define PMEN_RST          0x0
#define TDF_MODE_RST      0x0
#define TDF_CYCLES_RST    0x0
#define DBW_RST           0x0
#define BAT_RST           0x0
#define EXNW_MODE_RST     0x0
#define WRITE_MODE_RST    0x0
#define READ_MODE_RST     0x0

__INLINE void smc_mode3_pack(uint8_t ps, uint8_t pmen, uint8_t tdfmode, uint8_t tdfcycles, uint8_t dbw, uint8_t bat, uint8_t exnwmode, uint8_t writemode, uint8_t readmode)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE3_REG =  (ps << 28) | (pmen << 24) | (tdfmode << 20) | (tdfcycles << 16) | (dbw << 12) | (bat << 8) | (exnwmode << 4) | (writemode << 1) | (readmode << 0);
}

__INLINE void smc_mode3_unpack(uint8_t* ps, uint8_t* pmen, uint8_t* tdfmode, uint8_t* tdfcycles, uint8_t* dbw, uint8_t* bat, uint8_t* exnwmode, uint8_t* writemode, uint8_t* readmode)
{
    uint32_t localVal = SMC_MODE3_REG;

    *ps = (localVal & 0x30000000) >> 28;
    *pmen = (localVal & 0x01000000) >> 24;
    *tdfmode = (localVal & 0x00100000) >> 20;
    *tdfcycles = (localVal & 0x000F0000) >> 16;
    *dbw = (localVal & 0x00003000) >> 12;
    *bat = (localVal & 0x00000100) >> 8;
    *exnwmode = (localVal & 0x00000030) >> 4;
    *writemode = (localVal & 0x00000002) >> 1;
    *readmode = (localVal & 0x00000001) >> 0;
}

__INLINE uint8_t smc_mode3_ps_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x30000000) >> 28);
}

__INLINE void smc_mode3_ps_setf(uint8_t ps)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x30000000) | (ps << 28);
}

__INLINE uint8_t smc_mode3_pmen_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x01000000) >> 24);
}

__INLINE void smc_mode3_pmen_setf(uint8_t pmen)
{
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x01000000) | (pmen << 24);
}

__INLINE uint8_t smc_mode3_tdf_mode_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x00100000) >> 20);
}

__INLINE void smc_mode3_tdf_mode_setf(uint8_t tdfmode)
{
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x00100000) | (tdfmode << 20);
}

__INLINE uint8_t smc_mode3_tdf_cycles_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x000F0000) >> 16);
}

__INLINE void smc_mode3_tdf_cycles_setf(uint8_t tdfcycles)
{
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x000F0000) | (tdfcycles << 16);
}

__INLINE uint8_t smc_mode3_dbw_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x00003000) >> 12);
}

__INLINE void smc_mode3_dbw_setf(uint8_t dbw)
{
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x00003000) | (dbw << 12);
}

__INLINE uint8_t smc_mode3_bat_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x00000100) >> 8);
}

__INLINE void smc_mode3_bat_setf(uint8_t bat)
{
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x00000100) | (bat << 8);
}

__INLINE uint8_t smc_mode3_exnw_mode_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x00000030) >> 4);
}

__INLINE void smc_mode3_exnw_mode_setf(uint8_t exnwmode)
{
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x00000030) | (exnwmode << 4);
}

__INLINE uint8_t smc_mode3_write_mode_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x00000002) >> 1);
}

__INLINE void smc_mode3_write_mode_setf(uint8_t writemode)
{
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x00000002) | (writemode << 1);
}

__INLINE uint8_t smc_mode3_read_mode_getf(void)
{
    uint32_t localVal = SMC_MODE3_REG;
    return ((localVal & 0x00000001) >> 0);
}

__INLINE void smc_mode3_read_mode_setf(uint8_t readmode)
{
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE3_REG = (SMC_MODE3_REG & ~0x00000001) | (readmode << 0);
}

/**
 * @brief SMC_SETUP4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:24         NCS_RD_SETUP   0x0
 *  21:16            NRD_SETUP   0x0
 *  13:08         NCS_WR_SETUP   0x0
 *  05:00            NWE_SETUP   0x0
 * </pre>
 */
#define SMC_SETUP4_REG    (*(volatile uint32_t *)(0x01000040))
#define SMC_SETUP4_ADDR   0x01000040
#define SMC_SETUP4_OFFSET 0x00000040
#define SMC_SETUP4_INDEX  0x00000010

__INLINE uint32_t smc_setup4_get(void)
{
    return SMC_SETUP4_REG;
}

__INLINE void smc_setup4_set(uint32_t value)
{
    SMC_SETUP4_REG = value;
}

// field definitions
#define NCS_RD_SETUP_MASK   0x3F000000
#define NCS_RD_SETUP_LSB    24
#define NCS_RD_SETUP_WIDTH  0x00000006
#define NRD_SETUP_MASK      0x003F0000
#define NRD_SETUP_LSB       16
#define NRD_SETUP_WIDTH     0x00000006
#define NCS_WR_SETUP_MASK   0x00003F00
#define NCS_WR_SETUP_LSB    8
#define NCS_WR_SETUP_WIDTH  0x00000006
#define NWE_SETUP_MASK      0x0000003F
#define NWE_SETUP_LSB       0
#define NWE_SETUP_WIDTH     0x00000006

#define NCS_RD_SETUP_RST    0x0
#define NRD_SETUP_RST       0x0
#define NCS_WR_SETUP_RST    0x0
#define NWE_SETUP_RST       0x0

__INLINE void smc_setup4_pack(uint8_t ncsrdsetup, uint8_t nrdsetup, uint8_t ncswrsetup, uint8_t nwesetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP4_REG =  (ncsrdsetup << 24) | (nrdsetup << 16) | (ncswrsetup << 8) | (nwesetup << 0);
}

__INLINE void smc_setup4_unpack(uint8_t* ncsrdsetup, uint8_t* nrdsetup, uint8_t* ncswrsetup, uint8_t* nwesetup)
{
    uint32_t localVal = SMC_SETUP4_REG;

    *ncsrdsetup = (localVal & 0x3F000000) >> 24;
    *nrdsetup = (localVal & 0x003F0000) >> 16;
    *ncswrsetup = (localVal & 0x00003F00) >> 8;
    *nwesetup = (localVal & 0x0000003F) >> 0;
}

__INLINE uint8_t smc_setup4_ncs_rd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP4_REG;
    return ((localVal & 0x3F000000) >> 24);
}

__INLINE void smc_setup4_ncs_rd_setup_setf(uint8_t ncsrdsetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    SMC_SETUP4_REG = (SMC_SETUP4_REG & ~0x3F000000) | (ncsrdsetup << 24);
}

__INLINE uint8_t smc_setup4_nrd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP4_REG;
    return ((localVal & 0x003F0000) >> 16);
}

__INLINE void smc_setup4_nrd_setup_setf(uint8_t nrdsetup)
{
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    SMC_SETUP4_REG = (SMC_SETUP4_REG & ~0x003F0000) | (nrdsetup << 16);
}

__INLINE uint8_t smc_setup4_ncs_wr_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP4_REG;
    return ((localVal & 0x00003F00) >> 8);
}

__INLINE void smc_setup4_ncs_wr_setup_setf(uint8_t ncswrsetup)
{
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    SMC_SETUP4_REG = (SMC_SETUP4_REG & ~0x00003F00) | (ncswrsetup << 8);
}

__INLINE uint8_t smc_setup4_nwe_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP4_REG;
    return ((localVal & 0x0000003F) >> 0);
}

__INLINE void smc_setup4_nwe_setup_setf(uint8_t nwesetup)
{
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP4_REG = (SMC_SETUP4_REG & ~0x0000003F) | (nwesetup << 0);
}

/**
 * @brief SMC_PULSE4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  30:24         NCS_RD_PULSE   0x0
 *  22:16            NRD_PULSE   0x0
 *  14:08         NCS_WR_PULSE   0x0
 *  06:00            NWE_PULSE   0x0
 * </pre>
 */
#define SMC_PULSE4_REG    (*(volatile uint32_t *)(0x01000044))
#define SMC_PULSE4_ADDR   0x01000044
#define SMC_PULSE4_OFFSET 0x00000044
#define SMC_PULSE4_INDEX  0x00000011

__INLINE uint32_t smc_pulse4_get(void)
{
    return SMC_PULSE4_REG;
}

__INLINE void smc_pulse4_set(uint32_t value)
{
    SMC_PULSE4_REG = value;
}

// field definitions
#define NCS_RD_PULSE_MASK   0x7F000000
#define NCS_RD_PULSE_LSB    24
#define NCS_RD_PULSE_WIDTH  0x00000007
#define NRD_PULSE_MASK      0x007F0000
#define NRD_PULSE_LSB       16
#define NRD_PULSE_WIDTH     0x00000007
#define NCS_WR_PULSE_MASK   0x00007F00
#define NCS_WR_PULSE_LSB    8
#define NCS_WR_PULSE_WIDTH  0x00000007
#define NWE_PULSE_MASK      0x0000007F
#define NWE_PULSE_LSB       0
#define NWE_PULSE_WIDTH     0x00000007

#define NCS_RD_PULSE_RST    0x0
#define NRD_PULSE_RST       0x0
#define NCS_WR_PULSE_RST    0x0
#define NWE_PULSE_RST       0x0

__INLINE void smc_pulse4_pack(uint8_t ncsrdpulse, uint8_t nrdpulse, uint8_t ncswrpulse, uint8_t nwepulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE4_REG =  (ncsrdpulse << 24) | (nrdpulse << 16) | (ncswrpulse << 8) | (nwepulse << 0);
}

__INLINE void smc_pulse4_unpack(uint8_t* ncsrdpulse, uint8_t* nrdpulse, uint8_t* ncswrpulse, uint8_t* nwepulse)
{
    uint32_t localVal = SMC_PULSE4_REG;

    *ncsrdpulse = (localVal & 0x7F000000) >> 24;
    *nrdpulse = (localVal & 0x007F0000) >> 16;
    *ncswrpulse = (localVal & 0x00007F00) >> 8;
    *nwepulse = (localVal & 0x0000007F) >> 0;
}

__INLINE uint8_t smc_pulse4_ncs_rd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE4_REG;
    return ((localVal & 0x7F000000) >> 24);
}

__INLINE void smc_pulse4_ncs_rd_pulse_setf(uint8_t ncsrdpulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    SMC_PULSE4_REG = (SMC_PULSE4_REG & ~0x7F000000) | (ncsrdpulse << 24);
}

__INLINE uint8_t smc_pulse4_nrd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE4_REG;
    return ((localVal & 0x007F0000) >> 16);
}

__INLINE void smc_pulse4_nrd_pulse_setf(uint8_t nrdpulse)
{
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    SMC_PULSE4_REG = (SMC_PULSE4_REG & ~0x007F0000) | (nrdpulse << 16);
}

__INLINE uint8_t smc_pulse4_ncs_wr_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE4_REG;
    return ((localVal & 0x00007F00) >> 8);
}

__INLINE void smc_pulse4_ncs_wr_pulse_setf(uint8_t ncswrpulse)
{
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    SMC_PULSE4_REG = (SMC_PULSE4_REG & ~0x00007F00) | (ncswrpulse << 8);
}

__INLINE uint8_t smc_pulse4_nwe_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE4_REG;
    return ((localVal & 0x0000007F) >> 0);
}

__INLINE void smc_pulse4_nwe_pulse_setf(uint8_t nwepulse)
{
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE4_REG = (SMC_PULSE4_REG & ~0x0000007F) | (nwepulse << 0);
}

/**
 * @brief SMC_CYCLE4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16            NRD_CYCLE   0x0
 *  08:00            NWE_CYCLE   0x0
 * </pre>
 */
#define SMC_CYCLE4_REG    (*(volatile uint32_t *)(0x01000048))
#define SMC_CYCLE4_ADDR   0x01000048
#define SMC_CYCLE4_OFFSET 0x00000048
#define SMC_CYCLE4_INDEX  0x00000012

__INLINE uint32_t smc_cycle4_get(void)
{
    return SMC_CYCLE4_REG;
}

__INLINE void smc_cycle4_set(uint32_t value)
{
    SMC_CYCLE4_REG = value;
}

// field definitions
#define NRD_CYCLE_MASK   0x01FF0000
#define NRD_CYCLE_LSB    16
#define NRD_CYCLE_WIDTH  0x00000009
#define NWE_CYCLE_MASK   0x000001FF
#define NWE_CYCLE_LSB    0
#define NWE_CYCLE_WIDTH  0x00000009

#define NRD_CYCLE_RST    0x0
#define NWE_CYCLE_RST    0x0

__INLINE void smc_cycle4_pack(uint16_t nrdcycle, uint16_t nwecycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE4_REG =  (nrdcycle << 16) | (nwecycle << 0);
}

__INLINE void smc_cycle4_unpack(uint16_t* nrdcycle, uint16_t* nwecycle)
{
    uint32_t localVal = SMC_CYCLE4_REG;

    *nrdcycle = (localVal & 0x01FF0000) >> 16;
    *nwecycle = (localVal & 0x000001FF) >> 0;
}

__INLINE uint16_t smc_cycle4_nrd_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE4_REG;
    return ((localVal & 0x01FF0000) >> 16);
}

__INLINE void smc_cycle4_nrd_cycle_setf(uint16_t nrdcycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    SMC_CYCLE4_REG = (SMC_CYCLE4_REG & ~0x01FF0000) | (nrdcycle << 16);
}

__INLINE uint16_t smc_cycle4_nwe_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE4_REG;
    return ((localVal & 0x000001FF) >> 0);
}

__INLINE void smc_cycle4_nwe_cycle_setf(uint16_t nwecycle)
{
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE4_REG = (SMC_CYCLE4_REG & ~0x000001FF) | (nwecycle << 0);
}

/**
 * @brief SMC_MODE4 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28                   PS   0x0
 *     24                 PMEN   0
 *     20             TDF_MODE   0
 *  19:16           TDF_CYCLES   0x0
 *  13:12                  DBW   0x0
 *     08                  BAT   0
 *  05:04            EXNW_MODE   0x0
 *     01           WRITE_MODE   0
 *     00            READ_MODE   0
 * </pre>
 */
#define SMC_MODE4_REG    (*(volatile uint32_t *)(0x0100004C))
#define SMC_MODE4_ADDR   0x0100004C
#define SMC_MODE4_OFFSET 0x0000004C
#define SMC_MODE4_INDEX  0x00000013

__INLINE uint32_t smc_mode4_get(void)
{
    return SMC_MODE4_REG;
}

__INLINE void smc_mode4_set(uint32_t value)
{
    SMC_MODE4_REG = value;
}

// field definitions
#define PS_MASK           0x30000000
#define PS_LSB            28
#define PS_WIDTH          0x00000002
#define PMEN_BIT          0x01000000
#define PMEN_POS          24
#define TDF_MODE_BIT      0x00100000
#define TDF_MODE_POS      20
#define TDF_CYCLES_MASK   0x000F0000
#define TDF_CYCLES_LSB    16
#define TDF_CYCLES_WIDTH  0x00000004
#define DBW_MASK          0x00003000
#define DBW_LSB           12
#define DBW_WIDTH         0x00000002
#define BAT_BIT           0x00000100
#define BAT_POS           8
#define EXNW_MODE_MASK    0x00000030
#define EXNW_MODE_LSB     4
#define EXNW_MODE_WIDTH   0x00000002
#define WRITE_MODE_BIT    0x00000002
#define WRITE_MODE_POS    1
#define READ_MODE_BIT     0x00000001
#define READ_MODE_POS     0

#define PS_RST            0x0
#define PMEN_RST          0x0
#define TDF_MODE_RST      0x0
#define TDF_CYCLES_RST    0x0
#define DBW_RST           0x0
#define BAT_RST           0x0
#define EXNW_MODE_RST     0x0
#define WRITE_MODE_RST    0x0
#define READ_MODE_RST     0x0

__INLINE void smc_mode4_pack(uint8_t ps, uint8_t pmen, uint8_t tdfmode, uint8_t tdfcycles, uint8_t dbw, uint8_t bat, uint8_t exnwmode, uint8_t writemode, uint8_t readmode)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE4_REG =  (ps << 28) | (pmen << 24) | (tdfmode << 20) | (tdfcycles << 16) | (dbw << 12) | (bat << 8) | (exnwmode << 4) | (writemode << 1) | (readmode << 0);
}

__INLINE void smc_mode4_unpack(uint8_t* ps, uint8_t* pmen, uint8_t* tdfmode, uint8_t* tdfcycles, uint8_t* dbw, uint8_t* bat, uint8_t* exnwmode, uint8_t* writemode, uint8_t* readmode)
{
    uint32_t localVal = SMC_MODE4_REG;

    *ps = (localVal & 0x30000000) >> 28;
    *pmen = (localVal & 0x01000000) >> 24;
    *tdfmode = (localVal & 0x00100000) >> 20;
    *tdfcycles = (localVal & 0x000F0000) >> 16;
    *dbw = (localVal & 0x00003000) >> 12;
    *bat = (localVal & 0x00000100) >> 8;
    *exnwmode = (localVal & 0x00000030) >> 4;
    *writemode = (localVal & 0x00000002) >> 1;
    *readmode = (localVal & 0x00000001) >> 0;
}

__INLINE uint8_t smc_mode4_ps_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x30000000) >> 28);
}

__INLINE void smc_mode4_ps_setf(uint8_t ps)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x30000000) | (ps << 28);
}

__INLINE uint8_t smc_mode4_pmen_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x01000000) >> 24);
}

__INLINE void smc_mode4_pmen_setf(uint8_t pmen)
{
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x01000000) | (pmen << 24);
}

__INLINE uint8_t smc_mode4_tdf_mode_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x00100000) >> 20);
}

__INLINE void smc_mode4_tdf_mode_setf(uint8_t tdfmode)
{
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x00100000) | (tdfmode << 20);
}

__INLINE uint8_t smc_mode4_tdf_cycles_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x000F0000) >> 16);
}

__INLINE void smc_mode4_tdf_cycles_setf(uint8_t tdfcycles)
{
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x000F0000) | (tdfcycles << 16);
}

__INLINE uint8_t smc_mode4_dbw_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x00003000) >> 12);
}

__INLINE void smc_mode4_dbw_setf(uint8_t dbw)
{
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x00003000) | (dbw << 12);
}

__INLINE uint8_t smc_mode4_bat_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x00000100) >> 8);
}

__INLINE void smc_mode4_bat_setf(uint8_t bat)
{
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x00000100) | (bat << 8);
}

__INLINE uint8_t smc_mode4_exnw_mode_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x00000030) >> 4);
}

__INLINE void smc_mode4_exnw_mode_setf(uint8_t exnwmode)
{
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x00000030) | (exnwmode << 4);
}

__INLINE uint8_t smc_mode4_write_mode_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x00000002) >> 1);
}

__INLINE void smc_mode4_write_mode_setf(uint8_t writemode)
{
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x00000002) | (writemode << 1);
}

__INLINE uint8_t smc_mode4_read_mode_getf(void)
{
    uint32_t localVal = SMC_MODE4_REG;
    return ((localVal & 0x00000001) >> 0);
}

__INLINE void smc_mode4_read_mode_setf(uint8_t readmode)
{
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE4_REG = (SMC_MODE4_REG & ~0x00000001) | (readmode << 0);
}

/**
 * @brief SMC_SETUP5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:24         NCS_RD_SETUP   0x0
 *  21:16            NRD_SETUP   0x0
 *  13:08         NCS_WR_SETUP   0x0
 *  05:00            NWE_SETUP   0x0
 * </pre>
 */
#define SMC_SETUP5_REG    (*(volatile uint32_t *)(0x01000050))
#define SMC_SETUP5_ADDR   0x01000050
#define SMC_SETUP5_OFFSET 0x00000050
#define SMC_SETUP5_INDEX  0x00000014

__INLINE uint32_t smc_setup5_get(void)
{
    return SMC_SETUP5_REG;
}

__INLINE void smc_setup5_set(uint32_t value)
{
    SMC_SETUP5_REG = value;
}

// field definitions
#define NCS_RD_SETUP_MASK   0x3F000000
#define NCS_RD_SETUP_LSB    24
#define NCS_RD_SETUP_WIDTH  0x00000006
#define NRD_SETUP_MASK      0x003F0000
#define NRD_SETUP_LSB       16
#define NRD_SETUP_WIDTH     0x00000006
#define NCS_WR_SETUP_MASK   0x00003F00
#define NCS_WR_SETUP_LSB    8
#define NCS_WR_SETUP_WIDTH  0x00000006
#define NWE_SETUP_MASK      0x0000003F
#define NWE_SETUP_LSB       0
#define NWE_SETUP_WIDTH     0x00000006

#define NCS_RD_SETUP_RST    0x0
#define NRD_SETUP_RST       0x0
#define NCS_WR_SETUP_RST    0x0
#define NWE_SETUP_RST       0x0

__INLINE void smc_setup5_pack(uint8_t ncsrdsetup, uint8_t nrdsetup, uint8_t ncswrsetup, uint8_t nwesetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP5_REG =  (ncsrdsetup << 24) | (nrdsetup << 16) | (ncswrsetup << 8) | (nwesetup << 0);
}

__INLINE void smc_setup5_unpack(uint8_t* ncsrdsetup, uint8_t* nrdsetup, uint8_t* ncswrsetup, uint8_t* nwesetup)
{
    uint32_t localVal = SMC_SETUP5_REG;

    *ncsrdsetup = (localVal & 0x3F000000) >> 24;
    *nrdsetup = (localVal & 0x003F0000) >> 16;
    *ncswrsetup = (localVal & 0x00003F00) >> 8;
    *nwesetup = (localVal & 0x0000003F) >> 0;
}

__INLINE uint8_t smc_setup5_ncs_rd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP5_REG;
    return ((localVal & 0x3F000000) >> 24);
}

__INLINE void smc_setup5_ncs_rd_setup_setf(uint8_t ncsrdsetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    SMC_SETUP5_REG = (SMC_SETUP5_REG & ~0x3F000000) | (ncsrdsetup << 24);
}

__INLINE uint8_t smc_setup5_nrd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP5_REG;
    return ((localVal & 0x003F0000) >> 16);
}

__INLINE void smc_setup5_nrd_setup_setf(uint8_t nrdsetup)
{
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    SMC_SETUP5_REG = (SMC_SETUP5_REG & ~0x003F0000) | (nrdsetup << 16);
}

__INLINE uint8_t smc_setup5_ncs_wr_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP5_REG;
    return ((localVal & 0x00003F00) >> 8);
}

__INLINE void smc_setup5_ncs_wr_setup_setf(uint8_t ncswrsetup)
{
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    SMC_SETUP5_REG = (SMC_SETUP5_REG & ~0x00003F00) | (ncswrsetup << 8);
}

__INLINE uint8_t smc_setup5_nwe_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP5_REG;
    return ((localVal & 0x0000003F) >> 0);
}

__INLINE void smc_setup5_nwe_setup_setf(uint8_t nwesetup)
{
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP5_REG = (SMC_SETUP5_REG & ~0x0000003F) | (nwesetup << 0);
}

/**
 * @brief SMC_PULSE5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  30:24         NCS_RD_PULSE   0x0
 *  22:16            NRD_PULSE   0x0
 *  14:08         NCS_WR_PULSE   0x0
 *  06:00            NWE_PULSE   0x0
 * </pre>
 */
#define SMC_PULSE5_REG    (*(volatile uint32_t *)(0x01000054))
#define SMC_PULSE5_ADDR   0x01000054
#define SMC_PULSE5_OFFSET 0x00000054
#define SMC_PULSE5_INDEX  0x00000015

__INLINE uint32_t smc_pulse5_get(void)
{
    return SMC_PULSE5_REG;
}

__INLINE void smc_pulse5_set(uint32_t value)
{
    SMC_PULSE5_REG = value;
}

// field definitions
#define NCS_RD_PULSE_MASK   0x7F000000
#define NCS_RD_PULSE_LSB    24
#define NCS_RD_PULSE_WIDTH  0x00000007
#define NRD_PULSE_MASK      0x007F0000
#define NRD_PULSE_LSB       16
#define NRD_PULSE_WIDTH     0x00000007
#define NCS_WR_PULSE_MASK   0x00007F00
#define NCS_WR_PULSE_LSB    8
#define NCS_WR_PULSE_WIDTH  0x00000007
#define NWE_PULSE_MASK      0x0000007F
#define NWE_PULSE_LSB       0
#define NWE_PULSE_WIDTH     0x00000007

#define NCS_RD_PULSE_RST    0x0
#define NRD_PULSE_RST       0x0
#define NCS_WR_PULSE_RST    0x0
#define NWE_PULSE_RST       0x0

__INLINE void smc_pulse5_pack(uint8_t ncsrdpulse, uint8_t nrdpulse, uint8_t ncswrpulse, uint8_t nwepulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE5_REG =  (ncsrdpulse << 24) | (nrdpulse << 16) | (ncswrpulse << 8) | (nwepulse << 0);
}

__INLINE void smc_pulse5_unpack(uint8_t* ncsrdpulse, uint8_t* nrdpulse, uint8_t* ncswrpulse, uint8_t* nwepulse)
{
    uint32_t localVal = SMC_PULSE5_REG;

    *ncsrdpulse = (localVal & 0x7F000000) >> 24;
    *nrdpulse = (localVal & 0x007F0000) >> 16;
    *ncswrpulse = (localVal & 0x00007F00) >> 8;
    *nwepulse = (localVal & 0x0000007F) >> 0;
}

__INLINE uint8_t smc_pulse5_ncs_rd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE5_REG;
    return ((localVal & 0x7F000000) >> 24);
}

__INLINE void smc_pulse5_ncs_rd_pulse_setf(uint8_t ncsrdpulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    SMC_PULSE5_REG = (SMC_PULSE5_REG & ~0x7F000000) | (ncsrdpulse << 24);
}

__INLINE uint8_t smc_pulse5_nrd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE5_REG;
    return ((localVal & 0x007F0000) >> 16);
}

__INLINE void smc_pulse5_nrd_pulse_setf(uint8_t nrdpulse)
{
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    SMC_PULSE5_REG = (SMC_PULSE5_REG & ~0x007F0000) | (nrdpulse << 16);
}

__INLINE uint8_t smc_pulse5_ncs_wr_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE5_REG;
    return ((localVal & 0x00007F00) >> 8);
}

__INLINE void smc_pulse5_ncs_wr_pulse_setf(uint8_t ncswrpulse)
{
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    SMC_PULSE5_REG = (SMC_PULSE5_REG & ~0x00007F00) | (ncswrpulse << 8);
}

__INLINE uint8_t smc_pulse5_nwe_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE5_REG;
    return ((localVal & 0x0000007F) >> 0);
}

__INLINE void smc_pulse5_nwe_pulse_setf(uint8_t nwepulse)
{
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE5_REG = (SMC_PULSE5_REG & ~0x0000007F) | (nwepulse << 0);
}

/**
 * @brief SMC_CYCLE5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16            NRD_CYCLE   0x0
 *  08:00            NWE_CYCLE   0x0
 * </pre>
 */
#define SMC_CYCLE5_REG    (*(volatile uint32_t *)(0x01000058))
#define SMC_CYCLE5_ADDR   0x01000058
#define SMC_CYCLE5_OFFSET 0x00000058
#define SMC_CYCLE5_INDEX  0x00000016

__INLINE uint32_t smc_cycle5_get(void)
{
    return SMC_CYCLE5_REG;
}

__INLINE void smc_cycle5_set(uint32_t value)
{
    SMC_CYCLE5_REG = value;
}

// field definitions
#define NRD_CYCLE_MASK   0x01FF0000
#define NRD_CYCLE_LSB    16
#define NRD_CYCLE_WIDTH  0x00000009
#define NWE_CYCLE_MASK   0x000001FF
#define NWE_CYCLE_LSB    0
#define NWE_CYCLE_WIDTH  0x00000009

#define NRD_CYCLE_RST    0x0
#define NWE_CYCLE_RST    0x0

__INLINE void smc_cycle5_pack(uint16_t nrdcycle, uint16_t nwecycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE5_REG =  (nrdcycle << 16) | (nwecycle << 0);
}

__INLINE void smc_cycle5_unpack(uint16_t* nrdcycle, uint16_t* nwecycle)
{
    uint32_t localVal = SMC_CYCLE5_REG;

    *nrdcycle = (localVal & 0x01FF0000) >> 16;
    *nwecycle = (localVal & 0x000001FF) >> 0;
}

__INLINE uint16_t smc_cycle5_nrd_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE5_REG;
    return ((localVal & 0x01FF0000) >> 16);
}

__INLINE void smc_cycle5_nrd_cycle_setf(uint16_t nrdcycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    SMC_CYCLE5_REG = (SMC_CYCLE5_REG & ~0x01FF0000) | (nrdcycle << 16);
}

__INLINE uint16_t smc_cycle5_nwe_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE5_REG;
    return ((localVal & 0x000001FF) >> 0);
}

__INLINE void smc_cycle5_nwe_cycle_setf(uint16_t nwecycle)
{
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE5_REG = (SMC_CYCLE5_REG & ~0x000001FF) | (nwecycle << 0);
}

/**
 * @brief SMC_MODE5 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28                   PS   0x0
 *     24                 PMEN   0
 *     20             TDF_MODE   0
 *  19:16           TDF_CYCLES   0x0
 *  13:12                  DBW   0x0
 *     08                  BAT   0
 *  05:04            EXNW_MODE   0x0
 *     01           WRITE_MODE   0
 *     00            READ_MODE   0
 * </pre>
 */
#define SMC_MODE5_REG    (*(volatile uint32_t *)(0x0100005C))
#define SMC_MODE5_ADDR   0x0100005C
#define SMC_MODE5_OFFSET 0x0000005C
#define SMC_MODE5_INDEX  0x00000017

__INLINE uint32_t smc_mode5_get(void)
{
    return SMC_MODE5_REG;
}

__INLINE void smc_mode5_set(uint32_t value)
{
    SMC_MODE5_REG = value;
}

// field definitions
#define PS_MASK           0x30000000
#define PS_LSB            28
#define PS_WIDTH          0x00000002
#define PMEN_BIT          0x01000000
#define PMEN_POS          24
#define TDF_MODE_BIT      0x00100000
#define TDF_MODE_POS      20
#define TDF_CYCLES_MASK   0x000F0000
#define TDF_CYCLES_LSB    16
#define TDF_CYCLES_WIDTH  0x00000004
#define DBW_MASK          0x00003000
#define DBW_LSB           12
#define DBW_WIDTH         0x00000002
#define BAT_BIT           0x00000100
#define BAT_POS           8
#define EXNW_MODE_MASK    0x00000030
#define EXNW_MODE_LSB     4
#define EXNW_MODE_WIDTH   0x00000002
#define WRITE_MODE_BIT    0x00000002
#define WRITE_MODE_POS    1
#define READ_MODE_BIT     0x00000001
#define READ_MODE_POS     0

#define PS_RST            0x0
#define PMEN_RST          0x0
#define TDF_MODE_RST      0x0
#define TDF_CYCLES_RST    0x0
#define DBW_RST           0x0
#define BAT_RST           0x0
#define EXNW_MODE_RST     0x0
#define WRITE_MODE_RST    0x0
#define READ_MODE_RST     0x0

__INLINE void smc_mode5_pack(uint8_t ps, uint8_t pmen, uint8_t tdfmode, uint8_t tdfcycles, uint8_t dbw, uint8_t bat, uint8_t exnwmode, uint8_t writemode, uint8_t readmode)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE5_REG =  (ps << 28) | (pmen << 24) | (tdfmode << 20) | (tdfcycles << 16) | (dbw << 12) | (bat << 8) | (exnwmode << 4) | (writemode << 1) | (readmode << 0);
}

__INLINE void smc_mode5_unpack(uint8_t* ps, uint8_t* pmen, uint8_t* tdfmode, uint8_t* tdfcycles, uint8_t* dbw, uint8_t* bat, uint8_t* exnwmode, uint8_t* writemode, uint8_t* readmode)
{
    uint32_t localVal = SMC_MODE5_REG;

    *ps = (localVal & 0x30000000) >> 28;
    *pmen = (localVal & 0x01000000) >> 24;
    *tdfmode = (localVal & 0x00100000) >> 20;
    *tdfcycles = (localVal & 0x000F0000) >> 16;
    *dbw = (localVal & 0x00003000) >> 12;
    *bat = (localVal & 0x00000100) >> 8;
    *exnwmode = (localVal & 0x00000030) >> 4;
    *writemode = (localVal & 0x00000002) >> 1;
    *readmode = (localVal & 0x00000001) >> 0;
}

__INLINE uint8_t smc_mode5_ps_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x30000000) >> 28);
}

__INLINE void smc_mode5_ps_setf(uint8_t ps)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x30000000) | (ps << 28);
}

__INLINE uint8_t smc_mode5_pmen_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x01000000) >> 24);
}

__INLINE void smc_mode5_pmen_setf(uint8_t pmen)
{
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x01000000) | (pmen << 24);
}

__INLINE uint8_t smc_mode5_tdf_mode_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x00100000) >> 20);
}

__INLINE void smc_mode5_tdf_mode_setf(uint8_t tdfmode)
{
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x00100000) | (tdfmode << 20);
}

__INLINE uint8_t smc_mode5_tdf_cycles_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x000F0000) >> 16);
}

__INLINE void smc_mode5_tdf_cycles_setf(uint8_t tdfcycles)
{
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x000F0000) | (tdfcycles << 16);
}

__INLINE uint8_t smc_mode5_dbw_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x00003000) >> 12);
}

__INLINE void smc_mode5_dbw_setf(uint8_t dbw)
{
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x00003000) | (dbw << 12);
}

__INLINE uint8_t smc_mode5_bat_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x00000100) >> 8);
}

__INLINE void smc_mode5_bat_setf(uint8_t bat)
{
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x00000100) | (bat << 8);
}

__INLINE uint8_t smc_mode5_exnw_mode_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x00000030) >> 4);
}

__INLINE void smc_mode5_exnw_mode_setf(uint8_t exnwmode)
{
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x00000030) | (exnwmode << 4);
}

__INLINE uint8_t smc_mode5_write_mode_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x00000002) >> 1);
}

__INLINE void smc_mode5_write_mode_setf(uint8_t writemode)
{
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x00000002) | (writemode << 1);
}

__INLINE uint8_t smc_mode5_read_mode_getf(void)
{
    uint32_t localVal = SMC_MODE5_REG;
    return ((localVal & 0x00000001) >> 0);
}

__INLINE void smc_mode5_read_mode_setf(uint8_t readmode)
{
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE5_REG = (SMC_MODE5_REG & ~0x00000001) | (readmode << 0);
}

/**
 * @brief SMC_SETUP6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:24         NCS_RD_SETUP   0x0
 *  21:16            NRD_SETUP   0x0
 *  13:08         NCS_WR_SETUP   0x0
 *  05:00            NWE_SETUP   0x0
 * </pre>
 */
#define SMC_SETUP6_REG    (*(volatile uint32_t *)(0x01000060))
#define SMC_SETUP6_ADDR   0x01000060
#define SMC_SETUP6_OFFSET 0x00000060
#define SMC_SETUP6_INDEX  0x00000018

__INLINE uint32_t smc_setup6_get(void)
{
    return SMC_SETUP6_REG;
}

__INLINE void smc_setup6_set(uint32_t value)
{
    SMC_SETUP6_REG = value;
}

// field definitions
#define NCS_RD_SETUP_MASK   0x3F000000
#define NCS_RD_SETUP_LSB    24
#define NCS_RD_SETUP_WIDTH  0x00000006
#define NRD_SETUP_MASK      0x003F0000
#define NRD_SETUP_LSB       16
#define NRD_SETUP_WIDTH     0x00000006
#define NCS_WR_SETUP_MASK   0x00003F00
#define NCS_WR_SETUP_LSB    8
#define NCS_WR_SETUP_WIDTH  0x00000006
#define NWE_SETUP_MASK      0x0000003F
#define NWE_SETUP_LSB       0
#define NWE_SETUP_WIDTH     0x00000006

#define NCS_RD_SETUP_RST    0x0
#define NRD_SETUP_RST       0x0
#define NCS_WR_SETUP_RST    0x0
#define NWE_SETUP_RST       0x0

__INLINE void smc_setup6_pack(uint8_t ncsrdsetup, uint8_t nrdsetup, uint8_t ncswrsetup, uint8_t nwesetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP6_REG =  (ncsrdsetup << 24) | (nrdsetup << 16) | (ncswrsetup << 8) | (nwesetup << 0);
}

__INLINE void smc_setup6_unpack(uint8_t* ncsrdsetup, uint8_t* nrdsetup, uint8_t* ncswrsetup, uint8_t* nwesetup)
{
    uint32_t localVal = SMC_SETUP6_REG;

    *ncsrdsetup = (localVal & 0x3F000000) >> 24;
    *nrdsetup = (localVal & 0x003F0000) >> 16;
    *ncswrsetup = (localVal & 0x00003F00) >> 8;
    *nwesetup = (localVal & 0x0000003F) >> 0;
}

__INLINE uint8_t smc_setup6_ncs_rd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP6_REG;
    return ((localVal & 0x3F000000) >> 24);
}

__INLINE void smc_setup6_ncs_rd_setup_setf(uint8_t ncsrdsetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    SMC_SETUP6_REG = (SMC_SETUP6_REG & ~0x3F000000) | (ncsrdsetup << 24);
}

__INLINE uint8_t smc_setup6_nrd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP6_REG;
    return ((localVal & 0x003F0000) >> 16);
}

__INLINE void smc_setup6_nrd_setup_setf(uint8_t nrdsetup)
{
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    SMC_SETUP6_REG = (SMC_SETUP6_REG & ~0x003F0000) | (nrdsetup << 16);
}

__INLINE uint8_t smc_setup6_ncs_wr_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP6_REG;
    return ((localVal & 0x00003F00) >> 8);
}

__INLINE void smc_setup6_ncs_wr_setup_setf(uint8_t ncswrsetup)
{
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    SMC_SETUP6_REG = (SMC_SETUP6_REG & ~0x00003F00) | (ncswrsetup << 8);
}

__INLINE uint8_t smc_setup6_nwe_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP6_REG;
    return ((localVal & 0x0000003F) >> 0);
}

__INLINE void smc_setup6_nwe_setup_setf(uint8_t nwesetup)
{
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP6_REG = (SMC_SETUP6_REG & ~0x0000003F) | (nwesetup << 0);
}

/**
 * @brief SMC_PULSE6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  30:24         NCS_RD_PULSE   0x0
 *  22:16            NRD_PULSE   0x0
 *  14:08         NCS_WR_PULSE   0x0
 *  06:00            NWE_PULSE   0x0
 * </pre>
 */
#define SMC_PULSE6_REG    (*(volatile uint32_t *)(0x01000064))
#define SMC_PULSE6_ADDR   0x01000064
#define SMC_PULSE6_OFFSET 0x00000064
#define SMC_PULSE6_INDEX  0x00000019

__INLINE uint32_t smc_pulse6_get(void)
{
    return SMC_PULSE6_REG;
}

__INLINE void smc_pulse6_set(uint32_t value)
{
    SMC_PULSE6_REG = value;
}

// field definitions
#define NCS_RD_PULSE_MASK   0x7F000000
#define NCS_RD_PULSE_LSB    24
#define NCS_RD_PULSE_WIDTH  0x00000007
#define NRD_PULSE_MASK      0x007F0000
#define NRD_PULSE_LSB       16
#define NRD_PULSE_WIDTH     0x00000007
#define NCS_WR_PULSE_MASK   0x00007F00
#define NCS_WR_PULSE_LSB    8
#define NCS_WR_PULSE_WIDTH  0x00000007
#define NWE_PULSE_MASK      0x0000007F
#define NWE_PULSE_LSB       0
#define NWE_PULSE_WIDTH     0x00000007

#define NCS_RD_PULSE_RST    0x0
#define NRD_PULSE_RST       0x0
#define NCS_WR_PULSE_RST    0x0
#define NWE_PULSE_RST       0x0

__INLINE void smc_pulse6_pack(uint8_t ncsrdpulse, uint8_t nrdpulse, uint8_t ncswrpulse, uint8_t nwepulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE6_REG =  (ncsrdpulse << 24) | (nrdpulse << 16) | (ncswrpulse << 8) | (nwepulse << 0);
}

__INLINE void smc_pulse6_unpack(uint8_t* ncsrdpulse, uint8_t* nrdpulse, uint8_t* ncswrpulse, uint8_t* nwepulse)
{
    uint32_t localVal = SMC_PULSE6_REG;

    *ncsrdpulse = (localVal & 0x7F000000) >> 24;
    *nrdpulse = (localVal & 0x007F0000) >> 16;
    *ncswrpulse = (localVal & 0x00007F00) >> 8;
    *nwepulse = (localVal & 0x0000007F) >> 0;
}

__INLINE uint8_t smc_pulse6_ncs_rd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE6_REG;
    return ((localVal & 0x7F000000) >> 24);
}

__INLINE void smc_pulse6_ncs_rd_pulse_setf(uint8_t ncsrdpulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    SMC_PULSE6_REG = (SMC_PULSE6_REG & ~0x7F000000) | (ncsrdpulse << 24);
}

__INLINE uint8_t smc_pulse6_nrd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE6_REG;
    return ((localVal & 0x007F0000) >> 16);
}

__INLINE void smc_pulse6_nrd_pulse_setf(uint8_t nrdpulse)
{
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    SMC_PULSE6_REG = (SMC_PULSE6_REG & ~0x007F0000) | (nrdpulse << 16);
}

__INLINE uint8_t smc_pulse6_ncs_wr_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE6_REG;
    return ((localVal & 0x00007F00) >> 8);
}

__INLINE void smc_pulse6_ncs_wr_pulse_setf(uint8_t ncswrpulse)
{
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    SMC_PULSE6_REG = (SMC_PULSE6_REG & ~0x00007F00) | (ncswrpulse << 8);
}

__INLINE uint8_t smc_pulse6_nwe_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE6_REG;
    return ((localVal & 0x0000007F) >> 0);
}

__INLINE void smc_pulse6_nwe_pulse_setf(uint8_t nwepulse)
{
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE6_REG = (SMC_PULSE6_REG & ~0x0000007F) | (nwepulse << 0);
}

/**
 * @brief SMC_CYCLE6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16            NRD_CYCLE   0x0
 *  08:00            NWE_CYCLE   0x0
 * </pre>
 */
#define SMC_CYCLE6_REG    (*(volatile uint32_t *)(0x01000068))
#define SMC_CYCLE6_ADDR   0x01000068
#define SMC_CYCLE6_OFFSET 0x00000068
#define SMC_CYCLE6_INDEX  0x0000001A

__INLINE uint32_t smc_cycle6_get(void)
{
    return SMC_CYCLE6_REG;
}

__INLINE void smc_cycle6_set(uint32_t value)
{
    SMC_CYCLE6_REG = value;
}

// field definitions
#define NRD_CYCLE_MASK   0x01FF0000
#define NRD_CYCLE_LSB    16
#define NRD_CYCLE_WIDTH  0x00000009
#define NWE_CYCLE_MASK   0x000001FF
#define NWE_CYCLE_LSB    0
#define NWE_CYCLE_WIDTH  0x00000009

#define NRD_CYCLE_RST    0x0
#define NWE_CYCLE_RST    0x0

__INLINE void smc_cycle6_pack(uint16_t nrdcycle, uint16_t nwecycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE6_REG =  (nrdcycle << 16) | (nwecycle << 0);
}

__INLINE void smc_cycle6_unpack(uint16_t* nrdcycle, uint16_t* nwecycle)
{
    uint32_t localVal = SMC_CYCLE6_REG;

    *nrdcycle = (localVal & 0x01FF0000) >> 16;
    *nwecycle = (localVal & 0x000001FF) >> 0;
}

__INLINE uint16_t smc_cycle6_nrd_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE6_REG;
    return ((localVal & 0x01FF0000) >> 16);
}

__INLINE void smc_cycle6_nrd_cycle_setf(uint16_t nrdcycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    SMC_CYCLE6_REG = (SMC_CYCLE6_REG & ~0x01FF0000) | (nrdcycle << 16);
}

__INLINE uint16_t smc_cycle6_nwe_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE6_REG;
    return ((localVal & 0x000001FF) >> 0);
}

__INLINE void smc_cycle6_nwe_cycle_setf(uint16_t nwecycle)
{
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE6_REG = (SMC_CYCLE6_REG & ~0x000001FF) | (nwecycle << 0);
}

/**
 * @brief SMC_MODE6 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28                   PS   0x0
 *     24                 PMEN   0
 *     20             TDF_MODE   0
 *  19:16           TDF_CYCLES   0x0
 *  13:12                  DBW   0x0
 *     08                  BAT   0
 *  05:04            EXNW_MODE   0x0
 *     01           WRITE_MODE   0
 *     00            READ_MODE   0
 * </pre>
 */
#define SMC_MODE6_REG    (*(volatile uint32_t *)(0x0100006C))
#define SMC_MODE6_ADDR   0x0100006C
#define SMC_MODE6_OFFSET 0x0000006C
#define SMC_MODE6_INDEX  0x0000001B

__INLINE uint32_t smc_mode6_get(void)
{
    return SMC_MODE6_REG;
}

__INLINE void smc_mode6_set(uint32_t value)
{
    SMC_MODE6_REG = value;
}

// field definitions
#define PS_MASK           0x30000000
#define PS_LSB            28
#define PS_WIDTH          0x00000002
#define PMEN_BIT          0x01000000
#define PMEN_POS          24
#define TDF_MODE_BIT      0x00100000
#define TDF_MODE_POS      20
#define TDF_CYCLES_MASK   0x000F0000
#define TDF_CYCLES_LSB    16
#define TDF_CYCLES_WIDTH  0x00000004
#define DBW_MASK          0x00003000
#define DBW_LSB           12
#define DBW_WIDTH         0x00000002
#define BAT_BIT           0x00000100
#define BAT_POS           8
#define EXNW_MODE_MASK    0x00000030
#define EXNW_MODE_LSB     4
#define EXNW_MODE_WIDTH   0x00000002
#define WRITE_MODE_BIT    0x00000002
#define WRITE_MODE_POS    1
#define READ_MODE_BIT     0x00000001
#define READ_MODE_POS     0

#define PS_RST            0x0
#define PMEN_RST          0x0
#define TDF_MODE_RST      0x0
#define TDF_CYCLES_RST    0x0
#define DBW_RST           0x0
#define BAT_RST           0x0
#define EXNW_MODE_RST     0x0
#define WRITE_MODE_RST    0x0
#define READ_MODE_RST     0x0

__INLINE void smc_mode6_pack(uint8_t ps, uint8_t pmen, uint8_t tdfmode, uint8_t tdfcycles, uint8_t dbw, uint8_t bat, uint8_t exnwmode, uint8_t writemode, uint8_t readmode)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE6_REG =  (ps << 28) | (pmen << 24) | (tdfmode << 20) | (tdfcycles << 16) | (dbw << 12) | (bat << 8) | (exnwmode << 4) | (writemode << 1) | (readmode << 0);
}

__INLINE void smc_mode6_unpack(uint8_t* ps, uint8_t* pmen, uint8_t* tdfmode, uint8_t* tdfcycles, uint8_t* dbw, uint8_t* bat, uint8_t* exnwmode, uint8_t* writemode, uint8_t* readmode)
{
    uint32_t localVal = SMC_MODE6_REG;

    *ps = (localVal & 0x30000000) >> 28;
    *pmen = (localVal & 0x01000000) >> 24;
    *tdfmode = (localVal & 0x00100000) >> 20;
    *tdfcycles = (localVal & 0x000F0000) >> 16;
    *dbw = (localVal & 0x00003000) >> 12;
    *bat = (localVal & 0x00000100) >> 8;
    *exnwmode = (localVal & 0x00000030) >> 4;
    *writemode = (localVal & 0x00000002) >> 1;
    *readmode = (localVal & 0x00000001) >> 0;
}

__INLINE uint8_t smc_mode6_ps_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x30000000) >> 28);
}

__INLINE void smc_mode6_ps_setf(uint8_t ps)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x30000000) | (ps << 28);
}

__INLINE uint8_t smc_mode6_pmen_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x01000000) >> 24);
}

__INLINE void smc_mode6_pmen_setf(uint8_t pmen)
{
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x01000000) | (pmen << 24);
}

__INLINE uint8_t smc_mode6_tdf_mode_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x00100000) >> 20);
}

__INLINE void smc_mode6_tdf_mode_setf(uint8_t tdfmode)
{
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x00100000) | (tdfmode << 20);
}

__INLINE uint8_t smc_mode6_tdf_cycles_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x000F0000) >> 16);
}

__INLINE void smc_mode6_tdf_cycles_setf(uint8_t tdfcycles)
{
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x000F0000) | (tdfcycles << 16);
}

__INLINE uint8_t smc_mode6_dbw_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x00003000) >> 12);
}

__INLINE void smc_mode6_dbw_setf(uint8_t dbw)
{
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x00003000) | (dbw << 12);
}

__INLINE uint8_t smc_mode6_bat_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x00000100) >> 8);
}

__INLINE void smc_mode6_bat_setf(uint8_t bat)
{
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x00000100) | (bat << 8);
}

__INLINE uint8_t smc_mode6_exnw_mode_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x00000030) >> 4);
}

__INLINE void smc_mode6_exnw_mode_setf(uint8_t exnwmode)
{
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x00000030) | (exnwmode << 4);
}

__INLINE uint8_t smc_mode6_write_mode_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x00000002) >> 1);
}

__INLINE void smc_mode6_write_mode_setf(uint8_t writemode)
{
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x00000002) | (writemode << 1);
}

__INLINE uint8_t smc_mode6_read_mode_getf(void)
{
    uint32_t localVal = SMC_MODE6_REG;
    return ((localVal & 0x00000001) >> 0);
}

__INLINE void smc_mode6_read_mode_setf(uint8_t readmode)
{
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE6_REG = (SMC_MODE6_REG & ~0x00000001) | (readmode << 0);
}

/**
 * @brief SMC_SETUP7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:24         NCS_RD_SETUP   0x0
 *  21:16            NRD_SETUP   0x0
 *  13:08         NCS_WR_SETUP   0x0
 *  05:00            NWE_SETUP   0x0
 * </pre>
 */
#define SMC_SETUP7_REG    (*(volatile uint32_t *)(0x01000070))
#define SMC_SETUP7_ADDR   0x01000070
#define SMC_SETUP7_OFFSET 0x00000070
#define SMC_SETUP7_INDEX  0x0000001C

__INLINE uint32_t smc_setup7_get(void)
{
    return SMC_SETUP7_REG;
}

__INLINE void smc_setup7_set(uint32_t value)
{
    SMC_SETUP7_REG = value;
}

// field definitions
#define NCS_RD_SETUP_MASK   0x3F000000
#define NCS_RD_SETUP_LSB    24
#define NCS_RD_SETUP_WIDTH  0x00000006
#define NRD_SETUP_MASK      0x003F0000
#define NRD_SETUP_LSB       16
#define NRD_SETUP_WIDTH     0x00000006
#define NCS_WR_SETUP_MASK   0x00003F00
#define NCS_WR_SETUP_LSB    8
#define NCS_WR_SETUP_WIDTH  0x00000006
#define NWE_SETUP_MASK      0x0000003F
#define NWE_SETUP_LSB       0
#define NWE_SETUP_WIDTH     0x00000006

#define NCS_RD_SETUP_RST    0x0
#define NRD_SETUP_RST       0x0
#define NCS_WR_SETUP_RST    0x0
#define NWE_SETUP_RST       0x0

__INLINE void smc_setup7_pack(uint8_t ncsrdsetup, uint8_t nrdsetup, uint8_t ncswrsetup, uint8_t nwesetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP7_REG =  (ncsrdsetup << 24) | (nrdsetup << 16) | (ncswrsetup << 8) | (nwesetup << 0);
}

__INLINE void smc_setup7_unpack(uint8_t* ncsrdsetup, uint8_t* nrdsetup, uint8_t* ncswrsetup, uint8_t* nwesetup)
{
    uint32_t localVal = SMC_SETUP7_REG;

    *ncsrdsetup = (localVal & 0x3F000000) >> 24;
    *nrdsetup = (localVal & 0x003F0000) >> 16;
    *ncswrsetup = (localVal & 0x00003F00) >> 8;
    *nwesetup = (localVal & 0x0000003F) >> 0;
}

__INLINE uint8_t smc_setup7_ncs_rd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP7_REG;
    return ((localVal & 0x3F000000) >> 24);
}

__INLINE void smc_setup7_ncs_rd_setup_setf(uint8_t ncsrdsetup)
{
    ASSERT_ERR(((ncsrdsetup << 24) & ~0x3F000000) == 0);
    SMC_SETUP7_REG = (SMC_SETUP7_REG & ~0x3F000000) | (ncsrdsetup << 24);
}

__INLINE uint8_t smc_setup7_nrd_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP7_REG;
    return ((localVal & 0x003F0000) >> 16);
}

__INLINE void smc_setup7_nrd_setup_setf(uint8_t nrdsetup)
{
    ASSERT_ERR(((nrdsetup << 16) & ~0x003F0000) == 0);
    SMC_SETUP7_REG = (SMC_SETUP7_REG & ~0x003F0000) | (nrdsetup << 16);
}

__INLINE uint8_t smc_setup7_ncs_wr_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP7_REG;
    return ((localVal & 0x00003F00) >> 8);
}

__INLINE void smc_setup7_ncs_wr_setup_setf(uint8_t ncswrsetup)
{
    ASSERT_ERR(((ncswrsetup << 8) & ~0x00003F00) == 0);
    SMC_SETUP7_REG = (SMC_SETUP7_REG & ~0x00003F00) | (ncswrsetup << 8);
}

__INLINE uint8_t smc_setup7_nwe_setup_getf(void)
{
    uint32_t localVal = SMC_SETUP7_REG;
    return ((localVal & 0x0000003F) >> 0);
}

__INLINE void smc_setup7_nwe_setup_setf(uint8_t nwesetup)
{
    ASSERT_ERR(((nwesetup << 0) & ~0x0000003F) == 0);
    SMC_SETUP7_REG = (SMC_SETUP7_REG & ~0x0000003F) | (nwesetup << 0);
}

/**
 * @brief SMC_PULSE7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  30:24         NCS_RD_PULSE   0x0
 *  22:16            NRD_PULSE   0x0
 *  14:08         NCS_WR_PULSE   0x0
 *  06:00            NWE_PULSE   0x0
 * </pre>
 */
#define SMC_PULSE7_REG    (*(volatile uint32_t *)(0x01000074))
#define SMC_PULSE7_ADDR   0x01000074
#define SMC_PULSE7_OFFSET 0x00000074
#define SMC_PULSE7_INDEX  0x0000001D

__INLINE uint32_t smc_pulse7_get(void)
{
    return SMC_PULSE7_REG;
}

__INLINE void smc_pulse7_set(uint32_t value)
{
    SMC_PULSE7_REG = value;
}

// field definitions
#define NCS_RD_PULSE_MASK   0x7F000000
#define NCS_RD_PULSE_LSB    24
#define NCS_RD_PULSE_WIDTH  0x00000007
#define NRD_PULSE_MASK      0x007F0000
#define NRD_PULSE_LSB       16
#define NRD_PULSE_WIDTH     0x00000007
#define NCS_WR_PULSE_MASK   0x00007F00
#define NCS_WR_PULSE_LSB    8
#define NCS_WR_PULSE_WIDTH  0x00000007
#define NWE_PULSE_MASK      0x0000007F
#define NWE_PULSE_LSB       0
#define NWE_PULSE_WIDTH     0x00000007

#define NCS_RD_PULSE_RST    0x0
#define NRD_PULSE_RST       0x0
#define NCS_WR_PULSE_RST    0x0
#define NWE_PULSE_RST       0x0

__INLINE void smc_pulse7_pack(uint8_t ncsrdpulse, uint8_t nrdpulse, uint8_t ncswrpulse, uint8_t nwepulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE7_REG =  (ncsrdpulse << 24) | (nrdpulse << 16) | (ncswrpulse << 8) | (nwepulse << 0);
}

__INLINE void smc_pulse7_unpack(uint8_t* ncsrdpulse, uint8_t* nrdpulse, uint8_t* ncswrpulse, uint8_t* nwepulse)
{
    uint32_t localVal = SMC_PULSE7_REG;

    *ncsrdpulse = (localVal & 0x7F000000) >> 24;
    *nrdpulse = (localVal & 0x007F0000) >> 16;
    *ncswrpulse = (localVal & 0x00007F00) >> 8;
    *nwepulse = (localVal & 0x0000007F) >> 0;
}

__INLINE uint8_t smc_pulse7_ncs_rd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE7_REG;
    return ((localVal & 0x7F000000) >> 24);
}

__INLINE void smc_pulse7_ncs_rd_pulse_setf(uint8_t ncsrdpulse)
{
    ASSERT_ERR(((ncsrdpulse << 24) & ~0x7F000000) == 0);
    SMC_PULSE7_REG = (SMC_PULSE7_REG & ~0x7F000000) | (ncsrdpulse << 24);
}

__INLINE uint8_t smc_pulse7_nrd_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE7_REG;
    return ((localVal & 0x007F0000) >> 16);
}

__INLINE void smc_pulse7_nrd_pulse_setf(uint8_t nrdpulse)
{
    ASSERT_ERR(((nrdpulse << 16) & ~0x007F0000) == 0);
    SMC_PULSE7_REG = (SMC_PULSE7_REG & ~0x007F0000) | (nrdpulse << 16);
}

__INLINE uint8_t smc_pulse7_ncs_wr_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE7_REG;
    return ((localVal & 0x00007F00) >> 8);
}

__INLINE void smc_pulse7_ncs_wr_pulse_setf(uint8_t ncswrpulse)
{
    ASSERT_ERR(((ncswrpulse << 8) & ~0x00007F00) == 0);
    SMC_PULSE7_REG = (SMC_PULSE7_REG & ~0x00007F00) | (ncswrpulse << 8);
}

__INLINE uint8_t smc_pulse7_nwe_pulse_getf(void)
{
    uint32_t localVal = SMC_PULSE7_REG;
    return ((localVal & 0x0000007F) >> 0);
}

__INLINE void smc_pulse7_nwe_pulse_setf(uint8_t nwepulse)
{
    ASSERT_ERR(((nwepulse << 0) & ~0x0000007F) == 0);
    SMC_PULSE7_REG = (SMC_PULSE7_REG & ~0x0000007F) | (nwepulse << 0);
}

/**
 * @brief SMC_CYCLE7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  24:16            NRD_CYCLE   0x0
 *  08:00            NWE_CYCLE   0x0
 * </pre>
 */
#define SMC_CYCLE7_REG    (*(volatile uint32_t *)(0x01000078))
#define SMC_CYCLE7_ADDR   0x01000078
#define SMC_CYCLE7_OFFSET 0x00000078
#define SMC_CYCLE7_INDEX  0x0000001E

__INLINE uint32_t smc_cycle7_get(void)
{
    return SMC_CYCLE7_REG;
}

__INLINE void smc_cycle7_set(uint32_t value)
{
    SMC_CYCLE7_REG = value;
}

// field definitions
#define NRD_CYCLE_MASK   0x01FF0000
#define NRD_CYCLE_LSB    16
#define NRD_CYCLE_WIDTH  0x00000009
#define NWE_CYCLE_MASK   0x000001FF
#define NWE_CYCLE_LSB    0
#define NWE_CYCLE_WIDTH  0x00000009

#define NRD_CYCLE_RST    0x0
#define NWE_CYCLE_RST    0x0

__INLINE void smc_cycle7_pack(uint16_t nrdcycle, uint16_t nwecycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE7_REG =  (nrdcycle << 16) | (nwecycle << 0);
}

__INLINE void smc_cycle7_unpack(uint16_t* nrdcycle, uint16_t* nwecycle)
{
    uint32_t localVal = SMC_CYCLE7_REG;

    *nrdcycle = (localVal & 0x01FF0000) >> 16;
    *nwecycle = (localVal & 0x000001FF) >> 0;
}

__INLINE uint16_t smc_cycle7_nrd_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE7_REG;
    return ((localVal & 0x01FF0000) >> 16);
}

__INLINE void smc_cycle7_nrd_cycle_setf(uint16_t nrdcycle)
{
    ASSERT_ERR(((nrdcycle << 16) & ~0x01FF0000) == 0);
    SMC_CYCLE7_REG = (SMC_CYCLE7_REG & ~0x01FF0000) | (nrdcycle << 16);
}

__INLINE uint16_t smc_cycle7_nwe_cycle_getf(void)
{
    uint32_t localVal = SMC_CYCLE7_REG;
    return ((localVal & 0x000001FF) >> 0);
}

__INLINE void smc_cycle7_nwe_cycle_setf(uint16_t nwecycle)
{
    ASSERT_ERR(((nwecycle << 0) & ~0x000001FF) == 0);
    SMC_CYCLE7_REG = (SMC_CYCLE7_REG & ~0x000001FF) | (nwecycle << 0);
}

/**
 * @brief SMC_MODE7 register definition
 * <pre>
 *   Bits           Field Name   Reset Value
 *  -----   ------------------   -----------
 *  29:28                   PS   0x0
 *     24                 PMEN   0
 *     20             TDF_MODE   0
 *  19:16           TDF_CYCLES   0x0
 *  13:12                  DBW   0x0
 *     08                  BAT   0
 *  05:04            EXNW_MODE   0x0
 *     01           WRITE_MODE   0
 *     00            READ_MODE   0
 * </pre>
 */
#define SMC_MODE7_REG    (*(volatile uint32_t *)(0x0100007C))
#define SMC_MODE7_ADDR   0x0100007C
#define SMC_MODE7_OFFSET 0x0000007C
#define SMC_MODE7_INDEX  0x0000001F

__INLINE uint32_t smc_mode7_get(void)
{
    return SMC_MODE7_REG;
}

__INLINE void smc_mode7_set(uint32_t value)
{
    SMC_MODE7_REG = value;
}

// field definitions
#define PS_MASK           0x30000000
#define PS_LSB            28
#define PS_WIDTH          0x00000002
#define PMEN_BIT          0x01000000
#define PMEN_POS          24
#define TDF_MODE_BIT      0x00100000
#define TDF_MODE_POS      20
#define TDF_CYCLES_MASK   0x000F0000
#define TDF_CYCLES_LSB    16
#define TDF_CYCLES_WIDTH  0x00000004
#define DBW_MASK          0x00003000
#define DBW_LSB           12
#define DBW_WIDTH         0x00000002
#define BAT_BIT           0x00000100
#define BAT_POS           8
#define EXNW_MODE_MASK    0x00000030
#define EXNW_MODE_LSB     4
#define EXNW_MODE_WIDTH   0x00000002
#define WRITE_MODE_BIT    0x00000002
#define WRITE_MODE_POS    1
#define READ_MODE_BIT     0x00000001
#define READ_MODE_POS     0

#define PS_RST            0x0
#define PMEN_RST          0x0
#define TDF_MODE_RST      0x0
#define TDF_CYCLES_RST    0x0
#define DBW_RST           0x0
#define BAT_RST           0x0
#define EXNW_MODE_RST     0x0
#define WRITE_MODE_RST    0x0
#define READ_MODE_RST     0x0

__INLINE void smc_mode7_pack(uint8_t ps, uint8_t pmen, uint8_t tdfmode, uint8_t tdfcycles, uint8_t dbw, uint8_t bat, uint8_t exnwmode, uint8_t writemode, uint8_t readmode)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE7_REG =  (ps << 28) | (pmen << 24) | (tdfmode << 20) | (tdfcycles << 16) | (dbw << 12) | (bat << 8) | (exnwmode << 4) | (writemode << 1) | (readmode << 0);
}

__INLINE void smc_mode7_unpack(uint8_t* ps, uint8_t* pmen, uint8_t* tdfmode, uint8_t* tdfcycles, uint8_t* dbw, uint8_t* bat, uint8_t* exnwmode, uint8_t* writemode, uint8_t* readmode)
{
    uint32_t localVal = SMC_MODE7_REG;

    *ps = (localVal & 0x30000000) >> 28;
    *pmen = (localVal & 0x01000000) >> 24;
    *tdfmode = (localVal & 0x00100000) >> 20;
    *tdfcycles = (localVal & 0x000F0000) >> 16;
    *dbw = (localVal & 0x00003000) >> 12;
    *bat = (localVal & 0x00000100) >> 8;
    *exnwmode = (localVal & 0x00000030) >> 4;
    *writemode = (localVal & 0x00000002) >> 1;
    *readmode = (localVal & 0x00000001) >> 0;
}

__INLINE uint8_t smc_mode7_ps_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x30000000) >> 28);
}

__INLINE void smc_mode7_ps_setf(uint8_t ps)
{
    ASSERT_ERR(((ps << 28) & ~0x30000000) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x30000000) | (ps << 28);
}

__INLINE uint8_t smc_mode7_pmen_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x01000000) >> 24);
}

__INLINE void smc_mode7_pmen_setf(uint8_t pmen)
{
    ASSERT_ERR(((pmen << 24) & ~0x01000000) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x01000000) | (pmen << 24);
}

__INLINE uint8_t smc_mode7_tdf_mode_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x00100000) >> 20);
}

__INLINE void smc_mode7_tdf_mode_setf(uint8_t tdfmode)
{
    ASSERT_ERR(((tdfmode << 20) & ~0x00100000) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x00100000) | (tdfmode << 20);
}

__INLINE uint8_t smc_mode7_tdf_cycles_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x000F0000) >> 16);
}

__INLINE void smc_mode7_tdf_cycles_setf(uint8_t tdfcycles)
{
    ASSERT_ERR(((tdfcycles << 16) & ~0x000F0000) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x000F0000) | (tdfcycles << 16);
}

__INLINE uint8_t smc_mode7_dbw_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x00003000) >> 12);
}

__INLINE void smc_mode7_dbw_setf(uint8_t dbw)
{
    ASSERT_ERR(((dbw << 12) & ~0x00003000) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x00003000) | (dbw << 12);
}

__INLINE uint8_t smc_mode7_bat_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x00000100) >> 8);
}

__INLINE void smc_mode7_bat_setf(uint8_t bat)
{
    ASSERT_ERR(((bat << 8) & ~0x00000100) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x00000100) | (bat << 8);
}

__INLINE uint8_t smc_mode7_exnw_mode_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x00000030) >> 4);
}

__INLINE void smc_mode7_exnw_mode_setf(uint8_t exnwmode)
{
    ASSERT_ERR(((exnwmode << 4) & ~0x00000030) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x00000030) | (exnwmode << 4);
}

__INLINE uint8_t smc_mode7_write_mode_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x00000002) >> 1);
}

__INLINE void smc_mode7_write_mode_setf(uint8_t writemode)
{
    ASSERT_ERR(((writemode << 1) & ~0x00000002) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x00000002) | (writemode << 1);
}

__INLINE uint8_t smc_mode7_read_mode_getf(void)
{
    uint32_t localVal = SMC_MODE7_REG;
    return ((localVal & 0x00000001) >> 0);
}

__INLINE void smc_mode7_read_mode_setf(uint8_t readmode)
{
    ASSERT_ERR(((readmode << 0) & ~0x00000001) == 0);
    SMC_MODE7_REG = (SMC_MODE7_REG & ~0x00000001) | (readmode << 0);
}


#endif // _SMC_H_

