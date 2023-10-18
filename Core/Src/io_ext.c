/**
 * @file io_ext.c
 * @author simakeng (simakeng@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-10-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <spi.h>
#include <main.h>
#include <io_ext.h>
#include <io_manager.h>

#define HAL_WritePin(PinName, value) HAL_GPIO_WritePin(PinName##_GPIO_Port, PinName##_Pin, (value != 0 ? GPIO_PIN_SET : GPIO_PIN_RESET));

void ioext_init()
{
    HAL_WritePin(IO_LATCH, 0);
    HAL_WritePin(IO_OE, 0);
    io_manager_init();

    // update buffer to 74HC595 chips
    io_update_pins(ioext_spi_update);

    // enable outputs
    HAL_WritePin(IO_OE, 1);
}

void ioext_spi_update(int32_t bytes, const uint8_t* buffer)
{
  HAL_StatusTypeDef hr = HAL_OK;

  hr = HAL_SPI_Transmit(&hspi2, (uint8_t*)buffer, bytes, 100);
  if (hr != HAL_OK)
    return;

  // the controller we use only runs in 64Mhz
  HAL_GPIO_WritePin(IO_LATCH_GPIO_Port, IO_LATCH_Pin, GPIO_PIN_RESET);
  HAL_GPIO_WritePin(IO_LATCH_GPIO_Port, IO_LATCH_Pin, GPIO_PIN_SET);
  __NOP(); // place a nop here to generate some delay
  HAL_GPIO_WritePin(IO_LATCH_GPIO_Port, IO_LATCH_Pin, GPIO_PIN_RESET);
  __NOP(); // place a nop here to generate some delay

}