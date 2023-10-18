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
#include "stm32g0xx_hal.h"

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
#define DBG_UART1_RX_Pin GPIO_PIN_7
#define DBG_UART1_RX_GPIO_Port GPIOB
#define IO_SPI_SCLK_Pin GPIO_PIN_0
#define IO_SPI_SCLK_GPIO_Port GPIOA
#define IO_OE_Pin GPIO_PIN_1
#define IO_OE_GPIO_Port GPIOA
#define MET_MCU_UART_TX_Pin GPIO_PIN_2
#define MET_MCU_UART_TX_GPIO_Port GPIOA
#define MET_MCU_UART_RX_Pin GPIO_PIN_3
#define MET_MCU_UART_RX_GPIO_Port GPIOA
#define IO_SPI_MOSI_Pin GPIO_PIN_4
#define IO_SPI_MOSI_GPIO_Port GPIOA
#define IO_LATCH_Pin GPIO_PIN_5
#define IO_LATCH_GPIO_Port GPIOA
#define ADC_IN_Pin GPIO_PIN_7
#define ADC_IN_GPIO_Port GPIOA
#define DBG_UART_CTS_Pin GPIO_PIN_11
#define DBG_UART_CTS_GPIO_Port GPIOA
#define DBG_UART_RTS_Pin GPIO_PIN_12
#define DBG_UART_RTS_GPIO_Port GPIOA
#define DBG_UART1_TX_Pin GPIO_PIN_6
#define DBG_UART1_TX_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
