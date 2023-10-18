/**
 * @file io_ext.h
 * @author simakeng (simakeng@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdint.h>

#ifndef __IO_EXT_H__
#define __IO_EXT_H__

/**
 * @brief Initialize the IO extender
 * 
 */
void ioext_init();

/**
 * @brief Update the IO extender buffer to the device
 * 
 * @param bytes The bytes of the buffer.
 * @param buffer The buffer.
 */
void ioext_spi_update(int32_t bytes, const uint8_t* buffer);

#endif // ! __IO_EXT_H__