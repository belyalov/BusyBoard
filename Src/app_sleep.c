#include "app.h"

void MX_GPIO_Init(void);
void SystemClock_Config();

void sleep()
{
  HAL_SuspendTick();
  HAL_PWR_EnterSLEEPMode(PWR_MAINREGULATOR_ON, PWR_SLEEPENTRY_WFI);
  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
  HAL_ResumeTick(); 
  HAL_Delay(10);
}

void deep_sleep()
{
  turn_everything_off();
  // Just to be sure: disable 12v converter
  HAL_GPIO_WritePin(EN_12V_GPIO_Port, EN_12V_Pin, GPIO_PIN_RESET);

  // Disable pullup for buttons, except rocker switch
  GPIO_InitTypeDef mode = {};
  mode.Pin = BTN9_Pin|BTN11_Pin|BTN6_Pin|BTN7_Pin;
  mode.Mode = GPIO_MODE_ANALOG;
  mode.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOA, &mode);

  mode.Pin = BTN1_Pin|BTN2_Pin|BTN3_Pin|BTN10_Pin|BTN8_Pin;
  mode.Mode = GPIO_MODE_ANALOG;
  mode.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &mode);

  mode.Pin = BTN4_Pin;
  mode.Mode = GPIO_MODE_ANALOG;
  mode.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(BTN4_GPIO_Port, &mode);

  HAL_PWR_EnterSTOPMode(PWR_LOWPOWERREGULATOR_ON, PWR_STOPENTRY_WFI);
  __HAL_PWR_CLEAR_FLAG(PWR_FLAG_WU);
  SystemClock_Config();
  MX_GPIO_Init();
  HAL_Delay(10);
}
