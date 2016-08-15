/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This file contains function implementations for bluetooth communication
 */

#include "Bluetooth.h"
#include "Common.h"
#include <stdio.h>

void bluetooth_struct_init(bluetooth_t* bluetooth)
{
    if (bluetooth != NULL)
    {
        bluetooth->pin_tx = UNKNOWN_PIN;
        bluetooth->pin_rx = UNKNOWN_PIN;
    
        bluetooth->serial = NULL;
        bluetooth->uart_baudrate = DEFAULT_BAUDRATE;
    }
}

void bluetooth_initialize(bluetooth_t* bluetooth)
{
    if (bluetooth != NULL)
    {
        // Define pin mode
        pinMode(bluetooth->pin_tx, OUTPUT);
        pinMode(bluetooth->pin_rx, INPUT);
    
        // Initialize data
        bluetooth->serial = new SoftwareSerial(bluetooth->pin_rx, bluetooth->pin_tx);
        bluetooth_connection_begin(bluetooth);
    }
}

void bluetooth_connection_begin(bluetooth_t* bluetooth)
{
    if (bluetooth != NULL)
    {
        // Preparing data
        long uart_baudrate = (long)bluetooth->uart_baudrate;
        bluetooth->serial->begin(uart_baudrate);
    }
}

void bluetooth_send_character(bluetooth_t* bluetooth, char ch)
{
    if (bluetooth != NULL)
    {
        (bluetooth->serial)->write(ch);
    }
}

char bluetooth_receive_character(bluetooth_t* bluetooth)
{
    char recv_char = 0;
    if (bluetooth != NULL)
    {
        while ((bluetooth->serial)->available() == 0);
        recv_char = (bluetooth->serial)->read();
    }
    return recv_char;
}

bool bluetooth_is_receive_data_empty(bluetooth_t* bluetooth)
{
    bool is_empty = false;
    if ((bluetooth->serial)->available() == 0)
    {
        is_empty = true;
    }

    return is_empty;
}

