/**
 * Implements the "layout" section of '.../firmware/keyboard.h'
 *
 * Keymap: My Custom Layers for in QWERTY
 *
 * ** Layer 0
 *
 * ,--------------------------------------------------.    ,--------------------------------------------------.
 * |  ~     |   1  |   2  |   3  |   4  |   5  |dblEsc|    |  =   |   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |chWinF|    |  |   |   Y  |   U  |   I  |   O  |   P  |   '    |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
 * | ctrlL  |   A  |   S  |   D  |   F  |   G  |------|    |------|   H  |   J  |   K  |   L  |   ;  | ctrlL  |
 * |--------+------+------+------+------+------|lpup  |    |lpup  |------+------+------+------+------+--------|
 * |shL2kcap|   Z  |   X  |   C  |   V  |   B  |o1l1  |    |o1l1  |   N  |   M  |   ,  |   .  |   /  |shL2kcap|
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *   |grvAct|acuAct| guiL |divvy |alfred|                                |paneL |paneR |paneU |paneD | guiL |
 *   `----------------------------------'                                `----------------------------------'
 *                                      ,-------------.    ,-------------.
 *                                      | guiL | altL |    | altR | guiR |
 *                               ,------|------|------|    |------+------+------.
 *                               |      |      | home |    | pageU|      |      |
 *                               |  bs  |  del |------|    |------| enter| space|
 *                               |      |      | end  |    | pageD|      |      |
 *                               `--------------------'    `--------------------'
 *
 ****************************************************************************************************
 *
 * ** Layer 1 - Programmer's Toolkit
 *
 * ,--------------------------------------------------.    ,--------------------------------------------------.
 * | btldr  |  F1  |  F2  |  F3  |  F4  |  F5  | F11  |    | F12  |  F6  |  F7  |  F8  |  F9  | F10  | power  |
 * |--------+------+------+------+------+-------------|    |------+------+------+------+------+------+--------|
 * |transp  |transp|  +=  |  &&  |  ->  |  !=  |  >=  |    |  <<  |pageU |   {  |  [   |erbOpn|transp|transp  |
 * |--------+------+------+------+------+------|      |    |      |------+------+------+------+------+--------|
 * |transp  |transp|  &&= | ||=  |  =>  |  ==  |------|    |------|arrowL|arrowR|arrowU|arrowD| end  |transp  |
 * |--------+------+------+------+------+------|  <=  |    | home |------+------+------+------+------+--------|
 * |transp  |transp|  -=  |  ||  |  ~>  |  =~  |      |    |      |pageD |   }  |  ]   |erbCls|   \  |transp  |
 * `--------+------+------+------+------+-------------'    `-------------+------+------+------+------+--------'
 *   | esc  |  ::  |  ..  |  ... |  >>  |                                |transp|transp|transp|transp| iterm|
 *   `----------------------------------'                                `----------------------------------'
 *                                      ,-------------.    ,---------------.
 *                                      |transp|transp|    |volumeD|volumeU|
 *                               ,------|------|------|    |-------+-------+------.
 *                               |      |      |lang2 |    | mute  |       |      |
 *                               |mnoSnp|skitch|------|    |-------|transp |1pass |
 *                               |      |      |lang1 |    | pause |       |      |
 *                               `--------------------'    `----------------------'
 *
 */

#include "./fragments/includes.part.h"
#include "./fragments/macros.part.h"
#include "./fragments/types.part.h"
#include "./fragments/variables.part.h"

// ----------------------------------------------------------------------------
// keys
// ----------------------------------------------------------------------------

#include "./fragments/keys.part.h"

// ----------------------------------------------------------------------------
// LED control
// ----------------------------------------------------------------------------

#include "./fragments/led-control.part.h"

// ----------------------------------------------------------------------------
// matrix control
// ----------------------------------------------------------------------------

#include "./fragments/matrix-control.part.h"

// ----------------------------------------------------------------------------
// Custom Functions
// ----------------------------------------------------------------------------

// Bring up the Alfred search bar
void keys__press__alfred(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__Spacebar);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__Spacebar);
}
void R(alfred)(void) {}

