#include "app.h"

// LEDs that using 3v (don't require 12v converted to be on)
#define LEDS_3V  (LED_9 | LED_10 | LED_12 | LED_13)

volatile uint32_t all_leds_state = 0;

void transfer_leds_state()
{
  if (all_leds_state & ~LEDS_3V) {
    HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_SET);
  } else {
    HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_RESET);
  }

  HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)&all_leds_state, sizeof(all_leds_state), 1000);
  HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_SET);
}

void turn_leds_on(uint32_t leds)
{
  all_leds_state |= leds;

  transfer_leds_state();
}

void turn_leds_off(uint32_t leds)
{
  all_leds_state &= ~leds;

  transfer_leds_state();
}

void turn_all_leds_off()
{
  all_leds_state &= ~0xffff00;

  transfer_leds_state();
}

void turn_everything_off()
{
  all_leds_state = 0;

  transfer_leds_state();
}
