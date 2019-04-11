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

#ifndef IOT_CLI_SG_API_H
#define IOT_CLI_SG_API_H

#include "os_types_api.h"

#include "iot_pkt_api.h"
#include "iot_utils_api.h"

#pragma pack(push)  /* save the pack status */
#pragma pack(1)     /* 1 byte align */

/* message id used for cli report message to sg */
#define IOT_CLI_SG_MSG_START_METER_LIST            (0x1)
#define IOT_CLI_SG_MSG_STOP_METER_LIST             (0x2)
#define IOT_CLI_SG_MSG_GET_METER_LIST              (0x3)
#define IOT_CLI_SG_MSG_QUERY_WL_STATE              (0x4)
#define IOT_CLI_SG_MSG_QUERY_WL                    (0x5)
#define IOT_CLI_SG_MSG_ADD_WL                      (0x6)
#define IOT_CLI_SG_MSG_RM_WL                       (0x7)
#define IOT_CLI_SG_MSG_SET_WL_STATE                (0x8)

/* message id used for sg report message to cli */
#define IOT_CLI_SG_MSG_RPT_START_METER_LIST        (0x1)
#define IOT_CLI_SG_MSG_RPT_STOP_METER_LIST         (0x2)
#define IOT_CLI_SG_MSG_RPT_SEARCH_METER_DONE       (0x3)
#define IOT_CLI_SG_MSG_RPT_METER_LIST              (0x4)
#define IOT_CLI_SG_MSG_RPT_WL_STATE                (0x5)
#define IOT_CLI_SG_MSG_RPT_WL                      (0x6)
#define IOT_CLI_SG_MSG_RPT_ADD_WL                  (0x7)
#define IOT_CLI_SG_MSG_RPT_RM_WL                   (0x8)
#define IOT_CLI_SG_MSG_RPT_SET_WL_STATE            (0x9)

/* sg register cli interface result */
#define IOT_CLI_SG_REGISTER_SUCCESS                (0x0)
#define IOT_CLI_SG_REGISTER_FAILURE                (0x1)

/* meter communication protocol on plc */
#define IOT_CLI_SG_PROTO_TYPE_RAW_DATA             (0x00)
#define IOT_CLI_SG_PROTO_TYPE_645_1997             (0x01)
#define IOT_CLI_SG_PROTO_TYPE_645_2007             (0x02)
#define IOT_CLI_SG_PROTO_TYPE_698                  (0x03)

/* white list disabled */
#define IOT_CLI_SG_WL_STATE_DISABLE                (0)
/* white list enabled */
#define IOT_CLI_SG_WL_STATE_ENABLE                 (1)
/* white list enabled when cctt and meter entry exist */
#define IOT_CLI_SG_WL_STATE_ENABLE_DELAY           (2)

/* cli and sg transfer data msg header */
typedef struct _iot_cli_sg_msg_header {
    /* msg id */
    uint32_t     msg_id : 8;
    /* reserved for future */
    uint32_t    reserved : 24;
} iot_cli_sg_msg_header_t;

/**
 * @brief (*iot_cli_sg_recv_func_t)() - callback to receive event from
 *               cli host.
 * @param param: parameter registered in iot_cli_sg_interface_register
 * @param pkt:   buffer to store the event detail, application should call
 *               iot_free_pkt function ASAP to free the iot_pkt_t. it's very
 *               scarce resource.
 */
typedef void(*iot_cli_sg_recv_func_t)(void *param, iot_pkt_t *pkt);

typedef struct _iot_cli_sg_result {
    /* see ERR_XXX */
    uint32_t                   result;
} iot_cli_sg_result_t;

typedef struct _iot_cli_sg_interface {
    /* callback to receive event from cli host */
    iot_cli_sg_recv_func_t     recv;
    /* parameter that will be transferred back alone with the callback */
    void                       *param;
} iot_cli_sg_interface_t;

typedef struct _iot_cli_sg_start_sec_node_reg_dl {
    /* sec node registration duration. unit is 1 min. */
    uint16_t                   duration;
} iot_cli_sg_start_sec_node_reg_dl_t;

