#include "board.h"
Board::Board() {

}
Board::~Board()
{

}

char Board::get_gchar(int yVal, int xVal) {
    return gameboard[yVal][xVal];
}
void Board::make_board() {

    gameboard = new /*(nothrow)*/ char*[rows];

    //if (gameboard == nullptr) throw;
    for(int i = 0; i < rows; i++) gameboard[i] = new char[cols];

    // Sets the characters for the board.
    sideBorder = '|';
    verticalBorder = '-';
    cornerBorder = '+';
    emptyChar = ' ';
    wall = '#';
    checkpoint = 'C';

    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            gameboard[i][j] = emptyChar;
            // Wall Top
            if (i == 1 && j > 0 && j < cols-1)      gameboard[i][j] =
                                                    wall;
            // Wall Bottom
            if (i == rows-1 && j > 0 && j < cols-1) gameboard[i][j] =
                                                    wall;
            // Wall Left and Right
            if (j == 0 || j == cols-1)              gameboard[i][j] =
                                                    wall;
            // Corners of the board
            if (i == 1 || i == 22) {
                if (j == 0 || j == cols - 1) gameboard[i][j] = cornerBorder;
            }
            if (i == 2 && j == 3) gameboard[i][j] = wall;

            if (i == 3 && j == 20) gameboard[i][j] = wall;
            if (i == 4 && j < 20) gameboard[i][j] = wall;
            if (i >= 4 && i < 11 && j == 20) gameboard[i][j] = wall;
            if (i == 9 && j > 20 && j < cols - 2) gameboard[i][j] = wall;
            if (i >= 1 && i < 8 && j == 49) gameboard[i][j] = wall;
            if (i == 3 && j > 50 && j < cols - 2) gameboard[i][j] = wall;
            if (i == 4 && j >= 34 && j <= 36) gameboard[i][j] = wall;
            if (i == 6 && j >= 34 && j <= 36) gameboard[i][j] = wall;
            if (i == 5 && j == 34) gameboard[i][j] = wall;


            if (i == 3 && j == 14) gameboard[i][j] = checkpoint;
            if (i == 2 && j == cols - 3) gameboard[i][j] = checkpoint;
            if (i == 5 && j == 35) gameboard[i][j] = checkpoint;
            if (i == 6 && j == 63) gameboard[i][j] = checkpoint;
            if (i == 8 && j == 49) gameboard[i][j] = sideBorder;
            if (i == 2 && j == 20) gameboard[i][j] = sideBorder;
            if (i == 9 && j == cols - 2) gameboard[i][j] = verticalBorder;
            if (i == 12 && j >= 20) gameboard[i][j] = wall;
            if (i == 11 && j >= 20 && (j % 7 != 0)) gameboard[i][j] = wall;
            if (i == 11 && j == 21) gameboard[i][j] = checkpoint;
            if (i == 12 && j == 21) gameboard[i][j] = verticalBorder;

            //if ()
            if (i == 14 && j > 1 && j < 23 ) gameboard[i][j] = wall;

        }
    }
}

void Board::make_enemies() {
    for (int i = 0; i < 16; i++) {
        equal_obj eq;
        if (i == 0) {
            eq.row = 2;
            eq.col = 10;
            eq.direction = 0;
        }
        if (i == 1) {
            eq.row = 3;
            eq.col = 4;
            eq.direction = 1;
        }
        if (i == 2) {
            eq.row = 3;
            eq.col = 35;
            eq.direction = 1;
        }
        if (i == 3) {
            eq.row = 4;
            eq.col = 30;
            eq.direction = 1;
        }
        if (i == 4) {
            eq.row = 4;
            eq.col = 45;
            eq.direction = 0;
        }
        if (i == 5) {
            eq.row = 6;
            eq.col = 30;
            eq.direction = 1;
        }
        if (i == 6) {
            eq.row = 6;
            eq.col = 45;
            eq.direction = 0;
        }
        if (i == 7) {
            eq.row = 7;
            eq.col = 40;
            eq.direction = 0;
        }
        if (i == 8) {
            eq.row = 8;
            eq.col = 40;
            eq.direction = 1;
        }
        if (i == 9) {
            eq.row = 4;
            eq.col = 60;
            eq.direction = 0;
        }
        if (i == 10) {
            eq.row = 5;
            eq.col = 60;
            eq.direction = 1;
        }
        if (i == 11) {
            eq.row = 6;
            eq.col = 55;
            eq.direction = 0;
        }
        if (i == 12) {
            eq.row = 7;
            eq.col = 70;
            eq.direction = 1;
        }
        if (i == 13) {
            eq.row = 8;
            eq.col = 65;
            eq.direction = 0;
        }
        if (i == 14) {
            eq.row = 10;
            eq.col = 50;
            eq.direction = 0;
        }
        if (i == 15) {
            eq.row = 10;
            eq.col = 65;
            eq.direction = 1;
        }
        equalList.push_back(eq);
    }

}

void Board::run_game() {
    clear();

    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_CYAN, COLOR_BLACK);
    make_board();
    make_enemies();

    player.direction = 2;
    player.row = 2;
    player.col = 1;
    player.livesR = 3;
    player.livesT = 3;
    paused = false;
    draw_area();

    if (!paused) {
        draw_screen();
        do {

            draw_screen();
            // draw the new screen
            refresh();

            usleep(100000);
            time++;

        } while(!quit);
    }
    clear();
}

