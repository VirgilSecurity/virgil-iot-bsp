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

/* This file contains the Kunlun features configuration
 * any feature related .c file should include this file
 */

#ifndef IOT_CONFIG_API_H
#define IOT_CONFIG_API_H

/* HW configuration start *****************************************************/

/* HW platform defination, simulator by default */
#define HW_PLATFORM_SIMU                0
#define HW_PLATFORM_FPGA                1
#define HW_PLATFORM_SILICON             2

#ifndef HW_PLATFORM
#define HW_PLATFORM HW_PLATFORM_SIMU
#endif

/* For network size defination. */
#define IOT_NETWORK_SMALL   1
#define IOT_NETWORK_LARGE   2

#ifndef IOT_NETWORK_SCALE
#define IOT_NETWORK_SCALE   IOT_NETWORK_LARGE
#endif

/* HW configuration end *******************************************************/

/* PLC configuration start ****************************************************/

/* define if FW support CCO role */
#if (HW_PLATFORM == HW_PLATFORM_SIMU)

#ifndef PLC_SUPPORT_CCO_ROLE
#define PLC_SUPPORT_CCO_ROLE            1
#endif

#ifndef PLC_SUPPORT_STA_ROLE
#define PLC_SUPPORT_STA_ROLE            1
#endif

#define IOT_UART_DMA_SUPPORT            0

#else /* (HW_PLATFORM == HW_PLATFORM_SIMU) */

#ifndef PLC_SUPPORT_CCO_ROLE
#define PLC_SUPPORT_CCO_ROLE            0
#endif

#ifndef IOT_FLASH_BUILD
#define IOT_FLASH_BUILD                 0
#endif

#if PLC_SUPPORT_CCO_ROLE
#define PLC_SUPPORT_STA_ROLE            0
#define IOT_UART_DMA_SUPPORT            1
#else
#define PLC_SUPPORT_STA_ROLE            1
#define IOT_UART_DMA_SUPPORT            0
#endif

#endif /* (HW_PLATFORM == HW_PLATFORM_SIMU) */

/* PLC configuration end ******************************************************/

/* TASK priority configuration start ******************************************/

#define IOT_PING_TASK_PRIO              7

#define IOT_SMART_GRID_TASK_PRIO        7

#define IOT_PLCUART_TASK_PRIO           7

/* TASK priority configuration end ********************************************/

/* DEBUG configuration start **************************************************/

#define IOT_PKT_DEBUG                   0

#define SMART_GRID_DEBUG                1

#if PLC_SUPPORT_CCO_ROLE
#define IOT_EXCEPTION_DEBUG             0
#else
#define IOT_EXCEPTION_DEBUG             1
#endif

#define IOT_FULL_DUMP_DEBUG             0

#if (HW_PLATFORM == HW_PLATFORM_SIMU)

#define IOT_PRINTF_DEBUG                1
#define UART_DEBUG                      1

#else /* HW_PLATFORM == HW_PLATFORM_SIMU */
#if IOT_FLASH_BUILD
#define IOT_PRINTF_DEBUG                1
#else
#define IOT_PRINTF_DEBUG                1
#endif

#define UART_DEBUG                      1

#endif /* HW_PLATFORM == HW_PLATFORM_SIMU */

/* DEBUG configuration end ****************************************************/

/* APPLICAITON configuration start ********************************************/

/*IOT_SMART_CONFIG define IOT Market APP or SG Market APP */
#if (IOT_SMART_CONFIG)
#define IOT_SMART_GRID_ENABLE           0
#else
#define IOT_SMART_GRID_ENABLE           1
#endif

/*Below Macro will define which IOT APP will run */
#if (IOT_APP_SELECTION == 1)
#define IOT_PING_APP_ENABLE             1
#else
#define IOT_PING_APP_ENABLE             0
#endif

#if (IOT_APP_SELECTION == 2)
#define IOT_PLCUART_APP_ENABLE          1
#else
#define IOT_PLCUART_APP_ENABLE          0
#endif

#if (IOT_APP_SELECTION == 3)
#define IOT_DEMO_APP_ENABLE             1
#define IOT_APPCTRL_LED                 1
#else
#define IOT_DEMO_APP_ENABLE             0
#define IOT_APPCTRL_LED                 0
#endif

#if (IOT_APP_SELECTION == 4)
#define IOT_GR_APP_ENABLE               1
#else
#define IOT_GR_APP_ENABLE               0
#endif


#define IOT_LOG_TO_FLASH_ENABLE         1

#define IOT_MP_MODE_DIRECT_ENABLE       0

#define IOT_MP_TX_MODE_ENABLE           0

#define IOT_MP_RX_MODE_ENABLE           0

#define IOT_CCO_PRINT_CLI_UART_ENABLE   0

#define IOT_ENERGE_METER_ENABLE         0

#define IOT_PLC_PHY_TX_PWR_REDUCE       0

/* APPLICAITON configuration end **********************************************/

#endif /* IOT_CONFIG_API_H */
