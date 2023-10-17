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

#include <stdbool.h>

int app_main()
{
    shell_print_hello_information();
    while (true)
    {
        if (control_flags.control_script_eval)
        {
            eval_control_script();
        }

        if (control_flags.shell_input_complete)
        {
            process_shell_input();
        }
    }
}
