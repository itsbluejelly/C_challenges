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

//The struct definition for the "utils" property in the String data type
typedef struct String_type_utils{
    // A method that cleares the current String data type instance from memory
    void (*clear)();

    // A method that reverts any changes made to the temporary copy of the string during chaining back to the actual value stored, useful if you want to undo any changes due to chaining
    void (*revert)();
}String_type_utils;

//The struct definition for the "get" property in the String data type
typedef struct String_type_get{
    /**
     * A property that holds the actual string stored in the data type
     * @attention Please do not change it directly and instead use the setter methods for this purpose, as doing so can tamper with the inner value used by the internal methods
    */
    char* value;

    // A property that holds the length of the stored string
    size_t length;

    /**
     * A property that holds a copy of the actual value
     * @attention 1. Please do not access it directly, as it is used for internal methods within the struct with the value being the actual source of truth, aside from setter functions
     * @attention 2. It is not affected when setter functions are called, as those change the value property itself and directly force this property to mirror the changed value
     */
    char* __copy;

    /**
     * A method that returns the lowercase version of the stored string
     * @returns A copy of the stored value in lowercase form -> Type char*
     */
    char* (*lowercase)();

    /**
     * A method that returns the uppercase version of the stored string
     * @returns A copy of the stored value in uppercase form -> Type char*
     */
    char* (*uppercase)();

    /**
     * A method that returns a reversed form of the stored string
     * @return A copy of the stored value reversed -> type char*
     */
    char* (*reversed)();

    /**
     * A method that returns the stored string with a substring of it replaced by another
     * @param replaced_string The substring to replace -> type char*
     * @param new_string The new substring to replace the old substing -> type char*
     * @return A copy of the stored value with the new substring -> type char*
     */
    char* (*replaced)(char* replaced_string, char* new_string);

    /**
     * A function that returns an array of substrings by splitting the stored value
     * @param delimiter The character to separate the string on -> type char
     * @param limit The maximum number of substrings to produce -> type int
     * @return An array of substrings -> type char**
     */
    char **(*splits)(char delimiter, int limit);

    /**
     * A method that checks if the stored string has a value included
     * @param character The character to search for -> Type char
     * @return The boolean true or false depending on the prescence of the character -> Type bool
     */
    bool (*isIncluded)(char character);

    /**
     * A method that returns the index to which a searched character 1st appears, -1 if it isnt in the string
     * @param character The character to search for -> Type char
     * @return The position of the character in the string -> Type int
     */
    int (*position)(char character);

    /**
     * Converts the stored number string, whether float or int, of a specified base to a whole number base 10
     * @param radix The base the strings digits are in, should be between 2 and 36 -> Type int
     * @return A whole number in base 10 -> Type int
     */
    int (*wholeNumber)(int radix);

    /**
     * Converts the stored number string, whether a float or int, of a specified base to a whole number base 10
     * @param radix The base the strings digits are in, should be between 2 and 36 -> Type int
     * @return A decimal number in base 10 -> Type double
     */
    double (*decimalNumber)(int radix);
}String_type_get;

//The struct definition for the "set" property in the String data type
typedef struct String_type_set{
    /**
     * A method which resets the stored string to a new value
     * @param value The new string to store --> Type char*
     */
    void (*value)(char* value);

    //A method which resets the stored string to the lowercase form of its original value
    void (*toLowercase)();
    // A method which resets the stored string to the uppercase form of its original value
    void (*toUppercase)();
    // A method which resets the stored string to the reverse form of its original value
    void (*toReverse)();
}String_type_set;

/**
 * The struct definition for the String type that contains these properties:
 *  1. utils --> A property containing the utility methods
 *  2. get --> A property that holds all the getter methods
 *  3. set --> A property that holds all the setter methods
 *  ----It also has chaining methods, which only affect the tracked copy, listed below:----
 *  4. lowercase() --> Converts the tracked string to lowercase
 *  5. uppercase() --> Converts the tracked string to uppercase
 *  6. reverse() --> Reverses the tracked string
    7. replace() --> Replace a string within the tracked string
 */
