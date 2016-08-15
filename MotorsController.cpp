/*
 * Date: 11/4/2016
 * Writter: Loc Pham
 * Module: Motor
 * Description: This file contain function implementations for motors controller
 */

#include "MotorsController.h"
#include "Common.h"

void motors_controller_struct_init(motors_controller_t* controller)
{
    motor_struct_init(&(controller->motor_left));
    motor_struct_init(&(controller->motor_right));

    pin_speed_struct_init(&(controller->pin_speed_left));
    pin_speed_struct_init(&(controller->pin_speed_right));
}

void motors_controller_initialize(motors_controller_t* controller)
{
    motor_initialize(&(controller->motor_left));
    motor_initialize(&(controller->motor_right));

    pin_speed_initialize(&(controller->pin_speed_left));
    pin_speed_initialize(&(controller->pin_speed_right));
}

void motors_controller_set_speed(motors_controller_t* controller, uint8_t value_set)
{
    pin_speed_set_speed(&(controller->pin_speed_left), value_set);
    pin_speed_set_speed(&(controller->pin_speed_right), value_set);
}

void motors_controller_set_speed_percentage(motors_controller_t* controller, uint8_t percentage)
{
    pin_speed_set_speed_percentage(&(controller->pin_speed_left), percentage);
    pin_speed_set_speed_percentage(&(controller->pin_speed_right), percentage);
}

void motors_controller_inc_speed(motors_controller_t* controller, uint8_t value_set)
{
    pin_speed_inc_speed(&(controller->pin_speed_left), value_set);
    pin_speed_inc_speed(&(controller->pin_speed_right), value_set);
}

void motors_controller_inc_speed_percentage(motors_controller_t* controller, uint8_t percentage)
{
    pin_speed_inc_speed_percentage(&(controller->pin_speed_left), percentage);
    pin_speed_inc_speed_percentage(&(controller->pin_speed_right), percentage);
}

void motors_controller_dec_speed(motors_controller_t* controller, uint8_t value_set)
{
    pin_speed_dec_speed(&(controller->pin_speed_left), value_set);
    pin_speed_dec_speed(&(controller->pin_speed_right), value_set);
}

void motors_controller_dec_speed_percentage(motors_controller_t* controller, uint8_t percentage)
{
    pin_speed_dec_speed_percentage(&(controller->pin_speed_left), percentage);
    pin_speed_dec_speed_percentage(&(controller->pin_speed_right), percentage);
}

void motors_controller_brake(motors_controller_t* controller)
{
    motor_brake(&(controller->motor_left));
    motor_brake(&(controller->motor_right));
}

void motors_controller_forward(motors_controller_t* controller)
{
    motor_turn_forward(&(controller->motor_left));
    motor_turn_forward(&(controller->motor_right));
}

void motors_controller_backward(motors_controller_t* controller)
{
    motor_turn_backward(&(controller->motor_left));
    motor_turn_backward(&(controller->motor_right));
}

void motors_controller_turn_left(motors_controller_t* controller)
{
    motor_turn_backward(&(controller->motor_left));
    motor_turn_forward(&(controller->motor_right));
}

void motors_controller_turn_right(motors_controller_t* controller)
{
    motor_turn_forward(&(controller->motor_left));
    motor_turn_backward(&(controller->motor_right));
}

