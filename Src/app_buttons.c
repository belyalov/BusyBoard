#include "app.h"

volatile uint16_t last_interrupt_pin = 0;

GPIO_PinState button_state(uint8_t num)
{
  switch (num) {
  case 1:
    return HAL_GPIO_ReadPin(BTN1_GPIO_Port, BTN1_Pin);
  case 2:
    return HAL_GPIO_ReadPin(BTN2_GPIO_Port, BTN2_Pin);
  case 3:
    return HAL_GPIO_ReadPin(BTN3_GPIO_Port, BTN3_Pin);
  case 4:
    return HAL_GPIO_ReadPin(BTN4_GPIO_Port, BTN4_Pin);
  case 5:
    return HAL_GPIO_ReadPin(BTN5_GPIO_Port, BTN5_Pin);
  case 6:
    return HAL_GPIO_ReadPin(BTN6_GPIO_Port, BTN6_Pin);
  case 7:
    return HAL_GPIO_ReadPin(BTN7_GPIO_Port, BTN7_Pin);
  case 8:
    return HAL_GPIO_ReadPin(BTN8_GPIO_Port, BTN8_Pin);
  case 9:
    return HAL_GPIO_ReadPin(BTN9_GPIO_Port, BTN9_Pin);
  case 10:
    return HAL_GPIO_ReadPin(BTN10_GPIO_Port, BTN10_Pin);
  case 11:
    return HAL_GPIO_ReadPin(BTN11_GPIO_Port, BTN11_Pin);
  default:
    return 0;
  }
}

uint8_t button_pushed(uint8_t num)
{
  return button_state(num) == GPIO_PIN_RESET;
}

uint8_t last_button_pressed()
{
  switch (last_interrupt_pin) {
  case BTN9_Pin:
    return 9;
  case BTN11_Pin:
    return 11;
  case BTN6_Pin:
    return 6;
  case BTN1_Pin:
    return 1;
  case BTN2_Pin:
    return 2;
  case BTN3_Pin:
    return 3;
  case BTN7_Pin:
    return 7;
  case BTN5_Pin:
    return 5;
  case BTN10_Pin:
    return 10;
  case BTN8_Pin:
    return 8;
  default:
    return 0;
  }
}

GPIO_PinState last_button_state()
{
  return button_state(last_button_pressed());
}

void HAL_GPIO_EXTI_Callback(uint16_t pin)
{
  last_interrupt_pin = pin;
  DEBUG_UINT_LN("interrupt on ", last_button_pressed());
}
