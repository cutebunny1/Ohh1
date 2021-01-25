/**
 * test.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1 Test Suite
 * Fall 2019
 *
 * Kripa Srinivasan, Nikitha Kamath
 * kripas, ndkamath
 *
 * A replica of the 0h h1 puzzle game
 */

#include <iostream>
#include "utility.h"
#include "ohhi.h"

void test_count_unknown_squares();
void test_row_has_no_threes_of_color();
void test_col_has_no_threes_of_color();
void test_board_has_no_threes();
void test_solve_balance_row();
void test_solve_balance_column();
void test_rows_are_different();
void test_cols_are_different();
void test_board_has_no_duplicates();
void test_solve_three_in_a_row();
void test_solve_three_in_a_column();
void test_check_valid_input();
void test_check_valid_move();
// declare more test functions here

void startTests() {
    test_count_unknown_squares();
    test_row_has_no_threes_of_color();
    test_col_has_no_threes_of_color();
    test_board_has_no_threes();
    test_solve_balance_row();
    test_solve_balance_column();
    test_rows_are_different();
    test_cols_are_different();
    test_board_has_no_duplicates();
    test_solve_three_in_a_row();
    test_solve_three_in_a_column();
    test_check_valid_input();
    test_check_valid_move();
    // add your calls to test functions here
}


void test_count_unknown_squares() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 8, Actual: ";
    cout << count_unknown_squares(board, size_1) << endl;

    // test case 2
    string test_board_2[] = {"X--O",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_2 = 4;
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 10, Actual: ";
    cout << count_unknown_squares(board, size_2) << endl;

    // test case 3
    string test_board_3[] = {"XOXO",
                             "-XOO",
                             "-O-X",
                             "--OX"};
    int size_3 = 4;
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 5, Actual: ";
    cout << count_unknown_squares(board, size_3) << endl;
}

// define more test functions here
void test_row_has_no_threes_of_color() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_0[] = {"O-",
                            "OO"};
    int size_0 = 2;
    int row_0 = 0;
    int color_0 = 2;

    read_board_from_string(board, test_board_0, size_0);
    cout << "Expected: 1, Actual: ";
    cout << row_has_no_threes_of_color(board, size_0, row_0, color_0) << endl;
    
    // test case 2
    string test_board_1[] = {"XOXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_1 = 4;
    int row_1 = 0;
    int color = 1;

    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 1, Actual: ";
    cout << row_has_no_threes_of_color(board, size_1, row_1, color) << endl;
    
    // test case 3
    string test_board_2[] = {"XXXO",
                             "--OO",
                             "---X",
                             "--O-"};
    int size_2 = 4;
    int row_2 = 0;
    int color_2 = 1;

    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 0, Actual: ";
    cout << row_has_no_threes_of_color(board, size_2, row_2, color_2) << endl;
}

void test_col_has_no_threes_of_color() {
  int board[MAX_SIZE][MAX_SIZE];

// test case 1
  string test_board_1[] = {"XOXO",
                           "--OO",
                           "---X",
                           "--O-"};
    int size_1 = 4;
    int col_1 = 2;
    int color_1 = 1;

    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 1, Actual: ";
    cout << col_has_no_threes_of_color(board, size_1, col_1, color_1) << endl;

// test case 2
string test_board_2[] = {"XOXO",
                         "--OO",
                         "--OX",
                         "--O-"};
    int size_2 = 4;
    int col_2 = 2;
    int color_2 = 2;

    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 0, Actual: ";
    cout << col_has_no_threes_of_color(board, size_2, col_2, color_2) << endl;

// test case 3
string test_board_3[] = {"XOXO",
                         "X-XO",
                         "X-OX",
                         "--O-"};
    int size_3 = 4;
    int col_3 = 0;
    int color_3 = 1;

    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 0, Actual: ";
    cout << col_has_no_threes_of_color(board, size_3, col_3, color_3) << endl;
}

