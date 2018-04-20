#ifndef SCREEN_H
#include <iostream>
#include <string>
#include <curses.h>

#define SCREEN_H

using namespace std;

class screen
{
public:
    screen(); // Default Constructor
    ~screen(); // Deconstructor


    char input; // Key input
    int  cnt; // Integer value that changes

    char get(); // Retrives the number and returns as a char


    void initialize_screen(); // Sets up the screen
    void initialize_keypad(); // Adds the keyboard functionality
    void end_window(); // Clears the window and returns to bash.
};

#endif // SCREEN_H
