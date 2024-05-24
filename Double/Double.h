/*
    This file contains the struct responsible for the double type methods, which include:
        -toString() --> Converts a decimal to a string
        -toDecimals() --> rounds off a decimal to a string of specified decimal places

NB: THIS STRUCT IS APPLIED TO DOUBLE.c

STANDARDS:
    1. The struct defined holds all helper values
    2. The helper functions are defined with an underscore + name, to prevent naming issues

    3:
        - short int -> 2 bytes
        - int -> 4 bytes
        - unsigned int -> 4 bytes
        - float -> 4 bytes
        - long int -> 8 bytes for 64-bit, 4 bytes for 32-bit
        - unsigned long int -> 8 bytes for 64-bit, 4 bytes for 32-bit
        - long long int -> 8 bytes
        - double -> 8 bytes
        - long double -> 16 bytes for 64-bit, 12 bytes for 32-bit
*/

# pragma once

// DEFINING A STRUCT TO HOLD THE DOUBLE_TYPE STRUCT
typedef struct{
    char* (*toString)(double value, int radix);
    double (*toDecimals)(double value, int digits);
}Double_type;

char* _toString_Double(double value, int radix); // HELPER TOSTRING FUNCTION
double _toDecimals_Double(double value, int digits); // HELPER TODECIMALS FUNCTION
