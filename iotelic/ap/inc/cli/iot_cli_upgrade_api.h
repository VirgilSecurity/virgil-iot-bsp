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

#ifndef IOT_CLI_UPGRADE_API_H
#define IOT_CLI_UPGRADE_API_H

#include "os_types_api.h"
#include "iot_config_api.h"

#if PLC_SUPPORT_CCO_ROLE

/*
 * @brief iot_cli_sg_upgrade_completed_handler - upgrade completed handler
 */
typedef void(*iot_cli_sg_upgrade_completed_handler)();

/**
 * @brief iot_sg_upgrade_prepare - prepare for sg upgrade
 * @param handler:      completed handler
 * @param size:         size of upgrade file
 * @param data:         output para, data buffer pointer
 * @param sta_cnt:      count of sta in the network
 */
void iot_sg_upgrade_prepare(
    iot_cli_sg_upgrade_completed_handler handler,
    uint32_t size, uint8_t **data, uint16_t sta_cnt);

/**
 * @brief iot_sg_upgrade_start - sg upgrade start
 */
void iot_sg_upgrade_start();

/**
 * @brief iot_sg_upgrade_stop - sg upgrade stop
 */
void iot_sg_upgrade_stop();

#endif

#endif /* IOT_CLI_UPGRADE_API_H */
