/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This file contains function drclarations and macros for bluetooth robots
 */

#ifndef _BLUETOOTH_ROBOT_H_
#define _BLUETOOTH_ROBOT_H_

// Include header files
#include "MotorsController.h"
#include "Ultrasonic.h"
#include "Bluetooth.h"
#include "KeyBinding.h"

// Macro definitions
#define PIN_LED                     13
#define DISTANCE_CM                 35
#define SPEED_INTERVAL_PERCENTAGE   5

#define LEFT_MOTOR_PIN_ONE          2
#define LEFT_MOTOR_PIN_TWO          3

#define RIGHT_MOTOR_PIN_ONE         4
#define RIGHT_MOTOR_PIN_TWO         5

#define LEFT_MOTOR_PIN_SPEED        A1
#define RIGHT_MOTOR_PIN_SPEED       A0
#define MOTOR_SPEED_PWM_VALUE       MAX_UINT8

#define ULTRASONIC_TRIGGER_PIN      8
#define ULTRASONIC_ECHO_PIN         9

#define BLUETOOTH_TX_PIN            7
#define BLUETOOTH_RX_PIN            6
#define BLUETOOTH_BAUDRATE          DEFAULT_BAUDRATE

#define KEY_BINDING_UP              DEFAULT_KEY_UP
#define KEY_BINDING_DOWN            DEFAULT_KEY_DOWN
#define KEY_BINDING_LEFT            DEFAULT_KEY_LEFT
#define KEY_BINDING_RIGHT           DEFAULT_KEY_RIGHT
#define KEY_BINDING_AUTO            DEFAULT_KEY_AUTO
#define KEY_BINDING_BRAKE           DEFAULT_KEY_BRAKE
#define KEY_BINDING_SPEED_INC       DEFAULT_KEY_SPEED_INC
#define KEY_BINDING_SPEED_DEC       DEFAULT_KEY_SPEED_DEC

// Struct definitions
typedef enum
{
    STATE_AUTO,
    STATE_MANUAL
} state_t;

typedef struct
{
    motors_controller_t motors_controller;
    ultrasonic_t ultrasonic;
    bluetooth_t bluetooth;
    key_binding_t key_binding;
    state_t state;
} bluetooth_robot_t;

// Function declarations
void bluetooth_robot_struct_init(bluetooth_robot_t* robot);
void bluetooth_robot_initialize(bluetooth_robot_t* robot);

void bluetooth_robot_run_auto(bluetooth_robot_t* robot);
void bluetooth_robot_run_manual(bluetooth_robot_t* robot);
void bluetooth_robot_run(bluetooth_robot_t* robot);

void bluetooth_robot_set_state(bluetooth_robot_t* robot, state_t state_new);

#endif

