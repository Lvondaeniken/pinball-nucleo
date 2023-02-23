/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
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
#include "stm32f0xx_hal.h"

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
#define B1_Pin GPIO_PIN_13
#define B1_GPIO_Port GPIOC
#define RIGHT_KICKER_SWITCH_Pin GPIO_PIN_0
#define RIGHT_KICKER_SWITCH_GPIO_Port GPIOC
#define LEFT_KICKER_SWITCH_Pin GPIO_PIN_1
#define LEFT_KICKER_SWITCH_GPIO_Port GPIOC
#define LEFT_SLINGSHOT_SWITCH_Pin GPIO_PIN_2
#define LEFT_SLINGSHOT_SWITCH_GPIO_Port GPIOC
#define RIGHT_SLINGSHOT_SWITCH_Pin GPIO_PIN_3
#define RIGHT_SLINGSHOT_SWITCH_GPIO_Port GPIOC
#define BUMPER1_SWITCH_Pin GPIO_PIN_0
#define BUMPER1_SWITCH_GPIO_Port GPIOA
#define BUMPER2_SWITCH_Pin GPIO_PIN_1
#define BUMPER2_SWITCH_GPIO_Port GPIOA
#define USART_TX_Pin GPIO_PIN_2
#define USART_TX_GPIO_Port GPIOA
#define USART_RX_Pin GPIO_PIN_3
#define USART_RX_GPIO_Port GPIOA
#define BUMPER3_SWITCH_Pin GPIO_PIN_4
#define BUMPER3_SWITCH_GPIO_Port GPIOA
#define L2_Pin GPIO_PIN_5
#define L2_GPIO_Port GPIOA
#define LIGHTBARRIER1_Pin GPIO_PIN_5
#define LIGHTBARRIER1_GPIO_Port GPIOC
#define BALLSHOOTER_SWITCH_Pin GPIO_PIN_0
#define BALLSHOOTER_SWITCH_GPIO_Port GPIOB
#define KICKHOLE_COIL_Pin GPIO_PIN_1
#define KICKHOLE_COIL_GPIO_Port GPIOB
#define TARGET1_Pin GPIO_PIN_2
#define TARGET1_GPIO_Port GPIOB
#define TARGET2_Pin GPIO_PIN_11
#define TARGET2_GPIO_Port GPIOB
#define TARGET3_Pin GPIO_PIN_12
#define TARGET3_GPIO_Port GPIOB
#define BUMPER1_COIL_Pin GPIO_PIN_13
#define BUMPER1_COIL_GPIO_Port GPIOB
#define BUMPER3_COIL_Pin GPIO_PIN_15
#define BUMPER3_COIL_GPIO_Port GPIOB
#define LIGHTBARRIER2_Pin GPIO_PIN_6
#define LIGHTBARRIER2_GPIO_Port GPIOC
#define LIGHTBARRIER3_Pin GPIO_PIN_8
#define LIGHTBARRIER3_GPIO_Port GPIOC
#define LIGHTBARRIER4_Pin GPIO_PIN_9
#define LIGHTBARRIER4_GPIO_Port GPIOC
#define RIGHT_KICKER_HOLD_COIL_Pin GPIO_PIN_8
#define RIGHT_KICKER_HOLD_COIL_GPIO_Port GPIOA
#define LEFT_KICKER_HOLD_COIL_Pin GPIO_PIN_9
#define LEFT_KICKER_HOLD_COIL_GPIO_Port GPIOA
#define BUMPER2_COIL_Pin GPIO_PIN_10
#define BUMPER2_COIL_GPIO_Port GPIOA
#define LIGHTBARRIER7_Pin GPIO_PIN_11
#define LIGHTBARRIER7_GPIO_Port GPIOA
#define LIGTHBARRIER8_Pin GPIO_PIN_12
#define LIGTHBARRIER8_GPIO_Port GPIOA
#define TMS_Pin GPIO_PIN_13
#define TMS_GPIO_Port GPIOA
#define TCK_Pin GPIO_PIN_14
#define TCK_GPIO_Port GPIOA
#define BALLSHOOTER_COIL_Pin GPIO_PIN_15
#define BALLSHOOTER_COIL_GPIO_Port GPIOA
#define LEFT_KICKER_COIL_Pin GPIO_PIN_10
#define LEFT_KICKER_COIL_GPIO_Port GPIOC
#define RIGHT_KICKER_COIL_Pin GPIO_PIN_11
#define RIGHT_KICKER_COIL_GPIO_Port GPIOC
#define RIGHT_SLINGSHOT_COIL_Pin GPIO_PIN_12
#define RIGHT_SLINGSHOT_COIL_GPIO_Port GPIOC
#define LEFT_SLINGSHOT_COIL_Pin GPIO_PIN_2
#define LEFT_SLINGSHOT_COIL_GPIO_Port GPIOD
#define MAGAZIN_COIL_Pin GPIO_PIN_4
#define MAGAZIN_COIL_GPIO_Port GPIOB
#define MAGAZIN_SWITCH_Pin GPIO_PIN_5
#define MAGAZIN_SWITCH_GPIO_Port GPIOB
#define LIGHTBARRIER5_Pin GPIO_PIN_8
#define LIGHTBARRIER5_GPIO_Port GPIOB
#define LIGHTBARRIER6_Pin GPIO_PIN_9
#define LIGHTBARRIER6_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
