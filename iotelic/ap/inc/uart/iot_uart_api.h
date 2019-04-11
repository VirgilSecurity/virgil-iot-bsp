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

#ifndef IOT_UART_API_H
#define IOT_UART_API_H

#include "os_types_api.h"
#include "iot_pkt_api.h"
#include "iot_frame_parse_api.h"

/** \defgroup UART_APIs UART APIs
  * @brief WQ30x1 UART API
  */

/** @addtogroup UART_APIs
  * @{
  */


#ifdef _MSC_VER
#define UART_HANDLE_INVALID_VALUE INVALID_HANDLE_VALUE
#else
#define UART_HANDLE_INVALID_VALUE (int)-1
#endif

#define UART_PRINT       0
#define UART_CLI_PORT    1
#define UART_METER_PORT  2
#define UART_IR_PORT     3
#define UART_RS485_PORT  4

/*max support uart number*/
#define MAX_UART_PORT_NUM 4
/*actual uart number*/
//UART_METER_PORT and UART_RS485_PORT isn't used at same time
#define USED_UART_PORT_NUM 3

#if (IOT_UART_DMA_SUPPORT == 1)
#define UART_DMA_PORT_NUM 1
#else
#define UART_DMA_PORT_NUM 0
#endif

/* UART parity configuration */
#define IOT_UART_PARITY_NONE        0
#define IOT_UART_PARITY_ODD         1
#define IOT_UART_PARITY_EVEN        2
#define IOT_UART_PARITY_MARK        3
#define IOT_UART_PARITY_SPACE       4

#define IOT_UART_DLEN_5_BITS        5
#define IOT_UART_DLEN_6_BITS        6
#define IOT_UART_DLEN_7_BITS        7
#define IOT_UART_DLEN_8_BITS        8

#define IOT_UART_STOP_1_BITS        1
#define IOT_UART_STOP_1_5_BITS      2
#define IOT_UART_STOP_2_BITS        3

#define UART_THR_FLOWCTRL   0
#define UART_THR_RXTIMEOUT  1
#define UART_THR_RXFULL     2
#define UART_THR_TXEMPTY    3

#define UART_HW_FLOWCTRL_DISABLE    0
#define UART_HW_FLOWCTRL_RTS        1
#define UART_HW_FLOWCTRL_CTS        2
#define UART_HW_FLOWCTRL_CTS_RTS    3

#define IOT_UART_BANDRATE_DEFAULT   115200

/**
 * @brief (*iot_uart_recv_func_t)() - the callback when
 * the uart receive the data. if the iot_frame_fmt param is null, uart task
 * call this call immediately after receive any data from uart interface, if
 * iot_frame_fmt param is not null, uart task parse the frame, and call this
 * func with the full frame, is_full_frame is true for this case, but if the
 * timeout is happned, this func will be called with the all of buffer in buffer
 * cache, and is_full_frame is false.
 * @param buffer:               recv buffer
 * @param buffer_len:           recv buffer length
 * @param is_full_frame:        is full frame
 * @invalid_data_len            the premable code may not at the beginning of buffer,
 *                              please use buffer+invalid_data_len to get the first buffer
 */
typedef void(*iot_uart_recv_func_t)(uint8_t* buffer, uint32_t buffer_len,
    bool_t is_full_frame, uint32_t invalid_data_len);

typedef  void*  iot_uart_h;

/**
 * @brief iot_uart_open() - open a uart port
 * @param uart_port:            the define UART_xxxx_PORT
 *                                  1 - reserved for cli,
 *                                  2 - reserved for meter ...
 * @param iot_uart_recv_func_t: once get a full frame, this func
 *                              will be invoked.
 * @param receive_buffer_len:   the buffer size for receive a full frame
 * @param p_frame_fmt:          the format structor of a full frame, if it
 *                              is null,recv_func will be invoked once
 *                              receive any uart message.
 *
 * @return                      NULL     -- for failure case
 * @return                      othersie -- iot uart handle
 */
iot_uart_h iot_uart_open(const uint8_t uart_port, iot_uart_recv_func_t func,
    uint32_t receive_buffer_len, iot_frame_fmt *p_frame_fmt);

/**
 * @brief iot_uart_set_frame() - set the frame format, the receive buffer
 *                              will be empty when call this function
 * @param uart_h:               uart handle
 * @param p_frame_fmt:          the format structor of the frame
 *
 * @return                      false -- for failure case
 * @return                      true  -- iot uart handle
 */

bool_t iot_uart_set_frame(iot_uart_h uart_h, iot_frame_fmt *p_frame_fmt);

/**
 * @brief iot_uart_set_config() - set the uart paramter.
 *                              will be empty when call this function
 * @param uart_h:               uart handle
 * @param baud:                 baudrate
 * @param parity:               see IOT_UART_PARITY_XXX
 * @param data:                 data bits
 * @param stop:                 stop flag
 *
 * @return                      false -- for failure case
 * @return                      true  -- iot uart handle
 */
bool_t iot_uart_set_config(iot_uart_h uart_h, uint32_t baud, uint8_t parity,
    uint8_t data, uint8_t stop);

/**
 * @brief iot_uart_send() - send the buffer by uart, it is a asyn func.
 * @param uart_h:               uart handle
 * @param pkt:                  the iot pkt buffer.
 * @param p_frame_fmt:          the format structor of the frame
 *
 * @return                      ERR_OK(0) -- success
 * @return                      otherwise -- error code.
 */
uint32_t iot_uart_send(iot_uart_h uart_h, iot_pkt_t *pkt,
    iot_frame_fmt *p_frame_fmt);

/**
 * @brief iot_uart_close() - close uart port
 * @param uart_handle:          uart handle
 */
void iot_uart_close(iot_uart_h uart_handle);

/**
 * @brief iot_uart_set_flwctrl() - Set flow-control on a port..
 * @param uart_h:         uart handle
 * @param type:           Flow-control type. See UART_HW_FLOWCTRL_XX .
 * @param thrd:           Value of threshold for if RTS enabled.
 *
 * @return                      true -- success
 * @return                      false -- error.
 */
bool_t iot_uart_set_flwctrl(iot_uart_h uart_h, uint32_t type, uint32_t thrd);

/**
 * @brief iot_uart_set_threshold() - Set threshold.
 * @param uart_h:               uart handle
 * @param type:                 Threshold type.See UART_THR_XX.
 * @param thrd:                 Value of threshold.
 *
 * @return                      true -- success
 * @return                      false -- error.
 */
bool_t iot_uart_set_threshold(iot_uart_h uart_h, uint32_t type, uint32_t thrd);

/**
 * @brief iot_dbg_uart_set_config() - set the debug uart paramter.
 * @param baud:                 baudrate
 * @param parity:               see IOT_UART_PARITY_XXX
 * @param data:                 data bits
 * @param stop:                 stop flag
 */
void iot_dbg_uart_set_config(uint32_t baud, uint8_t parity,
    uint8_t data, uint8_t stop);


/**
  * @}
  */

#endif /* IOT_UART_API_H */
