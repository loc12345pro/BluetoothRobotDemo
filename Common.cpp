/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This file contains common function definitions
 */

#include "Common.h"
#include <Arduino.h>

uint8_t uint8_to_percentage(uint8_t value)
{
    return (MAX_PERCENTAGE * value) / MAX_UINT8;
}

uint8_t percentage_to_uint8(uint8_t percentage)
{
    return (MAX_UINT8 * percentage) / MAX_PERCENTAGE;
}
