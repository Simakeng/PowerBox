/**
 * @file app.main.c
 * @author simakeng (simakeng@outlook.com)
 * @brief The main application file
 * @version 0.1
 * @date 2023-10-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "app.main.h"

#include <stdbool.h>

#include <io_manager.h>

// all system flags
volatile control_flags_t flags = { 0 };

int app_main()
{
    shell_print_hello_information();
    while (true)
    {
        if (flags.script.eval_timeout)
        {
            // eval_control_script();
        }

        if (flags.shell.input_complete)
        {
            // process_shell_input();
        }
    }
}
