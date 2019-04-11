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

#ifndef IOT_PLC_MSG_API_H
#define IOT_PLC_MSG_API_H

#include "os_types_api.h"
#include "iot_utils_api.h"


/* pack for the structures in the whole file */
#pragma pack(push)  // save the pack status
#pragma pack(1)     // 1 byte align

/* app request succeed */
#define IOT_PLC_SUCCESS                     (0x0)
/* app request succeed, but assigned value is not the same as registered.
 * cvg layer allocated resource according to its status.
 */
#define IOT_PLC_SUCCESS_MODIFIED            (0x1)
/* app request failed */
#define IOT_PLC_FAILED                      (0x2)

/* PLC device role. this definition must be same as PLC_DEV_ROLE_XXX */
#define IOT_PLC_DEV_ROLE_INVALID            (0x0)
#define IOT_PLC_DEV_ROLE_STA                (0x1)
#define IOT_PLC_DEV_ROLE_PCO                (0x2)
#define IOT_PLC_DEV_ROLE_CCO                (0x4)

/* PLC device type. this definition must be same as PLC_DEV_TYPE_XXX */
#define IOT_PLC_DEV_TYPE_METER_CONTROLLER   1
#define IOT_PLC_DEV_TYPE_CONCENTRATOR       2
#define IOT_PLC_DEV_TYPE_POWER_METER        3
#define IOT_PLC_DEV_TYPE_REPEATER           4
#define IOT_PLC_DEV_TYPE_COLLECTOR_2        5
#define IOT_PLC_DEV_TYPE_COLLECTOR_1        6
/* iot customer device type start at 0x80 */
#define IOT_PLC_DEV_TYPE_GL_STA             0x80
#define IOT_PLC_DEV_TYPE_INVAL              0xFF

/* whitelist and blacklist operation */
#define IOT_PLC_WL_DISABLE                  (0x0)
#define IOT_PLC_WL_ADD                      (0x1)
#define IOT_PLC_WL_DEL                      (0x2)
#define IOT_PLC_WL_ENABLE                   (0x3)
#define IOT_PLC_BL_DISABLE                  (0x4)
#define IOT_PLC_BL_ADD                      (0x5)
#define IOT_PLC_BL_DEL                      (0x6)
#define IOT_PLC_BL_ENABLE                   (0x7)

/* common PLC message id definitions shared between CCO and STA device */
#define IOT_PLC_MSG_MSDU_SEND               0x01
#define IOT_PLC_MSG_MSDU_RECV               0x02
#define IOT_PLC_MSG_APP_REG_REQ             0x03
#define IOT_PLC_MSG_APP_REG_CONF            0x04

#define IOT_PLC_MSG_NW_ID_QUERY             0x82
#define IOT_PLC_MSG_NW_ID_RPT               0x83
#define IOT_PLC_MSG_NW_NEIGHBOR_QUERY       0x84
#define IOT_PLC_MSG_NW_NEIGHBOR_RPT         0x85
#define IOT_PLC_MSG_NW_WL_QUERY             0x86
#define IOT_PLC_MSG_NW_WL_RPT               0x87
#define IOT_PLC_MSG_NW_WL_SET               0x88
#define IOT_PLC_MSG_NW_WL_SET_RPT           0x89
#define IOT_PLC_MSG_NW_BL_QUERY             0x8A
#define IOT_PLC_MSG_NW_BL_RPT               0x8B
#define IOT_PLC_MSG_NW_BL_SET               0x8C
#define IOT_PLC_MSG_NW_BL_SET_RPT           0x8D

#define IOT_PLC_MSG_DEV_INFO_QUERY          0x90
#define IOT_PLC_MSG_DEV_INFO_RPT            0x91

#define IOT_PLC_MSG_DEV_STATE_CHANGE_RPT    0x96
#define IOT_PLC_MSG_CFG_SET_REQ             0x97
#define IOT_PLC_MSG_CFG_SET_CONF            0x98
#define IOT_PLC_MSG_START_NW_FMT            0X99
#define IOT_PLC_MSG_BAND_INFO_QUERY         0x9A
#define IOT_PLC_MSG_BAND_INFO_QUERY_RPT     0x9B
#define IOT_PLC_MSG_WDG_SET_REQ             0x9C
#define IOT_PLC_MSG_WDG_SET_CONF            0x9D
#define IOT_PLC_MSG_NEIGHBOR_DEV_QUERY      0x9E
#define IOT_PLC_MSG_NEIGHBOR_DEV_RPT        0x9F
#define IOT_PLC_MSG_INVALID_MAC_RPT         0xA0
#define IOT_PLC_MSG_TEI_ADDR_INFO_QUERY     0xA1
#define IOT_PLC_MSG_TEI_ADDR_INFO_RPT       0xA2

