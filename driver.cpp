/***
 * driver.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2020
 *
 * This file contains implementations of driver and other
 * staff-implemented functions that are not needed in writing ohhi.cpp
 * and test.cpp.
 */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include "color.h"
#include "driver.h"
#include "utility.h"
#include "ohhi.h"

using namespace std;

///////////////////////////////////////
// I/O HELPER FUNCTIONS ///////////////
///////////////////////////////////////

void print_color(int color) {
    if (color == RED) {
        set_color(LIGHTRED_CODE);
        cout << RED_LETTER;
        reset_color();
    } else if (color == BLUE) {
        set_color(LIGHTCYAN_CODE);
        cout << BLUE_LETTER;
        reset_color();
    } else {
        cout << UNKNOWN_LETTER;
    }
}

string filter_line(string line) {
    string result = "";
    for (size_t i = 0; i < line.length(); i++) {
        // throw away everything but 'X', 'x', 'O', 'o', and '-'
        char ch = toupper(line[i]);
        if (ch == RED_LETTER || ch == BLUE_LETTER ||
            ch == UNKNOWN_LETTER ) {
            result += ch;
        }
    }
    return result;
}

bool line_is_valid(string line) {
    if (line.length() % 2 == 1) {
        cout << "ERROR: a board must have "
             << "an even number of squares to each side." << endl;
        return false;
    } else if (line.length() > MAX_SIZE) {
        cout << "ERROR: a board can be at most "
             << MAX_SIZE << " by " << MAX_SIZE << endl;
        return false;
    }
    for (int col = 0; col < static_cast<int>(line.length()); col++) {
        if (line[col] != RED_LETTER &&
            line[col] != BLUE_LETTER &&
            line[col] != UNKNOWN_LETTER) {
            cout << "ERROR: unknown symbol "
                 << "'" << line[col] << "'" << endl;
            return false;
        }
    }
    return true;
}

int convert_char_to_color(char symbol) {
    if (toupper(symbol) == UNKNOWN_LETTER) {
        return UNKNOWN;
    } else if (toupper(symbol) == RED_LETTER) {
        return RED;
    } else if (toupper(symbol) == BLUE_LETTER) {
        return BLUE;
    }
    return 0;
}


///////////////////////////////////////
// VALIDITY CHECKS ////////////////////
///////////////////////////////////////

bool row_is_balanced(const int board[MAX_SIZE][MAX_SIZE], int size, int row) {
    int red_count = 0;
    int blue_count = 0;

    // sum the contents of the row
    for (int col = 0; col < size; col++) {
        if (board[row][col] == RED) red_count++;
        else if (board[row][col] == BLUE) blue_count++;
    }

    // check if it's possible to solve the row
    if (red_count > size / 2 || blue_count > size / 2) {
        return false;
    } else {
        return true;
    }
}

bool col_is_balanced(const int board[MAX_SIZE][MAX_SIZE], int size, int col) {
    int red_count = 0;
    int blue_count = 0;

    // sum the contents of the column
    for (int row = 0; row < size; row++) {
        if (board[row][col] == RED) red_count++;
        else if (board[row][col] == BLUE) blue_count++;
    }

    // check if it's possible to solve the column
    if (red_count > size / 2 || blue_count > size / 2) {
        return false;
    } else {
        return true;
    }
}

bool board_is_balanced(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        // if any row or column cannot be balanced, the board is invalid
        if (!row_is_balanced(board, size, i) ||
            !col_is_balanced(board, size, i)) {
            return false;
        }
    }
    return true;
}


///////////////////////////////////////
// SOLVER DRIVER //////////////////////
///////////////////////////////////////

void solve_duplicates_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int full_row,
                          bool announce) {
    // check that the row has all of one color
    int num_red = 0;
    int num_blue = 0;
    for (int col = 0; col < size; col++) {
        if (board[full_row][col] == RED) {
            num_red++;
        } else if (board[full_row][col] == BLUE) {
            num_blue++;
        }
    }

    // if all of one color is present, that's the color we're looking for
    int color = UNKNOWN;
    if (num_red == size / 2) {
        color = RED;
    } else if (num_blue == size / 2) {
        color = BLUE;
    }

    // Find a row which has all but one of this color
    // and only has two UNKNOWN squares.
    // Since this function is called after solve_balance_row,
    // the two missing squares are guaranteed to be of different colors.
    int matching_squares = 0;
    if (color != UNKNOWN) {
        for (int other_row = 0; other_row < size; other_row++) {
            if (other_row == full_row) {
                continue;
            }
            matching_squares = 0;
            for (int col = 0; col < size; col++) {
                if (board[other_row][col] == board[full_row][col]) {
                    matching_squares += 2;
                } else {
                    matching_squares--;
                }
            }
            if (matching_squares == 2 * size - 6) {
                for (int col = 0; col < size; col++) {
                    if (board[other_row][col] == UNKNOWN) {
                        mark_square_as(board, size, other_row, col,
                                       opposite_color(board[full_row][col]),
                                       announce);
                    }
                }
            }
        }
    }
}

