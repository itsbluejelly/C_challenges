#pragma once

// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <string.h>
#include <ctype.h>
    // IMPORTING STRING TYPE
#include "ModifiedString.h"

// DECLARING HELPER LENGTH FUNCTION
size_t _length(char* value){
    return strlen(value);
}

// DECLARING HELPER REVERSE FUNCTION
char* _reverse(char* value){
    // DECLARING VARIABLES
    int start = 0;
    int end = strlen(value) - 1;

    // LOOPING THROUGH THE STRING AND REVERSING THE STRING
    while(start < end){
        char temp_holder = value[start];
        value[start] = value[end];
        value[end] = temp_holder;
        start += 1;
        end -= 1;
    }

    return value;
}

// DECLARING HELPER TOLOWER FUNCTION
char* _toLower(char* value){
    return strlwr(value);
}

// DECLARING HELPER TOUPPER FUNCTION
char* _toUpper(char* value){
    int index = 0;
    char* result = malloc(strlen(value) + 1);

    while(index < (int)_length(value)){
        result[index] = toupper(value[index]);
        index += 1;
    }

    result[index] = '\0';
    
    return result;
}

// DECLARING THE STRING HELPER STRUCT
String_type Modified_String = {
    .length = _length,
    .reverse = _reverse,
    .toLower = _toLower,
    .toUpper = _toUpper
};