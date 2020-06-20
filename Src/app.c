#define DEBUG_PRINT

#include "app.h"

const static uint32_t inc_dec_leds_mapping[10] = {
    LED_1,
    LED_2,
    LED_3,
    LED_4,
    LED_5,
    LED_6,
    LED_8,
    LED_11,
    LED_14,
    LED_15,
};

// Main application //
void app()
{
  HAL_Delay(1000);
  DEBUGLN("BusyBoard started!");

  // HAL_SPI_DeInit(&hspi1);
  // DEBUGLN("deepsl");
  HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(BATT_PWR_GPIO_Port, BATT_PWR_Pin, GPIO_PIN_SET);
  // HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_SET);
  turn_everything_off();

  HAL_RTCEx_DeactivateWakeUpTimer(&hrtc);
  HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);

  // deep_sleep();
  DEBUGLN("deep woke");

  set_digit_off();
  turn_all_leds_off();

  uint8_t current_digit = 0;
  uint8_t current_inc_dec_led = 0;

  while (1) {
    uint8_t last_btn = last_button_pressed();

    // If board is not being used...
    if (board_not_in_use) {
      board_not_in_use = 0;
      DEBUGLN("Board is not being used, turning OFF");
      deep_sleep();
      DEBUGLN("Board turned ON");
      continue;
    }

    // Rocker switch: turn board on/off
    if (last_btn == 5) {
      DEBUGLN("Board turned OFF");
      deep_sleep();
      DEBUGLN("Board turned ON");
      continue;
    }

    // All cords are off: button self lights
    if (!button_pushed(10) && !button_pushed(4)) {
      set_digit_off();
      turn_all_leds_off();
      uint32_t leds = 0;
      if (button_pushed(1)) {
        leds |= LED_3;
      }
      if (button_pushed(2)) {
        leds |= LED_5;
      }
      if (button_pushed(3)) {
        leds |= LED_6;
      }
      if (button_pushed(9)) {
        leds |= LED_2;
      }
      if (button_pushed(6)) {
        leds |= LED_4;
      }
      if (button_pushed(7)) {
        leds |= LED_7;
      }
      if (button_pushed(11)) {
        leds |= LED_12;
      }
      if (button_pushed(8)) {
        leds |= LED_13;
      }
      turn_leds_on(leds);
      goto done;
    }

    // All cords put ON: moving LED light controlled by buttons near to digit
    if (button_pushed(10) && button_pushed(4)) {
      set_digit_off();
      if (button_pushed(7)) {
        current_inc_dec_led++;
      } else if (button_pushed(6)) {
        current_inc_dec_led--;
      }
      turn_all_leds_off();
      turn_leds_on(inc_dec_leds_mapping[current_inc_dec_led % 10]);
      goto done;
    }

    // Digit scenario: right cord put into socket
    if (button_pushed(10)) {
      turn_all_leds_off();
      // Inc / Dec number if 7 or 6 button pressed (left / right btns to digit)
      if (button_pushed(7)) {
        current_digit++;
      } else if (button_pushed(6)) {
        current_digit--;
      }
      set_digit(current_digit % 10);
    }
    // Button to colors scenario: left cord put into socket
    else if (button_pushed(4)) {
      set_digit_off();
      turn_all_leds_off();
      // All blues
      if (button_pushed(2)) {
        turn_leds_on(LED_4 | LED_5 | LED_9);
      } else {
        turn_leds_off(LED_4 | LED_5 | LED_9);
      }
      // All reds
      if (button_pushed(3)) {
        turn_leds_on(LED_1 | LED_6 | LED_11 | LED_12 | LED_15);
      } else {
        turn_leds_off(LED_1 | LED_6 | LED_11 | LED_12 | LED_15);
      }
      // All yellows
      if (button_pushed(1)) {
        turn_leds_on(LED_3 | LED_13 | LED_14);
      } else {
        turn_leds_off(LED_3 | LED_13 | LED_14);
      }
      // All greens
      if (button_pushed(9)) {
        turn_leds_on(LED_2 | LED_8 | LED_10);
      } else {
        turn_leds_off(LED_2 | LED_8 | LED_10);
      }
    }

done:
    // Sleep until next button press / RTC
    sleep();
  }
}
