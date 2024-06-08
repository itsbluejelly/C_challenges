#pragma once

// IMPORTING NECESSARY FILES
#include "Boolean.h"
#include <stddef.h>
#include <string.h>

/**
 * The current boolean created globally
 * @attention Please import the Boolean_maker function, as this is internal and only holds the current value without any type safety measures, to create your own Boolean_type structs
 */
Boolean_type Boolean_current;

char* Boolean_maker_boolValue(){
    if ( 
        *(int *)Boolean_current.value == 0 ||
       strcmp(*(char**)Boolean_current.value, "\0") == 0
    ){
        return "false";
    }else{
        return "true";
    }
}

Boolean_type Boolean_maker(void* value){
    if (value == NULL){
        fprintf(stderr, "Must provide a pointer to the value being stored");
        exit(EXIT_FAILURE);
    }
    Boolean_current.boolValue = Boolean_maker_boolValue;
    Boolean_current.value = value;

    return Boolean_current;
}