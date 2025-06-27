#include "Modules/Monitor.h"

void Monitor_PutChar(char c, FILE *stream)
{
    if (c == '\n')
    {
        Monitor_PutChar('\r', stream);
    }

    loop_until_bit_is_set(UCSR0A, UDRE0);

    UDR0 = c;
}

FILE MONITOR_UART_OUTPUT = FDEV_SETUP_STREAM(Monitor_PutChar, NULL, _FDEV_SETUP_WRITE);

void Monitor_Initialize()
{
    uint16_t ubrr = (F_CPU / 16 / MONITOR_UART_BAUD_RATE) - 1;

    UBRR0H = (unsigned char)(ubrr >> 8);
    UBRR0L = (unsigned char)ubrr;

    UCSR0B = (1 << RXEN0) | (1 << TXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

    stdout = &MONITOR_UART_OUTPUT;
}