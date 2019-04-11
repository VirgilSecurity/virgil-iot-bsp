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
#ifndef IOT_RINGBUF_API_H
#define IOT_RINGBUF_API_H

/** \defgroup MISC_APIs MISC APIs
 *  @brief MISC APIs
 *
 *
 */

/** @addtogroup MISC_APIs
 * @{
 *
 */

/**
 *Structure that holds the state of a ring buffer.
 */
typedef struct ringbuf {
  uint8_t *data;
  uint32_t mask;
  uint32_t put_ptr;
  uint32_t get_ptr;
} ringbuf_t;

/**
 * @brief iot_ringbuf_init() - Initialize a ring buffer
 * @param r:        A pointer to a struct ringbuf to hold the state of the
 *                  ring buffer
 * @param a:        A pointer to an array to hold the data in the buffer
 * @param size_power_of_two:    The size of the ring buffer, which must be
 *                  a power of two
 */
void iot_ringbuf_init(struct ringbuf *r, uint8_t *a,
        uint32_t size_power_of_two);

/**
 * @brief iot_get_ring_pos() - Covert a position in a ring buffer
 * @param pos:      A position
 * @param r:        A pointer to an array to hold the data in the buffer
 * @return          The position in the ring buffer
 */
uint32_t iot_get_ring_pos(int32_t pos, struct ringbuf *r);

/**
 * @brief iot_ringbuf_put() - Insert a byte into the ring buffer
 * @param r:    A pointer to a struct ringbuf to hold the state of the ring
 *              buffer
 * @param c:    The byte to be written to the buffer
 *
 * @return      1 -- if there data could be written
 * @return      0 -- if the buffer was full.
 */
int iot_ringbuf_put(struct ringbuf *r, uint8_t c);

/**
 * @brief iot_ringbuf_get() - Get a byte from the ring buffer
 * @param r:    A pointer to a struct ringbuf to hold the state of the
 *              ring buffer
 *
 * @return      The first byte
 * @return      -1 -- if the buffer was empty
 */
int iot_ringbuf_get(struct ringbuf *r);

/**
 * @brief iot_ringbuf_puts() - write a buffer into the ring buffer
 * @param r:    A pointer to a struct ringbuf to hold the state of the ring
 *              buffer
 * @param seq:  A pointer for write buffer
 * @param len:  len for write buffer
 *
 * @return      the size write into the ring buffer.
 */
uint32_t iot_ringbuf_puts(struct ringbuf *r, uint8_t *seq, uint32_t len);

/**
 * @brief iot_ringbuf_gets() -  read buffer from the ring buffer
 * @param r:    A pointer to a struct ringbuf to hold the state of the ring
 *              buffer
 * @param seq:  A pointer for write buffer
 * @param len:  len for write buffer
 *
 * @return      the size read from the fring buffer
 */
uint32_t iot_ringbuf_gets(struct ringbuf *r, uint8_t *seq, uint32_t len);

/**
 * @brief iot_ringbuf_drop() -  drop some data
 * @param r:    A pointer to a struct ringbuf to hold the state of the ring
 *              buffer
 * @param len:  len for write buffer
 *
 * @return      how many size drop
 */
uint32_t iot_ringbuf_drop(struct ringbuf *r, uint32_t len);

/**
 * @brief iot_ringbuf_size() - Get the size of a ring buffer
 * @param r:    A pointer to a struct ringbuf to hold the state of the ring
 *              buffer
 *
 * @return      The size of the buffer.
 */
int iot_ringbuf_size(struct ringbuf *r);

/**
 * @brief iot_ringbuf_elements() - Get the number of elements currently in the
 *                                 ring buffer
 * @param r:    A pointer to a struct ringbuf to hold the state of the ring
 *              buffer
 *
 * @return      The number of elements in the buffer.
 */
uint32_t iot_ringbuf_elements(struct ringbuf *r);

/**
 * @brief iot_ringbuf_offset_add() - add some offset at the original offset
 *                                   position
 * @param r:    A pointer to a struct ringbuf to hold the state of the ring
 *              buffer
 * @param origin_pos:   original offset position.
 * @param add:          offset required to increase.
 *
 * @return      new offset.
 */
uint32_t iot_ringbuf_offset_add(ringbuf_t *r, uint32_t origin_pos,
    uint32_t add);

/**
 * @brief iot_ringbuf_dummy_gets() -read buffer from the ring buffer, the get
 *                           cursor is not adjusted.
 * @param r:    A pointer to a struct ringbuf to hold the state of the ring
 *              buffer
 * @param buf:  A pointer for write buffer
 * @param len:  len for write buffer
 * @param pos:  the position of the specified start read, relative to r->data
 *
 * @return      the size read from the fring buffer.
 */
uint32_t iot_ringbuf_dummy_gets(ringbuf_t *r, uint8_t *buf,
    uint32_t len, uint32_t pos);

/**
  * @}
  */

#endif /* IOT_RINGBUF_API_H */