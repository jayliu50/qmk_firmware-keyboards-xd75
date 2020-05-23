
#include QMK_KEYBOARD_H

// #include "debug.h"
#include "action_layer.h"
#include "version.h"
#include "keymap_dvp.h" // DP_ for dvorak key
#include "personal.h"


// Layer definitions
enum {
    BASE = 0,   // default layer
    SYMB,       // the bunch of symbols I can never remember
    FKEY,       // Function keys, media
    NUMB,       // number keys
    SKCH,       // Bohemian Sketch
    PLVR,       // Plover
    _DYN,       // Dynamic Macro Recording (I think it should be last)
};

// OS-specific keys
#define SUPER KC_LGUI
#define SUPER_WIN KC_LCTL
#define MOD(x) (LGUI(x)) // CMD in OSX
#define SMOD(x) (SCMD(x)) // SHIFT CMD in OSX

#define SCRN_SHOT LCTL(LSFT(MOD(KC_4)))
#define SCRN_SAVE LSFT(MOD(KC_4))

// Sketch Layer
#define ICON_ADD HYPR(KC_I)
#define ICON_OUTLINE HYPR(KC_O)
#define DISTR LCTL(LALT(KC_D))
#define SWAP LCTL(LSFT(MOD(KC_L)))
#define ARTB_PREV LSFT(MOD(KC_LBRC))
#define ARTB_NEXT LSFT(MOD(KC_RBRC))
#define RUNR_GO_TO HYPR(KC_G)
#define RUNR_APPLY HYPR(KC_A)
#define RUNR_CREATE HYPR(KC_C)
#define RUNR_INSERT HYPR(KC_N)
#define RUNR_RUN MOD(KC_QUOT)

#define ALGN_LEFT HYPR(KC_LEFT)
#define ALGN_RIGHT HYPR(KC_RIGHT)
#define ALGN_BOTT HYPR(KC_DOWN)
#define ALGN_TOP HYPR(KC_UP)

#define STYLE_CREATE MEH(KC_S)
#define STYLE_COPY LALT(MOD(KC_C))
#define STYLE_PASTE LALT(MOD(KC_V))

#define POS_COPY LCTL(LSFT(KC_C))
#define POS_PASTE LCTL(LSFT(KC_P))

#define TOG_HIDE LSFT(MOD(KC_H))
#define TOG_LOCK LSFT(MOD(KC_L))
#define LAYER_FRONT LCTL(LALT(MOD(KC_UP)))
#define LAYER_BACK LCTL(LALT(MOD(KC_DOWN)))
#define LAYER_FORWARD LALT(MOD(KC_UP))
#define LAYER_BACKWARD LALT(MOD(KC_DOWN))
#define LAYER_COLLAPSE HYPR(KC_S)
#define LAYER_REVEAL LSFT(MOD(KC_J))

// resize artboard to fit
// align to
// user flows add connection
// user flows create diagram
// Zoom Artboard to Fit ( cmd+4 )
// fluid



/*======================================
=            FN Definitions            =
======================================*/

enum fn {
    JL_NUMB = 0,   // Tap toggle Number layer
    JL_SKCH,       // Tap toggle Sketch layer
};

const uint16_t PROGMEM fn_actions[] = {
    [JL_NUMB] = ACTION_LAYER_TAP_TOGGLE(NUMB),
    [JL_SKCH] = ACTION_LAYER_TAP_TOGGLE(SKCH),
};

/*=====  End of FN Definitions  ======*/



/*=========================================
=            Macro Definitions            =
=========================================*/

// Macro Definitions
enum {
  PLVR_TOG = 0,     // Plover toggle
  PLVR_DICT,        // Plover add to dictionary
  PLVR_LOOK,        // Plover lookup dictionary
  PLVR_RESET,       // Plover reset output
  PLVR_UP_LAST,     // Plover upper case last word
  PLVR_LO_LAST,     // Plover lower case last word
  PLVR_TOG_AST,     // Plover toggle asterisk
  PLVR_ADD_SP,      // Plover retroactively add space
  PLVR_REM_SP,      // Plover retroactively remove space
  DBL_P0,           // 00
  CLEAR_MODS,       // Sends up key on all mods

