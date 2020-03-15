#define DEBUG_PRINT

#include "app.h"

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

volatile uint32_t all_leds_state = 0;

void transfer_leds_state()
{
  HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_RESET);
  HAL_SPI_Transmit(&hspi1, (uint8_t*)&all_leds_state, sizeof(all_leds_state), 1000);
  HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_SET);
}

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

    // Main application //
void app()
{
  // Init configuration //
  DEBUGLN("\nBusyBoard started!");

  uint32_t leds = digit_mapping[2];
  int cnt = 0;
  uint8_t all_off[4] = {};

  // set_digit(8);
  // turn_leds_off(1<<31);
  HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_SET);
  // turn_leds_on(0xffffffff);
  set_digit(8);
  HAL_Delay(5000);
  turn_leds_off(0xffffffff);
  HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_RESET);

  HAL_Delay(1000);
  // HAL_SPI_DeInit(&hspi1);
  // HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_RESET);
  HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
  SystemClock_Config();

  while (1) {
    // turn_leds_on(0xffffffff);
    // HAL_Delay(5000);
    // turn_leds_off(0xffffffff);
    // HAL_Delay(1000);

    // DEBUG_UINT_LN("led ", cnt%16);
    // turn_leds_on(leds_mapping[cnt%16]);
    // HAL_Delay(1000);
    // turn_leds_off(leds_mapping[cnt%16]);

    // DEBUGLN("all on");
    // HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_SET);

    // HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_RESET);
    // HAL_SPI_Transmit(&hspi1, &digit_mapping[cnt % 10], 4, 1000);
    // HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_SET);
    // HAL_Delay(1000);
    // HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_RESET);

    // DEBUGLN("all off");
    // HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_RESET);
    // HAL_SPI_Transmit(&hspi1, all_off, 4, 1000);
    // HAL_GPIO_WritePin(LATCH_GPIO_Port, LATCH_Pin, GPIO_PIN_SET);
    HAL_Delay(5000);
    cnt++;
  }
}

// HAL_SPI
// DEBUGLN("12v on");
// HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_SET);
// HAL_Delay(5000);
// DEBUGLN("12v off");
// HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_RESET);

// DEBUGLN("sleep...");

// HAL_SPI_DeInit(&hspi1);
// // HAL_ADC_DeInit(&hadc);
// HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
// __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
// SystemClock_Config();

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
