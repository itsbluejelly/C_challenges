#pragma once

// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
    // IMPORTING STRING TYPE
#include "ModifiedString.h"

size_t _length(char* value){
    return strlen(value);
}

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

char* _toLower(char* value){
    return strlwr(value);
}

char* _toUpper(char* value){
    int index = 0;
    char* result = malloc(strlen(value) + 1);

    if(result == NULL){
        fprintf(stderr, "Error allocating memory for actual compact string\n");
        exit(EXIT_FAILURE);
    }

    while(index < (int)_length(value)){
        result[index] = toupper(value[index]);
        index += 1;
    }

    result[index] = '\0';
    
    return result;
}

char* _replace(char* original_string, char* replaced_string, char* new_string){
    // DECLARING VARIABLES
    char* result;
    int index = 0;
    int new_index, count = 0;
    size_t oldsub_length = strlen(replaced_string);
    size_t newsub_length = strlen(new_string);

    // COUNTING HOW MANY TIMES THE REPLACED STRING IS INSIDE THE ORIGINAL STRING
    while(original_string[index] != '\0'){
        if(strstr(&original_string[index], replaced_string) == &original_string[index]){
            count += 1;
            index += oldsub_length;
        }else{
            index += 1;
        }
    }

    // CREATING AN ACCURATE STRING FOR THE RESULT
    result = malloc(strlen(original_string) + (count * (newsub_length - oldsub_length)) + 1);

    if(result == NULL){
        fprintf(stderr, "Error allocating memory for actual compact string\n");
        exit(EXIT_FAILURE);
    }

    // REPLACING THE OLD STRING WITH THE NEW SUB STRING
    index = 0;
    new_index = 0;
    
    while(original_string[index] != '\0'){
        if(strstr(&original_string[index], replaced_string) == &original_string[index]){
            strcpy(&result[new_index], new_string);
            new_index += newsub_length;
            index += oldsub_length;
        }else{
            result[new_index] = original_string[index];
            new_index += 1;
            index += 1;
        }
    }

    // RETURNING THE NEW STRING
    result[new_index] = '\0';
    return result;
}

char** _split(char* value, char delimiter, int limit){
    // RETURN NULL IF LIMIT IS INVALD
    if(limit <= 0) return NULL;

    // DECLARING VARIABLES
    char** result;
    int outer_index = 0;
    int inner_index, index = 0;

    // ALLOCATING MEMORY FOR RESULT ARRAY
    result = malloc(limit * sizeof(char *));

    if(result == NULL){
        fprintf(stderr, "Error allocating memory for the array of strings\n");
        exit(EXIT_FAILURE);
    }

    // ALLOCATING MEMORY FOR INNER ARRAY
    result[outer_index] = malloc(strlen(value) + 1);

    if(result[outer_index] == NULL){
        fprintf(stderr, "Error allocating memory for the string at index %d\n", outer_index);
        exit(EXIT_FAILURE);
    }

    // LOOPING THROUGH THE STRING TO SPLIT IT
    inner_index = 0;

    while(value[index] != '\0'){
        if(value[index] == delimiter){
            // DEAL WITH THE JUST FINISHED SUBSTRING
            result[outer_index][inner_index] = '\0';

            // RECALCULATE THE INDEXES
            outer_index += 1;
            inner_index = 0;
            
            if(outer_index >= limit){
                break;
            }else{
                result[outer_index] = malloc(strlen(value) + 1);

                if(result[outer_index] == NULL){
                    fprintf(stderr, "Error allocating memory for the string at index %d\n", outer_index);
                    exit(EXIT_FAILURE);
                }
            }
        }else{
            result[outer_index][inner_index] = value[index];
            inner_index += 1;
        }

        index += 1;
    }

    // RETURNING THE ARRAY OF STRINGS
    result[outer_index][inner_index] = '\0';
    result[outer_index + 1] = NULL;

    return result;
}

int _inPosition(char* value, char character){
    int position = strcspn(value, &character);
    return value[position] == '\0' ? -1 : position;
}

char* _includes(char* value, char character){
    int position = _inPosition(value, character);
    return position == -1 ? "false" : "true";
}

int _convertToWhole(char* value, int radix){
    // CHECKING IF THE VALUES ARE OKAY
    if(!radix){
        radix = 10;
    }else if((radix < 2) || (radix > 36)){
        fprintf(stderr, "The base must be between 2 and 36");
        exit(EXIT_FAILURE);
    }

    // CONVERT TO DECIMAL AND ROUND OFF TO GET RESULT
    int result = round(_convertToDecimal(value, radix));
    return result;
}

float _convertToDecimal(char *value, int radix){
    // CHECKING IF THE VALUES ARE OKAY
    if (!radix){
        radix = 10;
    }else if ((radix < 2) || (radix > 36)){
        fprintf(stderr, "The base must be between 2 and 36");
        exit(EXIT_FAILURE);
    }

    // DECLARING VARIABLES
    bool isNegative = false;
    bool isDecimal = false;
    char *decimal_part, *integer_part;
    char *validCharacters = "0123456789abcdefghijklmnopqrstuvwxyz";
    float result;

    // CHECK IF THE STRING IS A DECIMAL OR A NEGATIVE NUMBER OR IS A VALID DIGIT
    for (long long unsigned i = 0; i < strlen(value); i++){
        // CHECK IF VALID
        char *value_exists = _includes(&validCharacters[radix], value[i]);
        if (strcmp(value_exists, "true") == 0){
            fprintf(stderr, "The digit '%c' in '%s' is invalid for base %d", value[i], value, radix);
            exit(EXIT_FAILURE);
        }

        // CHECK IF DECIMAL
        if (value[i] == '.') isDecimal = true;

        // CHECK IF NEGATIVE
        if ((value[i] == '-') && (radix == 10)){
            isNegative = true;
            value = &value[i + 1];
        }
    }

    // DEAL WITH THE DECIMAL PRESCENCE
    if (isDecimal){
        char **split_strings = _split(value, '.', 2);
        integer_part = split_strings[0];
        decimal_part = split_strings[1];
    }else{
        integer_part = value;
    }

    // CONVERT THE WHOLE PART TO AN INTEGER
    for (int i = 0; i < (int)strlen(integer_part); i++){
        double power = pow((double)radix, (double)(strlen(integer_part) - (i + 1)));
        int digit = _inPosition(validCharacters, integer_part[i]) * power;
        result += digit;
    }

    // CONVERT THE DECIMAL PART AND ADD IT TO THE RESULT
    if (decimal_part != NULL){
        for (int i = 1; i <= (int)strlen(decimal_part); i++){
            double power = 1 / (pow((double)radix, (double)i));
            float digit = _inPosition(validCharacters, decimal_part[i]) * power;
            result += digit;
        }
    }else{
        result += 0.0;
    }

    // RETURN THE DECIMAL
    if (isNegative) result = -(result);
    return (result);
}

/**
 * The struct that contains all helper functions for a modified string
 */
String_type Modified_String = {
    .length = _length,
    .reverse = _reverse,
    .toLower = _toLower,
    .toUpper = _toUpper,
    .replace = _replace,
    .split = _split,
    .inPosition = _inPosition,
    .includes = _includes,
    .convertToWhole = _convertToWhole,
    .convertToDecimal = _convertToDecimal
};