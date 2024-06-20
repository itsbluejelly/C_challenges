/*
    This file contains the struct responsible for the unsigned long int type methods, which include:
        -toString() --> Converts a number to a string
        -toDigits() --> rounds off a number to a string of specified digits

NB: THIS STRUCT IS APPLIED TO Unsigned_Long_Int.c

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

// DEFINING A STRUCT TO HOLD THE UNSIGNED_LONG_INT_TYPE STRUCT
typedef struct
{
    char* (*toString)(unsigned long int value, int radix);
    unsigned long int (*toDigits)(unsigned long int value, int digits);
} Unsigned_Long_Int_type;

char *_toString_Unsigned_Long(unsigned long int value, int radix); // HELPER TOSTRING FUNCTION
unsigned long int _toDigits_Unsigned_Long(unsigned long int value, int digits);  // HELPER TODIGITS FUNCTION
