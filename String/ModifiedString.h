/*
    This file contains the
        1. Struct declaration that holds all the setter functions for the String_type struct
        2. Struct declaration that holds all the getter functions for the String_type struct
        3. Struct declaration that holds all the utils functions for the String_type struct
        4. Struct declaration that holds the struct type enclosing the string
        5. A constructor for the modified string
        6. Helper function declarations for the String_type struct
        7. Helper functions for the whole String_type helper functions😅

    NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT ModifiedString.c

    STANDARDS:
        1. The struct defined holds the necessary structs and helper functions
        2. All private helper functions(those NOT meant for the struct) and variables follow the pattern "_String_(name)" to prevent naming issues
        3. All private variables within the String struct produced are prefixed with 2 underscores, as they are private
        4. The helper functions(those MEANT for the struct) are defined in the format "_String_maker_(helper fn)", to prevent naming issues
        5. The structs types contained within the String_type struct are prefixed with "String_type_(name) to prevent naming conflicts"
*/

# pragma once

// IMPORTING NECESSARY LIBRARIES
#include <stdbool.h>

/**
 * The struct definition for the utils property in the String data type, which holds the utils functions. These functions include:
 * 1. clear() -> Deletes the current String data type instance from memory
 * 2. revert() -> Reverts any changes made to the temporary copy of the string during chaining to the actual value stored, useful if you want to undo any changes after chaining
 */
typedef struct String_type_utils{
    // A function that deletes the current String data type instance from memory
    void (*clear)();
    // A function that reverts any changes made to the temporary copy of the string during chaining to the actual value stored
    void (*revert)();
}String_type_utils;

/**
 * The struct definition for the string type that contains these properties
 *  1. value --> A pointer to the string value held within the struct
 *  2. length --> The length of the string
 *  3. lowercase --> The string in lowercase
 *  4. uppercase --> The string in uppercase
 *  5. reverse() --> Reverses a string
    6. replace() --> Replace a string within a string
    7. split() --> split a string using a delimeter
    8. includes() --> checks if a string has a value included
    9. inPosition() --> returns the index to which a string searched 1st appears
    10. convertToWhole() --> Converts a string representing a number of a specified base to a whole number base 10
    11. convertToDecimal() --> Converts a string representing a number of a specified base to a decimal number base 10
 */
typedef struct{
    // A pointer to the value held within the struct --> Type char**
    char** value;
    // The length of the stored string --> Type size_t
    size_t length;
    // The string in lowercase form --> Tye char*
    char* lowercase;
    // The string in uppercase form --> Tye char*
    char* uppercase;

    /**
     * A function that returns a reversed form of the stored string
     * @return the string reversed -> type char*
     */
    char* (*reverse)();

    /**
     * A function that replaces a subset of the original string with a new one
     * @param replaced_string The substring to replace -> type char*
     * @param new_string The new substring to replace the old substing -> type char*
     * @return the new string with the new substring -> type char*
     */
    char* (*replace)(char*, char*);
    
    /**
     * A function that splits the stored string into a subset of strings
     * @param delimeter The character to separate the string on -> type char
     * @param limit The maximum number of substrings to produce -> type int
     * @return An array of substrings -> type char**
     */
    char** (*split)(char, int);

    /**
     * A function that returns the index of where a character is placed, -1 if it isnt in the string
     * @param character The character to search for -> Type char
     * @return The position of the character in the string -> Type int
    */
    int (*inPosition)(char);

    /**
     * A function that checks if the stored string contains a certain character
     * @param character The character to search for -> Type char
     * @return The boolean true or false depending on the prescence of the character -> Type bool
     */
    bool (*includes)(char);

    /**
     * A function to convert the stored string, whether a float or int, to a whole number base 10
     * @param radix The base the strings digits are in, should be between 2 and 36 -> Type int
     * @return A whole number in base 10 -> Type int
    */
    int (*convertToWhole)(int);

    /**
     * A function to convert a string, whether a float or int, to a decimal number base 10
     * @param radix The base the strings digits are in, should be between 2 and 36 -> Type int
     * @return A decimal number in base 10 -> Type double
    */
    float (*convertToDecimal)(int);
}String_type;

/**
 * A function that constructs the String_type struct
 * @param value An address to the string value to modify and return with the added functions -> Type string**
 * @return A struct that contains the value and the added functions -> Type String_type
 */
String_type String_maker(char **value);

/**
 * A helper function that returns a reversed form of the stored string
 * @return the string reversed -> type char*
 * @attention Please use this within the Modified String struct, as it is internal
 */
char* String_maker_reverse();

/**
 * A function that replaces a subset of a string within the original string with a new one
 * @param replaced_string The substring to replace -> type char*
 * @param new_string The new substring to replace the old substing -> type char*
 * @return the new string with the new substring -> type char*
 * @attention Please use this within the Modified String struct, as it is internal
 */
char* String_maker_replace(char* replaced_string, char* new_string);

/**
 * A function that splits a string into a subset of strings
 * @param delimiter The character to separate the string on -> type char
 * @param limit The maximum number of substrings to produce -> type int
 * @return An array of substrings -> type char**
 * @attention Please use this within the Modified String struct, as it is internal
 */
char** String_maker_split(char delimiter, int limit);

/**
 * A function that returns the index of where a character is placed, -1 if it isnt in the string
 * @param character The character to search for -> Type char
 * @return The position of the character in the string -> Type int
 * @attention Please use this within the Modified String struct, as it is internal
 */
int String_maker_inPosition(char character);

/**
 * A function that checks if a string contains a certain character
 * @param character The character to search for -> Type char
 * @return The boolean true or false depending on the character's presence -> Type bool
 * @attention Please use this within the Modified String struct, as it is internal
 */
bool String_maker_includes(char character);

/**
 * A function to convert a string, whether a float or int, to a whole number base 10
 * @attention Please use this within the Modified String struct, as it is internal
 * @param radix The base the strings digits are in, should be between 2 and 36 -> Type int
 * @return A whole number in base 10 -> Type int
 */
int String_maker_convertToWhole(int radix);

/**
 * A function to convert a string, whether a float or int, to a decimal number base 10
 * @attention Please use this within the Modified String struct, as it is internal
 * @param radix The base the strings digits are in, should be between 2 and 36 -> Type int
 * @return A decimal number in base 10 -> Type double
 */
float String_maker_convertToDecimal(int radix);