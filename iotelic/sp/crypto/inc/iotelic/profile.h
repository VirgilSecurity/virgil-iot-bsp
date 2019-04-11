
#ifndef PROFILE_H
#define PROFILE_H

#if defined(DEBUG_PROFILE)

#include "log.h"
#include "timer.h"

#define PROFILE(NAME, ACTION)                                                                                          \
    ({                                                                                                                 \
        int res;                                                                                                       \
        uint32_t beg, end;                                                                                             \
        beg = timer_now();                                                                                             \
        res = ACTION;                                                                                                  \
        end = timer_now();                                                                                             \
        LOG("%s time: %d ms", NAME, (int)(end - beg));                                                                 \
        res;                                                                                                           \
    });
#else
ACTION;
#endif


#endif // PROFILE_H
