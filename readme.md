# [Firmware][ergodox-firmware] for the [ErgoDox keyboard][]

## Custom Layout Rationale

I wanted to change my layout in ways that were not available to me on the
[Ergodox Layout Configurator](https://www.massdrop.com/ext/ergodox), so I started
compiling the source to customise.

I am primarily a Ruby developer, and type often in other human languages,
so my layout reflects my desire to make these those tasks as efficient as
possible.  This layout is likely to be a constant work in progress.

### Dependencies

This layout was developed on Mac OSX (Yosemite), which didn't have the needed
GNU AVR Toolchain to compile the code, so I used Brew to install it from
[homebrew-avr](https://github.com/larsimmisch/homebrew-avr):

    $ brew tap larsimmisch/avr
    $ brew install avr-libc

In order to make a layout that would compile, I had to fork my branch off the
`partial-rewrite` branch of the original repo and *not* the `master` branch;
the code structure etc has changed significantly from the `master` branch.

### Create/Compile/Load

My custom [layout file](/firmware/keyboard/ergodox/layout/custom-layout.c), was
originally a customisation of the
[`qwerty--ben`](/firmware/keyboard/ergodox/layout/qwerty--ben.c)
layout as it was the easiest layout to get started with.

(I originally tried downloading the source from the Layout Configurator using
the Source Code tickbox, but I couldn't get the generated layout to compile.
I assume this is because of the aforementioned code structure changes, and
that Massdrop is still using the same code that is in the `master` branch of
the original repo.)

Change the makefile options to use your layout when compiling instead of the
default:

    $ vim firmware/keyboard/ergodox/options.mk
    KEYBOARD_LAYOUT := custom-layout # change to your layout file's name

Then, switch to the `firmware/` directory and compile the file using `make`:

    $ cd firmware/
    $ make

Confirm that your `.hex` file has been generated (by default it's called
`firmware.hex`, but this can be changed in the [`makefile`](firmware/makefile),
and now you can load it into the Teensy as per the
[instructions at Massdrop](https://www.massdrop.com/ext/ergodox/assembly#step-13)

---

# rev-2 (`partial-rewrite`)

This branch is currently under development, and all parts are subject to
change.  I'll do my very best to keep the latest commit working properly
though.

Source level documentation is being written with the code.  Other documentation
(including a better readme) will be written afterwards.

**Pull requests for this branch will almost certainly not be accepted at this
time.**
Sorry.  It's a bit hard to explain exactly why.  Perhaps it will be
understandable if I just say that I've been working on this project for quite a
while now, and at this point rev-2 is kind of my baby.  One of my goals for it
is to not only have it work and have decent features, but be well designed and
well documented to the point that someone starting out where I did could pick
it up and learn without having to write their own.  Until it grows up, and I
send it out into the real world by moving it to the master branch, I'm likely
to feel very protective of it.

Notes:
* Gyuri Horak (dyuri) implemented NKRO and mouse keys in [his branch]
  (https://github.com/dyuri/ergodox-firmware) of rev-2.  Not merged, but I plan
  to implement the features later, if I can.  See [Pull Request #28]
  (https://github.com/benblazak/ergodox-firmware/pull/28).
* Oleg Kostyuk (cub-uanic) [ported the TMK firmware]
  (https://github.com/cub-uanic/tmk_keyboard)
  (written by "hasu") to the ErgoDox!

Status:
* (updated 2014-04-12)  School and chores and life in general still taking most
  of my time.  I still plan to finish everything I've already talked about
  though: macro recording, (attempt) USB features, layout examples, and other
  documentation.

