/*
    This file contains the struct responsible for the long double type methods, which include:
        -toString() --> Converts a decimal to a string

NB: THIS STRUCT IS APPLIED TO LONG DOUBLE.c

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

// DEFINING A STRUCT TO HOLD THE LONG_DOUBLE_TYPE STRUCT
typedef struct{
    char* (*toString)(long double value, int radix);
}Long_Double_type;

char* _toString_Long_Double(long double value, int radix); // HELPER TOSTRING FUNCTION
