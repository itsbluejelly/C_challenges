// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
    // IMPORTING INT TYPE
#include "Int.h"
#include "../../String/ModifiedString.c"

// DECLARING THE TOSTRING FUNCTION
char* _toString(int value, int radix){
    // CHECKING IF THE VALUES ARE ADDED APPROPRIATELY
    if(!radix){
        radix = 10;
    }else if(!value){
        fprintf(stderr, "Invalid params, no value is added");
        exit(EXIT_FAILURE);
    }else if((radix < 2) || (radix > 36)){
        fprintf(stderr, "The base must be between 2 and 36");
        exit(EXIT_FAILURE);
    }

    // DECLARING VARIABLES
    int index = 0; 
    bool is_negative = false;
    char* number_string = (char*)malloc(100 * sizeof(char));
    char* valid_characters = "0123456789abcdefghijklmnopqrstuvwxyz";

    // IF NO IS O, RETURN 0
    if(value == 0){
        char* compact_string = (char*)malloc(2 * sizeof(char));

        if(compact_string == NULL){
            fprintf(stderr, "Error allocating memory");
            exit(EXIT_FAILURE);
        }

        strcpy(compact_string, "0");
        return compact_string;
    }

    // IF NO IS -VE, CONVERT TO POSITIVE
    if((value < 0) && (radix == 10)){
        is_negative = true;
        value = -value;
    }

    // OTHERWISE, CONVERT NO TO RIGHT BASE
    while(value){
        int bit = value % radix;
        number_string[index] = valid_characters[bit];
        value /= radix;
        index += 1;
    }

    if(is_negative){
        number_string[index] = '-';
        index += 1;
    }

    number_string[index] = '\0';

    // REVERSE THE RESULTANT STRING
    char* compact_string = realloc(number_string, strlen(number_string) + 1);
    char* string_version = Modified_String.reverse(compact_string);

    return string_version;
}

// THE INT STRUCT
Int_type Int = {.toString = _toString};