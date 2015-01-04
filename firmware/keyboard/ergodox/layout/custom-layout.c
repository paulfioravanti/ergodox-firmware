/**                                                                 description
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
   grave,        1,        2,        3,        4,        5,      dash,
     tab,        q,        w,        e,        r,        t,   bkslash,
   ctrlL,        a,        s,        d,        f,        g,
shL2kcap,        z,        x,        c,        v,        b,  lpupo1l1,
    caps,    ctrlL,     guiL,     altL,    space,
                                                                guiL,     altL,
                                                       nop,      nop,     home,
                                                        bs,      del,      end,
// right hand ..... ......... ......... ......... ......... ......... .........
             equal,        6,        7,        8,        9,        0,     dash,
           bkslash,        y,        u,        i,        o,        p,    quote,
                           h,        j,        k,        l,  semicol,    ctrlL,
          lpupo1l1,        n,        m,    comma,   period,    slash, shR2kcap,
                                arrowL,   arrowR,    brktL,    brktR,     guiR,
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
                      arrowL,   arrowU,   arrowD,   arrowR, dblQuote,   transp,
            transp,   transp,     dash,   transp,   transp,   transp,   transp,
                                transp,   transp,   transp,   transp,   transp,
  volumeD,   volumeU,
     mute,    transp,   transp,
    pause,     lang1,   transp  ),

// ............................................................................
};

