/*
 * Date: 11/04/2016
 * Writter: Loc Pham
 * Description: This file contains function definitiions
 */

#include "KeyBinding.h"
#include "Common.h"

void key_binding_struct_init(key_binding_t* key_binding)
{
    if (key_binding != NULL)
    {
        key_binding->key_up         = DEFAULT_KEY_UP;
        key_binding->key_down       = DEFAULT_KEY_DOWN;
        key_binding->key_left       = DEFAULT_KEY_LEFT;
        key_binding->key_right      = DEFAULT_KEY_RIGHT;
        key_binding->key_speed_inc  = DEFAULT_KEY_SPEED_INC;
        key_binding->key_speed_dec  = DEFAULT_KEY_SPEED_DEC;
        key_binding->key_auto       = DEFAULT_KEY_AUTO;
        key_binding->key_brake      = DEFAULT_KEY_BRAKE;
    }
}

