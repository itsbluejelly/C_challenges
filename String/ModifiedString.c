#pragma once

// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
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
            // REALLOCATE MEMORY AND DEAL WITH THE JUST FINISHED SUBSTRING
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
    
    if(value[position] == '\0'){
        return -1;
    }else{
        return position;
    }
}

char* _includes(char* value, char character){
    int position = _inPosition(value, character);
    
    if(position == -1){
        return "false";
    }else{
        return "true";
    }
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
    .includes = _includes
};