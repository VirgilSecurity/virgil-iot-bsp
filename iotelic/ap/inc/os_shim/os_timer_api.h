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

#ifndef OS_SHIM_TIMER_API_H
#define OS_SHIM_TIMER_API_H

/* os shim includes */
#include "os_types_api.h"

/* common includes */
#include "iot_module_api.h"

/** \defgroup OS_APIs PLC OS APIs
  * @brief WQ30x1 PLC OS APIs
  */


/** @addtogroup OS_APIs
  * @{
  */

/** \defgroup OS_TIMER_APIs PLC OS TIMER APIs
  * @brief PLC OS TIMER
  *
  * OS Timer helper functions. Application can use for their own timers
  *
  */

/** @addtogroup OS_TIMER_APIs
  * @{
  */

typedef uint32_t timer_id_t;

/**
 * @brief void(*os_timer_func_t)() - define timer callback function pointer type.
 * @param timer_id:             timer_id of the timer related with this callback method.
 * @param arg:                  arg for the callback passed in os_timer_create.
 */
typedef void(*os_timer_func_t)(timer_id_t timer_id, void * arg);

/**
 * @brief os_create_timer() - create a timer
 * @param module_id:            id of module that the timer belongs to.
 * @param auto_reload:          parameter passed to the function call.
 * @param cb:                   callback method of the timer.
 * @param arg:                  argument for the callback method.
 *
 * @return                      0 -- for failure case
 * @return                      otherwise -- timer id
 */
timer_id_t os_create_timer(module_id_t module_id,
                           bool_t auto_reload,
                           os_timer_func_t cb,
                           void* arg);

/**
 * @brief os_start_timer() - start a timer. This method should not be called in ISR.
 * @param id:                   id of the timer to be started.
 * @param period:               time period of the timer in milliseconds.
 */
void os_start_timer(timer_id_t id, uint32_t period);

/**
 * @brief os_stop_timer() - stop a timer. This method should not be called in ISR.
 * @param id:                   id of the timer to be stopped.
 */
void os_stop_timer(timer_id_t id);

/**
 * @brief os_reset_timer() - reset a timer. This method should not be called in ISR.
 * @param id:                   id of the timer to be checked.
 */
void os_reset_timer(timer_id_t id);

/**
 * @brief os_delete_timer() - delete a timer.
 * @param id:                   id of the timer to be deleted.
 */
void os_delete_timer(timer_id_t id);

/**
 * @brief os_is_timer_active() - check if timer is active. Active means if
 * started AND callback will be called later
 * @param id:                   id of the timer to be reset
 *
 * @return                      0 -- if the timer is not active
 * @return                      1 -- if the timer is active
 */
uint32_t os_is_timer_active(timer_id_t id);

/**
  * @}
  */

/**
  * @}
  */

#endif /* OS_SHIM_TIMER_API_H */