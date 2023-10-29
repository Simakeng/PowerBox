/**
 * @file fsm.h
 * @author simakeng (simakeng@outlook.com)
 * @brief Finite state machine common defs
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef __FSM_H__
#define __FSM_H__

typedef enum
{
    FSM_STATE_IDLE = 0,
    FSM_STATE_MATCH,
    FSM_STATE_ACCEPT,
    FSM_STATE_ERROR,
} fsm_state_t;


#endif // ! #ifndef __FSM_H__
