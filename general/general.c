#pragma once

// IMPORTING NECESSARY FILES
    // IMPORTING HEADER FILES
#include "general.h"
    // IMPORTING LIBRARIES
#include <stdlib.h>
#include <stdio.h>

void General_Error_Generator(GENERAL_ERROR_CODES_TYPE code, char* message){
    switch(code){
        case GENERAL_ERROR_CODE_INVALID_VALUE:
            fprintf(stderr, "Error:\n\tInvalid value error: code %3d\n\t\t-> %s", code, message);
            break;
        case GENERAL_ERROR_CODE_MEMORY_ALLOCATION:
            fprintf(stderr, "Error:\n\tMemory allocation error: code %3d\n\t\t-> %s", code, message);
            break;
        case GENERAL_ERROR_CODE_NULL_POINTER:
            fprintf(stderr, "Error:\n\tNull pointer error: code %3d\n\t\t-> %s", code, message);
            break;
        case GENERAL_ERROR_CODE_UNKNOWN:
            fprintf(stderr, "Error:\n\tUnknown error: code %3d\n\t\t-> %s", code, message);
            break;
        default:
            fprintf(
                stderr, "Error:\n\tUnknown error: code %3d\n\t\t-> %s", 
                GENERAL_ERROR_CODE_UNKNOWN, message
            );

            break;
        
    }

    exit(EXIT_FAILURE);
}