#define IOT_PLC_MSG_TX_POWER_CAP_SET        0xA7
#define IOT_PLC_MSG_TX_POWER_CAP_SET_RPT    0xA8
#define IOT_PLC_MSG_TX_POWER_CAP_QUERY      0xA9
#define IOT_PLC_MSG_TX_POWER_CAP_QUERY_RPT  0xAA

/* broadcast message to all app */
#define IOT_PLC_APP_ID_BCAST                47

/* packet send type */
#define IOT_PLC_MSG_TYPE_INVALID            0x00
/* unicast packet */
#define IOT_PLC_MSG_TYPE_UNICAST            0x01
/* unicast packet to pco */
#define IOT_PLC_MSG_TYPE_UNICAST_TO_PCO     0x02
/* proxy broadcast */
#define IOT_PLC_MSG_TYPE_BCAST              0x03
/* local broadcast */
#define IOT_PLC_MSG_TYPE_BCAST_1HOP         0x04
/* local broadcast even in power collapsed status */
#define IOT_PLC_MSG_TYPE_BCAST_1HOP_PW_OFF  0x05

/* packet ack type */
#define IOT_PLC_ACK_TYPE_NONE               0x00
/* require the worst neighbor to ack */
#define IOT_PLC_ACK_TYPE_WORST              0x01

/* define reason that the MAC address is invalid */
#define IOT_PLC_INVD_MAC_NOT_IN_WHITELIST   0x01
#define IOT_PLC_INVD_MAC_IN_BLACKLIST       0x02

/* define beacon data maximum length */
#define IOT_PLC_BEACON_DATA_MAX             14

/* frequency band value: 1.953~11.96Mhz */
#define PLC_LIB_FREQ_BAND_0                 0
/* frequency band value: 2.441~5.615Mhz */
#define PLC_LIB_FREQ_BAND_1                 1
/* frequency band value: 0.781~2.930Mhz */
#define PLC_LIB_FREQ_BAND_2                 2
/* frequency band value: 1.758~2.930Mhz */
#define PLC_LIB_FREQ_BAND_3                 3

/* plc message header */
typedef struct _iot_plc_msg_header {
    /* application id */
    uint8_t     app_id;
    /* msg id */
    uint8_t     msg_id;
    /* request id */
    uint8_t     req_id;
    /* reserved for future */
    uint8_t    reserved;
} iot_plc_msg_header_t;

/* IOT_PLC_MSG_MSDU_SEND format */
typedef struct _iot_plc_msdu_send {
    /* type of the message. see IOT_PLC_MSG_TYPE_XXX */
    uint8_t     msg_type    :5,
    /* type of the ack required for this packet from the listener. see
     * IOT_PLC_ACK_TYPE_XXX this flag is only available for broadcast packet.
     */
                ack_type    :3;
    /* retry count */
    uint8_t     retry_cnt;
    /* payload length */
    uint16_t    len;
    /* final destion mac address */
    uint8_t     dst[IOT_MAC_ADDR_LEN];
    /* original source mac address */
    uint8_t     src[IOT_MAC_ADDR_LEN];
    /* msdu type */
    uint8_t     type;
    /* link id */
    uint8_t     lid;
    /* msdu data payload */
    uint8_t     data[0];
} iot_plc_msdu_send_t;

/* IOT_PLC_MSG_MSDU_RECV format */
typedef struct _iot_plc_msdu_recv {
    /* payload length */
    uint16_t    len;
    /* final destion mac address */
    uint8_t     dst[IOT_MAC_ADDR_LEN];
    /* original source mac address */
    uint8_t     src[IOT_MAC_ADDR_LEN];
    /* msdu data payload */
    uint8_t     data[0];
} iot_plc_msdu_recv_t;

/* IOT_PLC_MSG_APP_REG_REQ format */
typedef struct _iot_plc_app_reg_req {
    /* requested msdu type */
    uint8_t     type;
    /* requested default priority for the msdu */
    uint8_t     prio;
} iot_plc_app_reg_req_t;

