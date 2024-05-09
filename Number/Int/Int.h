/*
    This file contains the struct responsible for the int type methods, which include:
        -toString() --> Converts a number to a string

NB: THIS STRUCT IS APPLIED TO Int.c or Number.h
    
STANDARDS:
    1. The struct defined holds all helper values
    2. The helper functions are defined with an underscore + name, to prevent naming issues
*/

# pragma once

// DEFINING A STRUCT TO HOLD THE INT_TYPE STRUCT
typedef struct{
    char* (*toString)(int);
}Int_type;

// HELPER TOSTRING FUNCTION
char* _toString(int);
