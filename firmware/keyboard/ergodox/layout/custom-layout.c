/**
 * My QWERTY layout, at the moment.  I expect this will evolve over time.
 *
 * Implements the "layout" section of '.../firmware/keyboard.h'
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
void keys__press__paneLeft(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__LeftArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftArrow);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
}
void R(paneLeft)(void) {}

// Move one browser tab to the right (for Chrome and Firefox)
// Move one terminal pane to the right (iTerm)
void keys__press__paneRight(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__RightArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__RightArrow);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
}
void R(paneRight)(void) {}

// Move one terminal pane up (iTerm)
void keys__press__paneUp(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__UpArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__UpArrow);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
}
void R(paneUp)(void) {}

// Move one terminal pane down (iTerm)
void keys__press__paneDown(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__DownArrow);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__DownArrow);
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
}
void R(paneDown)(void) {}

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
void keys__press__graveAcnt(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__GraveAccent_Tilde);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__GraveAccent_Tilde);
}
void R(graveAcnt)(void) {}

// For acute accents eg áéíóú
void keys__press__acuteAcnt(void) {
    usb__kb__set_key(true, KEYBOARD__LeftAlt);
    usb__kb__set_key(true, KEYBOARD__e_E);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftAlt);
    usb__kb__set_key(false, KEYBOARD__e_E);
}
void R(acuteAcnt)(void) {}

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

// Change focus to next window of app in focus
void keys__press__chWinFoc(void) {
    usb__kb__set_key(true, KEYBOARD__LeftGUI);
    usb__kb__set_key(true, KEYBOARD__GraveAccent_Tilde);
    usb__kb__send_report();
    usb__kb__set_key(false, KEYBOARD__LeftGUI);
    usb__kb__set_key(false, KEYBOARD__GraveAccent_Tilde);
}
void R(chWinFoc)(void) {}

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
    grave,        1,        2,        3,        4,        5,        esc,
      tab,        q,        w,        e,        r,        t,   chWinFoc,
    ctrlL,        a,        s,        d,        f,        g,
 shL2kcap,        z,        x,        c,        v,        b,   lpupo1l1,
graveAcnt,acuteAcnt,     guiL,     divvy,    alfred,
                                                                guiL,     altL,
                                                       nop,      nop,     home,
                                                        bs,      del,      end,
// right hand ..... ......... ......... ......... ......... ......... .........
             equal,        6,        7,         8,        9,        0,     dash,
           bkslash,        y,        u,         i,        o,        p,    quote,
                           h,        j,         k,        l,  semicol,    ctrlL,
          lpupo1l1,        n,        m,     comma,   period,    slash, shR2kcap,
                              paneLeft, paneRight,   paneUp, paneDown,    iterm,
    altR,    guiR,
   pageU,      nop,      nop,
   pageD,    enter,    space  ),
// ............................................................................

    MATRIX_LAYER(  // layer 2 : symbols and function keys
// macro, unused,
       K,    nop,
// left hand ...... ......... ......... ......... ......... ......... .........
  btldr,       F1,       F2,       F3,       F4,       F5,      F11,
  transp,   quote, dblQuote,    colon,    equal, grtrThan,   transp,
  transp,   brktL,    brktR,   braceL,   braceR,     pipe,
  transp,   transp,  transp,    space,    enter,   transp,   transp,
  transp,   transp,   transp,   transp,   transp,
                                                              transp,   transp,
                                                    transp,   transp,   transp,
                                                    transp,    lang2,   transp,
// right hand ..... ......... ......... ......... ......... ......... .........
               F12,       F6,       F7,       F8,       F9,      F10,    power,
            transp,    tilde,     plus,    equal,   transp,   transp,   transp,
                      arrowL,   arrowD,   arrowU,   arrowR, dblQuote,   transp,
            transp,   transp,     dash,   transp,   transp,   transp,   transp,
                                transp,   transp,   transp,   transp,   transp,
  volumeD,   volumeU,
     mute,    transp,   transp,
    pause,     lang1,   transp  ),

// ............................................................................
};

