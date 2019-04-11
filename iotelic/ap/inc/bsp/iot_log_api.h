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

#ifndef _IOT_LOG_API_H
#define _IOT_LOG_API_H

/** \defgroup FLASH_APIs LOG APIs
 *  @brief LOG APIs
 *
 *
 */

/** @addtogroup LOG_APIs
 *  @{
 *
 */

/**
 * @brief iot_log_dev_query_rw_size() - query log flash part max size
 *
 * @return              the built-in flash size allocated for loger
 *                      application use
 *
 */
int32_t iot_log_dev_query_rw_size(uint8_t fd);

/**
 * @brief iot_log_dev_open() - open log flash part
 *
 * @return              -1 -- open log flash part failed
 * @return              other -- open log flash part successfully
 *
 */
int32_t iot_log_dev_open();

/**
 * @brief iot_log_dev_close() - close log flash part
 * @param fd:           log flash part file pointer
 *
 * @return              -1 -- close log flash part failed
 * @return              0 -- close log flash part successfully
 *
 */
int32_t iot_log_dev_close(int32_t fd);

/**
 * @brief iot_log_dev_seek() - set the position indicator for the file pointed
 * @param fd:           log flash part file pointer
 * @param offset:       the new position specified by fromwhere,
 *                      "offset" is below the built-in flash size
 * @param fromwhere:    it is set to DEV_SEEK_SET, DEV_SEEK, CUR DEV_SEEK_END,
 *                      and it means the start, the current, the end of part
 *
 * @return              -1 -- set log flash part position failed
 * @return              other -- the new position set
 *
 */
int32_t iot_log_dev_seek(int32_t fd, uint32_t offset, uint8_t fromwhere);

/**
 * @brief iot_log_dev_read() - read log flash part data
 * @param fd:           log flash part file pointer
 * @param buf:          store the data at the location
 * @param count:        the size of data to read
 *                      "count" is below the built-in flash size
 *
 * @return              -1 -- read log flash part data failed
 * @return              other -- return the read size
 *
 */
int32_t iot_log_dev_read(int32_t fd, void* buf, size_t count);

/**
 * @brief iot_log_dev_write() - write log flash part data
 * @param fd:           log flash part file pointer
 * @param buf:          the pointer of data to be written
 * @param count:        the size of data to be written
 *                      "count" is below the built-in flash size
 *
 * @return              -1 -- write log flash part data failed
 * @return              other -- return the written size
 *
 */
int32_t iot_log_dev_write(int32_t fd, void*buf, size_t count);


/**
 * @brief iot_log_get_flow_direction() - get log flow direction
 * @param direction:    the flow direction value will be saved in this pointer
 *
 * @return              -1 -- get log flow direction data failed
 * @return              0 -- return the written size
 *
 */
int32_t iot_log_get_flow_direction(uint8_t *direction);

/**
 * @brief iot_log_get_mem_pos() - get flash memory position informations
 * @param index:        current log position
 *
 * @return              -1 -- get flash log informations failed
 * @return              0 -- return the written size
 *
 */
int32_t iot_log_get_mem_pos(uint32_t *pos);

/**
 * @brief iot_log_dev_init() - initial flash log variable
 *
 * @return              -1 -- initial flash log failed
 * @return              0 -- initial flash log successful
 *
 */
int32_t iot_log_dev_init();

/**
 * @brief iot_log_get_save_freq() - get the frequency of saving log
 *
 * @return              the frequency of saving log
 *
 */
int32_t iot_log_get_save_freq();

/**
 * @}
 */

#endif // _IOT_LOG_API_H

