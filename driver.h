/***
 * driver.h
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2019
 *
 * This file contains declarations for driver and other
 * staff-implemented functions that are not needed in writing ohhi.cpp
 * and test.cpp.
 */

#ifndef _DRIVER_H_
#define _DRIVER_H_

#include <string>
#include "utility.h"

using namespace std;

//////////////////////////////////////////////////////////////////////
// DRIVER AND OTHER STAFF-IMPLEMENTED FUNCTIONS                     //
// --------------------------------------------                     //
// You likely will not need to call these functions in your code.   //
//////////////////////////////////////////////////////////////////////

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= row && row < size.
 * Modifies: Nothing.
 * Effects : Returns true if and only if the row at board[row] can still be
 *           balanced; meaning that neither blue nor red control more than
 *           half of the tiles.
 * Used In : board_is_balanced()
 */
bool row_is_balanced(const int board[MAX_SIZE][MAX_SIZE], int size, int row);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col && col < size.
 * Modifies: Nothing.
 * Effects : Returns true if and only if the column at board[col] can still be
 *           balanced; meaning that neither blue nor red control more than
 *           half of the tiles.
 * Used In : board_is_balanced()
 */
bool col_is_balanced(const int board[MAX_SIZE][MAX_SIZE], int size, int col);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: Nothing.
 * Effects : Returns true if and only if every row and column of the board
 *           can still be balanced.
 * Used In : board_is_valid()
 */
bool board_is_balanced(const int board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= full_row && full_row < size. The board must be valid.
 * Modifies: board, cout
 * Effects : If full_row is full and a row is almost a duplicate of
 *           full_row, this function will color the unknown squares in
 *           it so the rows do not become duplicates.
 *           If announce is true, prints out a message for each square
 *           that is modified.
 *
 *           Example:  ----              ----
 *                     XXOO   becomes    XXOO
 *                     ----              ----
 *                     -XO-              OXOX
 * Used In : solve()
 */
void solve_duplicates_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int full_row,
                          bool announce);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= full_col && full_col < size. The board must be valid.
 * Modifies: board, cout
 * Effects : If full_column is full and a column is almost a duplicate
 *           of full_column, this function will color the unknown
 *           squares in it so the columns do not become duplicates.
 *           If announce is true, prints out a message for each square
 *           that is modified.
 *
 *           Example:  --O-              X-O-
 *                     O-O-   becomes    O-O-
 *                     X-X-              X-X-
 *                     --X-              O-X-
 * Used In : solve()
 */
void solve_duplicates_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int full_col,
                             bool announce);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: board, cout
 * Effects : Attempts to solve a board by calling each of the solver
 *           functions in turn. Continues to do so until the board is
 *           solved or no more squares can be determined.
 *           Returns the number of remaining unmarked squares, or -1
 *           if the board is invalid.
 *           If announce is true, prints out a message each time a
 *           solver function is called and for each square that is
 *           modified.
 * Used In : solve_and_print(), gen_board()
 */
int solve(int board[MAX_SIZE][MAX_SIZE], int size, bool announce);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: current_board, cout, cin
 * Effects : Prompts the player to enter a move.
 *           Reads in the row, column and color of the player's move.
 *           Checks that the input is valid, and if necessary asks the
 *           player again for input until valid input is given.
 *           Modifies the input square as specified by the user.
 * Used In : play_board()
 */
void make_move(const int original_board[MAX_SIZE][MAX_SIZE],
               int current_board[MAX_SIZE][MAX_SIZE],
               int size);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: board, cout
 * Effects : Generates a random board that can be solved using just
 *           the strategies implemented in solve().
 *           Prints out the number of attempts required to generate a
 *           board.
 * Used In : main()
 */
void gen_board(int board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: Nothing.
 * Modifies: cout
 * Effects : Prints out the menu for the program.
 * Used In : get_menu_choice()
 */
void print_menu();

/**
 * Requires: Nothing.
 * Modifies: cin, cout
 * Effects : Prints the menu and reads input from the user. If the
 *           input is not a valid menu choice, prints an error message
 *           and returns 0. Otherwise returns the user's choice.
 * Used In : main()
 */
int get_menu_choice();

/**
 * Requires: Nothing.
 * Modifies: cin, cout
 * Effects : Prompts the user for an even board size between MIN_SIZE
 *           and MAX_SIZE. Reads in the size from the user and returns
 *           it if valid. Otherwise prints an error message and return
 *           0.
 * Used In : main()
 */
int get_board_size();

/**
 * Requires: color is one of RED, BLUE, UNKNOWN.
 * Modifies: cout
 * Effects : Prints a square representing the given color.
 * Used In : print_board()
 */
void print_color(int color);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects : Returns a new string that containing only the characters
 *           in line that represent colors. Capitalizes color
 *           representations if applicable.
 * Used In : read_board()
 */
string filter_line(string line);

/**
 * Requires: Nothing.
 * Modifies: Nothing.
 * Effects : Returns true if and only if the line has an even length that is
 *           less than or equal to MAX_SIZE, and only contains the
 *           characters 'X', 'O', and '-'.
 * Used In : read_board()
 */
bool line_is_valid(string line);

/**
 * Requires: Symbol must be one of 'X', 'O', 'x', 'o', or '-'.
 * Modifies: Nothing.
 * Effects : Returns the representation for RED, BLUE and UNKNOWN squares
 *           respectively.
 * Used In : read_board(), make_move()
 */
int convert_char_to_color(char symbol);

/**
 * Requires: Nothing.
 * Modifies: board is changed to reflect the input.
 * Effects : Returns the size of the board if the input is valid; returns 0
 *           otherwise.
 * Used In : main()
 */
int read_board(int board[MAX_SIZE][MAX_SIZE]);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col && col < size.
 * Modifies: cout
 * Effects : Checks if the board violates any of the three rules, and prints
 *           messages accordingly. A summary message of whether the board is
 *           valid is also printed. Returns true if the board is valid, false
 *           otherwise.
 * Used In : main()
 */
bool check_and_print(const int board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer.
 * Modifies: cin, cout
 * Effects : Plays the game of 0h h1 on the given board. Prompts the
 *           user for moves, printing the new board state after each
 *           move. Checks each move for validity, printing an error
 *           message if invalid. Congratulates the user upon
 *           completing the board.
 * Used In : main()
 */
void play_board(const int original_board[MAX_SIZE][MAX_SIZE], int size);

/**
 * Requires: size <= MAX_SIZE and size is a positive even integer,
 *           0 <= col && col < size.
 * Modifies: board, by filling in UNKNOWN squares through deduction by the
 *           three rules, cout
 * Effects : A message is printed to cout on whether the board is completely
 *           filled afterwards, or if the board is contradictory, or if the
 *           solver cannot find a solution. The final board is also printed.
 * Used In : main()
 */
void solve_and_print(int board[MAX_SIZE][MAX_SIZE], int size);


#endif // _DRIVER_H_
