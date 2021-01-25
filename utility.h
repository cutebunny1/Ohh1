/**
 * utility.h
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2019
 *
 * This file contains declarations for global constants and utility
 * functions that are likely to be useful in writing ohhi.cpp and
 * test.cpp.
 */

#ifndef _UTILITY_H_
#define _UTILITY_H_

#include <string>

using namespace std;

//////////////////////////////////////////////////////////////////////
// GLOBAL CONSTANTS                                                 //
// ----------------                                                 //
// These constants should be used where appropriate.                //
//////////////////////////////////////////////////////////////////////

const int MIN_SIZE = 2;
const int MAX_SIZE = 8;

const int UNKNOWN = 0;
const int RED = 1;
const int BLUE = 2;

const char UNKNOWN_LETTER = '-';
const char RED_LETTER = 'X';
const char BLUE_LETTER = 'O';

const string UNKNOWN_STRING = "unknown";
const string RED_STRING = "X";
const string BLUE_STRING = "O";


//////////////////////////////////////////////////////////////////////
// STAFF-IMPLEMENTED UTILITY FUNCTIONS                              //
// -----------------------------------                              //
// These are functions you will likely need to call in your         //
// solution or test suite.                                          //
//////////////////////////////////////////////////////////////////////

/**
 * Requires: Color is one of UNKNOWN, RED, or BLUE.
 * Modifies: Nothing.
 * Effects : Returns the opposite color (RED for BLUE, or BLUE for RED).
 *           If the input color is UNKNOWN, returns UNKNOWN.
 */
int opposite_color(int color);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: cout
 * Effects : Prints a visual representation of the game board to cout.
 *           A line of letters is printed first, from A to (A + size -
 *           1), aligning with the columns in the board.
 *           Then a line of '=' signs is printed, representing the top
 *           border of the board.
 *           Then each row begins with the row number, starting from
 *           1, a '|' representing the left border, the squares in the
 *           row with a space around each of them, a '|' representing
 *           the right border, the row number again, and a newline.
 *           Finally, a line of '=' signs are represnting the bottom
 *           border is printed, and then a line of column letters.
 *
 *           Example:
 *              A B C D
 *             =========
 *           1| - O O - |1
 *           2| X - X - |2
 *           3| - - - - |3
 *           4| - - X - |4
 *             =========
 *              A B C D
 *
 * Used In : main(), solve_and_print(), play_board()
 */
void print_board(const int board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: board
 * Effects : Sets all squares in board to be UNKNOWN
 * Used In : gen_board()
 */
void clear_board(int board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: copy
 * Effects : Modifies copy to have the same colors as board.
 * Used In : play_board(), gen_board(), solving functions
 */
void copy_board(const int board[MAX_SIZE][MAX_SIZE],
                int copy [MAX_SIZE][MAX_SIZE],
                int size);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= row && row < size && 0 <= col && col < size.
 * Modifies: cout, board so (row, col) becomes color
 * Effects : Changes the given square in the board to the given color.
 *           If announce is true, prints the changed square and the
 *           new color in English.
 * Used In : all solving and gameplay functions
 */
void mark_square_as(int board[MAX_SIZE][MAX_SIZE],
                    int size,
                    int row,
                    int col,
                    int color,
                    bool announce);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 * Modifies: Nothing.
 * Effects : This is the main driver for checking that a board is valid.
 *           It calls the three board-checking functions, then returns true if
 *           and only if all of those functions returns true; otherwise this
 *           function returns false
 * Used In : solve(), check_and_print(), gen_board()
 */
bool board_is_valid(const int board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: Each string in board_string is of length size.
 *           size <= MAX_SIZE and size is a positive even integer.
 * Modifies: board is changed to reflect the input.
 * Effects : Returns true if the input is valid; returns false otherwise
 * Used In : test suite
 */
bool read_board_from_string(int board[MAX_SIZE][MAX_SIZE],
                            string board_string[MAX_SIZE],
                            int size);


#endif // _UTILITY_H_
