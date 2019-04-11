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

#ifndef OS_SHIM_LOCK_API_H
#define OS_SHIM_LOCK_API_H

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

/** \defgroup OS_MUTEX_APIs PLC OS LOCK APIs
  * @brief PLC OS MUTEX
  *
  * OS MUTEX API for customer application.
  */

/** @addtogroup OS_MUTEX_APIs
  * @{
  */


/* mutex handle definition */
typedef void *os_mutex_h;

/**
 * @brief os_create_mutex() - create a mutex.
 * @param module_id:      the module that creates the event.
 *
 * @return                NULL -- for failure case
 * @return                otherwise -- mutex handle
 */
os_mutex_h os_create_mutex(module_id_t module_id);

/**
 * @brief os_acquire_mutex() - acquire a mutex. This function can be called
 * recursively from one task. For each call, a corresponding release call is
 * required to release the mutex. This function can NOT be called in ISR context.
 * @param mutex:          mutex to be acquired
 */
void os_acquire_mutex(os_mutex_h mutex);

/**
 * @brief os_release_mutex() - release a mutex This function can NOT be called
 * in ISR context.
 * @param mutex:          mutex to be released
 */

void os_release_mutex(os_mutex_h mutex);

/**
 * @brief os_delete_mutex() - delete a mutex
 * @param mutex:          mutex to be deleted
 */
void os_delete_mutex(os_mutex_h mutex);

/**
  * @}
  */

/**
  * @}
  */

#endif /* OS_SHIM_LOCK_API_H */