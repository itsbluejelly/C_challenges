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
    size_t (*length)(char*);
    char* (*reverse)(char*);
    char* (*toLower)(char*);
    char* (*toUpper)(char*);
}String_type;

size_t _length(char*);
char* _reverse(char*);
char* _toLower(char*);
char* _toUpper(char*);