void test_board_has_no_threes() {
  int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XOXO",
                             "X-XO",
                             "X-OX",
                             "--O-"};
        int size_1 = 4;

        read_board_from_string(board, test_board_1, size_1);
        cout << "Expected: 0, Actual: ";
        cout << board_has_no_threes(board, size_1) << endl;
    
    // test case 2
    string test_board_2[] = {"XXXO",
                             "O-XO",
                             "XOOX",
                             "--O-"};
        int size_2 = 4;

        read_board_from_string(board, test_board_2, size_2);
        cout << "Expected: 0, Actual: ";
        cout << board_has_no_threes(board, size_2) << endl;
    
    // test case 3
    string test_board_3[] = {"XOXO",
                             "O-XO",
                             "XOOX",
                             "--O-"};
        int size_3 = 4;

        read_board_from_string(board, test_board_3, size_3);
        cout << "Expected: 1, Actual: ";
        cout << board_has_no_threes(board, size_3) << endl;
    
    // test case 4
    string test_board_4[] = {"XXXO",
                             "X-XO",
                             "XOOX",
                             "--O-"};
        int size_4 = 4;

        read_board_from_string(board, test_board_4, size_4);
        cout << "Expected: 0, Actual: ";
        cout << board_has_no_threes(board, size_4) << endl;
}

void test_solve_balance_row() {
    int board[MAX_SIZE][MAX_SIZE];
    bool announce = true;
    bool announce_2 = false;

    // test case 1
    string test_board_1[] = {"X-X-",
                            "X-X-",
                            "--OX",
                            "--O-"};
    int size_1 = 4;
    int row = 0;

    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: ";
    cout << "XOXO" << endl
        <<  "X-X-" << endl
        << "--OX" << endl
        <<  "--O-" << endl;
    
    cout << ", Actual: ";
    solve_balance_row(board, size_1, row, announce);
    
    // test case 2
    string test_board_2[] = {"X-X-",
                            "X-X-",
                            "--OX",
                            "--O-"};
    int size_2 = 4;
    int row_2 = 0;

    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: ";
    cout << "XOXO" << endl
        <<  "X-X-" << endl
        << "--OX" << endl
        <<  "--O-" << endl;
    
    cout << ", Actual: ";
    solve_balance_row(board, size_2, row_2, announce_2);
    
    // test case 3
    string test_board_3[] = {"XO",
                            "OX"};
    int size_3 = 2;
    int row_3 = 0;
    
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: " << endl;
    cout << "XO" << endl
         << "OX" << endl;
    
    cout << "Actual: " << endl;
    solve_balance_row(board, size_3, row_3, announce);
    
    // test case 4
    string test_board_4[] = {"X-X-",
                            "X-X-",
                            "OO--",
                            "--O-"};
    int size_4 = 4;
    int row_4 = 2;

    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: " << endl;
    cout << "XOXO" << endl
        <<  "X-X-" << endl
        << "OOXX" << endl
        <<  "--O-" << endl;
    
    cout << "Actual: " << endl;
    solve_balance_row(board, size_4, row_4, announce);
}

void test_solve_balance_column() {
    int board[MAX_SIZE][MAX_SIZE];
    bool announce = true;

    // test case 1
    string test_board_1[] = {"X-X-",
                            "X-X-",
                            "--OX",
                            "--O-"};
    int size_1 = 4;
    int col = 0;

    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: ";
    cout << "X-X-" << endl
        <<  "X-X-" << endl
        << "O-OX" << endl
        <<  "O-O-" << endl;

    cout << ", Actual: "; // maybe add an endl
    solve_balance_column(board, size_1, col, announce);
    
    // test case 2
    string test_board_2[] = {"X---",
                            "X---",
                            "--OX",
                            "--O-"};
    int size_2 = 4;
    int col_2 = 2;

    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: " << endl;
    cout << "X-X-" << endl
        <<  "X-X-" << endl
        <<  "--OX" << endl
        <<  "--O-" << endl;

    cout << "Actual: " << endl;
    solve_balance_column(board, size_2, col_2, announce);
    
    // test case 3
    string test_board_3[] = {"X---",
                            "----",
                            "--OX",
                            "--O-"};
    int size_3 = 4;
    int col_3 = 0;

    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: " << endl;
    cout << "X---" << endl
        <<  "----" << endl
        <<  "--OX" << endl
        <<  "--O-" << endl;

    cout << "Actual: " << endl;
    solve_balance_column(board, size_3, col_3, announce);
}

