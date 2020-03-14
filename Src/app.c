#define DEBUG_PRINT

#include "app.h"

// Main application //
void app()
{
  // Init configuration //
  DEBUGLN("\nLoRa LED Strip Controller started.");

  while (1) {
    HAL_Delay(1000);
  }
}

void fatal_error(int delay)
{
  DEBUGLN("FATAL ERROR");
  while (1) {
    HAL_Delay(delay);
  }
}

void HAL_GPIO_EXTI_Callback(uint16_t pin)
{
  DEBUG_UINT_LN("interrupt on ", pin);
  // if (pin == R_INT_Pin) {
  //   DEBUG_UINT_LN("radio int ", HAL_GPIO_ReadPin(R_INT_GPIO_Port, pin));
  // }
}
