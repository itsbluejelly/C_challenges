#pragma once

// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
    // IMPORTING STRING TYPE
#include "ModifiedString.h"

/**
 * The current String created globally
 * @attention Please import the String_maker function, as this is internal and only holds the current value without any type safety measures, to create your own String_type structs
 */
String_type String_current;

int String_maker_inPosition(char character){
    char* value = *String_current.value;
    int position = strcspn(value, &character);
    return value[position] == '\0' ? -1 : position;
}

bool String_maker_includes(char character){
    int position = String_maker_inPosition(character);
    return position == -1 ? false : true;
}

char** String_maker_split(char delimiter, int limit){
    // GETTING THE CURRENT VALUES AND CHECK THE PARAMS
    char* value = *String_current.value;
    size_t original_length = String_current.length;
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
    result[outer_index] = malloc(original_length + 1);

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
                result[outer_index] = malloc(original_length + 1);

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

float String_maker_convertToDecimal(int radix){
    // GETTING THE VALUE AND CHECKING IF THE VALUES ARE OKAY
    char* value = *String_current.value;
    size_t original_length = String_current.length;

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
    float result;

    // CHECK IF THE STRING IS A DECIMAL OR A NEGATIVE NUMBER OR IS A VALID DIGIT
    char *possible_characters = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *valid_characters = &possible_characters[radix];
    String_type valid_string = String_maker(&valid_characters);

    for (long long unsigned i = 0; i < original_length; i++){
        // CHECK IF VALID
        if (valid_string.includes(value[i])){
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
        char **split_strings = String_current.split('.', 2);
        integer_part = split_strings[0];
        decimal_part = split_strings[1];
    }else{
        integer_part = value;
    }

    // CONVERT THE WHOLE PART TO AN INTEGER
    for (int i = 0; i < (int)strlen(integer_part); i++){
        double power = pow((double)radix, (double)(strlen(integer_part) - (i + 1)));
        int digit = valid_string.inPosition(integer_part[i]) * power;
        result += digit;
    }

    // CONVERT THE DECIMAL PART AND ADD IT TO THE RESULT
    if (decimal_part != NULL){
        for (int i = 1; i <= (int)strlen(decimal_part); i++){
            double power = 1 / (pow((double)radix, (double)i));
            float digit = valid_string.inPosition(integer_part[i]) * power;
            result += digit;
        }
    }else{
        result += 0.0;
    }

    // RETURN THE DECIMAL
    if (isNegative) result = -(result);
    return (result);
}

int String_maker_convertToWhole(int radix){
    // CHECKING THE PARAMS
    if(!radix){
        radix = 10;
    }else if((radix < 2) || (radix > 36)){
        fprintf(stderr, "The base must be between 2 and 36");
        exit(EXIT_FAILURE);
    }

    // CONVERT TO DECIMAL AND ROUND OFF TO GET RESULT
    int result = round(String_current.convertToDecimal(radix));
    return result;
}

char* String_maker_replace(char *replaced_string, char *new_string){
    // GETTIG CURRENT VALUES
    char* original_string = *String_current.value;
    size_t original_length = String_current.length;

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
    result = malloc(original_length + (count * (newsub_length - oldsub_length)) + 1);

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

char* String_maker_reverse(){
    // GETTING CURRENT VALUES
    char* value = *String_current.value;
    size_t original_length = String_current.length;

    // DECLARING VARIABLES
    int start = 0;
    int end = original_length - 1;

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

String_type String_maker(char **value){
    if (value == NULL){
        fprintf(stderr, "Must provide a pointer to the value being stored");
        exit(EXIT_FAILURE);
    }

    String_current.value = value;
    String_current.length = strlen(*value);
    String_current.lowercase = strlwr(strdup(*value));
    String_current.uppercase = strupr(strdup(*value));
    String_current.convertToDecimal = String_maker_convertToDecimal;
    String_current.convertToWhole = String_maker_convertToWhole;
    String_current.includes = String_maker_includes;
    String_current.inPosition = String_maker_inPosition;
    String_current.replace = String_maker_replace;
    String_current.reverse = String_maker_reverse;
    String_current.split = String_maker_split;

    return String_current;
}