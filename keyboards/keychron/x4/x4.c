/* Copyright 2023 @ Keychron (https://www.keychron.com)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "quantum.h"

static uint8_t win_lock_state = 0;

void eeconfig_init_kb(void) {
#if (EECONFIG_KB_DATA_SIZE) == 0
    // Reset Keyboard EEPROM value to blank, rather than to a set value
    eeconfig_update_kb(0);
#endif
    keymap_config.raw  = eeconfig_read_keymap();
    keymap_config.nkro = 1;
    eeconfig_update_keymap(keymap_config.raw);

    win_lock_state = 0;
    eeconfig_update_user_datablock(&win_lock_state);

    eeconfig_init_user();
}

void keyboard_post_init_kb(void) {
    eeconfig_read_user_datablock(&win_lock_state);

    keyboard_post_init_user();
}

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) {
        return false;
    }
    switch (keycode) {
#ifdef LED_MATRIX_ENABLE
        case BL_TOGG:
            if (record->event.pressed) {
                switch (led_matrix_get_flags()) {
                    case LED_FLAG_ALL: {
                        led_matrix_set_flags(LED_FLAG_NONE);
                        led_matrix_set_value_all(0);
                    } break;
                    default: {
                        led_matrix_set_flags(LED_FLAG_ALL);
                    } break;
                }
            }
            if (!led_matrix_is_enabled()) {
                led_matrix_set_flags(LED_FLAG_ALL);
                led_matrix_enable();
            }
            return false;
#endif
        case GU_TOGG:
            if (record->event.pressed) {
                win_lock_state = !win_lock_state;
                eeconfig_update_user_datablock(&win_lock_state);
            }
            return true;
        default:
            return true;
    }
}

bool led_matrix_indicators_kb(void) {
    if (!led_matrix_indicators_user()) {
        return false;
    }
    if (win_lock_state) {
        led_matrix_set_value(LED_WIN_LOCK_INDEX, 0xFF);
    } else {
        if (!led_matrix_get_flags()) {
            led_matrix_set_value(LED_WIN_LOCK_INDEX, 0);
        }
    }
#if defined(LED_CAPS_LOCK_INDEX)
    if (host_keyboard_led_state().caps_lock) {
#    if defined(DIM_CAPS_LOCK)
        led_matrix_set_value(LED_CAPS_LOCK_INDEX, 0);
#    endif
#endif
    }
    return true;
}
