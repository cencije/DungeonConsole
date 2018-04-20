#include "screen.h"

/**
 * Default constructor for the game.
 **/
screen::screen()
{
    input = 'X'; // Generic instantiation
}

/**
 * Deconstructor for the game to properly terminate the program upon completion
 */
screen::~screen() {

}

char  screen::get() {
    return input;
}

// METHOD: Creates the screen and instantiates all the basic necessities
void screen::initialize_screen(){


    // initialize the screen
    initscr();

    // hide the cursor from view (comment this line out for debugging)
    curs_set(0);

    // disables line buffering and erase/kill character-processing
    // (interrupt and flow control characters are unaffected),
    // making characters typed by the  user  immediately
    // available to the program
    cbreak();

    // control whether characters  typed  by  the user  are echoed
    // by getch as they are typed
    noecho();
}

// METHOD: Sets up the keypad to give the program actions.
void screen::initialize_keypad() {

    // the user can press a function key (such as an arrow key) and
    // getch returns a single value representing the  function  key,
    // as in KEY_LEFT
    keypad(stdscr, TRUE);
}

// METHOD: Ends the window.
void screen::end_window() {
    // cleanup the window and return control to bash
    endwin();
}
