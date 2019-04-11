/****************************************************************************

Copyright(c) 2016 by IoTelic Technologies. ALL RIGHTS RESERVED.

This Information is proprietary to IoTelic Technologies and MAY NOT
be copied by any method or incorporated into another program without
the express written consent of Iotelic. This Information or any portion
thereof remains the property of Iotelic. The Information contained herein
is believed to be accurate and Iotelic assumes no responsibility or
liability for its use in any way and conveys no license or title under
any patent or copyright and makes no representation or warranty that this
Information is free from patent or copyright infringement.

****************************************************************************/

#ifndef IOT_BITOPS_API_H
#define IOT_BITOPS_API_H

/* os shim includes */
#include "os_types_api.h"

/* define table size used for bit operation against one byte */
#define IOT_BITOPS_TAB_SIZE      (1 << 8)

/* table used for ffs and ffz operation */
extern const uint8_t iot_bitops_ffs_tab[IOT_BITOPS_TAB_SIZE];

/* table used for fls and flz operation */
extern const uint8_t iot_bitops_fls_tab[IOT_BITOPS_TAB_SIZE];

/* table used for cbs and cbz operation */
extern const uint8_t iot_bitops_cbs_tab[IOT_BITOPS_TAB_SIZE];

/**
 * @brief iot_bitops_ffs() - find first bit set to 1 from the least significant
 *                           bit.
 * @param b:  byte to be checked
 * @retval: 0        --  no bit set to 1
 * @retval: 1 ~ 8    --  the first bit set to 1.
 */
static inline uint8_t iot_bitops_ffs(uint8_t b)
{
    return iot_bitops_ffs_tab[b];
}

/**
 * @brief iot_bitops_ffz() - find first bit set to 0 from the least significant
 *                           bit.
 * @param b:  byte to be checked
 * @retval: 0        --  no bit set to 0
 * @retval: 1 ~ 8    --  the first bit set to 0.
 */
static inline uint8_t iot_bitops_ffz(uint8_t b)
{
    b = ~b;
    return iot_bitops_ffs_tab[b];
}

/**
 * @brief  iot_bitops_fls() - find last bit set to 1 from the least significant
 *                            bit.
 * @param b:  byte to be checked
 * @retval: 0        --  no bit set to 1
 * @retval: 1 ~ 8    --  the last bit set to 1.
 */
#define iot_bitops_fls(b) (iot_bitops_fls_tab[b])

/**
 * @brief iot_bitops_flz() - find last bit set to 0 from the least significant
 *                           bit.
 * @param b:  byte to be checked
 * @retval: 0        --  no bit set to 0
 * @retval: 1 ~ 8    --  the last bit set to 0.
 */
static inline uint8_t iot_bitops_flz(uint8_t b)
{
    b = ~b;
    return iot_bitops_fls_tab[b];
}

/**
 * @brief iot_bitops_cbs() - count the number of bits set to 1 in the byte
 * @param b: byte to be checked
 * @retval:  the number of bits set to 1
 */
static inline uint8_t iot_bitops_cbs(uint8_t b)
{
    return iot_bitops_cbs_tab[b];
}

/**
 * @brief  iot_bitops_cbz() - count the number of bits set to 0 in the byte
 * @param b: byte to be checked
 * @retval:  the number of bits set to 0
 */
static inline uint8_t iot_bitops_cbz(uint8_t b)
{
    b = ~b;
    return iot_bitops_cbs_tab[b];
}

#endif /* IOT_BITOPS_H */
