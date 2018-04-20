#include <iostream>
#include <string>
#include "board.h"

using namespace std;

int main(int argc, char *argv[])
{
    Board dungeon; // Name of the program that is to be run

    dungeon.initialize_screen(); // Sets up the terminal screen for the TUI
    dungeon.initialize_keypad(); // Sets up the keyboard for live input.

    dungeon.run_game(); // Runs the program
    dungeon.end_window();

    return 0;
}
