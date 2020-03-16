#define DEBUG_PRINT

#include "app.h"

const static uint32_t leds_mapping[16] = {
    0,
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_7,
    LED_8,
    LED_9,
    LED_10,
    LED_11,
    LED_12,
    LED_13,
    LED_14,
    LED_15,
};

// Main application //
void app()
{
  // Init configuration //
  DEBUGLN("\nBusyBoard started!");

  int cnt = 0;
  while (1) {
    set_digit(cnt%10);
    // DEBUG_UINT_LN("led ", cnt%16);
    // turn_leds_on(leds_mapping[cnt%16]);
    HAL_Delay(2000);
    // turn_leds_off(leds_mapping[cnt%16]);
    cnt++;
  }
}
    // deep_sleep();
void HAL_GPIO_EXTI_Callback(uint16_t pin)
{
  DEBUG_UINT_LN("interrupt on ", pin);
  // if (pin == R_INT_Pin) {
  //   DEBUG_UINT_LN("radio int ", HAL_GPIO_ReadPin(R_INT_GPIO_Port, pin));
  // }
}
