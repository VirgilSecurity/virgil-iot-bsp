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

#ifndef IOT_UTILS_API_H
#define IOT_UTILS_API_H

/* os shim includes */
#include "os_types_api.h"
#include "os_mem_api.h"

/** \defgroup MISC_APIs MISC APIs
 *  @brief MISC APIs
 *
 *
 */

/** @addtogroup MISC_APIs
 * @{
 *
 */

#if !defined(max)
#define max(a, b) (((a) > (b)) ? (a) : (b))
#endif

#if !defined(min)
#define min(a, b) (((a) < (b)) ? (a) : (b))
#endif

#define IOT_ARRAY_CNT(a) (sizeof(a) / sizeof(a[0]))

/**
 * @brief BUILD_BUG_ON() - raise build error if the condition is not true.
 *                  this macro is useful for checks in compilation time.
 * @param condition:    verify condition
 */
#define BUILD_BUG_ON(condition) ((void)sizeof(char[1 - (2 * (!(condition)))]))

/**
 * @brief container_of() - cast a member of a structure to the containing
 *                      structure.
 * @param ptr:      the pointer to the member
 * @param type:     the type of the container struct this is embedded in
 * @param member:   the name of the member within the struct
 */
#define container_of(ptr, type, member) ( \
    (type *)((uint8_t *)ptr - ((size_t) &((type *)0)->member)))

/* mac address length */
#define IOT_MAC_ADDR_LEN            6

/* maximum value of BCD codes */
#define IOT_MAC_BCD_MAX             0x99

/* broadcast mac address for downlink proxy broadcast */
extern const uint8_t bcast_mac[];

/**
 * @brief iot_mac_addr_uint8_array_to_long_int() - transform mac address
 *                      uint8_t[6] to a long long int.
 * @param mac_addr:     the uint8_t[6] mac address
 */
#define iot_mac_addr_uint8_array_to_long_int(mac_addr) \
    ((uint64_t)mac_addr[0] << (40) | \
    (uint64_t)mac_addr[1] << (32) | \
    (uint64_t)mac_addr[2] << (24) | \
    (uint64_t)mac_addr[3] << (16) | \
    (uint64_t)mac_addr[4] << (8) | \
    (uint64_t)mac_addr[5] << (0))

/**
 * @brief iot_uint64_to_mac_addr() - transform a long long int to mac address
 *                      uint8_t[6].
 * @param int64val:     the long int mac address
 * @param mac_addr:     the uint8_t[6] mac address
 */
#define iot_uint64_to_mac_addr(int64val, mac_addr) \
    {                                                        \
        mac_addr[0] = (((uint64_t)int64val) >> 40) & 0xFF;   \
        mac_addr[1] = (((uint64_t)int64val) >> 32) & 0xFF;   \
        mac_addr[2] = (((uint64_t)int64val) >> 24) & 0xFF;   \
        mac_addr[3] = (((uint64_t)int64val) >> 16) & 0xFF;   \
        mac_addr[4] = (((uint64_t)int64val) >> 8)  & 0xFF;   \
        mac_addr[5] = (((uint64_t)int64val) >> 0)  & 0xFF;   \
    }

/* get lower 32bit value of an unsigned long long */
#define iot_uint64_lower32(int64val)    ((uint32_t)((int64val) & 0xFFFFFFFF))

/* get higer 32bit value of an unsigned long long */
#define iot_uint64_higher32(int64val)   ((uint32_t)((int64val) >> 32))

#define iot_counter_inc(__cnt)          \
    do {                                \
        (__cnt)++;                      \
        if ((__cnt) == 0)               \
            (__cnt)--;                  \
    } while (0)

/**
 * @brief iot_mac_addr_cpy() - copy mac address
 * @param dst:  pointer to destination mac address
 * @param src:  pointer to source mac address
 */
static inline void iot_mac_addr_cpy(uint8_t* dst, uint8_t* src)
{
    os_mem_cpy(dst, src, IOT_MAC_ADDR_LEN);
}

