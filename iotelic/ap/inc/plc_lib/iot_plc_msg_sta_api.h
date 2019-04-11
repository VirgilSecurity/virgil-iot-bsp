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

#ifndef IOT_PLC_MSG_STA_API_H
#define IOT_PLC_MSG_STA_API_H

#include "os_types_api.h"
#include "iot_utils_api.h"
#include "iot_plc_msg_api.h"

/* pack for the structures in the whole file */
#pragma pack(push) // save the pack status
#pragma pack(1)    // 1 byte align

/* state of transformer detect operation */
#define IOT_PLC_TSFM_STATE_UNLOCK       (0)
#define IOT_PLC_TSFM_STATE_LOCK         (1)

/* STA role specific PLC message id definitions */
#define IOT_PLC_MSG_TSFM_CHANGE         (0xA3)
#define IOT_PLC_MSG_BEACON_DATA_RPT     (0xA4)

typedef struct _iot_plc_tsfm_change_req {
    /* the state of transformer detect, see IOT_PLC_TSFM_STATE_XXX */
    uint8_t state;
} iot_plc_tsfm_change_req_t;

/* IOT_PLC_MSG_BEACON_DATA_RPT format */
typedef struct _iot_plc_beacon_data_rpt {
    /* beacon data to be reported */
    uint8_t      data[IOT_PLC_BEACON_DATA_MAX];
} iot_plc_beacon_data_rpt_t;

#pragma pack(pop)  /* restore the pack status */

#endif /* IOT_PLC_MSG_STA_API_H */