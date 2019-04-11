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

#ifndef IOT_PLC_CCO_API_H
#define IOT_PLC_CCO_API_H

/* os shim includes */
#include "os_types_api.h"

/* common includes */
#include "iot_plc_api.h"
#include "iot_pkt_api.h"
#include "iot_plc_msg_cco_api.h"

/** \defgroup PLCLIB_APIs PLCLIB APIs
  * @brief WQ30x1 PLCLIB APIs
  */

/** @addtogroup PLCLIB_APIs
  * @{
  */

/** \defgroup PLC_CCO_APIs PLC CCO APIs
  * @brief CCO APIs
  *
  * APIs can be called only by CCO device
  */

/** @addtogroup PLC_CCO_APIs
  * @{
  */

/**
 * @brief iot_plc_lid_alloc_req() - request to allocate bandwidth for the
 *                          specified lid. the result will be notified through
 * @param handle:           plc application handler
 * @param lid:              the specified lid
 */
void iot_plc_lid_alloc_req(iot_plc_app_h handle, uint8_t lid);

/**
 * @brief iot_plc_lid_rel_req() - request to release bandwidth for the
 *                          specified lid.
 * @param handle:           plc application handler
 * @param lid:              the specified lid
 */
void iot_plc_lid_rel_req(iot_plc_app_h handle, uint8_t lid);

/**
 * @brief iot_plc_query_nw_topo() - Query the plc network topologic. the result
 *                       will be notified through iot_plc_recv_func_t callback.
 * @param handle:        plc application handler
 * @param req_id:        request id, the report data have a same request id,
 *                       see IOT_PLC_CCO_REQ_ID_XXX
 * @param req_data_ver:  request data type, see IOT_PLC_REQ_DATA_VER_XXX
 * @param start:         start tei of the query
 * @param cnt:           requested number of valid entries
 */
void iot_plc_query_nw_topo(iot_plc_app_h handle, uint8_t req_id,
    uint8_t req_data_ver, uint16_t start, uint16_t cnt);

/**
 * @brief iot_plc_set_nid() - set nid of current network will be
 *                          notified through iot_plc_recv_func_t callback.
 * @param handle:           plc application handler
 * @param new_ind:          new nid to be set to the network
 */
void iot_plc_set_nid(iot_plc_app_h handle, uint32_t new_nid);

/**
 * @brief iot_plc_query_whitelist() - query whitelist
 * @param start:            start index of whitelist entry
 * @param cnt:              count of entries to retrieve
 */
void iot_plc_query_whitelist(iot_plc_app_h handle, uint16_t start,uint16_t cnt);

/**
 * @brief iot_plc_query_blacklist() - query blacklist
 * @param start:            start index of blacklist entry
 * @param cnt:              count of entries to retrieve
 */
void iot_plc_query_blacklist(iot_plc_app_h handle, uint16_t start, uint16_t cnt);

/**
 * @brief iot_plc_set_whitelist() - set whitelist
 * @param handle:           plc application handler
 * @param action:           action of whitelist operation. available
 *                          value is IOT_PLC_WL_XXX
 * @param count:            number of mac address
 * @param mac_addry_array:  array of mac address
 */
void iot_plc_set_whitelist(iot_plc_app_h handle, uint8_t action, uint16_t count,
                           uint8_t * mac_addr_array);

/**
 * @brief iot_plc_set_blacklist() - set blacklist
 * @param handle:           plc application handler
 * @param action:           action of blacklist operation. available
 *                          value is IOT_PLC_WL_XXX
 * @param count:            number of mac address
 * @param mac_addry_array:  array of mac address
 */
void iot_plc_set_blacklist(iot_plc_app_h handle, uint8_t action, uint16_t count,
    uint8_t * mac_addr_array);

/**
 * @brief   iot_plc_set_freq_band() - set carrier communication frequency band
 *
 * @param         handle:     plc application handler
 * @param         freq_band: see PLC_LIB_FREQ_BAND_xxx
 */
void iot_plc_set_freq_band(iot_plc_app_h handle, uint8_t freq_band);

/**
 * @brief   set beacon data. beacon data can be broadcast to whole network in
 *          each beacon period.
 * @param   handle: plc application handler
 * @param   data:   data to be carried in each beacon
 * @param   len:    length of the data. must be qeual ro less than
 *                  IOT_PLC_BEACON_DATA_MAX
 *
 * @return  0 - requst sent to mac successfully
 *          otherwise - error code. see ERR_XXX
 */
uint32_t iot_plc_set_beacon_data(iot_plc_app_h handle, uint8_t *data,
    uint8_t len);

/**
  * @}
  */

#endif /* IOT_PLC_CCO_API_H */