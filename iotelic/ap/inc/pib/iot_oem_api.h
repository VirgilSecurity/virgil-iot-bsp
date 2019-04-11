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

#ifndef IOT_OEM_API_H
#define IOT_OEM_API_H

/* os shim includes */
#include "os_types_api.h"

/* common includes */
#include "iot_utils_api.h"

/* pack for the structures in the whole file */
#pragma pack(push)  // save the pack status
#pragma pack(1)     // 1 byte align

#define MODULE_TYPE_STA               0
#define MODULE_TYPE_CCO               1
#define MODULE_TYPE_COLLECTOR_II      2
#define MODULE_TYPE_STA_TEST          3
#define MODULE_TYPE_MAX_NUM           MODULE_TYPE_STA_TEST

#define IOT_OEM_BASE_DUMMY_LEN        32

typedef struct _iot_oem_base_cfg {
    uint8_t  oem_crc;
    uint8_t  oem_valid;
    uint8_t  module_mac[IOT_MAC_ADDR_LEN];
    uint32_t module_type;
    uint8_t  base_dummy[IOT_OEM_BASE_DUMMY_LEN];
} iot_oem_base_cfg_t;

/**
* @brief iot_oem_get_cfg() - read oem cfg from flash oem info section.
* @param oemcfg: pointer to receive oem cfg
* @retval 0 success; others fail
*/
uint32_t iot_oem_get_base_cfg(iot_oem_base_cfg_t** oemcfg);

/**
 * @brief iot_oem_get_module_mac() - read local mac from flash oem info section.
 * @params mac: pointer to the buffer for mac addr
 * @retval 0 success; others fail
 */
uint32_t iot_oem_get_module_mac(uint8_t *mac);

/**
* @brief iot_oem_get_vendor_id() - read vendor id from flash oem info section.
* @param null
* @retval vendor id success; 0 fail
*/
uint16_t iot_oem_get_vendor_id();

#pragma pack(pop)   // restore the pack status

#endif /* IOT_OEM_API_H */
