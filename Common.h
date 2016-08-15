/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This file contains maros and common struct for program
 */

#ifndef COMMON_H_
#define COMMON_H_

// Include header
#include <stdlib.h>
#include <stdint-gcc.h>

// Define macros
#define UNKNOWN_PIN 255

#define MAX_PERCENTAGE 100
#define MIN_PERCENTAGE 0

#define MAX_UINT8 255
#define MIN_UINT8 0

uint8_t uint8_to_percentage(uint8_t value);
uint8_t percentage_to_uint8(uint8_t percentage);

#endif
