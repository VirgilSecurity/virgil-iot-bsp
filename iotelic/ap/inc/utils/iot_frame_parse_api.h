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

#ifndef IOT_FRAME_PARSE_API_H
#define IOT_FRAME_PARSE_API_H

#include "os_types_api.h"
#include "iot_pkt_api.h"
#include "iot_ringbuf_api.h"


/** \defgroup MISC_APIs MISC APIs
 *  @brief MISC APIs
 *
 *
 */

/** @addtogroup MISC_APIs
 * @{
 *
 */


typedef struct _iot_uart_head
{
    uint32_t crc;
    uint32_t data_len;
} iot_uart_head;

typedef enum
{
    TIMEOUT_REGULAR_TIME=0,
    TIMEOUT_PERDATA
}iot_uart_timeout_mode;

#define MAX_FRAME_CODE_LEN 2

#define MAX_CLI_FRAME_HEAD (MAX_FRAME_CODE_LEN+sizeof(iot_uart_head))
#define MAX_CLI_FRAME_END MAX_FRAME_CODE_LEN

typedef void(*iot_frame_check_func_t)(uint8_t* buffer, uint32_t buffer_len,
    bool_t* is_frame);
/**
 * iot_frame_fmt - define a parse format, for example: the full frame look like
 * FE FE FE FE 68 01 00 00 00 00 00 68 81 07 43 C3 A9 33 33 33 34 D5 16
 * |             |                        |                        |  |
 * |  preamble   |                   07 is datalen                 |  |
 *                                                                 |  |
 *                                         D5 is the backcode offset  |
 *                                                                    |
 *                                                       16 is back code
 * in order to parse above frame, the struct value as below
 * preamble_code = FE FE FE FE 68
 * preamble_codelen = 5 //PLEASE NOTE: the len doesn't large than
 *                        MAX_FRAME_CODE_LEN
 * backcode = 16
 * backcode_len = 1
 * datalen_offset = 8 //it is the len of 01 00 00 00 00 00 68 81
 * datalen_size = 1
 * datalen_fix = 0  //datalen shall be the length of raw data to be send.
 *                    for 645, this field shall be 0.
 *                    for 3762, datalen is the length of the whole datagram.
 *                    datalen_fix = preamble_size + datalen_size + backcode_size
 * backcode_offset = 1 //this is the offset after data
 * frame_timeout // 1 mean 10 milliseconds, 100 = 1 second
 * timeout_mode  //TIMEOUT_REGULAR_TIME means timeout with a regular time which 
 *               is the frame_timeout, TIMEOUT_PERDATA means once uart receive a new
 *               data, the timer will be reseted again.
 * dc_func       invoke a callback whern receive a full frame before invoke receive 
 *               a full frame callback, up-level module can check if this frame is 
 *               correct or not, if yes, the receive callback will be invoked, if no,
 *               the uart module will hold this buffer and wait the new buffer.
 *               
 */
typedef struct _iot_frame_fmt {
    uint8_t frame_timeout;
    uint8_t preamble_code[MAX_FRAME_CODE_LEN];
    uint8_t preamble_codelen;
    uint8_t backcode[MAX_FRAME_CODE_LEN];
    uint8_t backcode_len;
    uint8_t datalen_offset;
    uint8_t datalen_size;
    uint8_t datalen_fix;
    uint8_t backcode_offset;
    uint8_t timeout_mode;
    iot_frame_check_func_t check_frame_func;
} iot_frame_fmt;

/**
 * @brief has_full_frame() - check if the buffer include a full frame.
 * @param buffer:       buffer
 * @param bufferlen:    bufferlen
 * @param fmt:          frame format
 * @param has_preamble_code:    indicate if this frame include preamble code or
 *                              not, if param could be null.
 *
 * @return      0 -- donesn't find the full frame,
 * @return     otherwise -- the postion of the end of full frame
 */
uint32_t has_full_frame(uint8_t* buffer, uint32_t* bufferlen, iot_frame_fmt fmt,
    bool_t* has_preamble_code);

/**
 * @brief has_full_frame_ringbuf() - check if the ring buffer include a full
 *                                   frame.
 * @param r:            pointer of ringbuf.
 * @param fmt:          specified frame format.
 * @param ec_len[out]:  length of messy code before full frame, 
 *                      please note the return value doesn't include ec_len length.
 *
 * @return      > 0 -- length of full frame.
 * @return      = 0 -- no full data frame was found.
 */
uint32_t has_full_frame_ringbuf(ringbuf_t *r, iot_frame_fmt fmt,
    uint32_t *ec_len);

/**
 * @brief build_frame_buf() - check the buffer with frame
 * @param buffer: buffer
 * @param fmt: frame format
 *
 * @return      true -- success
 * @return      otherwise -- failure
 */
bool_t build_frame_buf(iot_pkt_t* buffer, iot_frame_fmt fmt);

#define iot_frame_data_len(pkt_len, fmt) \
    pkt_len-fmt.preamble_codelen-fmt.backcode_len

#define iot_frame_data(pkt, fmt) \
    pkt+(fmt.preamble_codelen)

 /**
  * @}
  */
  
#endif // IOT_FRAME_PARSE_API_H