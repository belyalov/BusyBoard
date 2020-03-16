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
extern RTC_HandleTypeDef hrtc;
// extern ADC_HandleTypeDef hadc;

extern volatile uint8_t board_not_in_use;

#define LED_1        (1 << 24)
#define LED_2        (1 << 25)
#define LED_3        (1 << 26)
#define LED_4        (1 << 27)
#define LED_5        (1 << 28)
#define LED_6        (1 << 29)
#define LED_7        (1 << 30)
#define LED_8        (1 << 31)
#define LED_9        (1 << 16)
#define LED_10       (1 << 17)
#define LED_11       (1 << 18)
#define LED_12       (1 << 19)
#define LED_13       (1 << 20)
#define LED_14       (1 << 21)
#define LED_15       (1 << 22)

void app();

void set_digit(uint8_t digit);
void set_digit_off();

void turn_leds_on(uint32_t leds);
void turn_leds_off(uint32_t leds);
void turn_all_leds_off();
void turn_everything_off();

// Returns port state by button number
uint8_t button_pushed(uint8_t num);

// Returns port state of last pressed button
GPIO_PinState last_button_state();
// Returns number of last pressed button
uint8_t       last_button_pressed();

void deep_sleep();
void sleep();

#endif