void Board::draw_area() {
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){

            if (get_gchar(i,j) == '#' || get_gchar(i,j) == '+'){
                attron(COLOR_PAIR(1));
            }
            if (get_gchar(i,j) == '='){
                attron(COLOR_PAIR(2));
            }
            if (get_gchar(i,j) == 'C'){
                attron(COLOR_PAIR(3));
            }
            if (get_gchar(i,j) == '|' || get_gchar(i,j) == '-') {
                attron(COLOR_PAIR(4));
            }
            mvaddch(i, j, get_gchar(i, j));
        }
    }

    mvprintw(0, 18,  "Welcome to DungeonConsole © Joseph Cenci 2018");
    mvprintw(23, 55, "Press Q to Quit");
}

void Board::draw_enemies() {
    for (int i = 0; i < 16; i++)
    {
        equal_obj curEQ = equalList.at(i);
        int x = curEQ.col;
        int y = curEQ.row;

        if (curEQ.direction == 0) {
            if (get_gchar(y,x - 1) == '#' || get_gchar(y, x - 1) == '|') {
                equalList.at(i).direction = 1;
            }
            else {
                gameboard[y][x] = ' ';
                gameboard[y][x - 1] = '=';
                equalList.at(i).col--;
            }
        }
        else {
            if (get_gchar(y,x + 1) == '#' || get_gchar(y, x + 1) == '|') {
                equalList.at(i).direction = 0;
            }
            else {
                gameboard[y][x] = ' ';
                gameboard[y][x + 1] = '=';
                equalList.at(i).col++;
            }
        }
        if (curEQ.row == player.row && curEQ.col == player.col)
        {
            gameboard[player.row][player.col] = ' ';
            deaths++;
            score-= 10;
            if (got5) { player.row = 11; player.col = 21; }
            else if (got3) { player.row = 2; player.col = cols - 3; }
            else if (got2) { player.row = 5; player.col = 35; }
            else { player.row = 2; player.col = 1; }

        }
    }
}

void Board::draw_checkpoints() {
    // 1
    if (!got1) gameboard[3][14] = checkpoint;
    else gameboard[3][14] = emptyChar;
    // 2
    if (!got2) gameboard[5][35] = checkpoint;
    else gameboard[5][35] = emptyChar;
    // 3
    if (!got3) gameboard[2][cols - 3] = checkpoint;
    else gameboard[2][cols - 3] = emptyChar;
    // 4
    if (!got4) gameboard[6][63] = checkpoint;
    else gameboard[6][63] = emptyChar;
    // 5
    if (!got5) gameboard[11][21] = checkpoint;
    else gameboard[11][21] = emptyChar;
    if (got3 && got4)  gameboard[9][cols - 2] = emptyChar;
    //attroff(COLOR_PAIR(3));
}

void Board::draw_screen() {

    clear();

    int ch;
    nodelay(stdscr, TRUE);
    ch = getch();
    if (ch == 'w') {
        if (player.direction != 1)
        {
            player.iconShape = "^";
            player.direction = 1;
        }
        else {
            if (gameboard[player.row - 1][player.col] == ' ' ||
                gameboard[player.row - 1][player.col] == 'C') {
                player.row--;
                score += 1;
            }
        }
    }
    if (ch == 'a') {
        if (player.direction != 4)
        {
            player.iconShape = "<";
            player.direction = 4;
        }
        else {
            if (gameboard[player.row][player.col - 1] == ' ' ||
                gameboard[player.row][player.col - 1] == 'C') {
                player.col--;
                score += 1;
            }
        }

    }
    if (ch == 's') {
        if (player.direction != 3)
        {
            player.iconShape = "v";
            player.direction = 3;
        }
        else {
            if (gameboard[player.row + 1][player.col] == ' ' ||
                gameboard[player.row + 1][player.col] == 'C') {
                player.row++;
                score += 1;
            }
        }
    }
    if (ch == 'd') {
        if (player.direction != 2)
        {
            player.iconShape = ">";
            player.direction = 2;
        }
        else {
            if (gameboard[player.row][player.col + 1] == ' ' ||
                gameboard[player.row][player.col + 1] == 'C') {
                player.col++;
                score += 1;
            }
        }
    }
    if (player.row == 3 && player.col == 14) {
        got1 = true;
        gameboard[2][20] = emptyChar;
    }
    if (player.row == 5 && player.col == 35) {
        got2 = true;
        gameboard[8][49] = emptyChar;
    }
    if (player.row == 2 && player.col == cols - 3){
        got3 = true;
    }
    if (player.row == 6 && player.col == 63) {
        got4 = true;
    }
    if (player.row == 11 && player.col == 21) {
        got5 = true;
        gameboard[12][21] = emptyChar;
    }

    attron(COLOR_PAIR(1));
    draw_area();
    attron(COLOR_PAIR(2));
    draw_enemies();
    attron(COLOR_PAIR(3));
    draw_checkpoints();
    attron(COLOR_PAIR(4));
    string scoreStart = "Score is: ";
    string scoreString = to_string(score);
    string scoreLabel = scoreStart + scoreString;
    mvprintw(23, 1, scoreLabel.c_str());

    string deathStart = "Deaths: ";
    string deathString = to_string(deaths);
    string deathLabel = deathStart + deathString;
    mvprintw(23, 16, deathLabel.c_str());

    string timeStart = "Time is: ";
    string timeString = to_string(time);
    string timeLabel = timeStart + timeString;
    mvprintw(23, 28, timeLabel.c_str());
    attron(COLOR_PAIR(10));
    mvprintw(player.row, player.col, player.iconShape);
    attron(COLOR_PAIR(1));
    if (ch == 'q')
    {
        mvprintw(23, 1, "Are you sure you want to quit? (y/n)               ");
        bool paused = true;
        do {
            int inputQ = getch();
            if (inputQ == 'y') {
                quit = true;
                paused = false;
            }
            if (inputQ == 'n') {
                paused = false;
            }
            sleep(1);
        } while (paused);

    }
}