/* IOT_PLC_MSG_APP_REG_CONF format */
typedef struct _iot_plc_app_reg_conf {
    /* result of the request */
    uint8_t     result;
    /* approved msdu type */
    uint8_t     type;
    /* approved default priority for the msdu */
    uint8_t     prio;
} iot_plc_app_reg_conf_t;

/* IOT_PLC_MSG_DEV_INFO_RPT format */
typedef struct _iot_plc_dev_info_rpt {
    /* role of local device. see IOT_PLC_DEV_ROLE_XXX */
    uint8_t             dev_role;
    /* type of local device. see IOT_PLC_DEV_TYPE_XXX */
    uint8_t             dev_type;
    /* if lower layer is ready to serve app.
     * if is_ready is 0, app shall not call api
     * except iot_plc_query_dev_info.
     */
    uint8_t             is_ready;
    /* software reset count */
    uint16_t            hw_reset_cnt;
    /* hardware reset connt */
    uint16_t            sw_reset_cnt;
    /* mac address of local device */
    uint8_t             local_mac[IOT_MAC_ADDR_LEN];
    /* mac address of CCo */
    uint8_t             cco_mac[IOT_MAC_ADDR_LEN];
} iot_plc_dev_info_rpt_t;

/* IOT_PLC_MSG_DEV_STATE_CHANGE_RPT format */
typedef struct _iot_plc_dev_state_change_rpt {
    /* role of local device */
    uint8_t             dev_role;
    /* if lower layer is ready to serve app.
     * if is_ready is 0, app shall not call api
     * except iot_plc_query_dev_info.
     */
    uint8_t             is_ready           :1,
    /* flag to mark if cert test command ever detected */
                        cert_test_detected :1,
    /* reserved for further use */
                        rsvd               :6;
    /* tei of the device */
    uint16_t            dev_tei;
    /* mac address of local device */
    uint8_t             local_mac[IOT_MAC_ADDR_LEN];
    /* mac address of CCo */
    uint8_t             cco_mac[IOT_MAC_ADDR_LEN];
    /* local nid */
    uint32_t            nid;
} iot_plc_dev_state_change_rpt_t;

/* IOT_PLC_MSG_NW_ID_RPT format */
typedef struct _iot_plc_nid_rpt {
    /* nid of current network.
     * nid takes 3 byte according to SG spec
     */
    uint32_t            nid;
} iot_plc_nid_rpt_t;

/* neighbour network information */
typedef struct _iot_plc_nb_nw_info {
    /* nid of the neighbour network */
    uint32_t    nid             :24,
    /* flag indicate if neighbour network is single-pass to local network
     * 1 means single-pass. 0 means double-pass.
     */
                sp_flag         :1,
    /* flag to mark if beacon data is available */
                bc_data_flag    :1,
    /* flag to mark if cco address is available */
                addr_flag       :1,
    /* reserved for future */
                rvsd            :5;
    /* bandwidth taken by neighbour network in millisecond */
    uint32_t    bandwidth;
    /* cco mac address */
    uint8_t     addr[IOT_MAC_ADDR_LEN];
    /* beacon data info */
    uint8_t     bc_data[IOT_PLC_BEACON_DATA_MAX];
} iot_plc_nb_nw_info_t;

/* IOT_PLC_MSG_NW_NEIGHBOR_RPT format */
typedef struct _iot_plc_nb_nw_rpt {
    /* total number of neighbour network */
    uint16_t                count;
    /* neighbour network info entries */
    iot_plc_nb_nw_info_t    nb_info[0];
} iot_plc_nb_nw_rpt_t;

/* IOT_PLC_MSG_NW_WL_QUERY format */
typedef struct _iot_plc_wl_query {
    /* start entry index in whitelist */
    uint16_t             start;
    /* maximum number of whitelist entry to return for this request */
    uint16_t             count;
} iot_plc_wl_query_t;

/* IOT_PLC_MSG_NW_BL_QUERY format */
typedef struct _iot_plc_bl_query {
    /* start entry index in blacklist */
    uint16_t             start;
    /* maximum number of blacklist entry to return for this request */
    uint16_t             count;
} iot_plc_bl_query_t;

/* IOT_PLC_MSG_NW_WL_RPT format */
typedef struct _iot_plc_wl_rpt {
    /* total count of whitelist entries */
    uint16_t            total_count;
    /* count of entries contained in this reply packet */
    uint16_t            count;
    /* report done */
    uint16_t            done : 1,
    /* reserved for future */
                        reserved : 15;
    /* whitelist entries */
    uint8_t             mac_addr[0][IOT_MAC_ADDR_LEN];
} iot_plc_wl_rpt_t;

