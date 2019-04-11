

#ifndef KUNLUN_HELPERS_H
#define KUNLUN_HELPERS_H

#include <os_mem_api.h>
#include "../inc/iot_module_api.h"

void *vs_calloc (size_t size);
void vs_free(void *ptr);
void vs_abort();
void *vs_memcpy (void *destination, const void *source, size_t n);
void vs_assert_handler(const char *message, const char *file, int line);

#endif //KUNLUN_HELPERS_H
