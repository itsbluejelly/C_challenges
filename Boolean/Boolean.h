/* This file contains the struct that hold all functionality of the boolean type, which include:
    1. boolValue(bool) -> A function that accepts a bool and returns a string "true" if its true or "false" if its false

NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT Boolean.c

STANDARDS:
    1. The struct defined holds all helper values
    2. The helper functions are defined with an underscore + name, to prevent naming issues
*/

#pragma once

// IMPORTING NECESSARY LIBRARIES
#include <stdbool.h>

// THE STRUCT CONTAINING ALL HELPER FUNCTIONS
typedef struct{
    char* (*boolValue)(bool value);
}Boolean_type;

// HELPER BOOLVALUE FUNCTION
static char* _boolValue(bool value);