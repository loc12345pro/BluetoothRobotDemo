/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This file contains function declarations and macros for bluetooth communcation
 */

#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

// Include header files
#include <stdint-gcc.h>
#include <SoftwareSerial.h>
#include <Arduino.h>

// Struct definitions
typedef enum 
{
    BAUDRATE_300 = 300,
    BAUDRATE_600 = 600,
    BAUDRATE_1200 = 1200,
    BAUDRATE_2400 = 2400,
    BAUDRATE_4800 = 4800,
    BAUDRATE_9600 = 9600,
    BAUDRATE_14400 = 14400,
    BAUDRATE_19200 = 19200,
    BAUDRATE_28800 = 28800,
    BAUDRATE_38400 = 38400,
    BAUDRATE_57600 = 57600,
    BAUDRATE_115200 = 115200
} baudrate_t;

#define DEFAULT_BAUDRATE BAUDRATE_9600

// Struct definitions
typedef struct
{
    SoftwareSerial* serial;
    uint8_t pin_tx;
    uint8_t pin_rx;
    baudrate_t uart_baudrate;
} bluetooth_t;

// Function declarations
void bluetooth_initialize(bluetooth_t* bluetooth);
void bluetooth_struct_init(bluetooth_t* bluetooth);
void bluetooth_connection_begin(bluetooth_t* bluetooth);

void bluetooth_send_character(bluetooth_t* bluetooth, char ch);
char bluetooth_receive_character(bluetooth_t* bluetooth);

bool bluetooth_is_receive_data_empty(bluetooth_t* bluetooth);

#endif
