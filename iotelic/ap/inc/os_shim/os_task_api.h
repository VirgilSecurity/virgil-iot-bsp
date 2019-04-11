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

#ifndef OS_SHIM_TASK_API_H
#define OS_SHIM_TASK_API_H

/* os shim includes */
#include "os_types_api.h"

/** \defgroup OS_APIs PLC OS APIs
  * @brief WQ30x1 PLC OS APIs
  */


/** @addtogroup OS_APIs
  * @{
  */

/** \defgroup OS_TASK_APIs PLC OS TASK APIs
  * @brief PLC OS TASK
  *
  * OS TASK helper function for applications to set for their own task.
  *
  */

/** @addtogroup OS_TASK_APIs
  * @{
  */

/* define task handle */
typedef void *os_task_h;

/**
 * @brief (*os_task_func_t)() - define task routing function pointer type
 * @param arg:                  arg parameter is registered when creating a task.
 */
typedef void (*os_task_func_t)(void *arg);

/**
 * Priority definition. 5 priorities have been defined.
 * Higer number has higer priority. OS specific code can map them
 * to OS defined priority accordingly.
 */
#define OS_TASK_PRIO_5                  5
#define OS_TASK_PRIO_6                  6
#define OS_TASK_PRIO_7                  7
#define OS_TASK_PRIO_8                  8
#define OS_TASK_PRIO_9                  9

#define OS_TASK_PRIO_HIGHEST            OS_TASK_PRIO_9
#define OS_TASK_PRIO_LOWEST             OS_TASK_PRIO_5

/**
 * @brief os_create_task_ext() - create a task
 * @param fn:               function pointer of the task
 * @param arg:              parameter passed to the function call
 * @param prio:             task priority
 * @param stack_size:       required stack size for this task. if set to 0,
 *                          default stack size will be used. unit is 4 bytes.
 * @param name:             task name string
 *
 * @return                  NULL -- for failure case
 * @return                  otherwise -- task handle
 */
os_task_h os_create_task_ext(os_task_func_t fn, void *arg, uint8_t prio,
    uint32_t stack_size, const char *name);

/**
 * @brief os_create_task() - create a task
 * @param fn:               function pointer of the task
 * @param arg:              parameter passed to the function call
 * @paramprio:              task priority
 *
 * @return                  NULL -- for failure case
 * @return                  otherwise -- task handle
 */
#define os_create_task(fn, arg, prio) \
    os_create_task_ext(fn, arg, prio, 0, __FUNCTION__)

/**
 * @brief os_delete_task() - delete a task
 * @param handle:           handle of the task to be deleted
 */
void os_delete_task(os_task_h handle);

/**
 * @brief os_set_task_prio() - set priority of a task
 * @param handle:           handle of the task to be set
 * @param prio:             task priority
 */
void os_set_task_prio(os_task_h handle, uint8_t prio);

/**
 * @brief os_set_task_event() - set task event
 * @param handle:           handle of the task to be set
 */
void os_set_task_event(os_task_h handle);

/**
 * @brief os_wait_task_event() - wait for task event. a task can call this
 * funtion to wait for others to call os_set_task_event or os_set_task_event_with_v
 * to wake it up.
 */
void os_wait_task_event();

/**
 * @brief os_set_task_event_with_v() - set task event with value transferred
 * to the task. if the task haven't gotten the value through
 * os_wait_task_event_with_v yet, then value of multiple calls will be OR-ed.
 * @param handle:           handle of the task to be set
 * @param v:                value to be transferred
 */
void os_set_task_event_with_v(os_task_h handle, uint32_t v);

/**
 * @brief os_set_task_event_with_v_from_isr() - set task event with value
 * transferred to the task from ISR context. if the task haven't gotten the
 * value through os_wait_task_event_with_v yet, then value of multiple calls
 * will be OR-ed. Note that this function can only be called from ISR context.
 * @param handle:           handle of the task to be set
 * @param v:                value to be transferred
 */
void os_set_task_event_with_v_from_isr(os_task_h handle, uint32_t v);


/**
 * @brief os_wait_task_event_with_v() - wait task event and get the value.
 * a task can call this function to wait for others to call os_set_task_event
 * or os_set_task_event_with_v to wake it up. in addition, the value set by
 * os_set_task_event_with_v will be returned.
 * @param time_to_wait:     time to wait before timeout
 *
 * @return                  the received value from os_set_task_event_with_v.
 */
uint32_t os_wait_task_event_with_v(uint32_t time_to_wait);

/**
  * @}
  */

/**
  * @}
  */

#endif /* OS_SHIM_TASK_API_H */