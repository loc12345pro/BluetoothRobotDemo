/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Motor
 * Description: This file contain function implementations for ultrasonic motor
 */

#include "Motor.h"
#include "Common.h"
#include <Arduino.h>

void motor_struct_init(motor_t* motor)
{
    if (motor != NULL)
    {
        motor->pin_one = UNKNOWN_PIN;
        motor->pin_two = UNKNOWN_PIN;
    }
}

void motor_initialize(motor_t* motor)
{
    if (motor != NULL)
    {
        pinMode(motor->pin_one, OUTPUT);
        pinMode(motor->pin_two, OUTPUT);
    }
}

void motor_brake(motor_t* motor)
{
    if (motor != NULL)
    {
        digitalWrite(motor->pin_one, LOW);
        digitalWrite(motor->pin_two, LOW);
    }
}

void motor_turn_forward(motor_t* motor)
{
    if (motor != NULL)
    {
        digitalWrite(motor->pin_one, HIGH);
        digitalWrite(motor->pin_two, LOW);
    }
}

void motor_turn_backward(motor_t* motor)
{
    if (motor != NULL)
    {
        digitalWrite(motor->pin_one, LOW);
        digitalWrite(motor->pin_two, HIGH);
    }
}