typedef struct String_type{
    /**
     * This property contains all the utility functions which are not associated with the stored value and its mutations, but with the management of the String data type instance instead. Inside it are 2 methods:
     * 1. clear() -> Cleares the current String data type instance from memory
     * 2. revert() -> Reverts any changes made to the temporary copy of the string during chaining
     */
    String_type_utils utils;

    /**
     * This property contains all the getter methods that return a value of a specific type when called without affecting the stored string, suitable for reading one-off values without chaining. Inside it are 12 methods and properties:
     * 1. value -> A property that holds the actual string stored in the data type
     * 2. length -> A property that holds the length of the stored string
     * 3. lowercase() -> A method that returns the lowercase version of the stored string
     * 4. uppercase() -> A method that returns the uppercase version of the stored string
     * 5. reversed() -> A method that returns the reverse version of the stored string
     * 6. splits() -> A method that returns an array of substrings by splitting the stored value
     * 7. isIncluded() -> A method that checks if the stored string has a value included
     * 8. position() -> A method that returns the index to which a searched character 1st appears
     * 9. wholeNumber() -> Converts the stored number string of a specified base to a whole number base 10
     * 10. decimalNumber() -> Converts the stored number string of a specified base to a decimal number base 10
     * 11. replaced() -> A method that returns the stored string with a substring of it replaced by another
     * 12. __copy -> A property that holds a copy of the actual value
     */
    String_type_get get;

    /**
     * This property contains all the setter methods, which reset both the value and the tracked copy to a new value. It has these methods below:
     * 1. value() -> Resets the stored string to a new value
     * 2. toLowercase() -> Resets the stored string to the lowercase form of its original value
     * 3. toUppercase() -> Resets the stored string to the uppercase form of its original value
     * 4. toReverse() -> Resets the stored string to the reverse form of its original value
     */
    String_type_set set;

    /**
     * A method that converts the tracked string to lowercase
     * @return The memory address of the modified String data type -> Type void*
     */
    struct String_type* (*lowercase)();

    /**
     * A method that converts the tracked string to uppercase
     * @return The memory address of the modified String data type -> Type struct String_type*
     */
    struct String_type* (*uppercase)();

    /**
     * A method that reverses the tracked string
     * @return The memory address of the modified String data type -> Type struct String_type*
     */
    struct String_type* (*reverse)();

    /**
     * A method that replaces a string within the tracked string
     * @param replaced_string The substring to replace -> type char*
     * @param new_string The new substring to replace the old substing -> type char*
     * @return The memory address of the modified String data type -> Type struct String_type*
     */
    struct String_type* (*replace)(char* replaced_string, char* new_string);
}String_type;

/**
 * A function that constructs the String data type
 * @param value The string value to modify and return with the added functions -> Type char*
 * @return The memory address of the String data type -> Type String_type*
 */
String_type* String_maker(char *value);

/**
 * A helper private function that returns a string in lowercase
 * @param value The string to work on -> Type char*
 * @return The string in lowercase -> Type char*
 * @attention Please use this within the String data type helper functions, as it is private
 */
char* _String_lowercase(char* value);

/**
 * A helper function that converts the tracked string to lowercase
 * @return The memory address of the modified String data type -> Type String_type*
 * @attention Please use this within the String_type struct, as it is internal
 */
String_type* _String_maker_lowercase();

/**
 * A helper function that converts the tracked string to lowercase, and returns it
 * @return A copy of the stored string in lowercase form -> Type char*
 * @attention Please use this within the String_type struct, as it is internal
 */
char* _String_maker_get_lowercase();

/**
 * A helper function that converts the stored string to its lowercase form
 * @attention Please use this within the String_type struct, as it is internal
 */
void _String_maker_set_toLowercase();

/**
 * A helper private function that returns a string in uppercase
 * @param value The string to work on -> Type char*
 * @return The string in uppercase -> Type char*
 * @attention Please use this within the String data type helper functions, as it is private
 */
char* _String_uppercase(char* value);

/**
 * A helper function that converts the tracked string to uppercase
 * @return The memory address of the modified String data type -> Type String_type*
 * @attention Please use this within the String_type struct, as it is internal
 */
String_type* _String_maker_uppercase();

/**
 * A helper function that converts the tracked string to uppercase, and returns it
 * @return A copy of the stored string in uppercase form -> Type char*
 * @attention Please use this within the String_type struct, as it is internal
 */
char* _String_maker_get_uppercase();

/**
 * A helper function that converts the stored string to its uppercase form
 * @attention Please use this within the String_type struct, as it is internal
 */
void _String_maker_set_toUppercase();

/**
 * A helper private function that reverses a string
 * @param value The string to work on -> Type char*
 * @return The reversed string -> Type char*
 * @attention Please use this within the String data type helper functions, as it is private
 */
char* _String_reverse(char* value);

/**
 * A helper function that converts the tracked string to reverse
 * @return The memory address of the modified String data type -> Type String_type*
 * @attention Please use this within the String_type struct, as it is internal
 */
String_type* _String_maker_reverse();

/**
 * A helper function that converts the tracked string to reverse, and returns it
 * @return A copy of the stored string in reverse form -> Type char*
 * @attention Please use this within the String_type struct, as it is internal
 */