void test_rows_are_different() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = { "XOOX",
                              "XOOX",
                              "----",
                              "----"};
    int size_1 = 4;
    int row1_1 = 0;
    int row2_1 = 1;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 0, Actual: ";
    cout << rows_are_different(board, size_1, row1_1, row2_1) << endl;
    
    
    // test case 2
    string test_board_2[] = {"XOOX",
                            "XXOO",
                            "----",
                            "----"};
    int size_2 = 4;
    int row1_2 = 0;
    int row2_2 = 1;
    
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 1, Actual: ";
    cout << rows_are_different(board, size_2, row1_2, row2_2) << endl;
    
    
    // test case 3
    string test_board_3[] = {"XO-X",
                            "XOOX",
                            "----",
                            "----"};
    int size_3 = 4;
    int row1_3 = 0;
    int row2_3 = 1;
    
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 1, Actual: ";
    cout << rows_are_different(board, size_3, row1_3, row2_3) << endl;
    
    
    // test case 4
    string test_board_4[] = {"XO-X",
                            "XOOX",
                            "----",
                            "----"};
    int size_4 = 4;
    int row1_4 = 2;
    int row2_4 = 3;
    
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 1, Actual: ";
    cout << rows_are_different(board, size_4, row1_4, row2_4) << endl;
  
    
    // test case 5
    string test_board_5[] = {"XOOX",
                            "XOOX",
                            "----",
                            "----"};
    int size_5 = 4;
    int row1_5 = 0;
    int row2_5 = 1;
    
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: 0, Actual: ";
    cout << rows_are_different(board, size_5, row1_5, row2_5) << endl;
}

void test_cols_are_different() {
    int board[MAX_SIZE][MAX_SIZE];

    // test case 1
    string test_board_1[] = {"XX--",
                            "OO--",
                            "OO--",
                            "XX--"};
    int size_1 = 4;
    int col1_1 = 0;
    int col2_1 = 1;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 0, Actual: ";
    cout << cols_are_different(board, size_1, col1_1, col2_1) << endl;
    
    
    // test case 2
    string test_board_2[] = {"XX--",
                            "OX--",
                            "OO--",
                            "XO--"};
    int size_2 = 4;
    int col1_2 = 0;
    int col2_2 = 1;
    
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 1, Actual: ";
    cout << cols_are_different(board, size_2, col1_2, col2_2) << endl;
    
    
    // test case 3
    string test_board_3[] = {"XX--",
                             "OO--",
                             "-O--",
                             "XX--"};
       int size_3 = 4;
       int col1_3 = 0;
       int col2_3 = 1;
       
       read_board_from_string(board, test_board_3, size_3);
       cout << "Expected: 1, Actual: ";
       cout << cols_are_different(board, size_3, col1_3, col2_3) << endl;
    
    
    // test case 4
    string test_board_4[] = {"OXX-",
                             "XOO-",
                             "-OO-",
                             "OXX-"};
       int size_4 = 4;
       int col1_4 = 1;
       int col2_4 = 2;
       
       read_board_from_string(board, test_board_4, size_4);
       cout << "Expected: 0, Actual: ";
       cout << cols_are_different(board, size_4, col1_4, col2_4) << endl;
    
    
    // test case 5
    string test_board_5[] = {"XX--",
                             "OO--",
                             "----",
                             "XX--"};
       int size_5 = 4;
       int col1_5 = 0;
       int col2_5 = 1;
       
       read_board_from_string(board, test_board_5, size_5);
       cout << "Expected: 1, Actual: ";
       cout << cols_are_different(board, size_5, col1_5, col2_5) << endl;
}

