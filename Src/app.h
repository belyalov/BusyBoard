#ifndef __APP_H
#define __APP_H

#include "main.h"
#include "debug.h"

#define DEBUG(s)                   debug_print_str(&huart1, s)
#define DEBUGLN(s)                 debug_print_strln(&huart1, s)
#define DEBUG_UINT(s, v)           debug_print_uint64(&huart1, s, v)
#define DEBUG_UINT_LN(s, v)        debug_print_uint64ln(&huart1, s, v)
#define DEBUG_UINT_HEX(s, v)       debug_print_hex64(&huart1, s, v)
#define DEBUG_UINT_HEXLN(s, v)     debug_print_hex64ln(&huart1, s, v)

extern UART_HandleTypeDef huart1;
extern SPI_HandleTypeDef hspi1;
// extern ADC_HandleTypeDef hadc;

void app();
void fatal_error(int delay);
void assert_error(uint32_t error);

#endif
