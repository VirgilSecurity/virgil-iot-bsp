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

#ifndef IOT_PLC_MSG_CCO_API_H
#define IOT_PLC_MSG_CCO_API_H

#include "os_types_api.h"
#include "iot_utils_api.h"
#include "iot_plc_msg_api.h"

/* pack for the structures in the whole file */
#pragma pack(push)  // save the pack status
#pragma pack(1)     // 1 byte align

/* CCO role specific PLC message id definitions */
#define IOT_PLC_MSG_LID_REQ                 0x05
#define IOT_PLC_MSG_LID_CONF                0x06
#define IOT_PLC_MSG_LID_REL                 0x07

#define IOT_PLC_MSG_NW_TOPO_QUERY           0x80
#define IOT_PLC_MSG_NW_TOPO_RPT             0x81

#define IOT_PLC_MSG_FREQ_BAND_SET           0x8E
#define IOT_PLC_MSG_FREQ_BAND_SET_RPT       0x8F

#define IOT_PLC_MSG_NW_ID_SET               0x92
#define IOT_PLC_MSG_NW_ID_SET_RPT           0x93
#define IOT_PLC_MSG_STA_JOIN_INFO           0x94
#define IOT_PLC_MSG_STA_LEAVE_INFO          0x95

#define IOT_PLC_MSG_BEACON_DATA_SET         0xA5
#define IOT_PLC_MSG_BEACON_DATA_SET_RPT     0xA6

/* default request id */
#define IOT_PLC_CCO_REQ_ID_DEFAULT          (0)

/* request data version */
#define IOT_PLC_CCO_TOPO_REQ_DATA_VER_V0    (0)
#define IOT_PLC_CCO_TOPO_REQ_DATA_VER_V1    (1)

/* query topo data error code */
#define IOT_PLC_CCO_TOPO_QR_OK              (0) /* query ok */
#define IOT_PLC_CCO_TOPO_QR_API_NO_SUPP     (1) /* API don't support */
#define IOT_PLC_CCO_TOPO_QR_VER_NO_SUPP     (2) /* node version don't support */

#define IOT_PLC_MANAGE_ID_LEN               (24)

/* IOT_PLC_MSG_LID_REQ format */
typedef struct _iot_plc_lid_alloc_req {
    /* application layer lid applying for */
    uint8_t     lid;
} iot_plc_lid_alloc_req_t;

/* IOT_PLC_MSG_LID_CONF format */
typedef struct _iot_plc_lid_alloc_conf {
    /* result of the request */
    uint8_t     result;
    /* application layer lid */
    uint8_t     lid;
} iot_plc_lid_alloc_conf_t;

/* IOT_PLC_MSG_LID_REL format */
typedef struct _iot_plc_lid_release_req {
    /* application layer lid to release */
    uint8_t     lid;
} iot_plc_lid_release_req_t;

/* IOT_PLC_MSG_NW_TOPO_QUERY format */
typedef struct _iot_plc_nw_topo_query {
    /* start tei of the query */
    uint16_t    start;
    /* requested number of valid entries */
    uint16_t    count;
    /* request data version, IOT_PLC_CCO_TOPO_REQ_DATA_VER_XXX */
    uint8_t     version;
} iot_plc_nw_topo_query_t;

/* plc node info format v0 */
typedef struct _iot_plc_node_info_v0 {
    /* tei of the station */
    uint16_t            sta_tei;
    /* tei of the proxy */
    uint16_t            proxy_tei;
    /* level of the station */
    uint8_t             level;
    /* role of the station */
    uint8_t             role;
    /* uplink traffic success ratio */
    uint8_t             ul_tf_sr;
    /* downlink traffic success ratio */
    uint8_t             dl_tf_sr;
    /* rx snr from the node to local device */
    int8_t              snr;
    /* mac address of the station */
    uint8_t             addr[IOT_MAC_ADDR_LEN];
    /* device type. See  PLC_DEV_TYPE_XXX */
    uint8_t             dev_type;
    /* logical phase of the station */
    uint8_t             logic_phase1    :2,
                        logic_phase2    :2,
                        logic_phase3    :2,
                        reserved_1      :2;
    /* physical phase of the station */
    uint8_t             phy_phase1      :2,
                        phy_phase2      :2,
                        phy_phase3      :2,
                        reserved_2      :2;
    /* last boot up reason of the node */
    uint8_t             boot_reason;
    /* build version of the node */
    uint16_t            build_ver;
    /* software version of the node */
    uint16_t            sw_ver;
    /* vendor of the node */
    uint16_t            vendor;
    /* how many times received valid assoc request from the node since join
     * the network.
     */
    uint16_t            assoc_rx_cnt;
    /* how many times the node change proxy accepted since join the network */
    uint16_t            proxy_chg_accept_cnt;
    /* how many times received valid proxy change request from the node
     * since join the network.
     */
    uint32_t            proxy_chg_rx_cnt;
    /* how much time the node have been in the network, unit is 1s */
    uint32_t            in_network_time;
    /* how much time since last assoc request, unit is 1s */
    uint32_t            last_assoc_rx_time;
    /* how much time since last proxy change, unit is 1s */
    uint32_t            last_proxy_chg_time;
    /* how much time since last seen this device, unit is 1s */
    uint32_t            inactive_time;
} iot_plc_node_info_v0_t;

