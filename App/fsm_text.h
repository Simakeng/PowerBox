/**
 * @file fsm_text.h
 * @author simakeng (simakeng@outlook.com)
 * @brief fin
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */ 

#include <stdbool.h>
#include <stdint.h>

#include "fsm.h"

#ifndef __FSM_TEXT_H__
#define __FSM_TEXT_H__

/**
 * @brief Init state machine
 *
 * @return int
 */
void fsm_text_init(void);

/**
 * @brief Input data to state machine
 *
 * @param data
 * @return int
 */
fsm_state_t fsm_text_input(uint32_t data);


const char* fsm_text_get_result(void);

/**
 * @brief Reset state machine to idle
 */
void fsm_text_reset(void);

#endif // ! #ifndef __FSM_TEXT_H__
