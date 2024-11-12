/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
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
#include "stm32f1xx_hal.h"

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
#define a1_Pin GPIO_PIN_1
#define a1_GPIO_Port GPIOA
#define b1_Pin GPIO_PIN_2
#define b1_GPIO_Port GPIOA
#define c1_Pin GPIO_PIN_3
#define c1_GPIO_Port GPIOA
#define d1_Pin GPIO_PIN_4
#define d1_GPIO_Port GPIOA
#define e1_Pin GPIO_PIN_5
#define e1_GPIO_Port GPIOA
#define f1_Pin GPIO_PIN_6
#define f1_GPIO_Port GPIOA
#define g1_Pin GPIO_PIN_7
#define g1_GPIO_Port GPIOA
#define Button1_Pin GPIO_PIN_0
#define Button1_GPIO_Port GPIOB
#define Button2_Pin GPIO_PIN_1
#define Button2_GPIO_Port GPIOB
#define Button3_Pin GPIO_PIN_2
#define Button3_GPIO_Port GPIOB
#define EN3_Pin GPIO_PIN_10
#define EN3_GPIO_Port GPIOB
#define EN4_Pin GPIO_PIN_11
#define EN4_GPIO_Port GPIOB
#define Red1_Pin GPIO_PIN_8
#define Red1_GPIO_Port GPIOA
#define Yellow1_Pin GPIO_PIN_9
#define Yellow1_GPIO_Port GPIOA
#define Green1_Pin GPIO_PIN_10
#define Green1_GPIO_Port GPIOA
#define Red2_Pin GPIO_PIN_11
#define Red2_GPIO_Port GPIOA
#define Yellow2_Pin GPIO_PIN_12
#define Yellow2_GPIO_Port GPIOA
#define Green2_Pin GPIO_PIN_13
#define Green2_GPIO_Port GPIOA
#define EN1_Pin GPIO_PIN_14
#define EN1_GPIO_Port GPIOA
#define EN2_Pin GPIO_PIN_15
#define EN2_GPIO_Port GPIOA
#define a2_Pin GPIO_PIN_3
#define a2_GPIO_Port GPIOB
#define b2_Pin GPIO_PIN_4
#define b2_GPIO_Port GPIOB
#define c2_Pin GPIO_PIN_5
#define c2_GPIO_Port GPIOB
#define d2_Pin GPIO_PIN_6
#define d2_GPIO_Port GPIOB
#define e2_Pin GPIO_PIN_7
#define e2_GPIO_Port GPIOB
#define f2_Pin GPIO_PIN_8
#define f2_GPIO_Port GPIOB
#define g2_Pin GPIO_PIN_9
#define g2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
