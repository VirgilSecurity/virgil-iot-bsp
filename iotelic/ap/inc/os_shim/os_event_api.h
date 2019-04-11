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

#ifndef OS_SHIM_EVENT_API_H
#define OS_SHIM_EVENT_API_H

/* os shim includes */
#include "os_types_api.h"

/* common includes */
#include "iot_module_api.h"

/** \defgroup OS_APIs PLC OS APIs
  * @brief WQ30x1 PLC OS APIs
  *
  */


/** @addtogroup OS_APIs
  * @{
  */

/** \defgroup OS_EVENT_APIs PLC OS EVENT APIs
  * @brief PLC OS EVENT
  *
  * OS EVENT API for customer application.
  *
  */

/** @addtogroup OS_EVENT_APIs
  * @{
  */


typedef void* os_event_h;
#define MAX_TIME    0xffffffffUL

/**
 * @brief os_create_event() - create a event.
 * @param module_id:             the module id that creates the event.
 * @param init_state_set:        initial state of the new created event.
 *                               true means the event is set by default.
 *
 * @return                       0 -- for failure case
 * @return                       otherwise -- event id
 */
os_event_h os_create_event(module_id_t module_id, bool_t init_state_set);

/**
 * @brief os_wait_event() - wait to take a event. This method should NOT
 * be called in ISR.
 *
 * @param event_id:              id of the event being waiting to be taken.
 * @param timeout:               time to wait in millisecond for the event
 *                               to be available. when timeout is set to
 *                               MAX_TIME, this method return only if
 *                               the event become avaliable.
 *
 * @return                       TRUE -- Take the event successfully
 * @return                       FALSE -- Failed to take the event within ms milliseconds
 */
bool_t os_wait_event(os_event_h event_id, uint32_t timeout);

/**
 * @brief os_set_event() - give a event. This method should NOT be called in ISR.
 * @param event_id:              id of the event to be given.
 *
 * @return                       TRUE - Give the event successfully
 * @return                       FALSE - Failed to take the event
 */
bool_t os_set_event(os_event_h event_id);

/**
 * @brief os_delete_event() - delete a event.
 *
 * @param event_id:              id of the event to be deleted.
 */
void os_delete_event(os_event_h event_id);

/**
  * @}
  */

/**
  * @}
  */

#endif /* OS_SHIM_EVENT_API_H */
