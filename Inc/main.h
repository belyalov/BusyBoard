/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32l1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define EN_12V_Pin GPIO_PIN_0
#define EN_12V_GPIO_Port GPIOA
#define BTN9_Pin GPIO_PIN_1
#define BTN9_GPIO_Port GPIOA
#define BTN9_EXTI_IRQn EXTI1_IRQn
#define BTN11_Pin GPIO_PIN_2
#define BTN11_GPIO_Port GPIOA
#define BTN11_EXTI_IRQn EXTI2_IRQn
#define LATCH_Pin GPIO_PIN_3
#define LATCH_GPIO_Port GPIOA
#define BTN6_Pin GPIO_PIN_4
#define BTN6_GPIO_Port GPIOA
#define BTN6_EXTI_IRQn EXTI4_IRQn
#define BTN1_Pin GPIO_PIN_12
#define BTN1_GPIO_Port GPIOB
#define BTN1_EXTI_IRQn EXTI15_10_IRQn
#define BTN2_Pin GPIO_PIN_13
#define BTN2_GPIO_Port GPIOB
#define BTN2_EXTI_IRQn EXTI15_10_IRQn
#define BTN3_Pin GPIO_PIN_14
#define BTN3_GPIO_Port GPIOB
#define BTN3_EXTI_IRQn EXTI15_10_IRQn
#define BTN4_Pin GPIO_PIN_15
#define BTN4_GPIO_Port GPIOB
#define BTN5_Pin GPIO_PIN_8
#define BTN5_GPIO_Port GPIOA
#define BTN5_EXTI_IRQn EXTI9_5_IRQn
#define BTN7_Pin GPIO_PIN_15
#define BTN7_GPIO_Port GPIOA
#define BTN7_EXTI_IRQn EXTI15_10_IRQn
#define BTN_USR_Pin GPIO_PIN_3
#define BTN_USR_GPIO_Port GPIOB
#define BTN_USR_EXTI_IRQn EXTI3_IRQn
#define BTN10_Pin GPIO_PIN_5
#define BTN10_GPIO_Port GPIOB
#define BTN10_EXTI_IRQn EXTI9_5_IRQn
#define BTN8_Pin GPIO_PIN_6
#define BTN8_GPIO_Port GPIOB
#define BTN8_EXTI_IRQn EXTI9_5_IRQn
#define BATT_CHRG_Pin GPIO_PIN_7
#define BATT_CHRG_GPIO_Port GPIOB
#define BATT_CHRG_EXTI_IRQn EXTI9_5_IRQn
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
