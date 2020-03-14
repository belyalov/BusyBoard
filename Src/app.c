#define DEBUG_PRINT

#include "app.h"

// Main application //
void app()
{
  // Init configuration //
  DEBUGLN("\nBusyBoard started!");

  while (1) {
    DEBUGLN("12v on");
    HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_SET);
    HAL_Delay(5000);
    DEBUGLN("12v off");
    HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_RESET);
    HAL_Delay(5000);
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
