// IMPORTING NECESSARY FILES
#include "Boolean.h"

// DECLARING THE BOOLVALUE FUNCTION
char* _boolValue(bool value){
    if(value){
        return "true";
    }else{
        return "false";
    }
}

// DECLARING THE BOOLEAN TYPE, WHICH IS EXPORTED
Boolean_type Boolean = { .boolValue = _boolValue };