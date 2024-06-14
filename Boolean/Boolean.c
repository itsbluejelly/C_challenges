#pragma once

// IMPORTING NECESSARY FILES
#include "Boolean.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * The address of the current Boolean_type instance created globally
 * @attention Please import the Boolean_maker function, as this is internal and only holds the current value without any type safety measures, to create your own Boolean_type structs
 */
Boolean_type* _Boolean_current;

char* _Boolean_maker_boolValue(){
    void **array = _Boolean_current->value;
    
    // 1. IF POINTER LEADS TO NULL, RETURN FALSE
    if(_Boolean_current->value == NULL){
        return "false";
    }

    // 2. DEAL WITH THE TYPE
    if(_Boolean_current->type == BOOLEAN_VALUE_TYPE_ARRAY){
        // VALUE OF DEREFERENCED 1ST ELEMENT IN int** array is 0
        return **(int**)array == 0 ? "false" : "true";
    }else if(_Boolean_current->type == BOOLEAN_VALUE_TYPE_NON_ARRAY){
        if (
            *(int *)array == 0 ||            // VALUE OF DEREFERENCED NUMBER IS ZERO
            strcmp((char *)array, "\0") == 0 // VALUE OF DEREFERENCED STRING IS EMPTY
        ){
            return "false";
        }else{
            return "true";
        }
    }else{
        // VALUE OF DEREFERENCED 1ST ELEMENT IN char** array is 0
        return strcmp(*(char**)array, "\0") == 0 ? "false" : "true";
    }
}

void _Boolean_maker_clear(){
    free(_Boolean_current);
}

Boolean_type* Boolean_maker(void* value, BOOLEAN_VALUE_TYPE type){
    // ASSIGNING MEMORY TO THE INSTANCE AND CHECKING IF IT IS SUCCESSFULL
    _Boolean_current = malloc(sizeof(Boolean_type));

    if (_Boolean_current == NULL){
        fprintf(stderr, "Error in assigning memory to boolean data type");
        exit(EXIT_FAILURE);
    }
    
    // ASSIGNING VALUES TO THE CREATED INSTANCE
    _Boolean_current->value = value;
    _Boolean_current->type = type;
    _Boolean_current->boolValue = _Boolean_maker_boolValue;
    _Boolean_current->clear = _Boolean_maker_clear;

    return _Boolean_current;
}