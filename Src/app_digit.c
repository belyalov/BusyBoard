#include "app.h"

#define DIGIT_TOP          (1 << 3)
#define DIGIT_TOP_LEFT     (1 << 2)
#define DIGIT_TOP_RIGHT    (1 << 4)
#define DIGIT_MIDDLE       (1 << 1)
#define DIGIT_BOTTOM_LEFT  (1 << 7)
#define DIGIT_BOTTOM_RIGHT (1 << 5)
#define DIGIT_BOTTOM       (1 << 6)
#define DIGIT_EIGHT        (0xfe)

const static uint32_t digit_mapping[10] = {
    (DIGIT_EIGHT & ~(DIGIT_MIDDLE)),                                        // 0
    (DIGIT_TOP_RIGHT | DIGIT_BOTTOM_RIGHT),                                 // 1
    (DIGIT_EIGHT & ~(DIGIT_TOP_LEFT | DIGIT_BOTTOM_RIGHT)),                 // 2
    (DIGIT_EIGHT & ~(DIGIT_TOP_LEFT | DIGIT_BOTTOM_LEFT)),                  // 3
    (DIGIT_TOP_LEFT | DIGIT_MIDDLE | DIGIT_TOP_RIGHT | DIGIT_BOTTOM_RIGHT), // 4
    (DIGIT_EIGHT & ~(DIGIT_TOP_RIGHT | DIGIT_BOTTOM_LEFT)),                 // 5
    (DIGIT_EIGHT & ~(DIGIT_TOP_RIGHT)),                                      // 6
    (DIGIT_TOP | DIGIT_TOP_RIGHT | DIGIT_BOTTOM_RIGHT),                     // 7
    (DIGIT_EIGHT),                                                          // 8
    (DIGIT_EIGHT & ~(DIGIT_BOTTOM_LEFT)),                                   // 9
};

extern volatile uint32_t all_leds_state;
void transfer_leds_state();


void set_digit(uint8_t digit)
{
  if (digit > 9) {
    digit = 0;
  }
  all_leds_state &= ~DIGIT_EIGHT;
  all_leds_state |= digit_mapping[digit];

  transfer_leds_state();
}

void set_digit_off()
{
  all_leds_state &= ~DIGIT_EIGHT;

  transfer_leds_state();
}