/* IOT_PLC_MSG_NW_BL_RPT format */
typedef struct _iot_plc_bl_rpt {
    /* total count of blacklist entries */
    uint16_t            total_count;
    /* count of entries contained in this reply packet */
    uint16_t            count;
    /* report done */
    uint16_t            done : 1,
    /* reserved for future */
                        reserved : 15;
    /* blacklist entries */
    uint8_t             mac_addr[0][IOT_MAC_ADDR_LEN];
} iot_plc_bl_rpt_t;

/* IOT_PLC_MSG_NW_WL_SET format */
typedef struct _iot_plc_wl_set_req {
    /* action to perform: DISABLE / ADD / DELETE whitelist entries */
    uint8_t             action;
    /* count of whitelist entries to operate on */
    uint16_t            count;
    /* whitelist entries */
    uint8_t             mac_addr[0][IOT_MAC_ADDR_LEN];
} iot_plc_wl_set_req_t;

/* IOT_PLC_MSG_NW_BL_SET format */
typedef struct _iot_plc_bl_set_req {
    /* action to perform: DISABLE / ADD / DELETE blacklist entries */
    uint8_t             action;
    /* count of blacklist entries to operate on */
    uint16_t            count;
    /* blacklist entries */
    uint8_t             mac_addr[0][IOT_MAC_ADDR_LEN];
} iot_plc_bl_set_req_t;

/* IOT_PLC_MSG_NW_ID_SET format */
typedef struct _iot_plc_wl_set_rpt {
    /* result of the whitelist set request */
    uint8_t             result;
    /* error number */
    uint8_t             err_no;
} iot_plc_wl_set_rpt_t;

/* IOT_PLC_MSG_NW_BL_SET_RPT format */
typedef struct _iot_plc_bl_set_rpt {
    /* result of the blacklist set request */
    uint8_t             result;
    /* error number */
    uint8_t             err_no;
} iot_plc_bl_set_rpt_t;

/* IOT_PLC_MSG_CFG_SET_REQ format */
typedef struct _iot_plc_cfg_set_req {
    /* type of local device. see IOT_PLC_DEV_TYPE_XXX */
    uint8_t             dev_type;
    /* if reset lower layer to apply the configuration */
    uint8_t             reset;
    /* mac address of local device */
    uint8_t             addr[IOT_MAC_ADDR_LEN];
} iot_plc_cfg_set_req_t;

/* IOT_PLC_MSG_CFG_SET_CONF format */
typedef struct _iot_plc_cfg_set_conf {
    /* result of the request */
    uint8_t             result;
    /* error number */
    uint8_t             err_no;
} iot_plc_cfg_set_conf_t;

/* IOT_PLC_MSG_START_NW_FMT format */
typedef struct _iot_plc_start_nw_fmt {
    /* flag to mark if force start required. if plc network formation already
     * started, set this flag will restart the whole process from the very
     * beginning.
     */
    uint8_t             force;
} iot_plc_start_nw_fmt_t;

/* IOT_PLC_MSG_BAND_INFO_QUERY_RPT format */
typedef struct _iot_plc_band_info_query_rpt {
    /* frequency band. see PLC_LIB_FREQ_BAND_XXX */
    uint8_t     freq_band;
    /* noise floor of current band. unit is 1dbm */
    uint8_t     noise_floor;
    /* tx power cap. 0 means no tx power cap. unit is 1dbm */
    uint8_t     power_cap;
} iot_plc_freq_band_info_query_rpt_t;

/* IOT_PLC_MSG_WDG_SET_REQ format */
typedef struct _iot_plc_wdg_set_req {
    /* 0 - disable plc watch dog
     * otherwise - eanble plc watch dog
     */
    uint8_t             enable;
} iot_plc_wdg_set_req_t;

/* IOT_PLC_MSG_WDG_SET_CONF format */
typedef struct _iot_plc_wdg_set_conf {
    /* current status of the plc watch dog feature.
     * 0 - plc watch dog disabled
     * otherwise - plc watch dog enabled
     */
    uint8_t             status;
} iot_plc_wdg_set_conf_t;

/* IOT_PLC_MSG_NEIGHBOR_DEV_QUERY format */
typedef struct _iot_plc_neighbor_dev_query {
    /* start tei of the query */
    uint16_t    start;
    /* requested number of valid entries */
    uint16_t    count;
} iot_plc_neighbor_dev_query_t;

