/*
    This file contains:
        1. Common functions used across all types
        2. Common struct, union or enum definitions used across all types

    NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT general.c

    STANDARDS:
        1. Everything is prefixed with "General_(name)", to prevent naming conflicts, except enums
        2. Enums follow the pattern "GENERAL_(name)_TYPE", to prevent naming conflicts
*/

#pragma once

/*
    The enum definition for all error codes throughout this package, which consists of:
        1. GENERAL_ERROR_CODE_NULL_POINTER -> The pointer passed in decays to null
        2. GENERAL_ERROR_CODE_INVALID_VALUE -> The value passed in is invalid
        3. GENERAL_ERROR_CODE_MEMORY_ALLOCATION -> There was an error in allocating memory
        4. GENERAL_ERROR_CODE_UNKNOWN -> An unknown error has occured
 */
typedef enum GENERAL_ERROR_CODES_TYPE{
    // This error code is used if the pointer passed in decays to null
    GENERAL_ERROR_CODE_NULL_POINTER,
    // This error code is used if the value passed in is invalid
    GENERAL_ERROR_CODE_INVALID_VALUE,
    // This error code is used if there was an error in allocating memory
    GENERAL_ERROR_CODE_MEMORY_ALLOCATION,
    // This error code is used if an unknown error has occured
    GENERAL_ERROR_CODE_UNKNOWN
} GENERAL_ERROR_CODES_TYPE;

/**
 * This function is used to generate standard error messages
 * @param code The error code to work with -> Type GENERAL_ERROR_CODES_TYPE
 * @param message The error message to pass on -> Type char*
 */
void General_Error_Generator(GENERAL_ERROR_CODES_TYPE code, char* message);