// Move one browser tab to the left (for Chrome and Firefox)
// Move one terminal pane to the left (iTerm)
void keys__press__paneL(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__LeftArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftArrow);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
}
void R(paneL)(void) {}

// Move one browser tab to the right (for Chrome and Firefox)
// Move one terminal pane to the right (iTerm)
void keys__press__paneR(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__RightArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__RightArrow);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
}
void R(paneR)(void) {}

// Move one terminal pane up (iTerm)
void keys__press__paneU(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__UpArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__UpArrow);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
}
void R(paneU)(void) {}

// Move one terminal pane down (iTerm)
void keys__press__paneD(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__DownArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__DownArrow);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
}
void R(paneD)(void) {}

// Bring up default iTerm layout
void keys__press__iterm(void) {
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__LeftShift);
    usb__kb__set_key(true, KEYBOARD__r_R);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
    usb__kb__set_key(false, KEYBOARD__LeftShift);
    usb__kb__set_key(false, KEYBOARD__r_R);
}
void R(iterm)(void) {}

// For grave accents eg àèìòù
void keys__press__grvAct(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__GraveAccent_Tilde);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__GraveAccent_Tilde);
}
void R(grvAct)(void) {}

// For acute accents eg áéíóú
void keys__press__acuAct(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__e_E);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__e_E);
}
void R(acuAct)(void) {}

// Bring up Divvy
void keys__press__divvy(void) {
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__LeftShift);
    usb__kb__set_key(true, KEYBOARD__Spacebar);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
    usb__kb__set_key(false, KEYBOARD__LeftShift);
    usb__kb__set_key(false, KEYBOARD__Spacebar);
}
void R(divvy)(void) {}

// Bring up Skitch
void keys__press__skitch(void) {
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__LeftShift);
    usb__kb__set_key(true, KEYBOARD__5_Percent);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
    usb__kb__set_key(false, KEYBOARD__LeftShift);
    usb__kb__set_key(false, KEYBOARD__5_Percent);
}
void R(skitch)(void) {}

// Bring up Monosnap
void keys__press__mnoSnp(void) {
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__5_Percent);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__5_Percent);
}
void R(mnoSnp)(void) {}

// Change focus to next window of app in focus
void keys__press__chWinF(void) {
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__GraveAccent_Tilde);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
    usb__kb__set_key(false, KEYBOARD__GraveAccent_Tilde);
}
void R(chWinF)(void) {}

// Conversation Toggle for Flowdock
void keys__press__dblEsc(void) {
    usb__kb__set_key(true, KEYBOARD__Escape);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__Escape);
    usb__kb__send_report();
    usb__kb__set_key(true, KEYBOARD__Escape);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__Escape);
}
void R(dblEsc)(void) {}

// Bring up 1Password
void keys__press__1pass(void) {
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__Backslash_Pipe);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__Backslash_Pipe);
}
void R(1pass)(void) {}

// Keys to help out in Ruby development
void P(boolAnd)(void) { KF(type_string)( PSTR("&&") ); }
void R(boolAnd)(void) {}
void P(boolOr)(void) { KF(type_string)( PSTR("||") ); }
void R(boolOr)(void) {}
void P(orEq)(void) { KF(type_string)( PSTR("||=") ); }
void R(orEq)(void) {}
void P(andEq)(void) { KF(type_string)( PSTR("&&=") ); }
void R(andEq)(void) {}

void P(erbOpn)(void) { KF(type_string)( PSTR("<%=") ); }
void R(erbOpn)(void) {}
void P(erbCls)(void) { KF(type_string)( PSTR("%>") ); }
void R(erbCls)(void) {}

