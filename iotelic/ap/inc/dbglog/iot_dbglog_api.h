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
#ifndef IOT_DBGLOG_API_H
#define IOT_DBGLOG_API_H

#include "iot_dbglog_parser_api.h"

/** \defgroup DBGLOG_APIs DEBUGLOG APIs
  * @brief WQ30x1 DEBUGLOG APIs
  *
  * APIs to control, ouput debug messages through vairous physical interfaces.
  * case1: cco/sta output by local uart port.
  * case2: sta deliver through powerline to cco,and cco help to print with
  * uart to host
  *
  * TODO: need add API to config output level, and output physcial interface.
  */

/** @addtogroup DBGLOG_APIs
  * @{
  */

typedef enum {
    DBGLOG_VERBOSE = 1,
    DBGLOG_INFO,
    DBGLOG_INFO_LVL_1,
    DBGLOG_INFO_LVL_2,
    DBGLOG_WARN,
    DBGLOG_ERR,
    DBGLOG_LVL_MAX
} DBGLOG_LOG_LVL;

/**
 * @brief iot_dbglog_input() - input debug log
 * @param mod_id:              module id
 * @param log_lvl:             log level
 * @param msg_id:              messgage id
 * @param arg_cnt:             arg count
 *
 * @return 0 -- for success case
 * @return ERR_INVAL -- for failure case
 */
int32_t iot_dbglog_input(uint16_t mod_id,
    uint8_t log_lvl, uint16_t msg_id, uint8_t arg_cnt, ...);

/**
* @brief iot_crash_dbglog_input() - input crash debug log, will write to flash
* directly
* @param mod_id:              module id
* @param msg_id:              messgage id
* @param buffer:              raw log
* @param buffer_len:          log len
*/
void iot_crash_dbglog_input(uint16_t mod_id, uint16_t msg_id,
    uint8_t* data, uint32_t datalen);

/**
* @brief iot_dbglog_config_module_level() - config module log level water marker
* log level smaller than this will not be reported
* @param mod_id:              module id
* @param log_lvl:             log level water marker
*
* @return 0 -- for success case
* @return ERR_INVAL -- for failure case
*/
uint32_t iot_dbglog_config_module_level(uint16_t mod_id, uint8_t level);

/**
* @brief iot_dbglog_config_level() - config overall log level water marker;
* log level smaller than this will not be reported
* @param log_lvl:             log level water marker
*
* @return 0 -- for success case
* @return ERR_INVAL -- for failure case
*/
uint32_t iot_dbglog_config_level(uint8_t level);
#endif // !IOT_DBGLOG_API_H