/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This function contains function declartions for keybinding
 */

#ifndef KEY_BINDING_H_
#define KEY_BINDING_H_

// Include header files
typedef struct 
{
    char key_up;
    char key_down;
    char key_left;
    char key_right;
    char key_speed_inc;
    char key_speed_dec;
    char key_auto;
    char key_brake;
} key_binding_t;

// Define macros
#define DEFAULT_KEY_UP          'u'
#define DEFAULT_KEY_DOWN        'd'
#define DEFAULT_KEY_LEFT        'l'
#define DEFAULT_KEY_RIGHT       'r'
#define DEFAULT_KEY_AUTO        'a'
#define DEFAULT_KEY_BRAKE       'b'
#define DEFAULT_KEY_SPEED_INC   '+'
#define DEFAULT_KEY_SPEED_DEC  '-'

// Function declarations
void key_binding_struct_init(key_binding_t* key_binding);

#endif