void P(lte)(void) { KF(type_string)( PSTR("<=") ); }
void R(lte)(void) {}
void P(mte)(void) { KF(type_string)( PSTR(">=") ); }
void R(mte)(void) {}
void P(eqTilde)(void) { KF(type_string)( PSTR("=~") ); }
void R(eqTilde)(void) {}
void P(bangTilde)(void) { KF(type_string)( PSTR("!~") ); }
void R(bangTilde)(void) {}
void P(notEq)(void) { KF(type_string)( PSTR("!=") ); }
void R(notEq)(void) {}
void P(proc)(void) { KF(type_string)( PSTR("->") ); }
void R(proc)(void) {}
void P(hashRkt)(void) { KF(type_string)( PSTR("=>") ); }
void R(hashRkt)(void) {}
void P(plusEq)(void) { KF(type_string)( PSTR("+=") ); }
void R(plusEq)(void) {}
void P(minusEq)(void) { KF(type_string)( PSTR("-=") ); }
void R(minusEq)(void) {}
void P(spermy)(void) { KF(type_string)( PSTR("~>") ); }
void R(spermy)(void) {}
void P(dbEq)(void) { KF(type_string)( PSTR("==") ); }
void R(dbEq)(void) {}

void P(dbColon)(void) { KF(type_string)( PSTR("::") ); }
void R(dbColon)(void) {}
void P(shovelL)(void) { KF(type_string)( PSTR("<<") ); }
void R(shovelL)(void) {}
void P(shovelR)(void) { KF(type_string)( PSTR(">>") ); }
void R(shovelR)(void) {}
void P(rangeInc)(void) { KF(type_string)( PSTR("..") ); }
void R(rangeInc)(void) {}
void P(rangeExc)(void) { KF(type_string)( PSTR("...") ); }
void R(rangeExc)(void) {}

// ----------------------------------------------------------------------------
// layout
// Reference key codes in firmware/lib/layout/keys.h
// and key functions in firmware/keyboard/ergodox/layout/fragments/keys.part.h
// ----------------------------------------------------------------------------

static layout_t layout PROGMEM = {
// ............................................................................

    MATRIX_LAYER(  // layer 0 : Modified QWERTY layout
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
    grave,        1,        2,        3,        4,        5,     dblEsc,
      tab,        q,        w,        e,        r,        t,   chWinF,
    ctrlL,        a,        s,        d,        f,        g,
 shL2kcap,        z,        x,        c,        v,        b,   lpupo1l1,
   grvAct,   acuAct,     guiL,    divvy,   alfred,
                                                                guiL,     altL,
                                                       nop,      nop,     home,
                                                        bs,      del,      end,
// right hand ..... ......... ......... ......... ......... ......... .........
             equal,        6,        7,         8,        9,        0,     dash,

           pipe,        y,        u,         i,        o,        p,    quote,
                           h,        j,         k,        l,  semicol,    ctrlL,
          lpupo1l1,        n,        m,     comma,   period,    slash, shR2kcap,
                                 paneL,     paneR,    paneU,    paneD,   guiL,
    altR,    guiR,
   pageU,      nop,      nop,
   pageD,    enter,    space  ),
// ............................................................................

    MATRIX_LAYER(  // layer 1 : Programmer's toolkit
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
  btldr,       F1,        F2,       F3,       F4,        F5,       F11,
 transp,   transp,    plusEq,  boolAnd,     proc,     notEq,       mte,
 transp,   transp,     andEq,     orEq,  hashRkt,      dbEq,
 transp,   transp,   minusEq,   boolOr,   spermy,   eqTilde,       lte,
    esc,  dbColon,  rangeInc, rangeExc,  shovelR,
                                                              transp,   transp,
                                                    transp,   transp,   lang2,
                                                    mnoSnp,   skitch,   lang1,
// right hand ..... ......... ......... ......... ......... ......... .........
               F12,       F6,       F7,       F8,       F9,      F10,    power,
           shovelL,    pageU,   braceL,    brktL,   erbOpn,   transp,   transp,
                      arrowL,   arrowD,   arrowU,   arrowR,      end,   transp,
              home,    pageD,   braceR,    brktR,   erbCls,  bkslash,   transp,
                                transp,   transp,   transp,   transp,   iterm,
  volumeD,   volumeU,
     mute,    transp,   transp,
    pause,    transp,   1pass  ),

// ............................................................................
};

