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

#include QMK_KEYBOARD_H
#include "keychron_common.h"
#include "keychron_ft_common.h"

enum layers {
    WIN_BASE,
    WIN_FN,
    WIN_L2,
    WIN_L3,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [WIN_BASE] = LAYOUT(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,
        KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,
        KC_LCTL,            KC_LALT,  MO(WIN_FN), MO(WIN_FN),  KC_SPC),

    [WIN_FN] = LAYOUT(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_PSCR,  KC_CRTA,
        _______,  KC_7,     KC_8,     KC_9,     KC_0,     _______,  _______,
        BL_TOGG,  BL_STEP,  BL_UP,    _______,  _______,  _______,
        _______,  _______,  BL_DOWN,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  NK_TOGG,
        _______,            _______,  _______,  _______,       _______),

    [WIN_L2] = LAYOUT(
        _______,            _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,       _______),
    [WIN_L3] = LAYOUT(
        _______,            _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,  _______,
        _______,            _______,  _______,  _______,       _______),
};

// clang-format on

void housekeeping_task_user(void) {
    housekeeping_task_keychron();
    housekeeping_task_keychron_ft();
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_keychron(keycode, record)) {
        return false;
    }
    if (!process_record_keychron_ft(keycode, record)) {
        return false;
    }
    return true;
}
