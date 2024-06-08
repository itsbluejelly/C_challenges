/*
    This file contains the
        1. Struct declaration that holds the struct type enclosing the boolean
        2. A constructor for the modified boolean
        3. Helper function declarations for the Boolean_type struct

    NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT Boolean.c

    STANDARDS:
        1. The struct defined holds the value and helper functions
        2. The helper functions are defined in the format "Boolean_maker_(helper fn)", to prevent naming issues
        3. Anything to do with the custom type should be prefixed with "Boolean_"
*/

#pragma once

/**
 * The struct definition for the boolean type that contains these properties
 * 1. Value -> A pointer to the value held within the boolean struct
 * 2. boolValue() -> A function that checks if the value held is true or false
 */
typedef struct{
    // A pointer to the value of any type held within the boolean struct -> Type void*
    void* value;

    /**
     * A function that checks if the stored value held is true or false
     * @return The string "true" if true and "false" if false -> Type char*
     */
    char* (*boolValue)();
}Boolean_type;

/**
 * A function that constructs the Boolean_type struct
 * @param value The address of a value of any type to modify and return with the added functions -> Type void*
 * @return A struct that contains the value and the added functions -> Type Boolane_type
 */
Boolean_type Boolean_maker(void* value);

/**
 * A helper function that checks if the stored value is true or false
 * @attention Please use this within the Boolean_maker function, as it is internal
 * @return The string "true" if true and "false" if false -> Type char*
 */
char* Boolean_maker_boolValue();