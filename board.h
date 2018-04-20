#ifndef BOARD_H
#include "screen.h"
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <vector>

#define BOARD_H

class Board :public screen
{
public:
    Board();
    ~Board();

    void draw_area();
    void draw_screen(); // Prints the game to the screen
    void make_enemies();
    void draw_enemies();
    void draw_checkpoints();
    char get_gchar(int yVal, int xVal);
    int time = 0;

    bool quit = false;
    int score = 0;
    int deaths = 0;
    char ** gameboard;
    char sideBorder;
    char verticalBorder;
    char cornerBorder;
    char emptyChar;
    char wall;
    char checkpoint;

    int rows = 23;
    int cols = 78;
    void make_board();
    void run_game();
    int currentVal = 2;
    bool moveRight = true;
    bool paused = true;

    bool got1, got2, got3, got4, got5 = false;
    struct player_obj {
        int direction;
        int row;
        int col;
        int livesT;
        int livesR;
        char *iconShape = ">";
    };
    struct equal_obj {
        int direction;
        int row;
        int col;
        char *iconShape = "=";

    };
    struct percent_obj {
        int direction;
        int row;
        int col;
        char *iconShape = "%";

    };

    vector<equal_obj> equalList;
    vector<percent_obj> percentList;
    player_obj player;
};

#endif // BOARD_H
