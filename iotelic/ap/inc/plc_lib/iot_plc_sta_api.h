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

#ifndef IOT_PLC_STA_API_H
#define IOT_PLC_STA_API_H

#include "os_types_api.h"
#include "iot_plc_api.h"
#include "iot_pkt_api.h"
#include "iot_plc_msg_sta_api.h"

/**
 * @brief iot_plc_tsfm_state_lock() - change the state of transformer detect.
 *
 * @param  handle:     plc application handler.
 * @param  status:     the status of transformer detect, see
 *                     IOT_PLC_MSG_TSFM_XXX.
 */
void iot_plc_tsfm_state_change(iot_plc_app_h handle, uint8_t status);

/**
 * @brief iot_plc_tsfm_state_lock() - lock the state of transformer detect.
 *
 * @param  handle:     plc application handler
 */
#define iot_plc_tsfm_state_lock(handle) iot_plc_tsfm_state_change(handle, \
    IOT_PLC_TSFM_STATE_LOCK)

/**
 * @brief iot_plc_tsfm_state_unlock() - unlock the state of transformer detect.
 *
 * @param  handle:     plc application handler
 */
#define iot_plc_tsfm_state_unlock(handle) iot_plc_tsfm_state_change(handle, \
    IOT_PLC_TSFM_STATE_UNLOCK)

#endif /* IOT_PLC_STA_API_H */
