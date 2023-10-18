/**
 * @file io_manager.h
 * @author simakeng (simakeng@outlook.com)
 * @brief 
 * @version 0.1
 * @date 2023-10-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <pins.h>
#include <stdint.h>

#ifndef __IO_MANAGER_H__
#define __IO_MANAGER_H__

/**
 * @brief Initialize the IO manager.
 * Will set all pins to default value (0).
 * @note This function will not affect the physical pin voltage level.
 * call io_update_pins() to update the physical pin.
 * @return void 
 */
void io_manager_init(void);

/**
 * @brief Set the pin value.
 * 
 * @param pin The pin number, please refer to pins.h.
 * @param value The value to set, 0 or !0.
 * @return void 
 */
void io_set_pin(int32_t pin, int32_t value);

/**
 * @brief Get the pin value in the buffer
 * @note The return value is the bit value in the ram, not physical pin voltage level.
 * @param pin The pin number, please refer to pins.h.
 * @return int32_t the bit value in the ram, 0 or 1.
 */
int32_t io_get_pin(int32_t pin);


/**
 * @brief Handler for pins update event.
 * 
 * @param bytes The bytes of the buffer.
 * @param buffer The buffer.
 */
typedef void (*pins_update_handler_t)(int32_t bytes, const uint8_t* buffer);

/**
 * @brief Use this function to initiate the pins update event.
 * 
 * @param handler The handler function, refer to pins_update_handler_t.
 * 
 * @see pins_update_handler_t.
 */
void io_update_pins(pins_update_handler_t handler);

#endif // ! __IO_MANAGER_H__