  WORK_ID,
  WORK_USER,
  WORK_EMAIL,
  WORK_PH,
  PER_ID,
  PER_USER,
  PER_PH,
  PER_EMAIL,

  MO_PLVR,

};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  switch(id) {

    case PLVR_TOG: {
        if (record->event.pressed) {
            // this will be interpreted by my Plover dictionary to toggle steno mode
            return MACRO( D(A), D(W), D(H), D(I), D(K), D(N), W(10), U(A), U(W), U(H), U(I), U(K), U(N), END);
        }
        break;
    }
    case PLVR_DICT: {
        if (record->event.pressed) {
            // This will be interpreted by my Plover dictionary to open up the dictionary
            return MACRO( D(W), D(S), D(N), D(M), D(K), D(L), D(P), D(H), W(10), U(W), U(S), U(N), U(M), U(K), U(L), U(P), U(H), END);
        }
    }
    case PLVR_LOOK: {
        if (record->event.pressed) {
            return MACRO( D(W), D(S), D(N), D(M), D(K), D(L), D(P), W(10), U(W), U(S), U(N), U(M), U(K), U(L), U(P), END);
        }
    }
    case PLVR_RESET: {
        if (record->event.pressed) {
            return MACRO( D(F), D(N), D(H), D(U), D(P), W(10), U(F), U(N), U(H), U(U), U(P), END);
        }
    }
    case PLVR_UP_LAST: {
        if (record->event.pressed) {
            return MACRO( D(H), D(M), D(I), D(LBRC), W(10), U(H), U(M), U(I), U(LBRC), END);
        }
    }
    case PLVR_LO_LAST: {
        if (record->event.pressed) {
            return MACRO(D(R), D(F), D(V), D(N), D(H), D(J), D(LBRC), W(10), U(R), U(F), U(V), U(N), U(H), U(J), U(LBRC), END);
        }
    }
    case PLVR_TOG_AST: {
        if (record->event.pressed) {
            return MACRO( D(1), D(H), W(10), U(1), U(H), END);
        }
    }
    case PLVR_ADD_SP: {
        if (record->event.pressed) {
            return MACRO( D(C), D(U), D(I), D(SCLN), W(10), U(C), U(U), U(I), U(SCLN), END);
        }
    }
    case PLVR_REM_SP: {
        if (record->event.pressed) {
            return MACRO( D(W), D(S), D(U), D(I), D(SCLN), W(10), U(W), U(S), U(U), U(I), U(SCLN), END);
        }
    }
    case DBL_P0: {
        if (record->event.pressed) {
            // puts down two 0s
            return MACRO( T(P0), T(P0), END );
        }
    }
    case CLEAR_MODS: {
        if (record->event.pressed) {
            // sometimes QMK will send a stuck mod keypress. This hopefully clears them.
            clear_mods();
            return false;
        }
    }
    case WORK_ID: {
        if (record->event.pressed) {
            SEND_STRING(_WORK_ID);
            return false;
        }
    }
    case WORK_USER: {
        if (record->event.pressed) {
            SEND_STRING(_WORK_USER);
            return false;
        }
    }
    case WORK_EMAIL: {
        if (record->event.pressed) {
            SEND_STRING(_WORK_EMAIL);
            return false;
        }
    }
    case WORK_PH: {
        if (record->event.pressed) {
            SEND_STRING(_WORK_PHONE);
            return false;
        }
    }
    case PER_ID: {
        if (record->event.pressed) {
            SEND_STRING(_PER_ID);
            return false;
        }
    }
    case PER_USER: {
        if (record->event.pressed) {
            SEND_STRING(_PER_USER);
            return false;
        }
    }
    case PER_PH: {
        if (record->event.pressed) {
            SEND_STRING(_PER_PHONE);
            return false;
        }
    }
    case PER_EMAIL: {
        if (record->event.pressed) {
            SEND_STRING(_PER_EMAIL);
            return false;
        }
    }





  }
  return MACRO_NONE;
};

/*=====  End of Macro Definitions  ======*/



