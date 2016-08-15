/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Ultrasonic
 * Description: This file contain function implementations for ultrasonic HR-SC04
 */

#include "Ultrasonic.h"
#include "Common.h"
#include <Arduino.h>

void ultrasonic_struct_init(ultrasonic_t* ultra)
{
    if (ultra != NULL)
    {
        ultra->echo_pin = UNKNOWN_PIN;
        ultra->trig_pin = UNKNOWN_PIN;
    }
}

void ultrasonic_initialize(ultrasonic_t* ultra)
{
    if (ultra != NULL)
    {
        pinMode(ultra->echo_pin, INPUT);
        pinMode(ultra->trig_pin, OUTPUT);
    }
}

uint32_t ultrasonic_timing(ultrasonic_t* ultra)
{
    // Preparations
    uint32_t timing = 0;

    if (ultra != NULL)
    {
        // Trig of SR04 must receive a pulse of high (5V) for at least 10us
        digitalWrite(ultra->trig_pin, HIGH);
        delayMicroseconds(TRIGGER_TIME_US);
        digitalWrite(ultra->trig_pin, LOW);
    
        // When the sensor detected ultrasonic from receiver, 
        // it will set the Echo pin to high (5V) and delay for a period (width) which proportion to distance.
        timing = pulseIn(ultra->echo_pin, HIGH);
    }

    return timing;
}

float ultrasonic_ranging_cm(ultrasonic_t* ultra)
{
    float range = 0;
    if (ultra != NULL)
    {
        range = 1.0 * ultrasonic_timing(ultra) / CENTIMETER_UNIT;
    }

    return range;
}

float ultrasonic_ranging_inch(ultrasonic_t* ultra)
{
    float range = 0;
    if (ultra != NULL)
    {
        range = 1.0 * ultrasonic_timing(ultra) / INCH_UNIT;
    }

    return range;
}
