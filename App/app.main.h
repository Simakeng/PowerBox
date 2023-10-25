/**
 * @file app.main.h
 * @author simakeng (simakeng@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef __APP_MAIN_H__
#define __APP_MAIN_H__


typedef struct
{
    // script flags
    struct
    {
        int eval_timeout : 1;
    } script;

    // shell flags
    struct 
    {
        int input_complete : 1;
        int input_overflow : 1;
        int non_printable_char_detected : 1;
    } shell;

} control_flags_t;

int app_main(void);

#endif // ! __APP_MAIN_H__