#pragma once

// The layers that we are defining for this keyboards.
enum layer_names {
    _DVORAK,
    _LOWER,
    _RAISE,
    _ADJUST
};

// Adding macros to make the keymaps below much easier to read.
#define GUIMINS GUI_T(KC_MINS)
#define GUISLSH GUI_T(KC_SLSH)
#define SFTESC SFT_T(KC_ESC)

#define OSMGUI OSM(MOD_LGUI)
#define OSMCTL OSM(MOD_LCTL)
#define OSMSFT OSM(MOD_LSFT)
#define OSMALT OSM(MOD_LALT)

/* Home row */
#define LOWT LT(_LOWER, KC_T)
#define LOWE LT(_LOWER, KC_E)
#define SFT_U SFT_T(KC_U)
#define SFT_H SFT_T(KC_H)
#define CTLA   CTL_T(KC_A)
#define CTLS   CTL_T(KC_S)

// Other row.
#define ALTSCLN ALT_T(KC_SCLN)

#define SFTTAB LT(_LOWER, KC_TAB)
#define SFTENTER LT(_LOWER, KC_ENTER)
#define SFTSPC SFT_T(KC_SPC)
#define OSMALT OSM(MOD_LALT)
#define RAIGRV LT(_RAISE, KC_GRV)
#define RAIPIP LT(_RAISE, KC_PIPE)
#define SFTLBRC SFT_T(KC_LBRC)

#define T_DVORAK TO(_DVORAK)
#define T_LOWER TO(_LOWER)
#define T_RAISE TO(_RAISE)

// SAFE_RANGE must be used to tag the first element of the enum.
enum custom_keycodes {
    MC_REG = SAFE_RANGE,
};
