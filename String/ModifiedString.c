// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <string.h>
    // IMPORTING STRING TYPE
#include "ModifiedString.h"

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

// DECLARING THE STRING HELPER STRUCT
String_type Modified_String = {.reverse = _reverse};