/*=====================================
=            Dynamic Macro            =
=====================================*/

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  COLEMAK,
  DVORAK,
  PLOVER,
  LOWER,
  RAISE,
  BACKLIT,
  EXT_PLV,
  DYNAMIC_MACRO_RANGE,
};


#include "dynamic_macro.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }

    // switch (keycode) {
    //     case MO_PLVR:
    //     if (record->event.pressed) {
    //         lt12_timer = timer_read();
    //         layer_on(PLVR);
    //         gp100_led_on();
    //     } else {
    //         if (timer_elapsed(lt12_timer) > 200) {
    //         layer_off(PLVR);
    //         gp100_led_off();
    //         }
    //     }
    //     return false;
    //     break;
    //     case SWITCH_FS:
    //     if (record->event.pressed) {
    //         lt12_timer = timer_read();
    //         layer_on(_FS);
    //         gp100_led_on();
    //     } else {
    //         if (timer_elapsed(lt12_timer) > 200) {
    //         layer_off(_FS);
    //         gp100_led_off();
    //         }
    //     }
    //     return false;
    //     break;
    // }
    // return true;

    // <...THE REST OF THE FUNCTION...>
    return true;
}

/*=====  End of Dynamic Macro  ======*/


/*===============================================
=            Tap Dance Configuration            =
===============================================*/

// Declarations
enum {
    JL_CP = 0,      // Paste on single tap, Copy on double tap
    JL_CP_WIN,      // Windows: Paste on single tap, Copy on double tap

    JL_SCRN,          // Single: copy screenshot, Double: save screenshot to file

    SKCH_ICON,        // Single: insert icon, Double: convert icon to outline
    SKCH_LAYER_LIST,  // Single: collapse, Double: Reveal in layer list
    SKCH_SYMBOL,      // Single: insert symbol, Double: create symbol


};

static void copy_paste (qk_tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            register_code (SUPER);
            register_code (KC_V);
            unregister_code (KC_V);
            unregister_code (SUPER);
            break;
        case 2:
            register_code (SUPER);
            register_code (KC_C);
            unregister_code (KC_C);
            unregister_code (SUPER);
            break;
        case 3:
            register_code (SUPER);
            register_code (KC_X);
            unregister_code (KC_X);
            unregister_code (SUPER);
            reset_tap_dance (state);
            break;

    }
}


static void copy_paste_win (qk_tap_dance_state_t *state, void *user_data) {

    switch (state->count) {
        case 1:
            register_code (SUPER_WIN);
            register_code (KC_V);
            unregister_code (KC_V);
            unregister_code (SUPER_WIN);
            break;
        case 2:
            register_code (SUPER_WIN);
            register_code (KC_C);
            unregister_code (KC_C);
            unregister_code (SUPER_WIN);
            break;
        case 3:
            register_code (SUPER_WIN);
            register_code (KC_X);
            unregister_code (KC_X);
            unregister_code (SUPER_WIN);
            reset_tap_dance (state);
            break;

    }
}


qk_tap_dance_action_t tap_dance_actions[] = {
    [JL_CP] = ACTION_TAP_DANCE_FN (copy_paste),
    [JL_CP_WIN] = ACTION_TAP_DANCE_FN (copy_paste_win),

    [JL_SCRN] = ACTION_TAP_DANCE_DOUBLE(SCRN_SHOT, SCRN_SAVE),

    [SKCH_ICON] = ACTION_TAP_DANCE_DOUBLE(ICON_ADD, ICON_OUTLINE),
    [SKCH_LAYER_LIST] = ACTION_TAP_DANCE_DOUBLE(LAYER_REVEAL, LAYER_COLLAPSE),
    [SKCH_SYMBOL] = ACTION_TAP_DANCE_DOUBLE(RUNR_INSERT, RUNR_CREATE),


};

/*=====  End of Tap Dance Configuration  ======*/

/*===============================================
=             Unicode Configuration             =
===============================================*/

#define SMILE 0x263A


/*=====  End of Unicode Configuration  ======*/


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


// see tmk_core/common/keycode.h
// see quantum/quantum_keycodes.h
// AlignTab Regex: /\*\*//l2
// Wrapping required keycodes around (parens), typically for MO() and getting back to original layer
//