/* plc neighbor device info format */
typedef struct _iot_plc_neighbor_dev_info {
    /* tei of the neighbor device */
    uint16_t            tei;
    /* level of the station */
    uint8_t             level;
    /* role of the station */
    uint8_t             role;
    /* uplink traffic success ratio */
    uint8_t             ul_tf_sr;
    /* downlink traffic success ratio */
    uint8_t             dl_tf_sr;
    /* physical phase of the station */
    uint16_t            phase1      :2,
                        phase2      :2,
                        phase3      :2,
    /* flag to mark if device is direct sub sta of local device */
                        d_sub_sta   :1,
    /* flag to mark if device proxy of local device */
                        proxy       :1,
    /* flag to mark if devie address is valid */
                        addr_valid  :1,
    /* reserved for future */
                        reserved    :5;
    /* rx snr from the node to local device */
    int8_t              snr;
    /* mac address of the station */
    uint8_t             addr[IOT_MAC_ADDR_LEN];
} iot_plc_neighbor_dev_info_t;

/* IOT_PLC_MSG_NEIGHBOR_DEV_RPT format */
typedef struct _iot_plc_neighbor_dev_rpt {
    /* total number of valid tei */
    uint16_t            total_cnt;
    /* total direct sub sta of local device */
    uint16_t            total_d_sub_sta_cnt;
    /* number of valid tei in current message */
    uint16_t            cnt;
    /* report done */
    uint16_t            done:       1,
    /* reserved for future */
                        reserved:   15;
    /* node info of each valid tei */
    iot_plc_neighbor_dev_info_t node[0];
} iot_plc_neighbor_dev_rpt_t;

/* IOT_PLC_MSG_INVALID_MAC_RPT format */
typedef struct _iot_plc_invalid_mac_rpt {
    /* the reason that the MAC address is invalid, see IOT_PLC_INVD_MAC_XXX */
    uint8_t reason;
    /* pointer to invalid mac addr */
    uint8_t mac[IOT_MAC_ADDR_LEN];
} iot_plc_invalid_mac_rpt_t;

/* IOT_PLC_MSG_TEI_ADDR_INFO_QUERY format
 * query tei address information
 */
typedef struct _iot_plc_query_tei_addr_info {
    /* start tei */
    uint16_t            start_tei;
    /* start query position. bit0, bit1, bit2, ... */
    uint16_t            offset;
    /* bm len */
    uint8_t             bm_len;
    /* tei bitmap, bit0 represent start tei,
     * bit1 represent start tei + 1 and so on.
     */
    uint8_t             bm[0];
} iot_plc_query_tei_addr_info_t;

/* tei address information */
typedef struct _iot_plc_tei_addr_info {
    /* tei */
    uint16_t            tei;
    /* mac address */
    uint8_t             addr[IOT_MAC_ADDR_LEN];
} iot_plc_tei_addr_info_t;

/* IOT_PLC_MSG_TEI_ADDR_INFO_RPT format
 * report tei address information
 */
typedef struct _iot_plc_rpt_tei_addr_info {
    /* flag to mark if all tei in the bitmap have been handled */
    uint8_t                    done;
    /* tei and addr count */
    uint8_t                    count;
    /* tei and addr information */
    iot_plc_tei_addr_info_t    info[0];
} iot_plc_rpt_tei_addr_info_t;

/* IOT_PLC_MSG_TX_POWER_CAP_SET format */
typedef struct _iot_plc_tx_power_cap_set {
    /* tx power. unit is 1dbm */
    uint8_t      power;
} iot_plc_tx_power_cap_set_t;

/* IOT_PLC_MSG_TX_POWER_CAP_SET_RPT format */
typedef struct _iot_plc_tx_power_cap_set_rpt {
    /* result of the tx power cap set request */
    uint8_t             result;
    /* error number */
    uint8_t             err_no;
} iot_plc_tx_power_cap_set_rpt_t;

/* IOT_PLC_MSG_TX_POWER_CAP_QUERY_RPT format */
typedef struct _iot_plc_tx_power_cap_query_rpt {
    /* tx power cap. unit is 1 dbm */
    uint8_t      power;
} iot_plc_tx_power_cap_query_rpt_t;

#pragma pack(pop)    /* restore the pack status */

#endif /* IOT_PLC_MSG_API_H */