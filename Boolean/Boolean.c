#pragma once

// IMPORTING NECESSARY FILES
#include "Boolean.h"

static char* _boolValue(bool value){
    if(value){
        return "true";
    }else{
        return "false";
    }
}

/**
 * The struct that contains all helper functions for boolean types
*/
Boolean_type Boolean = { .boolValue = _boolValue };