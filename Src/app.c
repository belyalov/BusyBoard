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
  HAL_Delay(2000);
  DEBUGLN("\nBusyBoard started!");

  uint8_t current_digit = 0;
  uint8_t current_inc_dec_led = 0;

  while (1) {
    uint8_t last_btn = last_button_pressed();
    DEBUG_UINT_LN("woke up, last btn ", last_btn);
    DEBUG_UINT_LN("                  ", button_state(last_btn));

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

    // Turn digit on when cord (btn 10) is put into
    if (button_pushed(10)) {
      turn_all_leds_off();
      // Inc / Dec number if 7 or 6 button pressed
      if (button_pushed(7)) {
        current_digit++;
      } else if (button_pushed(6)) {
        current_digit--;
      }
      set_digit(current_digit % 10);
    } else if (!button_pushed(9)){
      set_digit_off();
      // Inc / Dec LEDs count if 7 or 6 button pressed
      if (button_pushed(7)) {
        current_inc_dec_led++;
      } else if (button_pushed(6)) {
        current_inc_dec_led--;
      }
      turn_all_leds_off();
      turn_leds_on(inc_dec_leds_mapping[current_inc_dec_led % 10]);
    }

    // Buttons by colors
    if (button_pushed(9) && !button_pushed(10)) {
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
        turn_leds_on(LED_1 | LED_6 | LED_11 | LED_15);
      } else {
        turn_leds_off(LED_1 | LED_6 | LED_11 | LED_15);
      }
      // All yellows
      if (button_pushed(1)) {
        turn_leds_on(LED_3 | LED_13 | LED_14);
      } else {
        turn_leds_off(LED_3 | LED_13 | LED_14);
      }
      // All greens
      if (button_pushed(4)) {
        turn_leds_on(LED_2 | LED_8 | LED_10);
      } else {
        turn_leds_off(LED_2 | LED_8 | LED_10);
      }
    }

    // Sleep until next button press / RTC
    sleep();
  }
}
