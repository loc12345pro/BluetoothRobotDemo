/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This file contains structs and macros for motor controller L298N
 */

#ifndef MOTORS_CONTROLLER_H_
#define MOTORS_CONTROLLER_H_

// Include header files
#include "Motor.h"
#include "SpeedPin.h"

// Struct definitions
typedef struct
{
     motor_t motor_left;
     motor_t motor_right;
     pin_speed_t pin_speed_left;
     pin_speed_t pin_speed_right;
} motors_controller_t;

// Function declarations
void motors_controller_struct_init(motors_controller_t* controller);
void motors_controller_initialize(motors_controller_t* controller);

void motors_controller_set_speed(motors_controller_t* controller, uint8_t value_set);
void motors_controller_set_speed_percentage(motors_controller_t* controller, uint8_t percentage);

void motors_controller_inc_speed(motors_controller_t* controller, uint8_t value_set);
void motors_controller_inc_speed_percentage(motors_controller_t* controller, uint8_t percentage);

void motors_controller_dec_speed(motors_controller_t* controller, uint8_t value_set);
void motors_controller_dec_speed_percentage(motors_controller_t* controller, uint8_t percentage);

void motors_controller_brake(motors_controller_t* controller);

void motors_controller_forward(motors_controller_t* controller);
void motors_controller_backward(motors_controller_t* controller);

void motors_controller_turn_left(motors_controller_t* controller);
void motors_controller_turn_right(motors_controller_t* controller);

#endif