[BASE] = LAYOUT_ortho_5x15(
//  /**/  -------01--------  /**/  -------02---------  /**/  -------03---------  /**/  -------04---------  /**/  -------05---------  /**/  -------06---------  /**/  -------07---------  /**/  -------08---------  /**/  -------09---------  /**/  -------10---------  /**/  -------11---------  /**/  -------12---------  /**/  -------13---------  /**/  -------14---------  /**/  -------15---------    /**/
    /**/  KC_GRV,            /**/  KC_LT,              /**/  KC_LBRC,            /**/  KC_LCBR,            /**/  KC_LPRN,            /**/  KC_EQL,             /**/  TD(JL_SCRN),        /**/  MO(_DYN),           /**/  TD(JL_CP),          /**/  KC_GT,              /**/  KC_RPRN,            /**/  KC_RCBR,            /**/  KC_RBRC,            /**/  KC_EXLM,            /**/  TO(PLVR),             /**/
    /**/  KC_TAB,            /**/  KC_SCLN,            /**/  KC_COMM,            /**/  KC_DOT,             /**/  KC_P,               /**/  KC_Y,               /**/  MO(SYMB),           /**/  KC_NO,              /**/  LT(SYMB, KC_PGUP),  /**/  KC_F,               /**/  KC_G,               /**/  KC_C,               /**/  KC_R,               /**/  KC_L,               /**/  KC_SLSH,              /**/
    /**/  KC_ENT,            /**/  KC_A,               /**/  KC_O,               /**/  KC_E,               /**/  KC_U,               /**/  KC_I,               /**/  KC_DEL,             /**/  KC_NO,              /**/  KC_PGDN,            /**/  KC_D,               /**/  KC_H,               /**/  KC_T,               /**/  KC_N,               /**/  KC_S,               /**/  KC_MINS,              /**/
    /**/  KC_LSFT,           /**/  KC_QUOT,            /**/  KC_Q,               /**/  KC_J,               /**/  KC_K,               /**/  KC_X,               /**/  KC_LALT,            /**/  KC_NO,              /**/  KC_RALT,            /**/  KC_B,               /**/  KC_M,               /**/  KC_W,               /**/  KC_V,               /**/  KC_Z,               /**/  KC_RSFT,              /**/
    /**/  KC_LCTL,           /**/  MO(FKEY),           /**/  KC_TRNS,            /**/  MO(SKCH),           /**/  MO(NUMB),           /**/  KC_SPC,             /**/  KC_LGUI,            /**/  KC_ESC,             /**/  KC_RGUI,            /**/  KC_BSPC,            /**/  KC_LEFT,            /**/  KC_DOWN,            /**/  KC_UP,              /**/  KC_RGHT,            /**/  KC_SPC                /**/
    ),


    /*
    & aNd
    % Percent
    ~ Tilde
    $ Dollar
    = Equal
    * Star
    ! eXclaim
    # Hash
    ` backticK
    @ At
    ^ Caret
    \ Backslash
    | pIpe
     */


[SYMB] = LAYOUT_ortho_5x15(
//  /**/  -------01--------  /**/  -------02---------  /**/  -------03---------  /**/  -------04---------  /**/  -------05---------  /**/  -------06---------  /**/  -------07---------  /**/  -------08---------  /**/  -------09---------  /**/  -------10---------  /**/  -------11---------  /**/  -------12---------  /**/  -------13---------  /**/  -------14---------  /**/  -------15---------    /**/
    /**/  KC_TRNS,           /**/  KC_7,               /**/  KC_5,               /**/  KC_3,               /**/  KC_1,               /**/  KC_9,               /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_0,               /**/  KC_2,               /**/  KC_4,               /**/  KC_6,               /**/  KC_8,               /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_PERC,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_CIRC,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_AT,              /**/  KC_TRNS,            /**/  KC_EQL,             /**/  KC_TRNS,            /**/  KC_PIPE,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_PGDN,            /**/  KC_DLR,             /**/  KC_HASH,            /**/  KC_TILD,            /**/  KC_AMPR,            /**/  KC_ASTR,            /**/  UC(SMILE),            /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_GRV,             /**/  KC_EXLM,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_BSLS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS               /**/
    ),


