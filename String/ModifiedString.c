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
 * The memory address to the String data type created globally
 * @attention Please import the String_maker function, as this is internal and only holds the current value without any type safety measures, to create your own String data types
 */
String_type* _String_current;

int _String_inPosition(char* value, char character){
    int position = strcspn(value, &character);
    return value[position] == '\0' ? -1 : position;
}

int _String_maker_get_position(char character){
    return _String_inPosition(_String_current->get.__copy, character);
}

bool _String_includes(char* value, char character){
    int position = _String_inPosition(value, character);
    return position == -1 ? false : true;
}

bool _String_maker_get_isIncluded(char character){
    return _String_includes(_String_current->get.__copy, character);
}

char** _String_split(char* value, char delimiter, int limit){
    // GETTING THE CURRENT VALUES AND CHECK THE PARAMS
    size_t original_length = _String_current->get.length;
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

    // ALLOCATING MEMORY FOR 1ST INNER ARRAY
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

char** _String_maker_get_splits(char delimiter, int limit){
    return _String_split(_String_current->get.value, delimiter, limit);
}

void _String_maker_utils_clear(){
    free(_String_current);
}

double _String_maker_get_decimalNumber(int radix){
    // GETTING THE VALUE AND CHECKING IF THE VALUES ARE OKAY
    char* value = _String_current->get.__copy;
    size_t original_length = _String_current->get.length;

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
    double result;

    // CHECK IF THE STRING IS A DECIMAL OR A NEGATIVE NUMBER OR IS A VALID DIGIT
    char *possible_characters = "0123456789abcdefghijklmnopqrstuvwxyz";
    char *valid_characters = malloc(radix + 1);
    strncpy(valid_characters, possible_characters, radix); //COPY ONLY THOSE VALID STRINGS

    for (long long unsigned i = 0; i < original_length; i++){
        // CHECK IF VALID AND IF DECIMAL
        if(value[i] == '.'){
            isDecimal = true;
        }else if (!_String_includes(valid_characters, value[i])){
            fprintf(stderr, "The digit '%c' in '%s' is invalid for base %d", value[i], value, radix);
            exit(EXIT_FAILURE);
        }

        // CHECK IF NEGATIVE
        if ((value[i] == '-') && (radix == 10)){
            isNegative = true;
            value = &value[i + 1];
        }
    }

    // DEAL WITH THE DECIMAL PRESCENCE
    if (isDecimal){
        char **split_strings = _String_split(value, '.', 2);
        integer_part = split_strings[0];
        decimal_part = split_strings[1];
    }else{
        integer_part = value;
    }

    //CONVERT THE WHOLE PART TO AN INTEGER
    for (int i = 0; i < (int)strlen(integer_part); i++){
        double power = pow(radix, (strlen(integer_part) - (i + 1)));
        int digit = _String_inPosition(valid_characters, integer_part[i]) * power;
        result += digit;
    }

    // CONVERT THE DECIMAL PART AND ADD IT TO THE RESULT
    if (isDecimal){
        for (int i = 0; i < (int)strlen(decimal_part); i++){
            double power = 1 / pow(radix, i + 1);
            double digit = _String_inPosition(valid_characters, decimal_part[i]) * power;
            result += digit;
        }
    }

    // RETURN THE RESULT
    if (isNegative) result = -(result);
    return result;
}

int _String_maker_get_wholeNumber(int radix){
    // CHECKING THE PARAMS
    if(!radix){
        radix = 10;
    }else if((radix < 2) || (radix > 36)){
        fprintf(stderr, "The base must be between 2 and 36");
        exit(EXIT_FAILURE);
    }

    // CONVERT TO DECIMAL AND ROUND OFF TO GET RESULT
    int result = round(_String_current->get.decimalNumber(radix));
    return result;
}

void _String_maker_utils_revert(){
    _String_current->get.__copy = strdup(_String_current->get.value);
    _String_current->get.length = strlen(_String_current->get.value);
}

char *_String_replace(char *value, char *old_substring, char *new_substring){
    // GETTIG CURRENT VALUES
    size_t original_length = strlen(value);

    // DECLARING VARIABLES
    char* result;
    int index = 0;
    int new_index, count = 0;
    size_t oldsub_length = strlen(old_substring);
    size_t newsub_length = strlen(new_substring);

    // COUNTING HOW MANY TIMES THE REPLACED STRING IS INSIDE THE ORIGINAL STRING
    while(value[index] != '\0'){
        if(strstr(&value[index], old_substring) == &value[index]){
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
    
    while(value[index] != '\0'){
        if(strstr(&value[index], old_substring) == &value[index]){
            strcpy(&result[new_index], new_substring);
            new_index += newsub_length;
            index += oldsub_length;
        }else{
            result[new_index] = value[index];
            new_index += 1;
            index += 1;
        }
    }

    // RETURNING THE NEW STRING
    result[new_index] = '\0';
    return result;
}

String_type* _String_maker_replace(char *old_substring, char *new_substring){
    char* result = _String_replace(_String_current->get.__copy, old_substring, new_substring);
    _String_current->get.__copy = result;
    _String_current->get.length = strlen(result);

    return _String_current;
}

char* _String_maker_get_replaced(char *old_substring, char *new_substring){
    char* result = _String_replace(_String_current->get.__copy, old_substring, new_substring);
    _String_maker_utils_revert();
    return result;
}

void _String_maker_set_value(char* value){
    _String_current->get.value = value;
    _String_current->get.length = strlen(value);
    _String_current->get.__copy = strdup(value);
}

char* _String_reverse(char* value){
    // GETTING CURRENT VALUES
    size_t original_length = strlen(value);

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

String_type* _String_maker_reverse(){
    char* result = _String_reverse(_String_current->get.__copy);
    _String_current->get.__copy = result;
    return _String_current;
}

char* _String_maker_get_reversed(){
   char* result = _String_reverse(_String_current->get.__copy);
   _String_maker_utils_revert();
   return result; 
}

void _String_maker_set_toReverse(){
    char* result = _String_reverse(_String_current->get.__copy);
    _String_maker_set_value(result);
}

char* _String_lowercase(char* value){
    return strlwr(value);
}

String_type* _String_maker_lowercase(){
    char* result = _String_lowercase(_String_current->get.__copy);
    _String_current->get.__copy = result;
    return _String_current;
}

char* _String_maker_get_lowercase(){
    char* result = _String_lowercase(_String_current->get.__copy);
    _String_maker_utils_revert();
    return result;
}

void _String_maker_set_toLowercase(){
    char* result = _String_lowercase(_String_current->get.__copy);
    _String_maker_set_value(result);
}

char* _String_uppercase(char* value){
    return strupr(value);
}

String_type* _String_maker_uppercase(){
    char* result = _String_uppercase(_String_current->get.__copy);
    _String_current->get.__copy = result;
    return _String_current;
}

char* _String_maker_get_uppercase(){
    char* result = _String_uppercase(_String_current->get.__copy);
    _String_maker_utils_revert();
    return result;
}

void _String_maker_set_toUppercase(){
    char* result = _String_uppercase(_String_current->get.__copy);
    _String_maker_set_value(result);
}

String_type* String_maker(char *value){
    // ASSIGNING MEMORY TO THE INSTANCE AND CHECKING IF IT IS SUCCESSFULL
    if (value == NULL){
        fprintf(stderr, "The value pointer passed in decays to a null value");
        exit(EXIT_FAILURE);
    }

    _String_current = malloc(sizeof(String_type));

    if (_String_current == NULL){
        fprintf(stderr, "Error in assigning memory to string data type");
        exit(EXIT_FAILURE);
    }

    // 1. CREATING UTILS SECTION
    String_type_utils utils = {
        .clear = _String_maker_utils_clear,
        .revert = _String_maker_utils_revert
    };

    // 2. CREATING GET SECTION
    String_type_get get = {
        .value = value,
        .__copy = strdup(value),
        .length = strlen(value),

        .decimalNumber = _String_maker_get_decimalNumber,
        .isIncluded = _String_maker_get_isIncluded,
        .lowercase = _String_maker_get_lowercase,
        .uppercase = _String_maker_get_uppercase,
        .position = _String_maker_get_position,
        .replaced = _String_maker_get_replaced,
        .reversed = _String_maker_get_reversed,
        .splits = _String_maker_get_splits,
        .wholeNumber = _String_maker_get_wholeNumber,
    };

    // 3. CREATING SET SECTION
    String_type_set set = {
        .toLowercase = _String_maker_set_toLowercase,
        .toUppercase = _String_maker_set_toUppercase,
        .toReverse = _String_maker_set_toReverse,
        .value = _String_maker_set_value,
    };

    // 4. PUTTING THE PIECES TOGETHER
    _String_current->get = get;
    _String_current->set = set;
    _String_current->utils = utils;

    _String_current->lowercase = _String_maker_lowercase;
    _String_current->uppercase = _String_maker_uppercase;
    _String_current->reverse = _String_maker_reverse;
    _String_current->replace = _String_maker_replace;

    return _String_current;
}