
#ifndef iotelic_log_H
#define iotelic_log_H

#include <stdio.h>

#if defined(DEBUG_PRINTF)
#define LOG(Format, ...)                                                                                               \
    do {                                                                                                               \
        printf(Format, ##__VA_ARGS__);                                                                                 \
        printf("\r\n");                                                                                                \
    } while (0)
#else
#define LOG()
#endif

#endif // iotelic_log_H