char* _String_maker_get_reversed();

/**
 * A helper function that converts the stored string to its reverse form
 * @attention Please use this within the String_type struct, as it is internal
 */
void _String_maker_set_toReverse();

/**
 * A helper private function that replaces a subset of a string within the original string with a new one
 * @param value The string to work on -> Type char*
 * @param old_substring The substring to replace -> Type char*
 * @param new_substring The new substring to replace the old substing -> Type char*
 * @return the new string with the new substring -> Type char*
 * @attention Please use this within the String data type helper functions, as it is private
 */
char* _String_replace(char* value, char* old_substring, char* new_substring);

/**
 * A helper function that replaces a subset of the tracked string with a new one
 * @return The memory address of the modified String data type -> Type String_type*
 * @param old_substring The substring to replace -> Type char*
 * @param new_substring The new substring to replace the old substing -> Type char*
 * @attention Please use this within the String_type struct, as it is internal
 */
String_type* _String_maker_replace(char* old_substring, char* new_substring);

/**
 * A helper function that replaces a subset of the tracked string with a new one, and returns it
 * @return The new string with the old substring replaced -> Type char*
 * @param old_substring The substring to replace -> Type char*
 * @param new_substring The new substring to replace the old substing -> Type char*
 * @attention Please use this within the String_type struct, as it is internal
 */
char* _String_maker_get_replaced(char* old_substring, char* new_substring);

/**
 * A helper function that resets the stored string with a new one
 * @param value The new string to use -> Type char*
 * @attention Please use this within the String_type struct, as it is internal
 */
void _String_maker_set_value(char* value);

/**
 * A helper function that cleares the current String data type instance from memory
 * @attention Please use this within the String_type struct, as it is internal
*/
void _String_maker_utils_clear();

/**
 * A helper function that reverts any changes made to the tracked copy of the stored string back to the original value
 * @attention Please use this within the String_type struct, as it is internal
*/
void _String_maker_utils_revert();

/**
 * A helper private function that splits a string into a subset of strings, and returns them
 * @param value The string to split -> Type char*
 * @param delimiter The character to separate the string on -> type char
 * @param limit The maximum number of substrings to produce -> type int
 * @return An array of substrings -> type char**
 * @attention Please use this within the String data type helper functions, as it is private
 */
char** _String_split(char* value, char delimiter, int limit);

/**
 * A helper function that splits a string into a subset of strings, and returns them
 * @param delimiter The character to separate the string on -> type char
 * @param limit The maximum number of substrings to produce -> type int
 * @return An array of substrings -> type char**
 * @attention Please use this within the String_type struct, as it is internal
 */
char** _String_maker_get_splits(char delimiter, int limit);

/**
 * A helper private function that returns the index of where a character is placed, -1 if it isnt in the string
 * @param value The string to perform the search on -> Type char*
 * @param character The character to search for -> Type char
 * @return The position of the character in the string -> Type int
 * @attention Please use this within the String data type helper functions, as it is private
 */
int _String_inPosition(char* value, char character);

/**
 * A helper function that returns the index of where a character is placed, -1 if it isnt in the string
 * @param character The character to search for -> Type char
 * @return The position of the character in the string -> Type int
 * @attention Please use this within the String_type struct, as it is internal
 */
int _String_maker_get_position(char character);

/**
 * A helper private function that checks if a string contains a certain character
 * @param value The string to perform the search on -> Type char*
 * @param character The character to search for -> Type char
 * @return The boolean true or false depending on the character's presence -> Type bool
 * @attention Please use this within the String data type helper functions, as it is private
 */
bool _String_includes(char* value, char character);

/**
 * A helper function that checks if a string contains a certain character
 * @param character The character to search for -> Type char
 * @return The boolean true or false depending on the character's presence -> Type bool
 * @attention Please use this within the String_type struct, as it is internal
 */
bool _String_maker_get_isIncluded(char character);

/**
 * A helper function to convert a string, whether a float or int, to a whole number base 10
 * @attention Please use this within the String_type struct, as it is internal
 * @param radix The base the strings digits are in, should be between 2 and 36 -> Type int
 * @return A whole number in base 10 -> Type int
 */
int _String_maker_get_wholeNumber(int radix);

/**
 * A helper function to convert a string, whether a float or int, to a decimal number base 10
 * @attention Please use this within the String_type struct, as it is internal
 * @param radix The base the strings digits are in, should be between 2 and 36 -> Type int
 * @return A decimal number in base 10 -> Type double
 */
double _String_maker_get_decimalNumber(int radix);