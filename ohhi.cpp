/**
 * ohhi.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2020
 *
 * Kripa Srinivasan, Nikitha Kamath
 * kripas, ndkamath
 *
 * A replica of the 0h h1 puzzle game
 */

#include <iostream>
#include <cctype>
#include "utility.h"
#include "ohhi.h"

/**
 * --------------------------------------------------------
 * ---------- UTILITY FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

// counts the number of unknown squares on the board
int count_unknown_squares(const int board[MAX_SIZE][MAX_SIZE], int size) {
    if (size <= MAX_SIZE && size > 0 && size % 2 == 0) {
        int unknownSquares = 0;
        for (int row = 0; row < size; ++row) {
            for (int col = 0; col < size; ++col) {
                if (board[row][col] == UNKNOWN) {
                    ++unknownSquares;
                }
            }
        }
        return unknownSquares;
    }
    return 0;
}

/**
 * --------------------------------------------------------
 * --------- VALIDITY CHECKING FUNCTIONS ------------------
 * --------------------------------------------------------
 */

//checks whether a row has three consecutive elements of the given color
bool row_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int row,
                                int color) {
    for (int col = 0; col < size - 2; ++col) {
        if (board[row][col] == board[row][col + 1] && board[row][col + 1] ==
            board[row][col + 2] && board[row][col] == color) {
            return false;
        }
    }
    return true;
}


//checks whether a column has three consecutive elements of the given color
bool col_has_no_threes_of_color(const int board[MAX_SIZE][MAX_SIZE],
                                int size,
                                int col,
                                int color) {
    for (int row = 0; row < size - 2; ++row) {
        if (board[row][col] == board[row + 1][col] && board[row + 1][col] ==
            board[row + 2][col] && board[row][col] == color) {
            return false;
        }
    }
    return true;
}


//checks whether the board has three consecutive elements of the given color
bool board_has_no_threes(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i < size; i++) {
        if (!row_has_no_threes_of_color(board, size, i, BLUE) ||
            !col_has_no_threes_of_color(board, size, i, BLUE)) {
            return false;
        }
        
        if (!row_has_no_threes_of_color(board, size, i, RED) ||
            !col_has_no_threes_of_color(board, size, i, RED)) {
            return false;
        }
    }
    return true;
}


//checks if the two given rows are different
bool rows_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int row1,
                        int row2) {
    //counter for the number of same elements in two rows
    int same = 0;
    for (int col = 0; col < size; ++col) {
        if (board[row1][col] == board[row2][col]) {
            ++same;
        }
    }
    for (int col = 0; col < size; ++col) {
        if (board[row1][col] == UNKNOWN || board[row2][col] == UNKNOWN ||
            same != size) {
            return true;
        }
    }
    return false;
}


//checks if the two given columns are different
bool cols_are_different(const int board[MAX_SIZE][MAX_SIZE],
                        int size,
                        int col1,
                        int col2) {
    //counter for the number of same elements in two columns
    int same = 0;
    for (int row = 0; row < size; ++row) {
        if (board[row][col1] == board[row][col2]) {
            ++same;
        }
    }
    for (int row = 0; row < size; ++row) {
        if (board[row][col1] == UNKNOWN || board[row][col2] == UNKNOWN ||
            same != size) {
            return true;
        }
    }
    return false;
}


//checks if there are any duplicate rows or columns on the board
bool board_has_no_duplicates(const int board[MAX_SIZE][MAX_SIZE], int size) {
    for (int i = 0; i <= size / 2; ++i) {
        for (int j = size - 1; j > i; --j) {
            if (!rows_are_different(board, size, i, j)) {
                return false;
            }
            else if (!cols_are_different(board, size, i, j)) {
                return false;
            }
        }
    }
    return true;
}    

/**
 * --------------------------------------------------------
 * ---------- SOLVING FUNCTIONS ---------------------------
 * --------------------------------------------------------
 */

//if two consecutive elements in a row are of the same color, marks elements on
//either side as the opposite color
void solve_three_in_a_row(int board[MAX_SIZE][MAX_SIZE],
                          int size,
                          int row,
                          bool announce) {
    for (int i = 0; i < size; ++i) {
        if (board[row][i] == board[row][i + 1] && (i + 1 < size) &&
            board[row][i] != UNKNOWN) {
            if ((i - 1 >= 0) && (board[row][i - 1] == UNKNOWN)) {
                mark_square_as(board, size, row, i - 1,
                               opposite_color(board[row][i]), announce);
            }
            if ((i + 2 < size) && (board[row][i + 2] == UNKNOWN)) {
                mark_square_as(board, size, row, i + 2,
                               opposite_color(board[row][i]), announce);
            }
        }
        
        if ((i + 2 < size) && board[row][i] == board[row][i + 2] &&
            board[row][i + 1] == UNKNOWN && board[row][i] != UNKNOWN) {
            mark_square_as(board, size, row, i + 1,
                           opposite_color(board[row][i]), announce);
        }
    }
    return;
}


