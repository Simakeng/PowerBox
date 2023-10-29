/**
 * @file fsm_text.c
 * @author simakeng (simakeng@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-10-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string.h>
#include "fsm_text.h"

typedef enum
{
    TEXT_BEGIN,
    TEXT_MATCH,
    TEXT_ACCEPT,
} text_fsm_state_t;

volatile struct
{
    text_fsm_state_t state;
    char buffer[8];
    uint32_t buffer_len;
    uint32_t utf8_begin_length;
} fsm_text;

void fsm_text_init(void)
{
    fsm_text_reset();
}

fsm_state_t fsm_text_process_begin(uint32_t data);
fsm_state_t fsm_text_process_match(uint32_t data);

/**
 * @brief fsm jump table rule for TEXT_BEGIN
 *
 * @param data
 * @return fsm_state_t
 */
fsm_state_t fsm_text_process_begin(uint32_t data)
{
    char *text_buffer = fsm_text.buffer;
    if (data < 0x80)
    {
        *text_buffer = data;
        fsm_text.state = TEXT_ACCEPT;
        return FSM_STATE_ACCEPT;
    }
    else if (data & 0xE0 == 0xC0) // 2 byte UTF-8
    {
        fsm_text.utf8_begin_length = 2;
        goto fms_utf8_match;
    }
    else if (data & 0xF0 == 0xE0) // 3 byte UTF-8
    {
        fsm_text.utf8_begin_length = 3;
        goto fms_utf8_match;
    }
    else if (data & 0xF8 == 0xF0) // 4 byte UTF-8
    {
        fsm_text.utf8_begin_length = 4;
        goto fms_utf8_match;
    }
    else if (data & 0xFC == 0xF8) // 5 byte UTF-8
    {
        fsm_text.utf8_begin_length = 5;
        goto fms_utf8_match;
    }
    else if (data & 0xFE == 0xFC) // 6 byte UTF-8
    {
        fsm_text.utf8_begin_length = 6;
        goto fms_utf8_match;
    }
    else
    {
        return FSM_STATE_ERROR;
    }

fms_utf8_match:
    *text_buffer = data;
    return FSM_STATE_MATCH;
}


fsm_state_t fsm_text_process_match(uint32_t data)
{
    char *text_buffer = fsm_text.buffer;
    uint32_t buffer_len = fsm_text.buffer_len;
    if (data & 0xC0 == 0x80)
    {
        // add to buffer
        text_buffer[buffer_len] = data;

        // inc buffer len
        fsm_text.buffer_len++;

        // if eq with utf8_begin_length
        if (fsm_text.utf8_begin_length == fsm_text.buffer_len)
        {
            fsm_text.state = TEXT_ACCEPT;
            return FSM_STATE_ACCEPT;
        }
        else
        {
            return FSM_STATE_MATCH;
        }
    }
    else
    {
        return FSM_STATE_ERROR;
    }
}

fsm_state_t fsm_text_input(uint32_t data)
{
    switch (fsm_text.state)
    {
    case TEXT_BEGIN:
        return fsm_text_process_begin(data);
    case TEXT_MATCH:
        return fsm_text_process_match(data);
    default:
        return FSM_STATE_ERROR;
    }
}

const char* fsm_text_get_result(void)
{
    return fsm_text.buffer;
}


void fsm_text_reset(void)
{
    memset((void *)&fsm_text, 0, sizeof(fsm_text));
}