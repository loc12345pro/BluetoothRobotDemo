/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Motor
 * Description: This file contain function declarations also macros and data structures for 
 *  motor
 */

#ifndef _MOTOR_H
#define _MOTOR_H

#include <stdint-gcc.h>

typedef struct 
{
    uint8_t pin_one;
    uint8_t pin_two;
} motor_t;

void motor_struct_init(motor_t* motor);
void motor_initialize(motor_t* motor);
void motor_brake(motor_t* motor);
void motor_turn_forward(motor_t* motor);
void motor_turn_backward(motor_t* motor);

#endif
