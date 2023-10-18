/**
 * @file io_manager.c
 * @author simakeng (simakeng@outlook.com)
 * @brief
 * @version 0.1
 * @date 2023-10-18
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "io_manager.h"

struct
{
    uint8_t buffer[IO_EXT_BUFFER_SIZE];
} ioext;

void io_manager_init(void)
{
    for (int i = 0; i < IO_EXT_BUFFER_SIZE; i++)
    {
        ioext.buffer[i] = 0;
    }

    return;
}

void io_set_pin(int32_t pin, int32_t value)
{
    int32_t offset = pin / 8;
    int32_t bit = pin % 8;

    if (offset >= IO_EXT_BUFFER_SIZE)
    {
        return;
    }

    int32_t mask = 1 << bit;

    if (value)
    {
        ioext.buffer[offset] |= mask;
    }
    else
    {
        ioext.buffer[offset] &= ~mask;
    }

    return;
}

int32_t io_get_pin(int32_t pin)
{
    int32_t offset = pin / 8;
    int32_t bit = pin % 8;

    if (offset >= IO_EXT_BUFFER_SIZE)
    {
        return -1;
    }

    int32_t mask = 1 << bit;

    return (ioext.buffer[offset] & mask) ? 1 : 0;
}

void io_update_pins(pins_update_handler_t handler)
{
    handler(IO_EXT_BUFFER_SIZE, ioext.buffer);
}
