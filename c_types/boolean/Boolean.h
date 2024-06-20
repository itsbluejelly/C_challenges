/*
    This file contains the
        1. Struct declaration that holds the struct type enclosing the boolean
        2. Enum declaration for the value type passed in the maker
        2. A constructor for the modified boolean
        3. Helper function declarations for the Boolean_type struct

    NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT Boolean.c

    STANDARDS:
        1. The struct defined holds the value and helper functions
        2. All private helper functions(those NOT meant for the struct) and variables follow the pattern "_Boolean_(name)" to prevent naming issues
        3. All private variables within the Boolean struct produced are prefixed with 2 underscores, as they are private
        4. The helper functions(those MEANT for the struct) are defined in the format "_Boolean_maker_(helper fn)", to prevent naming issues
        5. The enum types contained within the Boolean_type struct are prefixed with "BOOLEAN_(name)_TYPE" to prevent naming conflicts"
*/

#pragma once

// IMPORTING NECESSARY LIBRARIES
#include <stdbool.h>

/**
 * The enum definition for the type of pointer passed in the Boolean_maker, it consists of:
 *  1. array -> For array pointers
 *  2. non-array -> For non-array pointers
 *  3. string-array -> For an array of strings
*/
typedef enum BOOLEAN_VALUE_TYPE
{
    /**
     * This is used for array types, which are pointers-to-pointers.
     * @attention 1. To pass an array, you will have to replace the values in the array with their pointers
     * @attention 2. To pass an array of strings, you will have to use BOOLEAN_VALUE_TYPE_STRING_ARRAY
     */
    BOOLEAN_VALUE_TYPE_ARRAY,

    /**
     * This is used for non-array types, which are pointers-to-value.
     * @attention To pass a string, you will have to use this type
     */
    BOOLEAN_VALUE_TYPE_NON_ARRAY,

    // This is used for an array of strings
    BOOLEAN_VALUE_TYPE_STRING_ARRAY
} BOOLEAN_VALUE_TYPE;

/**
 * The struct definition for the boolean type that contains these properties:
 * 1. value -> A pointer to the value held within the boolean struct
 * 2. type -> A property that holds the type of the pointer stored in the type
 * 2. boolValue() -> A method that checks if the value held is true or false
 * 3. clear() -> A method to clear the Boolean data type instance from memory
 */
typedef struct Boolean_type
{
    // A pointer to the value, or an array, of any type held within the boolean struct -> Type void*
    void *value;
    // A property that holds the type of the pointer stored in the type -> Type BOOLEAN_VALUE_TYPE
    BOOLEAN_VALUE_TYPE type;

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
 * @param value The address of a value, or an array, of any type to modify and return with the added functions -> Type void*
 * @param type The type of pointer passed in, whether a pointer to a specific value or array -> Type BOOLEAN_VALUE_TYPE
 * @return The address of a struct that contains the value and the added functions -> Type Boolean_type*
 */
Boolean_type* Boolean_maker(void* value, BOOLEAN_VALUE_TYPE type);

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