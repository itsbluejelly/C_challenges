/* This file contains the struct that hold all functionality of the string type, which include:
    1. length(string) --> The length of the string
    1. reverse(string) --> Reverses a string
    2. toLower(string) --> Converts to lowercase
    3. toUpper(string) --> Converts to uppercase
    4. replace(string original, string replacer) --> Replace a string within a string
    5. split(string original, string delimiter) --> split a string using a delimeter
    6. includes(string original, string included) --> checks if a string has a value included
    7. inPosition(string original, string included) --> returns the index to which a string searched 1st appears
    8. convertToWhole(string) --> Converts a string to a whole number base 10
    9. convertToDecimal(string) --> Converts a string to a decimal number base 10

NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT ModifiedString.c

STANDARDS:
    1. The struct defined holds all helper values
    2. The helper functions are defined with an underscore + name, to prevent naming issues
*/

# pragma once

// A STRUCT TO CONTAIN THE STRING METHODS
typedef struct{
    /*
     * A helper function that returns the length of a string
     * @param value A string to calculate the length -> type char*
     * @return the size of the string -> type size_t
     */
    size_t (*length)(char*);

    /*
     * A function that returns a reversed form of the string
     * @param value A string to reverse -> type char*
     * @return the string reversed -> type char*
     */
    char* (*reverse)(char*);

    /*
     * A function that returns a string all in lowercase
     * @param value A string to convert -> type char*
     * @return the string in lowercase -> type char*
     */
    char* (*toLower)(char*);

    /*
     * A function that returns a string all in uppercase
     * @param value A string to convert -> type char*
     * @return the string in uppercase -> type char*
     */
    char* (*toUpper)(char*);

    /*
     * A function that replaces a subset of a string within the original string with a new one
     * @param original_string The original string to work on -> type char*
     * @param replaced_string The substring to replace -> type char*
     * @param new_string The new substring to replace the old substing -> type char*
     * @return the new string with the new substring -> type char*
     */
    char* (*replace)(char*, char*, char*);
    
    /*
     * A function that splits a string into a subset of strings
     * @param value The string to split -> type char*
     * @param delimeter The character to separate the string on -> type char
     * @param limit The maximum number of substrings to produce -> type int
     * @return An array of substrings -> type char**
     */
    char** (*split)(char*, char, int);

    /**
     * A function that returns the index of where a character is placed, -1 if it isnt in the string
     * @param value The string which has the character -> Type char*
     * @param character The character to search fo -> Type char
     * @return The position of the character in the string
    */
    int (*inPosition)(char*, char);

    /**
     * A function that checks if a string contains a certain character
     * @param value The string which has the character -> Type char*
     * @param character The character to search fo -> Type char
     * @return The string "true" if true and "false" if false
     */
    char* (*includes)(char*, char);
}String_type;

/**
 * A helper function that returns the length of a string
 * @attention Please use this within the Modified String struct, as it is internal
 */
size_t _length(char*);

/**
 * A function that returns a reversed form of the string
 * @attention Please use this within the Modified String struct, as it is internal
 */
char* _reverse(char*);

/**
 * A function that returns a string all in lowercase
 * @attention Please use this within the Modified String struct, as it is internal
 */
char* _toLower(char*);

/**
 * A function that returns a string all in uppercase
 * @attention Please use this within the Modified String struct, as it is internal
 */
char* _toUpper(char* value);

/**
 * A function that replaces a subset of a string within the original string with a new one
 * @attention Please use this within the Modified String struct, as it is internal
 */
char* _replace(char* original_string, char* replaced_string, char* new_string);

/**
 * A function that splits a string into a subset of strings
 * @attention Please use this within the Modified String struct, as it is internal
 */
char** _split(char* value, char delimiter, int limit);

/**
 * A function that returns the index of where a character is placed, -1 if it isnt in the string
 * @attention Please use this within the Modified String struct, as it is internal
*/
int _inPosition(char* value, char character);

/**
 * A function that checks if a string contains a certain character
 * @attention Please use this within the Modified String struct, as it is internal
 */
char* _includes(char* value, char character);