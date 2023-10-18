/**
 * @file shell.c
 * @author simakeng (simakeng@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-10-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "shell.h"
#include <Version.h>
#include <logo.h>
#include <libe15-dbg.h>

void shell_print(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    dbg_vprintf(fmt, ap);
    va_end(ap);
}

void shell_print_hello_information()
{
    shell_print(LOGO_ART_STRING);
    shell_print("\n");
    shell_print("PowerBox Version " APP_VERSION_VERSION "\n");
    shell_print("\n");
    shell_print(APP_VERSION_STRING "\n");
    shell_print("url: " APP_VERSION_GIT_REMOTE_URL "\n");
    shell_print("at: " APP_VERSION_GIT_REMOTE_BRANCH "\n");
}