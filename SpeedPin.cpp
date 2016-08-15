/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This files contains function definition for speed pins
 */

// Include headers
#include "SpeedPin.h"
#include <Arduino.h>

void pin_speed_struct_init(pin_speed_t* pin_speed)
{
    if (pin_speed != NULL)
    {
        pin_speed->pin = UNKNOWN_PIN;
        pin_speed->pwm_value = DEFAULT_SPEED;
    }
}

void pin_speed_initialize(pin_speed_t* pin_speed)
{
    if (pin_speed != NULL)
    {
        pinMode(pin_speed->pin, OUTPUT);
        analogWrite(pin_speed->pin, MAX_UINT8);
    }
}

void pin_speed_set_speed(pin_speed_t* pin_speed, uint8_t value_set)
{
    if (pin_speed != NULL)
    {        
        pin_speed->pwm_value = value_set;
        analogWrite(pin_speed->pin, value_set);
    }
}

void pin_speed_set_speed_percentage(pin_speed_t* pin_speed, uint8_t percentage)
{
    if (percentage >= MIN_PERCENTAGE && percentage <= MAX_PERCENTAGE)
    {
        // Convert percentage to a value between 0 to 255
        uint8_t value_set = percentage_to_uint8(percentage);
    
        // Then call pin_speed_set_speed to make changes
        pin_speed_set_speed(pin_speed, value_set);
    }
}

void pin_speed_inc_speed(pin_speed_t* pin_speed, uint8_t value_set)
{
    pin_speed_set_speed(pin_speed, pin_speed->pwm_value + value_set);
}

void pin_speed_inc_speed_percentage(pin_speed_t* pin_speed, uint8_t percentage)
{
    uint8_t new_percentage = uint8_to_percentage(pin_speed->pwm_value) + percentage; 
    pin_speed_set_speed_percentage(pin_speed, new_percentage);
}

void pin_speed_dec_speed(pin_speed_t* pin_speed, uint8_t value_set)
{
    pin_speed_set_speed(pin_speed, pin_speed->pwm_value - value_set);
}

void pin_speed_dec_speed_percentage(pin_speed_t* pin_speed, uint8_t percentage)
{
    uint8_t new_percentage = uint8_to_percentage(pin_speed->pwm_value) - percentage;
    pin_speed_set_speed_percentage(pin_speed, new_percentage);
    Serial.print("Decrease speed ");
    Serial.print("Current speed is: ");
    Serial.print(new_percentage);
    Serial.print(" - ");
    Serial.println(percentage_to_uint8(new_percentage));
}
