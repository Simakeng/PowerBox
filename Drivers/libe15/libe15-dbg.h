/**
 * @file libe15-dbg.h
 * @author Simakeng (simakeng@outlook.com)
 * @brief Debugging functions
 * @version 0.1
 * @date 2023-04-10
 * @see https://github.com/simakeng/libe15
 * @copyright Copyright (c) 2023
 *
 */

#include <stdint.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef __LIBE15_DBG_H__
#define __LIBE15_DBG_H__

// If you want to disable all the debug messages,
// uncomment the line below this will save you some ROM space
// #define CONFIG_OMIT_MESSAGE 1

// If you dont want to print the location of the function call
// uncomment the line below
// #define CONFIG_OMIT_LOCATION 1

// uncomment this if you want to print the full path of the file
// #define CONFIG_LOCATION_FULLNAME

// if you dont want to print the function name
// uncomment the line below
// #define CONFIG_OMIT_FUNCTION_NAME 1


#define COLOR_RESET "\033[0m"
#define COLOR_RED "\033[31m"
#define COLOR_DARKGREEN "\033[32m"
#define COLOR_YELLOW "\033[33m"
#define COLOR_BLUE "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN "\033[36m"
#define COLOR_GRAY "\033[37m"
#define COLOR_PINK "\033[91m"
#define COLOR_GREEN "\033[92m"
#define COLOR_BEIGE "\033[93m"
#define COLOR_ROYALBLUE "\033[94m"
#define COLOR_PURPLE "\033[95m"
#define COLOR_TEAL "\033[96m"
#define COLOR_WHITE "\033[97m"

// if you want to print the message with color
// uncomment the line below
#define CONFIG_DEBUG_COLOR 1

// if you dont want to print the message level
// uncomment the line below
// #define CONFIG_OMIT_LEVEL 1

#define LDEBUG 0
#define LINFO 1
#define LWARN 2
#define LERROR 3
#define LFATAL 4

// if you want to surpress certain level of message
// uncomment the line below and set the level
// only message with level higher than the level set will be printed
#define CONFIG_PRINT_LEVEL -1

#ifdef __cplusplus
extern "C"
{
#endif // ! #ifdef __cplusplus

    typedef struct
    {
        /**
         * @brief put a char into an output device
         * @param ch ASCII char code
         * @return int32_t ch: success, EOF: failure
         */
        int32_t (*putc)(int32_t ch);
        /**
         * @brief put a string into an output device
         * default behaviour is call dev_putc on each char
         * @param s The string to print
         * @return int32_t num of char puted, EOF: failure
         * @note The string is encoded in UTF-8
         */
        int32_t (*puts)(const char *s);
    } dbg_low_level_io_ops_t;

    /**
     * @brief Initialize the debug print function
     *
     * @param ops low level io functions
     */
    void dbg_print_init(dbg_low_level_io_ops_t *ops);

    /**
     * @brief Print an error message
     * @param level The level of the message
     * @param location The location where this function is called
     * @param function The function name of the caller function
     * @param msg The message to print
     * @param ... The arguments to the message
     */
    void dbg_print(int32_t level, const char *location, const char *function, const char *msg, ...);

    /**
     * @brief Print an message using given va_list
     * 
     * @param msg The fmt message
     * @param ap The arguments to the message
     */
    void dbg_vprint(const char *msg, va_list ap);
#ifdef __cplusplus
}
#endif // ! #ifdef __cplusplus

#define DBG_TRANSLATE_LINE(line) #line

#define DBG_TRANSLATE_LOCATION(file, line) file ":" DBG_TRANSLATE_LINE(line)

#if defined(CONFIG_OMIT_LEVEL)

#endif // ! #if defined(CONFIG_OMIT_LEVEL)

/************************************
 * @brief Debug level debug message
 ************************************/
#if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LDEBUG)
#define dbg_print_LDEBUG(level, location, function, msg, ...) ((void)0)
#else
#define dbg_print_LDEBUG(level, location, function, msg, ...) dbg_print(level, location, function, msg, ##__VA_ARGS__)
#endif // #if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LDEBUG)

/************************************
 * @brief Info level debug message
 ************************************/
#if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LINFO)
#define dbg_print_LINFO(level, location, function, msg, ...) ((void)0)
#else
#define dbg_print_LINFO(level, location, function, msg, ...) dbg_print(level, location, function, msg, ##__VA_ARGS__)
#endif // #if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LINFO)

/************************************
 * @brief Info level debug message
 ************************************/
#if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LWARN)
#define dbg_print_LWARN(level, location, function, msg, ...) ((void)0)
#else
#define dbg_print_LWARN(level, location, function, msg, ...) dbg_print(level, location, function, msg, ##__VA_ARGS__)
#endif // #if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LWARN)

/************************************
 * @brief Info level debug message
 ************************************/
#if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LERROR)
#define dbg_print_LERROR(level, location, function, msg, ...) ((void)0)
#else
#define dbg_print_LERROR(level, location, function, msg, ...) dbg_print(level, location, function, msg, ##__VA_ARGS__)
#endif // #if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LERROR)

/************************************
 * @brief Fatal level debug message
 ************************************/
#if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LFATAL)
#define dbg_print_LFATAL(level, location, function, msg, ...) ((void)0)
#else
#define dbg_print_LFATAL(level, location, function, msg, ...) dbg_print(level, location, function, msg, ##__VA_ARGS__)
#endif // #if defined(CONFIG_OMIT_LEVEL) && (CONFIG_OMIT_LEVEL >= LFATAL)

#ifdef CONFIG_OMIT_MESSAGE
#define print(level, ...) ((void)0)
#else
#define print(level, ...) dbg_print_##level(level, DBG_TRANSLATE_LOCATION(__FILE__, __LINE__), __FUNCTION__, __VA_ARGS__)
#endif

#endif // ! #ifndef __LIBE15_DBG_H__
