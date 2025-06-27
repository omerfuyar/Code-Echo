#pragma once

#include "Core.h"

#define MONITOR_UART_BAUD_RATE 9600

void Monitor_Initialize();

void Monitor_PutChar(char c, FILE *stream);