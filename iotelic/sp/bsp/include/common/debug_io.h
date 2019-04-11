
#ifndef __DEBUG_IO_H__
#define __DEBUG_IO_H__

int32_t iot_printf(const char *fmt, ...);

#ifdef printf
#undef printf
#define printf iot_printf
#endif

#endif //__DEBUG_IO_H__
