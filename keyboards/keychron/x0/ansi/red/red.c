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

#ifdef LED_MATRIX_ENABLE
// clang-format off
const ckled2001_led PROGMEM g_ckled2001_leds[LED_MATRIX_LED_COUNT] = {
/* Refer to CKLED2001 manual for these locations
 *   driver
 *   |  LED address
 *   |  |   */
    {0, F_1 },
    {0, F_2 },
    {0, F_3 },
    {0, F_4 },
    {0, F_5 },
    {0, F_6 },
    {0, E_1 },
    {0, E_2 },
    {0, E_3 },
    {0, E_4 },
    {0, E_5 },
    {0, E_6 },
    {0, E_7 },
    {0, D_1 },
    {0, D_2 },
    {0, D_3 },
    {0, D_4 },
    {0, D_5 },
    {0, D_6 },
    {0, C_1 },
    {0, C_2 },
    {0, C_3 },
    {0, C_4 },
    {0, C_5 },
    {0, C_6 },
    {0, B_1 },
    {0, B_3 },
    {0, B_4 },
    {0, B_5 },
    {0, B_6 },
    {0, A_1 },
    {0, A_3 },
    {0, A_4 },
    {0, A_5 },
    {0, A_6 },
};
#endif
