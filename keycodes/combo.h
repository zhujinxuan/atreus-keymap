#pragma once

enum combos {
    TK__LS_CB,
    KAPSLOCK,
    SFT_CB,
    LPR_CB,
    RPR_CB,
    LBR_CB,
    RBR_CB,
    LSR_CB,
    RSR_CB,
    GRV_CB,
    TILD_CB,
    BSLASH_CB,
    PIPE_CB,
    QUES_CB,
    SLASH_CB,
    MINS_CB,
    UNDS_CB,
    LOWER_CB,
    BASE_CB,
    VPASTE_CB,
    VYANK_CB,
};

const uint16_t PROGMEM tk_ls[] = {KC_O, KC_DOT, KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM kapslock[] = {KC_COMM, KC_DOT, KC_P, COMBO_END};
const uint16_t PROGMEM sftcb[] = {KC_O, KC_COMM, KC_S, COMBO_END};
const uint16_t PROGMEM lprcb[] = {KC_O, KC_U, KC_G, COMBO_END};
const uint16_t PROGMEM rprcb[] = {KC_O, KC_U, KC_R, COMBO_END};
const uint16_t PROGMEM lbrcb[] = {KC_O, KC_U, KC_H, COMBO_END};
const uint16_t PROGMEM rbrcb[] = {KC_O, KC_U, KC_N, COMBO_END};
const uint16_t PROGMEM lsrcb[] = {KC_O, KC_U, KC_L, COMBO_END};
const uint16_t PROGMEM rsrcb[] = {KC_O, KC_U, KC_W, COMBO_END};
const uint16_t PROGMEM tildcb[] = {KC_O, KC_U, KC_C, COMBO_END};
const uint16_t PROGMEM grvcb[] = {KC_O, KC_U, KC_V, COMBO_END};
const uint16_t PROGMEM bslashcb[] = {KC_O, KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM pipecb[] = {KC_O, KC_R, KC_N, COMBO_END};
const uint16_t PROGMEM questioncb[] = {KC_O, KC_H, KC_G, COMBO_END};
const uint16_t PROGMEM slashcb[] = {KC_O, KC_H, KC_C, COMBO_END};
const uint16_t PROGMEM undscb[] = {KC_O, KC_L, KC_M, COMBO_END};
const uint16_t PROGMEM minscb[] = {KC_O, KC_G, KC_C, COMBO_END};
const uint16_t PROGMEM lowercb[] = {KC_O, KC_J, KC_U, COMBO_END};
const uint16_t PROGMEM basecb[] = {KC_UP, KC_LEFT, KC_RIGHT, COMBO_END};
const uint16_t PROGMEM vimPasteCB[] = {KC_A, KC_O, KC_P, COMBO_END};
const uint16_t PROGMEM vimYankCB[] = {KC_A, KC_O, KC_K, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [TK__LS_CB] = COMBO_ACTION(tk_ls),
    [KAPSLOCK] = COMBO_ACTION(kapslock),
    [SFT_CB] = COMBO_ACTION(sftcb),
    [LPR_CB] = COMBO(lprcb, KC_LPRN),
    [RPR_CB] = COMBO(rprcb, KC_RPRN),
    [LBR_CB] = COMBO(lbrcb, KC_LBRC),
    [RBR_CB] = COMBO(rbrcb, KC_RBRC),
    [LSR_CB] = COMBO(lsrcb, KC_LCBR),
    [RSR_CB] = COMBO(rsrcb, KC_RCBR),
    [GRV_CB] = COMBO(grvcb, KC_GRV),
    [TILD_CB] = COMBO(tildcb, KC_TILD),
    [BSLASH_CB] = COMBO(bslashcb, KC_BSLASH),
    [PIPE_CB] = COMBO(pipecb, KC_PIPE),
    [SLASH_CB] = COMBO(slashcb, KC_SLASH),
    [QUES_CB] = COMBO(questioncb, KC_QUES),
    [MINS_CB] = COMBO(minscb, KC_MINS),
    [UNDS_CB] = COMBO(undscb, KC_UNDS),
    [LOWER_CB] = COMBO_ACTION(lowercb),
    [BASE_CB] = COMBO_ACTION(basecb),
    [VPASTE_CB] = COMBO_ACTION(vimPasteCB),
    [VYANK_CB] = COMBO_ACTION(vimYankCB),
};

static bool kpa_active = false;

void capOn(void) {
    if (kpa_active) {
        return;
    }
    kpa_active = true;
    tap_code(KC_CAPS);
}

void capOff(void) {
    if (!kpa_active) {
        return;
    }
    kpa_active = false;
    tap_code(KC_CAPS);
}

void process_combo_event(uint16_t combo_index, bool pressed) {
    if (!pressed) {
        return;
    }
    switch(combo_index) {
    case TK__LS_CB:
        capOff();
        break;
    case KAPSLOCK:
        capOn();
        break;
    case SFT_CB:
        capOff();
        set_oneshot_mods(MOD_BIT(KC_LSFT));
        break;
    case LOWER_CB:
        layer_on(_LOWER);
        break;
    case BASE_CB:
        layer_off(_LOWER);
        layer_on(_DVORAK);
        break;
    case VPASTE_CB:
        SEND_STRING("\"+p");
        break;
    case VYANK_CB:
        SEND_STRING("\"+y");
        break;
    }
}
