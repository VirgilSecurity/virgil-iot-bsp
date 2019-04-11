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

#ifndef IOT_MODULE_API_H
#define IOT_MODULE_API_H

#include "os_types_api.h"

// define module id for each module
#define BASIC_MID_BASE          0

#define UNKNOWN_MID             (BASIC_MID_BASE + 0)
#define OS_TIMER_MID            (BASIC_MID_BASE + 1)
#define OS_LOCK_MID             (BASIC_MID_BASE + 2)
#define OS_TASK_MID             (BASIC_MID_BASE + 3)
#define OS_UTILS_MID            (BASIC_MID_BASE + 4)
#define CPL_UTILS_MID           (BASIC_MID_BASE + 5)
#define IOT_PKT_MID             (BASIC_MID_BASE + 6)
#define IOT_QUEUE_MID           (BASIC_MID_BASE + 7)
#define IOT_IPC_MID             (BASIC_MID_BASE + 8)
#define IOT_PLC_LIB_MID         (BASIC_MID_BASE + 9)
#define IOT_DBGLOG_MID          (BASIC_MID_BASE + 10)
#define IOT_COMMUNICATOR_MID    (BASIC_MID_BASE + 11)
#define IOT_CLI_MID             (BASIC_MID_BASE + 12)
#define IOT_APP_PING_MID        (BASIC_MID_BASE + 13)
#define IOT_DRIVER_MID          (BASIC_MID_BASE + 14)
#define IOT_STATISTICS_MID      (BASIC_MID_BASE + 15)
#define IOT_TASK_MID            (BASIC_MID_BASE + 16)
#define IOT_SMART_GRID_MID      (BASIC_MID_BASE + 17)
#define IOT_FTM_MID             (BASIC_MID_BASE + 18)
#define IOT_PIB_MID             (BASIC_MID_BASE + 19)
#define IOT_SHARE_TASK          (BASIC_MID_BASE + 20)
#define IOT_CLI_HOST            (BASIC_MID_BASE + 21)
#define IOT_APP_PLCUART_MID     (BASIC_MID_BASE + 22)
#define IOT_UART_TASK_MID       (BASIC_MID_BASE + 23)
#define IOT_APP_DEMO_MID        (BASIC_MID_BASE + 24)
#define IOT_COMMON_MID_END      IOT_APP_DEMO_MID
#define PLC_MID_BASE            30

#define PLC_CVG_MID_BASE        (PLC_MID_BASE + 10)
#define PLC_CVG_COMMON_MID      (PLC_CVG_MID_BASE + 0)
#define PLC_CVG_RT_MID          (PLC_CVG_MID_BASE + 1)
#define PLC_CVG_SEC_MID         (PLC_CVG_MID_BASE + 2)
#define PLC_CVG_BWM_MID         (PLC_CVG_MID_BASE + 3)
#define PLC_CVG_PRM_MID         (PLC_CVG_MID_BASE + 4)
#define PLC_CVG_NWM_MID         (PLC_CVG_MID_BASE + 5)
#define PLC_CVG_MID_END         PLC_CVG_NWM_MID

#define PLC_MAC_MID_BASE        (PLC_MID_BASE + 20)
#define PLC_MAC_COMMON_MID      (PLC_MAC_MID_BASE + 0)
#define PLC_MAC_BEACON_MID      (PLC_MAC_MID_BASE + 1)
#define PLC_MAC_DATA_MID        (PLC_MAC_MID_BASE + 2)
#define PLC_MAC_VDEV_MID        (PLC_MAC_MID_BASE + 3)
#define PLC_MAC_PDEV_MID        (PLC_MAC_MID_BASE + 4)
#define PLC_MAC_RX_RING_MID     (PLC_MAC_MID_BASE + 5)
#define PLC_MAC_DESC_ENGINE_MID (PLC_MAC_MID_BASE + 6)
#define PLC_MAC_SHC_MID         (PLC_MAC_MID_BASE + 7)
#define PLC_MAC_KEY_MID         (PLC_MAC_MID_BASE + 8)
#define PLC_MAC_SCHED_MID       (PLC_MAC_MID_BASE + 9)
#define PLC_MAC_RX_HW_MID       (PLC_MAC_MID_BASE + 10)
#define PLC_MAC_RX_MID          (PLC_MAC_MID_BASE + 11)
#define PLC_MAC_TX_HW_MID       (PLC_MAC_MID_BASE + 12)
#define PLC_MAC_TX_MID          (PLC_MAC_MID_BASE + 13)
#define PLC_MAC_CRC_MID         (PLC_MAC_MID_BASE + 14)
#define PLC_MAC_RATE_MID        (PLC_MAC_MID_BASE + 15)
#define PLC_MAC_REORDER_MID     (PLC_MAC_MID_BASE + 16)
#define PLC_MAC_ZC_MID          (PLC_MAC_MID_BASE + 17)
#define PLC_MAC_STATUSE_MID     (PLC_MAC_MID_BASE + 18)
#define PLC_MAC_SCAN_MID        (PLC_MAC_MID_BASE + 19)
#define PLC_MAC_MID_END         PLC_MAC_SCAN_MID

#define PLC_PHY_MID_BASE        (PLC_MID_BASE + 40)
#define PLC_PHY_COMMON_MID      (PLC_PHY_MID_BASE + 0)
#define PLC_PHY_STATUS_MID      (PLC_PHY_MID_BASE + 1)
#define PLC_PHY_MID_END         PLC_PHY_STATUS_MID

#define PLC_SIM_MID_BASE        (PLC_MID_BASE + 50)
#define PLC_SIM_COMMON_MID      (PLC_SIM_MID_BASE + 0)
#define PLC_SIM_BEACON_MID      (PLC_SIM_MID_BASE + 1)
#define PLC_SIM_TX_MID          (PLC_SIM_MID_BASE + 2)
#define PLC_SIM_RX_MID          (PLC_SIM_MID_BASE + 3)
#define PLC_SIM_MID_END         PLC_SIM_RX_MID

#define OS_RISCV_BASE           0xe0
#define RISCV_DUMP_MID_BASE     (OS_RISCV_BASE + 0)
#define RISCV_DUMP_EXCP_MID     (RISCV_DUMP_MID_BASE + 1)
#define RISCV_DUMP_GREG_MID     (RISCV_DUMP_MID_BASE + 2)
#define RISCV_DUMP_TRACE_MID    (RISCV_DUMP_MID_BASE + 3)
#define RISCV_DUMP_DREG_MID     (RISCV_DUMP_MID_BASE + 4)
#define RISCV_DUMP_MID_END      RISCV_DUMP_DREG_MID

#define MAX_MID_NUM             0xff

typedef uint8_t module_id_t;

#endif // !PLC_MODULE_API_H