[FKEY] = LAYOUT_ortho_5x15(
//  /**/  -------01--------  /**/  -------02---------  /**/  -------03---------  /**/  -------04---------  /**/  -------05---------  /**/  -------06---------  /**/  -------07---------  /**/  -------08---------  /**/  -------09---------  /**/  -------10---------  /**/  -------11---------  /**/  -------12---------  /**/  -------13---------  /**/  -------14---------  /**/  -------15---------    /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_MUTE,            /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_F10,             /**/  KC_F11,             /**/  KC_F12,             /**/  KC_TRNS,            /**/  RESET,                /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_VOLU,            /**/  KC_TRNS,            /**/  KC_MS_WH_DOWN,      /**/  KC_TRNS,            /**/  KC_F7,              /**/  KC_F8,              /**/  KC_F9,              /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_VOLD,            /**/  KC_TRNS,            /**/  KC_MS_WH_UP,        /**/  KC_TRNS,            /**/  KC_F4,              /**/  KC_F5,              /**/  KC_F6,              /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_MS_BTN3,         /**/  KC_TRNS,            /**/  KC_F1,              /**/  KC_F2,              /**/  KC_F3,              /**/  KC_TRNS,            /**/  KC_CAPS,              /**/
    /**/  KC_TRNS,           /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_MPLY,            /**/  M(CLEAR_MODS),      /**/  KC_MS_BTN2,         /**/  KC_MS_BTN1,         /**/  KC_MS_LEFT,         /**/  KC_MS_DOWN,         /**/  KC_MS_UP,           /**/  KC_MS_RIGHT,        /**/  KC_TRNS               /**/
    ),


[SKCH] = LAYOUT_ortho_5x15(
//  /**/  -------01--------  /**/  -------02---------  /**/  -------03---------  /**/  -------04---------  /**/  -------05---------  /**/  -------06---------  /**/  -------07---------  /**/  -------08---------  /**/  -------09---------  /**/  -------10---------  /**/  -------11---------  /**/  -------12---------  /**/  -------13---------  /**/  -------14---------  /**/  -------15---------    /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  LAYER_FORWARD,        /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  ARTB_PREV,          /**/  SWAP,               /**/  TOG_LOCK,           /**/  TD(SKCH_ICON),      /**/  STYLE_PASTE,        /**/  STYLE_COPY,         /**/  LAYER_FRONT,          /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  ARTB_NEXT,          /**/  DISTR,              /**/  TOG_HIDE,           /**/  TD(SKCH_SYMBOL),    /**/  RUNR_APPLY,         /**/  STYLE_CREATE,       /**/  TD(SKCH_LAYER_LIST),  /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  POS_PASTE,          /**/  POS_COPY,           /**/  LAYER_BACK,           /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  RUNR_RUN,           /**/  RUNR_GO_TO,         /**/  ALGN_LEFT,          /**/  ALGN_BOTT,          /**/  ALGN_TOP,           /**/  ALGN_RIGHT,         /**/  LAYER_BACKWARD        /**/
    ),




