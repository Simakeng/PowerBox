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

#ifndef __SHELL_H__
#define __SHELL_H__

/**
 * @brief print hello information
 * 
 */
void shell_print_hello_information();

/**
 * @brief print to debug console
 * 
 * @arg fmt format string
 * @arg ... variable arguments
 */
void shell_print(const char *fmt, ...);

#endif // __SHELL_H__