//if two consecutive elements in a column are of the same color, marks elements
//on either side as the opposite color
void solve_three_in_a_column(int board[MAX_SIZE][MAX_SIZE],
                             int size,
                             int col,
                             bool announce) {
     for (int i = 0; i < size; ++i) {
         if (board[i][col] == board[i + 1][col] && (i + 1 < size) &&
               board[i][col] != UNKNOWN) {
             if ((i - 1 >= 0) && (board[i - 1][col] == UNKNOWN)) {
                 mark_square_as(board, size, i - 1, col,
                                opposite_color(board[i][col]), announce);
             }
             if ((i + 2 < size) && (board[i + 2][col] == UNKNOWN)) {
                 mark_square_as(board, size, i + 2, col,
                                opposite_color(board[i][col]), announce);
             }
         }
         
         if ((i + 2 < size) && board[i][col] == board[i + 2][col] &&
             board[i + 1][col] == UNKNOWN && board[i][col] != UNKNOWN) {
             mark_square_as(board, size, i + 1, col,
                            opposite_color(board[i][col]), announce);
         }
    }
    return;
}


//if a row has half the number of elements of a color, marks the rest of the
//elements in the row the opposite color
void solve_balance_row(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int row,
                       bool announce) {
    int numRedTiles = 0;
    int numBlueTiles = 0;

    for (int i = 0; i < size; i++) {
        if (board[row][i] == RED) {
            numRedTiles++;
        }
        else if (board[row][i] == BLUE) {
            numBlueTiles++;
        }
    }
        
    if (numRedTiles == (size / 2)) {
        for (int j = 0; j < size; j++) {
            if (board[row][j] == UNKNOWN) {
                mark_square_as(board, size, row, j, opposite_color(RED),
                               announce);
            }
        }
    }
        
    if (numBlueTiles == (size / 2)) {
        for (int j = 0; j < size; j++) {
            if (board[row][j] == UNKNOWN) {
                mark_square_as(board, size, row, j, opposite_color(BLUE),
                               announce);
            }
        }
    }
}


//if a column has half the number of elements of a color, marks the rest of the
//elements in the column the opposite color
void solve_balance_column(int board[MAX_SIZE][MAX_SIZE],
                       int size,
                       int col,
                       bool announce) {
    int numRedTiles = 0;
    int numBlueTiles = 0;

    for (int i = 0; i < size; i++) {
        if (board[i][col] == RED) {
            numRedTiles++;
        }
        else if (board[i][col] == BLUE) {
            numBlueTiles++;
        }
    }
    
    if (numRedTiles == (size / 2)) {
        for (int j = 0; j < size; j++) {
            if (board[j][col] == UNKNOWN) {
                mark_square_as(board, size, j, col, opposite_color(RED),
                               announce);
            }
        }
    }
            
    if (numBlueTiles == (size / 2)) {
        for (int j = 0; j < size; j++) {
            if (board[j][col] == UNKNOWN) {
                mark_square_as(board, size, j, col, opposite_color(BLUE),
                               announce);
            }
        }
    }
}

/**
 * --------------------------------------------------------
 * ---------- GAMEPLAY FUNCTIONS --------------------------
 * --------------------------------------------------------
 */

//checks whether the board is filled and is valid
bool board_is_solved(const int board[MAX_SIZE][MAX_SIZE], int size) {
    if ((count_unknown_squares(board, size) == 0) &&
        board_is_valid(board, size)) {
        return true;
    }
    return false;
}


// determines whether or not a user’s input (i.e. attempted move) corresponds
// to a valid row, column, and color and modifies row and col to be the
// corresponding row and column indices
bool check_valid_input(int size, int row_input, char col_input,
                       char color_char, int &row, int &col) {
    col_input = toupper(col_input);
    color_char = toupper(color_char);
    
    if (row_input >= 1 && row_input <= size && col_input >= 'A' &&
        col_input <= ('A' + size - 1)) {
            if (color_char == RED_LETTER || color_char == BLUE_LETTER ||
                color_char == UNKNOWN_LETTER) {
                row_input -= 1;
                row = row_input;
                
                col_input = col_input - 'A';
                col = col_input;
                return true;
            }
    }
    cout << "Sorry, that's not a valid input." << endl;
    return false;
}


//checks whether a move is valid by ensuring that the element does not exist in
//the original board and that the move does not violate the rules of the game
bool check_valid_move(const int original_board[MAX_SIZE][MAX_SIZE],
                      const int current_board[MAX_SIZE][MAX_SIZE],
                      int size, int row, int col, int color) {
    int newBoard[MAX_SIZE][MAX_SIZE];
    
    copy_board(current_board, newBoard, size);
    
    newBoard[row][col] = color;

    if (original_board[row][col] != UNKNOWN) {
        cout << "Sorry, original squares cannot be changed." << endl;
        return false;
    }
    
    else if (!board_is_valid(newBoard, size)) {
        cout << "Sorry, that move violates a rule." << endl;
        return false;
    }
    
    else {
        return true;
    }
}