typedef struct _iot_cli_sg_get_sec_node_info_dl {
    /* query start node index */
    uint16_t                   sec_node_start_index;
    /* query node count */
    uint8_t                    sec_node_count;
} iot_cli_sg_get_sec_node_info_dl_t;

typedef struct _iot_cli_sg_sec_node_info {
    /* meter mac address */
    uint8_t                     meter_mac[IOT_MAC_ADDR_LEN];
    /* station mac address */
    uint8_t                     sta_mac[IOT_MAC_ADDR_LEN];
    /* proto type, see IOT_CLI_SG_PROTO_TYPE_xxx */
    uint8_t                     proto_type;
} iot_cli_sg_sec_node_info_t;

typedef struct _iot_cli_sg_rpt_sec_node_info_ul {
    /* report node total count */
    uint16_t                    sec_node_count;
    /* this time report node count */
    uint8_t                     rsp_sec_node_count;
    /* sec node information */
    iot_cli_sg_sec_node_info_t  node_info[0];
} iot_cli_sg_rpt_sec_node_info_ul_t;

typedef struct _iot_cli_sg_node_info {
    /* mac address of secondary node */
    uint8_t                     mac[IOT_MAC_ADDR_LEN];
    /* protocol the node supports, see IOT_CLI_SG_PROTO_TYPE_xxx */
    uint8_t                     proto_type;
} iot_cli_sg_node_info_t;

typedef struct _iot_cli_sg_query_wl {
    /* query start node index */
    uint16_t                    start_index;
    /* query node count */
    uint16_t                    count;
} iot_cli_sg_query_wl_t;

typedef struct _iot_cli_sg_rpt_wl {
    /* report node total count */
    uint16_t                    total_count;
    /* this time report node count */
    uint8_t                     rsp_count;
    /* sec node information */
    iot_cli_sg_node_info_t      node_info[0];
} iot_cli_sg_rpt_wl_t;

typedef struct _iot_cli_sg_add_wl {
    /* count of meter mac */
    uint8_t                     count;
    /* info of node for wl operation */
    iot_cli_sg_node_info_t      node_info[0];
} iot_cli_sg_add_wl_t;

typedef struct _iot_cli_sg_rm_wl {
    /* count of meter mac */
    uint8_t                     count;
    /* mac address array */
    uint8_t                     mac_addr[0][IOT_MAC_ADDR_LEN];
} iot_cli_sg_rm_wl_t;

typedef struct _iot_cli_sg_set_wl_state {
    /* white list state, see IOT_CLI_SG_WL_STATE_XXX */
    uint8_t                     state;
} iot_cli_sg_set_wl_state_t;

typedef struct _iot_cli_sg_rpt_wl_state {
    /* white list state, see IOT_CLI_SG_WL_STATE_XXX */
    uint8_t                     state;
} iot_cli_sg_rpt_wl_state_t;

#if PLC_SUPPORT_CCO_ROLE
/**
 * @brief iot_cli_sg_get_headroom_req() - when sg transter iot_pkt_t to cli
 *                                        that the iot_pkt_t need reserve some
 *                                        space in iot_pkt_t head part.
 * @return:                               the space size to be reserved.
 */
uint8_t iot_cli_sg_get_headroom_req();

/**
 * @brief iot_cli_sg_interface_register() - register smart grid interface to
 *                          cli module.
 * @param cli_interface:    smart grid interface.
 * @return:                 register result, see IOT_CLI_SG_REG_xxx.
 */
uint32_t iot_cli_sg_interface_register(iot_cli_sg_interface_t *cli_interface);

/**
 * @brief iot_cli_sg_send_data_to_cli_interface() - sg send data to cli
 *                                                  interface.
 * @param pkt:    meter list data.
 * @param msg_id: the data identify
 */
void iot_cli_sg_send_data_to_cli_interface(iot_pkt_t *pkt, uint8_t msg_id);

#else

#define iot_cli_sg_get_headroom_req() (0)

#define iot_cli_sg_interface_register(cli_interface) \
    IOT_CLI_SG_REGISTER_FAILURE

#define iot_cli_sg_send_data_to_cli_interface(pkt, msg_id) IOT_ASSERT(0)

#endif

#pragma pack(pop)   /* restore the pack status */

#endif /* IOT_CLI_SG_API_H */