typedef struct _iot_plc_node_info_v1 {
    /* tei of the station */
    uint16_t            sta_tei;
    /* tei of the proxy */
    uint16_t            proxy_tei;
    /* level of the station */
    uint8_t             level;
    /* role of the station */
    uint8_t             role;
    /* uplink traffic success ratio */
    uint8_t             ul_tf_sr;
    /* downlink traffic success ratio */
    uint8_t             dl_tf_sr;
    /* rx snr from the node to local device */
    int8_t              snr;
    /* mac address of the station */
    uint8_t             addr[IOT_MAC_ADDR_LEN];
    /* device type. See  PLC_DEV_TYPE_XXX */
    uint8_t             dev_type;
    /* logical phase of the station */
    uint8_t             logic_phase1    :2,
                        logic_phase2    :2,
                        logic_phase3    :2,
                        reserved_1      :2;
    /* physical phase of the station */
    uint8_t             phy_phase1      :2,
                        phy_phase2      :2,
                        phy_phase3      :2,
                        reserved_2      :2;
    /* boot version */
    uint8_t             boot_ver;
    /* software version of the node */
    uint16_t            sw_ver;
    /* module vendor ID */
    uint16_t            vendor;
    /* chip id information of the node */
    uint8_t             chip_id[IOT_PLC_MANAGE_ID_LEN];
} iot_plc_node_info_v1_t;

/* IOT_PLC_MSG_NW_TOPO_RPT format */
typedef struct _iot_plc_nw_topo_rpt {
    /* total number of valid tei */
    uint16_t            total_count;
    /* number of valid tei in current message */
    uint16_t            count;
    /* report data version, see IOT_PLC_CCO_REQ_TOPO_DATA_VER_XXX  */
    uint8_t             version;
    /* report done */
    uint8_t             done        :1,
    /* error code, see IOT_PLC_CCO_QR_TOPO_DATA_XXX */
                        err_code    :2,
    /* reserved for future */
                        reserved    :5;
    /* node info of each valid tei, see iot_plc_node_info_xxx_t */
    uint8_t             data[0];
} iot_plc_nw_topo_rpt_t;

/* IOT_PLC_MSG_NW_ID_SET format */
typedef struct _iot_plc_set_nid_req {
    /* new nid to be set.
     * nid takes 3 byte according to SG spec */
    uint32_t             nid;
} iot_plc_set_nid_req_t;

/* IOT_PLC_MSG_NW_WL_SET_RPT format */
typedef struct _iot_plc_nw_id_set_rpt {
    /* result of the nid set request */
    uint8_t             result;
    /* error number */
    uint8_t             err_no;
} iot_plc_nw_id_set_rpt_t;

/* IOT_PLC_MSG_STA_JOIN_INFO format
 * CCo reports this message when a STA join in a network
 */
typedef struct _iot_plc_sta_join_info {
    /* total node count of this network */
    uint16_t               total_node_count;
    /* info of STA */
    iot_plc_node_info_v0_t sta_info;
} iot_plc_sta_join_info_t;

typedef struct _iot_plc_sta_info {
    /* tei of the station */
    uint16_t                tei;
    /* tei of the proxy */
    uint16_t                proxy;
    /* mac address of the device */
    uint8_t                 mac_addr[IOT_MAC_ADDR_LEN];
} iot_plc_sta_info_t;

/* IOT_PLC_MSG_STA_LEAVE_INFO format
 * CCo reports this message when a STA disassociated from network
 */
typedef struct _iot_plc_sta_leave_info {
    /* left node count of this network */
    uint16_t           total_node_count;
    /* number of STAs leaveing the network */
    uint8_t            sta_count;
    /* info of STAs */
    iot_plc_sta_info_t sta[0];
} iot_plc_sta_leave_info_t;

/* IOT_PLC_MSG_FREQ_BAND_SET format */
typedef struct _iot_plc_freq_band_set {
    /* frequency band */
    uint8_t      freq_band;
} iot_plc_freq_band_set_t;

/* IOT_PLC_MSG_FREQ_BAND_SET_RPT format */
typedef struct _iot_plc_freq_band_set_rpt {
    /* result of the freq band set request */
    uint8_t             result;
    /* error number */
    uint8_t             err_no;
} iot_plc_freq_band_set_rpt_t;

/* IOT_PLC_MSG_BEACON_DATA_SET format */
typedef struct _iot_plc_beacon_data_set {
    /* beacon data to be set */
    uint8_t      data[IOT_PLC_BEACON_DATA_MAX];
} iot_plc_beacon_data_set_t;

/* IOT_PLC_MSG_BEACON_DATA_SET_RPT format */
typedef struct _iot_plc_beacon_data_set_rpt {
    /* result of the beacon data set request */
    uint8_t             result;
    /* error number */
    uint8_t             err_no;
} iot_plc_beacon_data_set_rpt_t;

#pragma pack(pop)  /* restore the pack status */

#endif /* IOT_PLC_MSG_CCO_API_H */