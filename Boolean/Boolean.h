/*
    This file contains the
        1. Struct declaration that holds the struct type enclosing the boolean
        2. A constructor for the modified boolean
        3. Helper function declarations for the Boolean_type struct

    NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT Boolean.c

    STANDARDS:
        1. The struct defined holds the value and helper functions
        2. All private helper functions(those NOT meant for the struct) and variables follow the pattern "_Boolean_(name)" to prevent naming issues
        3. All private variables within the Boolean struct produced are prefixed with 2 underscores, as they are private
        4. The helper functions(those MEANT for the struct) are defined in the format "_Boolean_maker_(helper fn)", to prevent naming issues
*/

#pragma once

/**
 * The struct definition for the boolean type that contains these properties:
 * 1. Value -> A pointer to the value held within the boolean struct
 * 2. boolValue() -> A function that checks if the value held is true or false
 * 3. clear() -> A function to clear the Boolean data type instance from memory
 */
typedef struct Boolean_type
{
    // A pointer to the value, or an array, of any type held within the boolean struct -> Type void*
    void *value;

    /**
     * A function that checks if the stored value held is true or false
     * @return The string "true" if true and "false" if false -> Type char*
     */
    char *(*boolValue)();

    // A function to clear the Boolean data type instance from memory
    void (*clear)();
} Boolean_type;

/**
 * A function that constructs the Boolean_type struct
 * @param value The address of a value, or an array,  of any type to modify and return with the added functions -> Type void*
 * @return The address of a struct that contains the value and the added functions -> Type Boolane_type*
 */
Boolean_type* Boolean_maker(void* value);

/**
 * A helper function that checks if the stored value is true or false
 * @attention Please use this within the Boolean_maker function, as it is internal
 * @return The string "true" if true and "false" if false -> Type char*
 */
char* _Boolean_maker_boolValue();

/**
 * A helper function that cleares the current Boolean_type instance
 * @attention Please use this within the Boolean_maker function, as it is internal
 */
void _Boolean_maker_clear();