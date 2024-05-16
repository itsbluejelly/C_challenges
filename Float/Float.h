/*
    This file contains the struct responsible for the float type methods, which include:
        -toString() --> Converts a decimal to a string
        -toDecimals() --> rounds off a decimal to a string of specified decimal places

NB: THIS STRUCT IS APPLIED TO Float.c

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

// DEFINING A STRUCT TO HOLD THE FLOAT_TYPE STRUCT
typedef struct{
    char* (*toString)(float value, int radix);
    float (*toDecimals)(float value, int digits);
}Float_type;

char* _toString_Float(float value, int radix); // HELPER TOSTRING FUNCTION
float _toDecimals(float value, int digits); // HELPER TODECIMALS FUNCTION
