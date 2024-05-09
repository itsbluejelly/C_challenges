/* This file contains the struct that hold all functionality of the string type, which include:
    1. reverse(string) --> Reverses a string

NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT ModifiedString.c

STANDARDS:
    1. The struct defined holds all helper values
    2. The helper functions are defined with an underscore + name, to prevent naming issues
*/

# pragma once

// A STRUCT TO CONTAIN THE STRING METHODS
typedef struct{
    char* (*reverse)(char*);
}String_type;

// HELPER REVERSE METHOD
static char* _reverse(char*);