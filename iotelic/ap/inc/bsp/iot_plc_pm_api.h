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
#ifndef IOT_PLC_PM_API_H
#define IOT_PLC_PM_API_H

#include "os_types_api.h"
#include "iot_config_api.h"

/* define the message send to callback */
#define IOT_PLC_PM_MSG_POWER_COLLAPSED        1

/* @brief the power listener callback function format
 * @param message power message to be sent to the callback,
 *        see IOT_PLC_PM_MSG_XXX
 */
typedef void (*iot_plc_pm_listener_func_t)(uint32_t message);

/* @brief register power listener callback function
 * @param exe_func:   the callback function for power message listening
 * @return
 *     ERR_FAIL  -- operation failed.
 *     ERR_INVAL -- operation invalid.
 *     ERR_OK    -- operation successful.
 */
uint32_t iot_plc_pm_register_listener(iot_plc_pm_listener_func_t exe_func);

#endif /* IOT_PLC_PM_API_H */

