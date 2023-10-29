/**
 * @file fsm_esc_seq.c
 * @author simakeng (simakeng@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-10-29
 *
 * @copyright Copyright (c) 2023
 *
 */
#include <string.h>

#include "fsm_esc_seq.h"
typedef enum
{
    ESC_SEQ_BEGIN,
    ESC_SEQ_CSI,
    ESC_SEQ_PARAM,
    ESC_SEQ_MATCH,
} esc_fsm_state_t;

volatile struct
{
    esc_fsm_state_t state;
    int32_t param;
    esc_seq_t result;
} fsm_esc_seq;

void fsm_esc_init(void)
{
    fsm_esc_reset();
}

fsm_state_t fsm_esc_process_begin(uint32_t data);
fsm_state_t fsm_esc_process_csi(uint32_t data);
fsm_state_t fsm_esc_process_param(uint32_t data);
fsm_state_t fsm_esc_process_match(uint32_t data);

/**
 * @brief fsm jump table rule for ESC_SEQ_BEGIN
 *
 * @param data
 * @return fsm_state_t
 */
fsm_state_t fsm_esc_process_begin(uint32_t data)
{
    if (data == 0x1B) // \033
    {
        fsm_esc_seq.state = ESC_SEQ_CSI;
        return FSM_STATE_MATCH;
    }
    else
    {
        return FSM_STATE_ERROR;
    }
}

/**
 * @brief fsm jump table rule for ESC_SEQ_CSI
 *
 * @param data
 * @return fsm_state_t
 */
fsm_state_t fsm_esc_process_csi(uint32_t data)
{
    if (data == 0x5B) // [
    {
        fsm_esc_seq.state = ESC_SEQ_PARAM;
        return FSM_STATE_MATCH;
    }
    else
    {
        return FSM_STATE_ERROR;
    }
}

/**
 * @brief fsm jump table rule for ESC_SEQ_PARAM
 *
 * @param data
 * @return fsm_state_t
 */
fsm_state_t fsm_esc_process_param(uint32_t data)
{
    if (data >= 0x30 && data <= 0x39) // 0-9
    {
        uint32_t data = data - 0x30;
        uint32_t value = fsm_esc_seq.param;
        value = value * 10 + data;
        fsm_esc_seq.param = value;
        fsm_esc_seq.state = ESC_SEQ_PARAM;
        return FSM_STATE_MATCH;
    }
    else // sometimes param is not present
    {
        return fsm_esc_process_match(data);
    }
}

/**
 * @brief 
 * 
 * @param data 
 * @return fsm_state_t 
 */
fsm_state_t fsm_esc_process_match(uint32_t data)
{
    if (data >= 'A' && data <= 'D')
    {
        fsm_esc_seq.result = data;
        fsm_esc_seq.state = ESC_SEQ_MATCH;
        return FSM_STATE_ACCEPT;
    }
    else
    {
        return FSM_STATE_ERROR;
    }
}

fsm_state_t fsm_esc_input(uint32_t data)
{
    switch (fsm_esc_seq.state)
    {
    case ESC_SEQ_BEGIN:
        return fsm_esc_process_begin(data);
    case ESC_SEQ_CSI:
        return fsm_esc_process_csi(data);
    case ESC_SEQ_PARAM:
        return fsm_esc_process_param(data);
    case ESC_SEQ_MATCH:
        return fsm_esc_process_match(data);
    default:
        return FSM_STATE_ERROR;
    }
}

esc_seq_t fsm_esc_get_result(void)
{
    return fsm_esc_seq.result;
}

void fsm_esc_reset(void)
{
    memset(&fsm_esc_seq, 0, sizeof(fsm_esc_seq));
    fsm_esc_seq.result = ESC_SEQ_UNKONWN;
    fsm_esc_seq.state = ESC_SEQ_BEGIN;
}
