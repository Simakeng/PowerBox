/**
 * @file shell.h
 * @author simakeng (simakeng@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-16
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <stdint.h>

#ifndef __SHELL_H__
#define __SHELL_H__

/**
 * @brief print hello information
 * 
 */
void shell_print_hello_information(void);

/**
 * @brief print to debug console
 * 
 * @arg fmt format string
 * @arg ... variable arguments
 */
void shell_print(const char* fmt, ...);

/**
 * @brief initialize shell
 * 
 */
void shell_init(void);

enum
{
  INPUT_FLAG_FIRST, // `data` is the first byte rxed
  INPUT_FLAG_RECV,  // normal rx on going
  INPUT_FLAG_END,   // `data` is invalid, and no more data will be rxed
};

/**
 * @brief callback function for input
 * 
 * @param data input data
 * @param flag see enum above
 */
void shell_input_callback(uint32_t data, uint32_t flag);

#endif // __SHELL_H__
