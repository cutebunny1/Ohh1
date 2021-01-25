/**
 * main.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183
 * Project 3: 0h h1
 * Fall 2020
 *
 * <#Name(s)#>
 * <#uniqname(s)#>
 *
 * <#A description of the project here#>
 */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include "color.h"
#include "driver.h"
#include "utility.h"
#include "ohhi.h"

using namespace std;

void ohhi() {
    int board[MAX_SIZE][MAX_SIZE];
    int size = 0;

    int menu_choice = get_menu_choice();
    color_enabled(true, menu_choice == 4 || menu_choice == 5);
    if (menu_choice == 2 || menu_choice == 3 || menu_choice == 5) {
        // read the board
        size = read_board(board);
        while (size == 0) {
            cout << "starting over..." << endl;
            cout << endl;
            size = read_board(board);
        }
        cout << endl;

        // print it
        cout << "Your board is:" << endl;
        print_board(board, size);
        cout << endl;

        // check it
        if (!check_and_print(board, size)) {
            return;
        }

        if (menu_choice == 3) {
            solve_and_print(board, size);
        } else {
            play_board(board, size);
        }
    } else if (menu_choice != 0) {
        size = get_board_size();
        while (size == 0) {
            size = get_board_size();
        }

        // seed the random number generator
        srand(static_cast<unsigned int>(time(NULL)));

        gen_board(board, size);
        play_board(board, size);
    }
}

void print_menu() {
    cout << "Menu Options" << endl
         << "------------" << endl;
    cout << "1) Play a random game" << endl;
    cout << "2) Play a custom game" << endl;
    cout << "3) Solve a custom game" << endl;
    cout << "4) Play a random game with colors" << endl;
    cout << "5) Play a custom game with colors" << endl;
    cout << endl;
    cout << "Choice --> ";
}

int get_menu_choice() {
    print_menu();

    int choice;
    cin >> choice;
    if (choice < 1 || choice > 5 || cin.fail()) {
        cout << "Invalid menu choice, quitting" << endl;
        return 0;
    }

    return choice;
}

int get_board_size() {
    cout << "Choose an even board size between " << MIN_SIZE
         << " and " << MAX_SIZE << ": ";

    int size;
    cin >> size;
    if (cin.fail()) {
        cin.clear();
        string s;
        getline(cin, s);
        cout << "Error: invalid size" << endl;
        return 0;
    } else if (size < MIN_SIZE || size > MAX_SIZE) {
        cout << "Error: invalid size" << endl;
        return 0;
    } else if (size % 2 != 0) {
        cout << "Error: size must be even" << endl;
        return 0;
    } else {
        return size;
    }
}

int read_board(int board[MAX_SIZE][MAX_SIZE]) {
    cout << "What board do you want to solve?" << endl;

    // initialize size so the loop will run, but so the size is invalid
    int size = 1;
    for (int row = 0; row < size; row++) {
        string line;
        getline(cin, line);
        line = filter_line(line);
        while (line == "") {
            getline(cin, line);
            line = filter_line(line);
        }

        if (!line_is_valid(line)) {
            return 0;
        }

        // if we don't know the size (it's still the initial value)
        // set the size to however long the line is
        // otherwise, make sure the size matches the line we're reading
        if (size == 1) {
            size = static_cast<int>(line.length());
        } else {
            if (static_cast<int>(line.length()) != size) {
                cout << "Error: every row must be the same size." << endl;
                return 0;
            }
        }

        // modify the board to what the line says
        for (int col = 0; col < size; col++) {
            board[row][col] =  convert_char_to_color(line[col]);
        }
    }

    return size;
}


bool check_and_print(const int board[MAX_SIZE][MAX_SIZE], int size) {
    // print individual checks
    if (board_is_balanced(board, size)) {
        cout << "This board is balanced." << endl;
    } else {
        cout << "This board is NOT balanced." << endl;
    }
    if (board_has_no_threes(board, size)) {
        cout << "This board does not contain threes-in-a-row/column." << endl;
    } else {
        cout << "This board DOES contain threes-in-a-row/column." << endl;
    }
    if (board_has_no_duplicates(board, size)) {
        cout << "This board does not contain duplicate rows/columns." << endl;
    } else {
        cout << "This board DOES contain duplicate rows/columns." << endl;
    }
    cout << endl;

    // and print an overall validity check
    if (board_is_valid(board, size)) {
        cout << "This board is valid; solving..." << endl;
        return true;
    } else {
        cout << "This board is INVALID; quitting..." << endl;
        return false;
    }
}

void solve_and_print(int board[MAX_SIZE][MAX_SIZE], int size) {
    int unknown_squares = solve(board, size, true);
    cout << endl;

    if (unknown_squares == -1) {
        cout << "There is no solution to this board." << endl;
    } else if (unknown_squares == 0) {
        cout << "Solved!" << endl;
    } else {
        cout << "There may be a unique solution, but I can't find it." << endl;
    }
    print_board(board, size);
}

void play_board(const int original_board[MAX_SIZE][MAX_SIZE], int size) {
    int board[MAX_SIZE][MAX_SIZE];
    copy_board(original_board, board, size);

    while (!board_is_solved(board, size)) {
        print_board(board, size);
        make_move(original_board, board, size);
    }

    print_board(board, size);
    cout << "\nCongratulations, you've won!" << endl;
}
