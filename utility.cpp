/**
 * utility.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2019
 *
 * This file contains implementations of utility functions that are likely
 * to be useful in writing ohhi.cpp and test.cpp.
 */

#include <iostream>
#include "driver.h"
#include "utility.h"
#include "ohhi.h"

using namespace std;

///////////////////////////////////////
// UTILITY FUNCTIONS //////////////////
///////////////////////////////////////

int opposite_color(int color) {
    if (color == RED) {
        return BLUE;
    } else if (color == BLUE) {
        return RED;
    }
    return UNKNOWN;
}

// Helper functions for print_board().
void print_col_header(int size);
void print_horizontal_boundary(int size);

void print_board(const int board[MAX_SIZE][MAX_SIZE], int size) {
    print_col_header(size);
    print_horizontal_boundary(size);

    for (int row = 0; row < size; row++) {
        cout << row + 1 << '|';
        for (int col = 0; col < size; col++) {
            cout << ' ';
            print_color(board[row][col]);
        }
        cout << " |" << row + 1 << endl;
    }

    print_horizontal_boundary(size);
    print_col_header(size);
}

void clear_board(int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            board[row][col] = UNKNOWN;
        }
    }
}

void copy_board(const int board[MAX_SIZE][MAX_SIZE],
                int copy [MAX_SIZE][MAX_SIZE],
                int size) {
    for (int row = 0; row < size; row++) {
        for (int col = 0; col < size; col++) {
            copy[row][col] = board[row][col];
        }
    }
}

void mark_square_as(int board[MAX_SIZE][MAX_SIZE],
                    int size,
                    int row,
                    int col,
                    int color,
                    bool announce) {
    if (announce) {
        cout << "marking (" << row + 1 << ", "
             << static_cast<char>(col + 'A') << ") as ";
        if (color == RED) {
            cout << RED_STRING;
        } else if (color == BLUE) {
            cout << BLUE_STRING;
        } else {
            cout << UNKNOWN_STRING;
        }
        cout << endl;
    }
    board[row][col] = color;
}

bool board_is_valid(const int board[MAX_SIZE][MAX_SIZE], int size) {
    return (board_is_balanced(board, size) &&
            board_has_no_threes(board, size) &&
            board_has_no_duplicates(board, size));
}

bool read_board_from_string(int board[MAX_SIZE][MAX_SIZE],
                            string board_string[MAX_SIZE],
                            int size) {
    for (int row = 0; row < size; row++) {
        string line = board_string[row];

        if (!line_is_valid(line)) {
            return false;
        }

        for (int col = 0; col < size; col++) {
            board[row][col] =  convert_char_to_color(line[col]);
        }
    }

    return true;
}


///////////////////////////////////////
// print_board() HELPER FUNCTIONS /////
///////////////////////////////////////

void print_col_header(int size) {
    cout << "  ";
    for (int col = 0; col < size; col++) {
        cout << ' ' << static_cast<char>('A' + col);
    }
    cout << endl;
}

void print_horizontal_boundary(int size) {
    cout << "  =";
    for (int col = 0; col < size; col++) {
        cout << "==";
    }
    cout << endl;
}
