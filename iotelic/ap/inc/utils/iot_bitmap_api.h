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

#ifndef IOT_BITMAP_API_H
#define IOT_BITMAP_API_H

/* os shim includes */
#include "os_types_api.h"
#include "os_mem_api.h"

/*@brief reset iot bitmap
 *@param bm:   pointer to the bitmap to be reset
 *@param size: size of the bitmap. unit is byte.
 */
static inline void iot_bitmap_reset(uint8_t *bm, uint8_t size)
{
    os_mem_set(bm, 0, size);
}

/*
 *@brief    find first bit set to 1 from the least significant bit
 *          of the bitmap.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *
 *@return
 *  0           --  no bit set to 1
 *  otherwise   --  the first bit set to 1.
 */
uint32_t iot_bitmap_ffs(uint8_t *bm, uint8_t size);

/*
 *@brief    find last bit set to 1 from the least significant bit
 *          of the bitmap.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *
 *@return
 *  0           --  no bit set to 1
 *  otherwise   --  the last bit set to 1.
 */
uint32_t iot_bitmap_fls(uint8_t *bm, uint8_t size);

/*
 *@brief    find first bit set to 1 from the least significant
 *          bit of the bitmap and clear it to 0.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *
 *@return
 *  0           --  no bit set to 0
 *  otherwise   --  the first bit set to 0.
 */
uint32_t iot_bitmap_ffs_and_c(uint8_t *bm, uint8_t size);

/*
 *@brief    find first bit set to 1 from the dedicated start point of
 *          the bitmap.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *@param sp:    start point
 *
 *@return
 *  0           --  no bit set to 1
 *  otherwise   --  the first bit set to 1
 */
uint32_t iot_bitmap_ffs_from(uint8_t *bm, uint8_t size, uint32_t sp);

/*
 *@brief    find first bit set to 0 from the least significant bit
 *          of the bitmap.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *
 *@return
 *  0           --  no bit set to 0
 *  otherwise   --  the first bit set to 0.
 */
uint32_t iot_bitmap_ffz(uint8_t *bm, uint8_t size);

/*
 *@brief    find first bit set to 0 from the dedicated start point of
 *          the bitmap.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *@param sp:    start point
 *
 *@return
 *  0           --  no bit set to 0
 *  otherwise   --  the first bit set to 0
 */
uint32_t iot_bitmap_ffz_from(uint8_t *bm, uint8_t size, uint32_t sp);

/*
 *@brief    find first bit set to 0 from the least significant
 *          bit of the bitmap and set it to 1.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *
 *@return
 *  0           --  no bit set to 0
 *  otherwise   --  the first bit set to 0.
 */
uint32_t iot_bitmap_ffz_and_s(uint8_t *bm, uint8_t size);

/*
 *@brief    set one bit of the bitmap
 *@param bm:    bitmap to be set
 *@param size:  size of the bitmap. unit is byte.
 *@param bit:   the bit number to be set. the least signification bit mapping
 *              to 1.
 */
void iot_bitmap_set(uint8_t *bm, uint8_t size, uint32_t bit);

/*
 *@brief    check if one bit of the bitmap is set
 *@param bm:    bitmap to be set
 *@param size:  size of the bitmap. unit is byte.
 *@param bit:   the bit number to be checked. the least signification bit
 *              mapping to 1.
 *
 *@return
 *  false   --  the bit is not set to 1
 *  true    --  the bit is set to 1
 */
bool_t iot_bitmap_is_set(uint8_t *bm, uint8_t size, uint32_t bit);

/*
 *@brief    clear one bit of the bitmap
 *@param bm:    bitmap to be cleared
 *@param size:  size of the bitmap. unit is byte.
 *@param bit:   the bit number to be cleared. the least signification bit
 *              mapping to 1.
 */
void iot_bitmap_clear(uint8_t *bm, uint8_t size, uint32_t bit);

/*
 *@brief    count number of bits set to 1 of the bitmap.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *
 *@return   number of bits set to 1 in the bitmap
 */
uint32_t iot_bitmap_cbs(uint8_t *bm, uint8_t size);

/*
 *@brief    count number of bits set to 0 of the bitmap.
 *@param bm:    bitmap to be checked
 *@param size:  size of the bitmap. unit is byte.
 *
 *@return   number of bits set to 0 in the bitmap
 */
uint32_t iot_bitmap_cbz(uint8_t *bm, uint8_t size);

#endif /* IOT_BITMAP_API_H */