/**
 * @brief iot_mac_addr_cmp() - mac address compare
 * @param dst:  pointer to first mac address to compare
 * @param src:  pointer to second mac address to compare
 *
 * @return      1 -- if mac address is the same
 * @return      0 -- otherwise
 */
static inline uint8_t iot_mac_addr_cmp(const uint8_t* dst, const uint8_t* src)
{
    return os_mem_cmp(dst, src, IOT_MAC_ADDR_LEN) == 0 ? 1 : 0;
}

/**
 * @brief iot_mac_is_bcast() - check if a mac is broadcast mac
 * @param dst:  the mac address to be checked
 *
 * @return      1 -- is broadcast mac
 * @return      0 -- NOT a broadcast mac
 */
static inline uint8_t iot_mac_is_bcast(const uint8_t* dst)
{
    return iot_mac_addr_cmp(dst, bcast_mac);
}

/**
 * @brief iot_set_bcast_mac() - set the dest mac as bcast addr
 * @param mac:  the dest mac to be filled with bcast addr
 */
static inline void iot_set_bcast_mac(uint8_t *mac)
{
    iot_mac_addr_cpy(mac, (uint8_t*)bcast_mac);
}

/**
 * @brief iot_mac_addr_reverse() - reverse the mac address sequence
 * @param addr:     pointer to mac address to be reversed
 */
static inline void iot_mac_addr_reverse(uint8_t* addr)
{
    uint8_t tmp;

    tmp = addr[0];
    addr[0] = addr[5];
    addr[5] = tmp;

    tmp = addr[1];
    addr[1] = addr[4];
    addr[4] = tmp;

    tmp = addr[2];
    addr[2] = addr[3];
    addr[3] = tmp;
}

/**
 * @brief iot_mac_addr_valid() - check if mac address is valid
 * @param addr:     pointer to mac address to be checked
 *
 * @return      1 -- if mac address is valid
 * @return      0 -- otherwise
 */
static inline uint8_t iot_mac_addr_valid(uint8_t* addr)
{
    if (!addr) {
        return 0;
    }

    return !!(addr[0] || addr[1] || addr[2] || addr[3] || addr[4] || addr[5]);
}

/* iot_bytes_to_uint32() - parse byte stream to get a uint32_t value
 * @data:       data stream
 *
 * return:
 *      the value from byte stream
 */
static inline uint32_t iot_bytes_to_uint32(uint8_t* data)
{
    uint32_t result = 0;
    result = data[0] + (data[1] << 8) + (data[2] << 16) + (data[3] << 24);
    return result;
}

/* iot_bytes_to_uint16() - parse byte stream to get a uint32_t value
 * @data:       data stream
 *
 * return:
 *      the value from byte stream
 */
static inline uint16_t iot_bytes_to_uint16(uint8_t* data)
{
    uint16_t result = 0;
    result = data[0] + (data[1] << 8);
    return result;
}

/* iot_uint32_to_bytes - convert uint32_t value to byte stream
 * @value:  the uint32_t value to be converted to byte stream
 * @data:   pointer to the buffer containing the output byte stream
 */
static inline void iot_uint32_to_bytes(uint32_t value, uint8_t *data)
{
    data[0] = value & 0xFF;
    data[1] = (value >> 8) & 0xFF;
    data[2] = (value >> 16) & 0xFF;
    data[3] = (value >> 24) & 0xFF;
}

/* iot_uint16_to_bytes - convert uint32_t value to byte stream
 * @value:  the uint16_t value to be converted to byte stream
 * @data:   pointer to the buffer containing the output byte stream
 */
static inline void iot_uint16_to_bytes(uint16_t value, uint8_t *data)
{
    data[0] = value & 0xFF;
    data[1] = (value >> 8) & 0xFF;
}

/* iot_bcd_to_byte - convert BCD code to byte
 * @value:   the BCD value to be converted to byte
 * @return:  the byte value
 */
static inline uint8_t iot_bcd_to_byte(uint8_t value)
{
    return (value >> 4) * 10 + (value & 0x0F);
}

/**
  * @}
  */

#endif /* IOT_UTILS_API_H */
