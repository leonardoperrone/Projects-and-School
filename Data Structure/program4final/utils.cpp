//  utils.cpp
//  Leonardo Perrone
//  F285Y428
//  Assignment Number: 4
//  Last Changed: 3/24/2015

// Description: This module provides functions for getting keyboard input from
//    the user, initially as a string, and converting it to various numeric
//    types.  Each function will repeat the prompt and reading of the user's
//    response until a valid number of the correct type is entered.

#include <iostream>
#include <string>
#include <cstring>      // conversion function parameters use C-strings
#include <cstdlib>      // for conversion functions
#include "utils.hpp"
using namespace std;

// Prompts user to enter number, reads response as string, and converts string
// to int, until a valid number is obtained. Returns the resulting int.
int get_int(string prompt)
{
    char str[20];             // original user input as a C-string
    long num;                 // number converted from user input
    bool valid_number = true; // flag tracks valid conversion of input to number
    char *end_ptr;            // pointer to char after last used in conversion
    
    do {
        if (!valid_number)
        {
            cout << "\nYou must enter an integer. " << endl;
        }
        cout << prompt;
        cin >> str;
        num = strtol(str, &end_ptr, 10);
        if (end_ptr != (str + strlen(str)))
            valid_number = false;
        else
            valid_number = true;
    } while (!valid_number);
    
    return static_cast<int>(num);
}

// Prompts user to enter number, reads response as string, and converts string
// to long, until a valid number is obtained. Returns the resulting long.
long get_long(string prompt)
{
    char str[20];             // original user input as a C-string
    long num;                 // number converted from user input
    bool valid_number = true; // flag tracks valid conversion of input to number
    char *end_ptr;            // pointer to char after last used in conversion
    
    do {
        if (!valid_number)
        {
            cout << "You must enter an integer. ";
        }
        cout << prompt;
        cin >> str;
        num = strtol(str, &end_ptr, 10);
        if (end_ptr != (str + strlen(str)))
            valid_number = false;
        else
            valid_number = true;
    } while (!valid_number);
    
    return num;
}

// Prompts user to enter number, reads response as string, and converts string
// to float, until a valid number is obtained. Returns the resulting float.
float get_float(string prompt)
{
    char str[20];             // original user input as a C-string
    float num;                // number converted from user input
    bool valid_number = true; // flag tracks valid conversion of input to number
    char *end_ptr;            // pointer to char after last used in conversion
    
    do {
        if (!valid_number)
        {
            cout << "You must enter a number. ";
        }
        cout << prompt;
        cin >> str;
        num = strtof(str, &end_ptr);
        if (end_ptr != (str + strlen(str)))
            valid_number = false;
        else
            valid_number = true;
    } while (!valid_number);
    
    return num;
}

// Prompts user to enter number, reads response as string, and converts string
// to double, until a valid number is obtained. Returns the resulting double.
double get_double(string prompt)
{
    char str[20];             // original user input as a C-string
    double num;               // number converted from user input
    bool valid_number = true; // flag tracks valid conversion of input to number
    char *end_ptr;            // pointer to char after last used in conversion
    
    do {
        if (!valid_number)
        {
            cout << "\nYou must enter a number.\n\n ";
        }
        cout << prompt;
        cin >> str;
        num = strtod(str, &end_ptr);
        if (end_ptr != (str + strlen(str)))
            valid_number = false;
        else
            valid_number = true;
    } while (!valid_number);
    
    return num;
}