void test_board_has_no_duplicates() {
    int board[MAX_SIZE][MAX_SIZE];
   
    // test case 1
    string test_board_1[] = {"OO--",
                            "XXOO",
                            "XXO-",
                            "O-X-"};
    int size_1 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: 1, Actual: ";
    board_has_no_duplicates(board, size_1);
    cout << endl;
    
    // test case 2
    string test_board_2[] = {"OO--",
                              "XXOO",
                              "XXOO",
                              "O-O-"};
    int size_2 = 4;
      
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: 0, Actual: ";
    board_has_no_duplicates(board, size_2);
    cout << endl;
    

    // test case 3
    string test_board_3[] = {"OOOO",
                            "XOXX",
                            "XXOO",
                            "O-XX"};
    int size_3 = 4;
        
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: 0, Actual: ";
    cout << board_has_no_duplicates(board, size_3) << endl;
        
    // test case 4
    string test_board_4[] = {"OO--",
                            "XOXX",
                            "XXOO",
                            "O--X"};
    int size_4 = 4;
        
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: 1, Actual: ";
    cout << board_has_no_duplicates(board, size_4) << endl;
}

void test_solve_three_in_a_row() {
    int board[MAX_SIZE][MAX_SIZE];
    bool announce = true;
    
    // test case 1
    string test_board_1[] = {"----",
                            "XX--",
                            "-XX-",
                            "--X-"};
    
    int size_1 = 4;
    int row_1 = 1;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: " << endl;
    cout << "----" << endl
         << "XXO-" << endl
         << "-XX-" << endl
         << "--X-" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_row(board, size_1, row_1, announce);
    cout << endl;
    
    
    // test case 2
    string test_board_2[] = {"----",
                            "XX--",
                            "-XX-",
                            "--X-"};
    
    int size_2 = 4;
    int row_2 = 2;
    
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: " << endl;
    cout << "----" << endl
         << "XX--" << endl
         << "OXXO" << endl
         << "--X-" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_row(board, size_2, row_2, announce);
    cout << endl;
    
    
    // test case 3
    string test_board_3[] = {"----",
                            "X-X-",
                            "----",
                            "--X-"};
    
    int size_3 = 4;
    int row_3 = 1;
    
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: " << endl;
    cout << "----" << endl
         << "XOX-" << endl
         << "----" << endl
         << "--X-" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_row(board, size_3, row_3, announce);
    cout << endl;
    
    
    // test case 4
    string test_board_4[] = {"OXOX",
                            "-OO-",
                            "-OX-",
                            "----"};
    int size_4 = 4;
    int row_4 = 1;
    
    read_board_from_string(board, test_board_4, size_4);
    cout << "Expected: " << endl;
    cout << "OXOX" << endl
         << "XOOX" << endl
         << "-OX-" << endl
         << "----" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_row(board, size_4, row_4, announce);
    
    // test case 5
    string test_board_5[] = {"X-X-",
                            "X-X-",
                            "----",
                            "--X-"};
    int size_5 = 4;
    int row_5 = 0;
    
    read_board_from_string(board, test_board_5, size_5);
    cout << "Expected: " << endl;
    cout << "----" << endl
         << "XOX-" << endl
         << "----" << endl
         << "--X-" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_row(board, size_5, row_5, announce);
    
    // test case 6
    string test_board_6[] = {"O-OXX-",
                            "-OO---",
                            "-OX-X-",
                            "----XX",
                            "XX----",
                            "---X-X"};
    int size_6 = 6;
    int row_6 = 4;
    
    read_board_from_string(board, test_board_6, size_6);
    cout << "Expected: " << endl;
    cout << "O-OXX-" << endl <<
            "-OO---" << endl <<
            "-OX-X-" << endl <<
            "----XX" << endl <<
            "XXO---" << endl <<
            "---X-X" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_row(board, size_6, row_6, announce);
    
    // test case 7
    string test_board_7[] = {"O-",
                            "-O"};
    int size_7 = 2;
    int row_7 = 1;
    
    read_board_from_string(board, test_board_7, size_7);
    cout << "Expected: " << endl;
    cout << "O-" << endl
    << "-O" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_row(board, size_7, row_7, announce);
}