[PLVR] = LAYOUT_ortho_5x15(
//  /**/  -------01--------  /**/  -------02---------  /**/  -------03---------  /**/  -------04---------  /**/  -------05---------  /**/  -------06---------  /**/  -------07---------  /**/  -------08---------  /**/  -------09---------  /**/  -------10---------  /**/  -------11---------  /**/  -------12---------  /**/  -------13---------  /**/  -------14---------  /**/  -------15---------  /**/
    /**/  KC_NO,             /**/  KC_1,               /**/  KC_2,               /**/  KC_3,               /**/  KC_4,               /**/  KC_5,               /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_6,               /**/  KC_7,               /**/  KC_8,               /**/  KC_9,               /**/  KC_0,               /**/  TO(BASE),           /**/
    /**/  KC_NO,             /**/  KC_Q,               /**/  KC_W,               /**/  KC_E,               /**/  KC_R,               /**/  KC_T,               /**/  M(PLVR_LOOK),       /**/  MAGIC_TOGGLE_NKRO,  /**/  M(PLVR_TOG_AST),    /**/  KC_Y,               /**/  KC_U,               /**/  KC_I,               /**/  KC_O,               /**/  KC_P,               /**/  KC_LBRC,            /**/
    /**/  KC_NO,             /**/  KC_A,               /**/  KC_S,               /**/  KC_D,               /**/  KC_F,               /**/  KC_G,               /**/  M(PLVR_DICT),       /**/  M(PLVR_TOG),        /**/  M(PLVR_TOG_AST),    /**/  KC_H,               /**/  KC_J,               /**/  KC_K,               /**/  KC_L,               /**/  KC_SCLN,            /**/  KC_QUOT,            /**/
    /**/  KC_NO,             /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/  KC_NO,              /**/
    /**/  KC_NO,             /**/  MO(FKEY),           /**/  KC_NO,              /**/  KC_NO,              /**/  KC_C,               /**/  KC_V,               /**/  MO(NUMB),           /**/  M(PLVR_RESET),      /**/  MO(SYMB),           /**/  KC_N,               /**/  KC_M,               /**/  M(PLVR_REM_SP),     /**/  M(PLVR_LO_LAST),    /**/  M(PLVR_UP_LAST),    /**/  M(PLVR_ADD_SP)      /**/
    ),



[NUMB] = LAYOUT_ortho_5x15(
//  /**/  -------01--------  /**/  -------02---------  /**/  -------03---------  /**/  -------04---------  /**/  -------05---------  /**/  -------06---------  /**/  -------07---------  /**/  -------08---------  /**/  -------09---------  /**/  -------10---------  /**/  -------11---------  /**/  -------12---------  /**/  -------13---------  /**/  -------14---------  /**/  -------15---------    /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_PSLS,            /**/  KC_PAST,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_UP,              /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_P7,              /**/  KC_P8,              /**/  KC_P9,              /**/  KC_PMNS,            /**/  TG(NUMB),             /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_LEFT,            /**/  KC_DOWN,            /**/  KC_RIGHT,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_P4,              /**/  KC_P5,              /**/  KC_P6,              /**/  KC_PPLS,            /**/  KC_PENT,              /**/
    /**/  KC_F,              /**/  KC_E,               /**/  KC_D,               /**/  KC_C,               /**/  KC_B,               /**/  KC_A,               /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_P1,              /**/  KC_P2,              /**/  KC_P3,              /**/  KC_TRNS,            /**/  KC_NLCK,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/  KC_C,               /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_N,               /**/  KC_M ,              /**/  KC_P0,              /**/  M(DBL_P0),          /**/  KC_PDOT,            /**/  KC_TRNS,            /**/  KC_TRNS               /**/
    ),



[_DYN] = LAYOUT_ortho_5x15(
//  /**/  -------01--------  /**/  -------02---------  /**/  -------03---------  /**/  -------04---------  /**/  -------05---------  /**/  -------06---------  /**/  -------07---------  /**/  -------08---------  /**/  -------09---------  /**/  -------10---------  /**/  -------11---------  /**/  -------12---------  /**/  -------13---------  /**/  -------14---------  /**/  -------15---------    /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  M(PER_ID),          /**/  M(WORK_ID),         /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  (KC_TRNS),          /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  M(PER_EMAIL),       /**/  M(WORK_EMAIL),      /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  DYN_REC_START1,     /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  M(PER_USER),        /**/  M(WORK_USER),       /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  DYN_REC_START2,     /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  M(PER_PH),          /**/  M(WORK_PH),         /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,              /**/
    /**/  KC_TRNS,           /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_C,               /**/  KC_TRNS,            /**/  DYN_REC_STOP,       /**/  DYN_MACRO_PLAY2,    /**/  DYN_MACRO_PLAY1,    /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS,            /**/  KC_TRNS               /**/
    ),

};


void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

void led_set_user(uint8_t usb_led) {
    if (IS_LED_ON(usb_led, USB_LED_CAPS_LOCK)) {
        capslock_led_on();
    } else {
        capslock_led_off();
    }
    if (IS_LAYER_ON(PLVR)) {
        rgblight_setrgb(0xFF, 0xFF, 0);
    } else {
        rgblight_setrgb(0, 0, 0);
    }
}
