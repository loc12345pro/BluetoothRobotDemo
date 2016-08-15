/*
 * Date: 12/3/2016
 * Writter: Loc Pham
 * Module: Main program
 * Description: Main program
 */

// Include header files
#include "BluetoothRobot.h"
#include "Common.h"

// Function declarations
motors_controller_t motors_controller_create();

ultrasonic_t ultrasonic_create(uint8_t trig_pin, uint8_t echo_pin);

bluetooth_t bluetooth_create(uint8_t pin_tx, uint8_t pin_rx, baudrate_t uart_baudrate);

key_binding_t key_binding_create(uint8_t key_up, uint8_t key_down, uint8_t key_left, uint8_t key_right, 
    uint8_t key_speed_inc, uint8_t key_speed_dec, uint8_t key_auto, uint8_t key_brake);

bluetooth_robot_t bluetooth_robot_create();

motor_t motor_create(uint8_t pin_one, uint8_t pin_two);

pin_speed_t pin_speed_create(uint8_t pin, uint8_t pwm_value);

// Global variables
bluetooth_robot_t robot;

// Set up functions
void setup() 
{
    Serial.begin(9600);
    robot = bluetooth_robot_create();
    bluetooth_robot_initialize(&robot);
}

// Loop function
void loop() 
{
    bluetooth_robot_run(&robot);
}

pin_speed_t pin_speed_create(uint8_t pin, uint8_t pwm_value)
{
    pin_speed_t pin_speed;
    pin_speed_struct_init(&pin_speed);
    pin_speed.pin = pin;
    pin_speed.pwm_value = pwm_value;

    return pin_speed;
}

motor_t motor_create(uint8_t pin_one, uint8_t pin_two)
{
    motor_t motor_left;
    motor_struct_init(&motor_left);
    motor_left.pin_one = pin_one;
    motor_left.pin_two = pin_two;

    return motor_left;
}

motors_controller_t motors_controller_create()
{
    motors_controller_t controller;
    motors_controller_struct_init(&controller);

    controller.motor_left       = motor_create(LEFT_MOTOR_PIN_ONE, LEFT_MOTOR_PIN_TWO);
    controller.motor_right      = motor_create(RIGHT_MOTOR_PIN_ONE, RIGHT_MOTOR_PIN_TWO);
    controller.pin_speed_left   = pin_speed_create(LEFT_MOTOR_PIN_SPEED, MOTOR_SPEED_PWM_VALUE);
    controller.pin_speed_right  = pin_speed_create(RIGHT_MOTOR_PIN_SPEED, MOTOR_SPEED_PWM_VALUE);

    return controller;
}

ultrasonic_t ultrasonic_create(uint8_t trig_pin, uint8_t echo_pin)
{
    ultrasonic_t ultrasonic;
    ultrasonic_struct_init(&ultrasonic);
    ultrasonic.trig_pin = trig_pin;
    ultrasonic.echo_pin = echo_pin;

    return ultrasonic;
}

bluetooth_t bluetooth_create(uint8_t pin_tx, uint8_t pin_rx, baudrate_t uart_baudrate)
{
    bluetooth_t bluetooth;
    bluetooth_struct_init(&bluetooth);
    bluetooth.pin_tx = pin_tx;
    bluetooth.pin_rx = pin_rx;
    bluetooth.uart_baudrate = uart_baudrate;

    return bluetooth;
}

key_binding_t key_binding_create(uint8_t key_up, uint8_t key_down, uint8_t key_left, uint8_t key_right, 
    uint8_t key_speed_inc, uint8_t key_speed_dec, uint8_t key_auto, uint8_t key_brake)
{
    key_binding_t key_binding;
    key_binding_struct_init(&key_binding);
    
    key_binding.key_up = key_up;
    key_binding.key_down = key_down;
    key_binding.key_left = key_left;
    key_binding.key_right = key_right;
    
    key_binding.key_speed_inc = key_speed_inc;
    key_binding.key_speed_dec = key_speed_dec;

    key_binding.key_auto = key_auto;
    key_binding.key_brake = key_brake;

    return key_binding;
}

bluetooth_robot_t bluetooth_robot_create()
{
    bluetooth_robot_t robot;
    bluetooth_robot_struct_init(&robot);

    robot.motors_controller = motors_controller_create();
    
    robot.ultrasonic = ultrasonic_create(ULTRASONIC_TRIGGER_PIN, ULTRASONIC_ECHO_PIN);
    
    robot.bluetooth = bluetooth_create(BLUETOOTH_TX_PIN, BLUETOOTH_RX_PIN, BLUETOOTH_BAUDRATE);
    
    robot.key_binding = key_binding_create(KEY_BINDING_UP, KEY_BINDING_DOWN, KEY_BINDING_LEFT, KEY_BINDING_RIGHT, 
        KEY_BINDING_SPEED_INC, KEY_BINDING_SPEED_DEC, KEY_BINDING_AUTO, KEY_BINDING_BRAKE);

    robot.state = STATE_MANUAL;

    return robot;
}
