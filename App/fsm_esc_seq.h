/**
 * @file fsm_esc_seq.h
 * @author simakeng (simakeng@outlook.com)
 * @brief State machine for match escape sequence
 * @version 0.1
 * @date 2023-10-26
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <stdbool.h>
#include <stdint.h>

#include "fsm.h"

#ifndef __FSM_ESC_SEQ_H__
#define __FSM_ESC_SEQ_H__

typedef enum
{
    ESC_SEQ_MOVE_LEFT = 'C',
    ESC_SEQ_MOVE_RIGHT = 'D',
    ESC_SEQ_MOVE_UP = 'A',
    ESC_SEQ_MOVE_DOWN = 'B',
    ESC_SEQ_UNKONWN,   // Unknown escape sequence
} esc_seq_t;

/**
 * @brief Init state machine
 *
 * @return int
 */
void fsm_esc_init(void);

/**
 * @brief Input data to state machine
 *
 * @param data
 * @return int
 */
fsm_state_t fsm_esc_input(uint32_t data);

/**
 * @brief Get result of a match
 *
 * @return esc_seq_t
 */
esc_seq_t fsm_esc_get_result(void);

/**
 * @brief Reset state machine to idle
 */
void fsm_esc_reset(void);

#endif // ! #ifndef __FSM_ESC_SEQ_H__
