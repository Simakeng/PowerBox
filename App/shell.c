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
#include <usart.h>
#include <string.h>

#include <fsm_esc_seq.h>

// status flags
volatile struct {
    uint32_t cursor_pos;
    uint32_t input_len;

    // statmachine flags
    uint32_t esc_match_state;
    uint32_t utf8_match_state;
    
    char input_buf[256];
} shell;

void shell_print(const char* fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    dbg_vprint(fmt, ap);
    va_end(ap);
}

#define shell_putc(ch) dbg_putc(ch)

void shell_print_hello_information(void)
{
    shell_print(LOGO_ART_STRING);
    shell_print("\n");
    shell_print("PowerBox Version " APP_VERSION_VERSION "\n");
    shell_print("\n");
    shell_print("build id: " APP_VERSION_STRING "\n");
    shell_print("url     : " APP_VERSION_GIT_REMOTE_URL "\n");
    shell_print("branch  : " APP_VERSION_GIT_REMOTE_BRANCH "\n");
    shell_print("\n");
}

void shell_init(void)
{
    memset((void*)&shell, 0, sizeof(shell));

    shell_print("shell > ");
}

void shell_input_process_escape_seq(void)
{
    esc_seq_t seq = fsm_esc_get_result();
    fsm_esc_reset();
    return;
}

void shell_input_callback(uint32_t data, uint32_t flag)
{
    if(flag == INPUT_FLAG_END)
        return;

    switch (fsm_esc_input(data))
    {
    case FSM_STATE_ACCEPT:
        shell_input_process_escape_seq();
    case FSM_STATE_MATCH:
        return;
    case FSM_STATE_ERROR:
    default:
        fsm_esc_reset();
        break;
    } 

}