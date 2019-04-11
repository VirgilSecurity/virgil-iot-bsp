/****************************************************************************

Copyright(c) 2016 - 2017 by IoTelic Technologies. ALL RIGHTS RESERVED.

This Information is proprietary to IoTelic Technologies and MAY NOT
be copied by any method or incorporated into another program without
the express written consent of Iotelic. This Information or any portion
thereof remains the property of Iotelic. The Information contained herein
is believed to be accurate and Iotelic assumes no responsibility or
liability for its use in any way and conveys no license or title under
any patent or copyright and makes no representation or warranty that this
Information is free from patent or copyright infringement.

****************************************************************************/

#ifndef IOT_FLASH_API_H
#define IOT_FLASH_API_H

#define DEV_SEEK_SET 0
#define DEV_SEEK_CUR 1
#define DEV_SEEK_END 2

/** \defgroup FLASH_APIs CUSTOM APIs
 *  @brief CUSTOM APIs
 *
 *
 */

/** @addtogroup FLASH_APIs
 *  @{
 *
 */

/**
 * @brief custom_dev_query_rw_size() - query custom flash part max size
 *
 * @return              the built-in flash size allocated for customer
 *                      application use
 *
 */
int32_t custom_dev_query_rw_size();

/**
 * @brief custom_dev_open() - open custom flash part
 *
 * @return              -1 -- open custom flash part failed
 * @return              other -- open custom flash part successfully
 *
 */
int32_t custom_dev_open();

/**
 * @brief custom_dev_close() - close custom flash part
 * @param fd:           custom flash part file pointer
 *
 * @return              -1 -- close custom flash part failed
 * @return              0 -- close custom flash part successfully
 *
 */
int32_t custom_dev_close(int32_t fd);

/**
 * @brief custom_dev_seek() - set the position indicator for the file pointed
 * @param fd:           custom flash part file pointer
 * @param offset:       the new position specified by fromwhere,
 *                      "offset" is below the built-in flash size
 * @param fromwhere:    it is set to DEV_SEEK_SET, DEV_SEEK, CUR DEV_SEEK_END,
 *                      and it means the start, the current, the end of part
 *
 * @return              -1 -- set custom flash part position failed
 * @return              other -- the new position set
 *
 */
int32_t custom_dev_seek(int32_t fd, uint32_t offset, uint8_t fromwhere);

/**
 * @brief custom_dev_read() - read custom flash part data
 * @param fd:           custom flash part file pointer
 * @param buf:          store the data at the location
 * @param count:        the size of data to read
 *                      "count" is below the built-in flash size
 *
 * @return              -1 -- read custom flash part data failed
 * @return              other -- return the read size
 *
 */
int32_t custom_dev_read(int32_t fd, void* buf, size_t count);

/**
 * @brief custom_dev_write() - write custom flash part data
 * @param fd:           custom flash part file pointer
 * @param buf:          the pointer of data to be written
 * @param count:        the size of data to be written
 *                      "count" is below the built-in flash size
 *
 * @return              -1 -- write custom flash part data failed
 * @return              other -- return the written size
 *
 */
int32_t custom_dev_write(int32_t fd, void*buf, size_t count);

#endif

/**
 * @}
 */