void solve_duplicates_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int full_col,
                             bool announce) {
    // check that the column has all of one color
    int num_red = 0;
    int num_blue = 0;
    for (int row = 0; row < size; row++) {
        if (board[row][full_col] == RED) {
            num_red++;
        } else if (board[row][full_col] == BLUE) {
            num_blue++;
        }
    }

    // if all of one color is present, that's the color we're looking for
    int color = UNKNOWN;
    if (num_red == size / 2) {
        color = RED;
    } else if (num_blue == size / 2) {
        color = BLUE;
    }

    // Find a column which has all but one of this color
    // and only has two UNKNOWN squares.
    // Since this function is called after solve_balance_column,
    // the two missing squares are guaranteed to be of different colors.
    int matching_squares = 0;
    if (color != UNKNOWN) {
        for (int other_col = 0; other_col < size; other_col++) {
            if (other_col == full_col) {
                continue;
            }
            matching_squares = 0;
            for (int row = 0; row < size; row++) {
                if (board[row][other_col] == board[row][full_col]) {
                    matching_squares += 2;
                } else {
                    matching_squares--;
                }
            }
            if (matching_squares == 2 * size - 6) {
                for (int row = 0; row < size; row++) {
                    if (board[row][other_col] == UNKNOWN) {
                        mark_square_as(board, size, row, other_col,
                                       opposite_color(board[row][full_col]),
                                       announce);
                    }
                }
            }
        }
    }
}

int solve(int board[MAX_SIZE][MAX_SIZE], int size, bool announce) {
    if (!board_is_valid(board, size)) {
        return -1;
    }

    int unknown_squares_now = count_unknown_squares(board, size);
    int unknown_squares_old = unknown_squares_now + 1;
    while (unknown_squares_now != 0 &&
           unknown_squares_old > unknown_squares_now) {
        unknown_squares_now = count_unknown_squares(board, size);
        unknown_squares_old = unknown_squares_now + 1;

        // keep blocking threes-in-a-row/column until there are
        // no more to block
        if (announce) {
            cout << "looking for threes-in-a-row/column..." << endl;
        }
        while (unknown_squares_old > unknown_squares_now) {
            unknown_squares_old = unknown_squares_now;

            for (int row = 0; row < size; row++) {
                solve_three_in_a_row(board, size, row, announce);
            }
            for (int col = 0; col < size; col++) {
                solve_three_in_a_column(board, size, col, announce);
            }

            unknown_squares_now = count_unknown_squares(board, size);
        }

        // look for rows/columns with all of one color and fill in
        // the rest
        if (unknown_squares_now != 0) {
            if (announce) {
                cout << "looking for rows/columns with half "
                     << RED_STRING << "/" << BLUE_STRING << "..."
                     << endl;
            }
            for (int row = 0; row < size; row++) {
                solve_balance_row(board, size, row, announce);
            }
            for (int col = 0; col < size; col++) {
                solve_balance_column(board, size, col, announce);
            }
            unknown_squares_now = count_unknown_squares(board, size);
        }

        // look for rows/columns that could be duplicates and avoid it
        if (unknown_squares_now != 0 &&
            unknown_squares_now == unknown_squares_old) {
            if (announce) {
                cout << "looking for potential duplicate rows/columns..."
                     << endl;
            }
            for (int row = 0; row < size; row++) {
                solve_duplicates_row(board, size, row, announce);
            }
            for (int col = 0; col < size; col++) {
                solve_duplicates_column(board, size, col, announce);
            }
            unknown_squares_now = count_unknown_squares(board, size);
        }
    }

    if (!board_is_valid(board, size)) {
        return -1;
    }

    return unknown_squares_now;
}


///////////////////////////////////////
// INTERACTIVE GAMEPLAY ///////////////
///////////////////////////////////////

void make_move(const int original_board[MAX_SIZE][MAX_SIZE],
               int current_board[MAX_SIZE][MAX_SIZE],
               int size) {
    int row_input;
    char col_input;
    char color_char;
    int row;
    int col;

    cout << "\nPlease enter your move (ROW COLUMN COLOR): ";
    cin >> row_input >> col_input >> color_char;
    cout << "Read: " << row_input << " " << col_input << " "
         << color_char << endl;
    while (cin.fail() ||
           !check_valid_input(size, row_input, col_input, color_char,
                              row, col) ||
           !check_valid_move(original_board, current_board,
                             size, row, col,
                             convert_char_to_color(color_char))) {
        if (cin.fail()) {
            cin.clear();
            string s;
            getline(cin, s);
            cout << "Sorry, that's not a valid input." << endl;
        }

        cout << "\nPlease enter your move (ROW COLUMN COLOR): ";
        cin >> row_input >> col_input >> color_char;
        cout << "Read: " << row_input << " " << col_input << " "
             << color_char << endl;
    }

    int color = convert_char_to_color(color_char);
    mark_square_as(current_board, size, row, col, color, false);
    cout << endl;
}

void gen_board(int board[MAX_SIZE][MAX_SIZE], int size) {
    int attempts = 0;
    bool made_board = false;
    int copy[MAX_SIZE][MAX_SIZE];

    while (!made_board) {
        // try from scratch
        clear_board(board, size);

        int unknowns = size * size;
        // make random valid moves until either the board is known to
        // be solvable or unsolvable
        while (unknowns > 0) {
            bool valid = false;
            int row = 0;
            int col = 0;
            int color = UNKNOWN;

            // reset copy to current board
            copy_board(board, copy, size);

            // find a random valid move
            while (!valid) {
                // generate a move
                row = rand() % size;
                col = rand() % size;
                if (rand() % 2 == 0) {
                    color = RED;
                } else {
                    color = BLUE;
                }

                // try new move
                int old_color = copy[row][col];
                copy[row][col] = color;
                valid = board_is_valid(copy, size);

                // if invalid, undo move
                if (!valid) {
                    copy[row][col] = old_color;
                }
            }

            // make move and attempt to solve
            board[row][col] = color;
            unknowns = solve(copy, size, false);
        }

        // if solve returned -1, then board is unsolvable; try again
        made_board = (unknowns == 0);
        attempts++;
    }

    cout << "Generated a board after " << attempts << " attempt(s)."
         << endl << endl;

    return;
}
