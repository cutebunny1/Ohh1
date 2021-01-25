/**
 * start.cpp
 * Project UID 5557cbe19b6ff413629a3743c503275413233136
 *
 * EECS 183: Project 3
 *
 * main() function selects between executing your test cases
 * and the main application.
 * 
 * You do not need to make any changes to this file or
 * submit it to the autograder.
 */

#include <iostream>
#include <string>

using namespace std;

//************************************************************************
// Function declarations. Function definitions are in birthdays.cpp and test.cpp
//************************************************************************
void ohhi();
void startTests();

int main()
{

    cout << "-------------------------------" << endl
         << "EECS 183 Project 3 Menu Options" << endl
         << "-------------------------------" << endl;
    cout << "1) Execute testing functions in test.cpp" << endl;
    cout << "2) Execute ohhi() function in main.cpp" << endl;
    cout << "Choice --> ";

    int choice;
    cin >> choice;

    // remove the return character from the cin stream buffer
    string junk;
    getline(cin, junk);

    cout << endl;

    if (choice == 1)
    {
        startTests();
    }
    else if (choice == 2)
    {
        ohhi();
    }

    return 0;
}
