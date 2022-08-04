/**
  ******************************************************************************
  * @file    gpio.h
  * @brief   This file contains all the function prototypes for
  *          the gpio.c file
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __GPIO_H__
#define __GPIO_H__

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* USER CODE BEGIN Private defines */
#define KEYON_GPIO GPIOB
#define KEYON_PIN GPIO_PIN_1

#define KEY2_GPIO GPIOB
#define KEY2_PIN GPIO_PIN_2

#define PWR_EN_GPIO GPIOB
#define PWR_EN_PIN GPIO_PIN_0

#define MOTOR_GPIO GPIOB
#define MOTOR_PIN GPIO_PIN_3

#define REDL_GPIO GPIOB
#define REDL_PIN GPIO_PIN_4
#define REDL_ON() HAL_GPIO_WritePin(REDL_GPIO, REDL_PIN, GPIO_PIN_SET);
#define REDL_OFF() HAL_GPIO_WritePin(REDL_GPIO, REDL_PIN, GPIO_PIN_RESET);

#define UVL_GPIO GPIOB
#define UVL_PIN GPIO_PIN_5
#define UVL_ON() HAL_GPIO_WritePin(UVL_GPIO, UVL_PIN, GPIO_PIN_SET);
#define UVL_OFF() HAL_GPIO_WritePin(UVL_GPIO, UVL_PIN, GPIO_PIN_RESET);

#define MRS_GPIO GPIOA
#define MRS_PIN GPIO_PIN_1
#define MRS_CLK_ENABLE() __HAL_RCC_GPIOA_CLK_ENABLE()
/* USER CODE END Private defines */

void MX_GPIO_Init(void);
void MRS_GPIO_Init(void);

/* USER CODE BEGIN Prototypes */

/* USER CODE END Prototypes */

#ifdef __cplusplus
}
#endif
#endif /*__ GPIO_H__ */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
