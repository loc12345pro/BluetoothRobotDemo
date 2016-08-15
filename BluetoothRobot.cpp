/*
 * Date: 11/04/2016 
 * Writter: Loc Pham
 * Description: This file contains function definition for bluetooth robot
 */

#include "BluetoothRobot.h"
#include <string.h>

void bluetooth_robot_struct_init(bluetooth_robot_t* robot)
{
    motors_controller_struct_init(&(robot->motors_controller));
    ultrasonic_struct_init(&(robot->ultrasonic));
    bluetooth_struct_init(&(robot->bluetooth));
    key_binding_struct_init(&(robot->key_binding));
    bluetooth_robot_set_state(robot, STATE_MANUAL);
}

void bluetooth_robot_initialize(bluetooth_robot_t* robot)
{
    motors_controller_initialize(&(robot->motors_controller));
    ultrasonic_initialize(&(robot->ultrasonic));
    bluetooth_initialize(&(robot->bluetooth));
    bluetooth_robot_set_state(robot, STATE_MANUAL);
}

void bluetooth_robot_run_auto(bluetooth_robot_t* robot)
{
    if (bluetooth_is_receive_data_empty(&(robot->bluetooth)) == false)
    {
        char recv_char = bluetooth_receive_character(&(robot->bluetooth));
        if (recv_char == (robot->key_binding).key_auto)
        {
            bluetooth_robot_set_state(robot, STATE_MANUAL);
            motors_controller_brake(&(robot->motors_controller));
        }
    }
    
    float calc_distance = ultrasonic_ranging_cm(&(robot->ultrasonic));
    if (calc_distance <= DISTANCE_CM)
    {
        digitalWrite(PIN_LED, HIGH);
        motors_controller_turn_right(&(robot->motors_controller));
    }
    else
    {
        digitalWrite(PIN_LED, LOW);
        motors_controller_forward(&robot->motors_controller);
    }
}

void bluetooth_robot_run_manual(bluetooth_robot_t* robot)
{
    char recv_char = bluetooth_receive_character(&(robot->bluetooth));
    if (recv_char == (robot->key_binding).key_up)
    {
        motors_controller_forward(&(robot->motors_controller));
    }
    else if (recv_char == (robot->key_binding).key_down)
    {
        motors_controller_backward(&(robot->motors_controller));
    }
    else if (recv_char == (robot->key_binding).key_left)
    {
        motors_controller_turn_left(&(robot->motors_controller));
    }
    else if (recv_char == (robot->key_binding).key_right)
    {
        motors_controller_turn_right(&(robot->motors_controller));
    }
    else if (recv_char == (robot->key_binding).key_speed_inc)
    {
        motors_controller_inc_speed_percentage(&(robot->motors_controller), SPEED_INTERVAL_PERCENTAGE);
    }
    else if (recv_char == (robot->key_binding).key_speed_dec)
    {
        motors_controller_dec_speed_percentage(&(robot->motors_controller), SPEED_INTERVAL_PERCENTAGE);
    }
    else if (recv_char == (robot->key_binding).key_auto)
    {
        bluetooth_robot_set_state(robot, STATE_AUTO);
        motors_controller_brake(&(robot->motors_controller));
    }
    else if (recv_char == (robot->key_binding).key_brake)
    {
        motors_controller_brake(&(robot->motors_controller));
    }
    else 
    {
        // Do nothing
    }
}

void bluetooth_robot_run(bluetooth_robot_t* robot)
{
    if (robot->state == STATE_AUTO)
    {
        bluetooth_robot_run_auto(robot);
    }
    else 
    {
        bluetooth_robot_run_manual(robot);
    }
}

void bluetooth_robot_set_state(bluetooth_robot_t* robot, state_t state_new)
{
    robot->state = state_new;
}

