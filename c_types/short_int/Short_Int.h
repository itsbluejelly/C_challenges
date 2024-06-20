/*
    This file contains the struct responsible for the short int type methods, which include:
        -toString() --> Converts a number to a string
        -toDigits() --> rounds off a number to a string of specified digits

NB: THIS STRUCT IS APPLIED TO Short_Int.c

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

#pragma once

// DEFINING A STRUCT TO HOLD THE SHORT_INT_TYPE STRUCT
typedef struct
{
    char *(*toString)(short int value, int radix);
    short int (*toDigits)(short int value, int digits);
} Short_Int_type;

char *_toString_Short(short int value, int radix); // HELPER TOSTRING FUNCTION
short int _toDigits_Short(short int value, int digits);  // HELPER TODIGITS FUNCTION