void test_solve_three_in_a_column() {
    int board[MAX_SIZE][MAX_SIZE];
    bool announce = true;
    
    // test case 1
    string test_board_1[] = {"----",
                             "XX--",
                             "-XX-",
                             "--X-"};
    int size_1 = 4;
    int col_1 = 1;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: " << endl;
    cout << "-O--" << endl <<
            "XX--" << endl <<
            "-XX-" << endl <<
            "-OX-" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_column(board, size_1, col_1, announce);
    
    // test case 2
    string test_board_2[] = {"----",
                             "X-X-",
                             "----",
                             "--X-"};
    int size_2 = 4;
    int col_2 = 2;
    
    read_board_from_string(board, test_board_2, size_2);
    cout << "Expected: " << endl;
    cout << "----" << endl <<
            "X-X-" << endl <<
            "--O-" << endl <<
            "--X-" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_column(board, size_2, col_2, announce);
    
    
    
    // test case 3
    string test_board_3[] = {"X---",
                             "-X-X",
                             "--XO",
                             "OOX-"};
    int size_3 = 4;
    int col_3 = 3;
    
    read_board_from_string(board, test_board_3, size_3);
    cout << "Expected: " << endl;
    cout << "X---" << endl <<
            "-XOX" << endl <<
            "--XO" << endl <<
            "OOX-" << endl;
    cout << "Actual: " << endl;
    solve_three_in_a_column(board, size_3, col_3, announce);
}

void test_check_valid_input() {
    int board[MAX_SIZE][MAX_SIZE];
    
    // test case 1
    string test_board_1[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int row_input = 2;
    char col_input = 'd';
    char color_char = RED_LETTER;
    int row_1 = 0;
    int col_1 = 0;
    int size_1 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: True " << endl;
    cout << "Actual: ";
    cout << check_valid_input(size_1, row_input, col_input, color_char, row_1, col_1) << endl;
    cout << row_1 << endl;
    cout << col_1 << endl;
    cout << endl;
    
    // test case 2
    string test_board_2[] = {"----",
                             "XXO-",
                             "-XO-",
                             "--X-"};
    int row_input_2 = 2;
    char col_input_2 = 'e';
    char color_char_2 = RED_LETTER;
    int row_2 = 1; //note: this is changed value
    int col_2 = 3;
    int size_2 = 4;
    
    read_board_from_string(board, test_board_1, size_1);
    cout << "Expected: Sorry, that's not a valid input." << endl;
    cout << "Actual: ";
    check_valid_input(size_2, row_input_2, col_input_2, color_char_2, row_2, col_2);
    cout << endl;
}

void test_check_valid_move() {
    int board[MAX_SIZE][MAX_SIZE];
    int board_2[MAX_SIZE][MAX_SIZE];

    // test case 1
    string original_board[] = { "X-----",
                                "X----X",
                                "--O--X",
                                "--O---",
                                "X-----",
                                "---X--"};
    
    string current_board[] = { "X----O",
                               "XOXOOX",
                               "OXO--X",
                               "OXOXXO",
                               "XOXO-X",
                               "O--X--"};

    int size_1 = 6;
    int row_1 = 4;
    int col_1 = 4;
    int color_1 = BLUE;

    read_board_from_string(board, original_board, size_1);
    read_board_from_string(board_2, current_board, size_1);
    cout << "Expected: Sorry, that move violates a rule." << endl << "Actual: ";
    check_valid_move(board, board_2, size_1, row_1, col_1, color_1);
}
