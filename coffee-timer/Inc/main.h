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
#include "stm32g4xx_hal.h"
#include "stm32g4xx_ll_pwr.h"

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

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */
void BUTTON1_IRQ_Callback();
void BUTTON2_IRQ_Callback();

void DACPlay(const uint8_t *samples, size_t size);

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define BUTTON1_Pin GPIO_PIN_0
#define BUTTON1_GPIO_Port GPIOA
#define BUTTON1_EXTI_IRQn EXTI0_IRQn
#define BUTTON2_Pin GPIO_PIN_1
#define BUTTON2_GPIO_Port GPIOA
#define BUTTON2_EXTI_IRQn EXTI1_IRQn
#define USART2_TX_Pin GPIO_PIN_2
#define USART2_TX_GPIO_Port GPIOA
#define USART2_RX_Pin GPIO_PIN_3
#define USART2_RX_GPIO_Port GPIOA
#define AUDIO_OUT_Pin GPIO_PIN_4
#define AUDIO_OUT_GPIO_Port GPIOA
#define BACKLIGHT_PWM_Pin GPIO_PIN_8
#define BACKLIGHT_PWM_GPIO_Port GPIOA
#define T_SWDIO_Pin GPIO_PIN_13
#define T_SWDIO_GPIO_Port GPIOA
#define T_SWCLK_Pin GPIO_PIN_14
#define T_SWCLK_GPIO_Port GPIOA
#define T_SWO_Pin GPIO_PIN_3
#define T_SWO_GPIO_Port GPIOB
#define TFT_CS_Pin GPIO_PIN_5
#define TFT_CS_GPIO_Port GPIOB
#define TFT_RST_Pin GPIO_PIN_6
#define TFT_RST_GPIO_Port GPIOB
#define TFT_DC_Pin GPIO_PIN_7
#define TFT_DC_GPIO_Port GPIOB
#define LD2_Pin GPIO_PIN_8
#define LD2_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
