/**
 * @file pins.h
 * @author simakeng (simakeng@outlook.com)
 * @brief Pins configuration file
 * @version 0.1
 * @date 2023-10-18
 * 
 * @copyright Copyright (c) 2023
 * 
 */


#ifndef __PINS_H__
#define __PINS_H__

enum
{
    //* 74HC595 chip 0
    // no use in postion 0
    // no use in postion 1
    IO_VEN_VV1 = 2,
    IO_VEN_VV2,
    IO_VEN_VV3,
    IO_VEN_12V1,
    IO_VEN_12V2,
    IO_VEN_12V3,

    //* 74HC595 chip 1
    AC_CH1_RLY_KEEP = 8,
    IO_ISEN_MUX_SEL_D,
    IO_ISEN_MUX_SEL_C,
    IO_ISEN_MUX_SEL_B,
    IO_ISEN_MUX_SEL_A,
    IO_AC_CH1_RLY_ACTION,
    IO_AC_CH2_RLY_KEEP,
    IO_AC_CH2_RLY_ACTION,

    //* 74HC595 chip 2
    IO_AC_CH3_RLY_KEEP = 16,
    IO_MCU_MET_SEL_B,
    IO_MCU_MET_SEL_A,
    // no use in postion 19
    IO_AC_CH4_RLY_ACTION = 20,
    IO_AC_CH4_RLY_KEEP,
    // no use in postion 22
    // no use in postion 23
};


#define IO_EXT_CNT 24
#define IO_EXT_BUFFER_SIZE (IO_EXT_CNT / 8)


#endif // ! __PINS_H__