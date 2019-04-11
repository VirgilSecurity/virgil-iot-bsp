#ifndef __DEBUG_UART_H__
#define __DEBUG_UART_H__

unsigned int dbg_send_bytes(const unsigned char *seq, unsigned int len);

void dbg_putchar(const char ch);

#endif /* __DEBUG_UART_H__ */
