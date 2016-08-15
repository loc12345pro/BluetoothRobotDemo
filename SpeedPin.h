/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This file contains function declarations and macros for speed pins
 */

#ifndef SPEED_PIN_H_
#define SPEED_PIN_H_

// Include headers
#include "Common.h"
#include <stdint-gcc.h>

// Macros definition
#define DEFAULT_SPEED_PERCENTAGE MAX_PERCENTAGE
#define DEFAULT_SPEED MAX_UINT8

// Struct definition
typedef struct
{
    uint8_t pin;
    uint8_t pwm_value;
} pin_speed_t;

// Function definition
void pin_speed_struct_init(pin_speed_t* pin_speed);
void pin_speed_initialize(pin_speed_t* pin_speed);

void pin_speed_set_speed(pin_speed_t* pin_speed, uint8_t value_set);
void pin_speed_set_speed_percentage(pin_speed_t* pin_speed, uint8_t percentage);

void pin_speed_inc_speed(pin_speed_t* pin_speed, uint8_t value_set);
void pin_speed_inc_speed_percentage(pin_speed_t* pin_speed, uint8_t percentage);

void pin_speed_dec_speed(pin_speed_t* pin_speed, uint8_t value_set);
void pin_speed_dec_speed_percentage(pin_speed_t* pin_speed, uint8_t percentage);

#endif
