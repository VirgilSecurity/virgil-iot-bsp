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

#ifndef IOT_APP_API_H
#define IOT_APP_API_H

#include "iot_plc_api.h"
#include "iot_errno_api.h"

/** \defgroup APP_APIs APP APIs
  * @brief WQ30x1 APP APIs
  *
  * APIs for customer application(s) to register their entry main function.
  * MAX 3 customer appliccations can be added
  */

/** @addtogroup APP_APIs
  * @{
  */

typedef enum {
    IOT_PLC_APP_SMART_GRID = IOT_PLC_APP_ID_MIN,
    IOT_PLC_IP_ID,
    IOT_PLC_APP_HOST_INTERFACE,
    IOT_PING_APP_ID,
    IOT_PLCUART_APP_ID,
    IOT_PLC_APP_DEMO_ID,
    IOT_GR_APP_ID,
    IOT_PLC_APP_MAX = IOT_GR_APP_ID
} iot_app_id_t;

/**
 * @brief iot_plc_entry() - entry point to bring up the whole plc stack.
 * after whole plc stack is up, app entries will be called in the sequence
 * they are added. Note that this function returns nonzero for a failed case,
 * and doesn't return any value for a successful case.
 *
 * @return nonzero -- OS boot failur, mostly cfg not right
 */
uint32_t iot_plc_entry();

/**
 * @brief (*iot_app_entry_func_t)() - declaration for app entry method.
 *
 * @return ERR_PENDING -- if application want to delay the plc network formation.
 *         otherwise -- plc network formation will be started automatically.
 */
typedef uint32_t (*iot_app_entry_func_t)();

/**
 * @brief iot_app_add_entry() - add app entry. the app entry will be called
 * after the whole plc stack is up. customer can create their own task in
 * app entry function.
 * @param entry:                 app entry method to be added
 *
 * @return   0 -- for success case
 * @return   otherwise -- for failure case
 */
uint32_t iot_app_add_entry(iot_app_entry_func_t entry);

/**
  * @}
  */

#endif /* IOT_APP_API_H */