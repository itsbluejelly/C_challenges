#pragma once

// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
    // IMPORTING DOUBLE TYPE
#include "Double.h"
#include "../String/ModifiedString.c"

/**
 * The current Double created globally
 * @attention Please import the Double_maker function, as this is internal and only holds the current value without any type safety measures, to create your own Double_type structs
 */
Double_type Double_current;

char* Double_maker_toString(int radix){
    // GETTING THE VALUE PROPERTY AND CHECKING REQUIRED PARAMS
    double value = *Double_current.value;

    if(!radix){
        radix = 10;
    }else if((radix < 2) || (radix > 36)){
        fprintf(stderr, "The base must be between 2 and 36");
        exit(EXIT_FAILURE);
    }

    // DECLARING VARIABLES
        // THE INDEX FOR BOTH DECIMAL AND INTEGER PARTS, AND A BOOL TO TRACK POSITIVITY OF THE VALUE
    int integer_index = 0; 
    int decimal_index = 0; 
    bool is_negative = false;
        // STRINGS FOR THE INTEGER AND DECIMAL BITS
    char* integer_string = (char*)malloc(100 * sizeof(char));
    char* decimal_string = (char*)malloc(100 * sizeof(char));
        // A STRING OF VALID CHARACTERS IN THE STING VERSION OF THE NO
    char* valid_characters = "0123456789abcdefghijklmnopqrstuvwxyz";

    // IF NO IS O, RETURN 0 WITH 4 D.P
    if(value == 0){
        char* compact_string = (char*)malloc(7 * sizeof(char));

        if(compact_string == NULL){
            fprintf(stderr, "Error allocating memory");
            exit(EXIT_FAILURE);
        }

        strcpy(compact_string, "0.0000");
        return compact_string;
    }

    // IF NO IS -VE, CONVERT TO POSITIVE
    if((value < 0) && (radix == 10)){
        is_negative = true;
        value = -(value);
    }

    // DIVIDE THE NO INTO 2 PARTS, INTEGER AND DECIMAL
    int integer_part = floor(value);
    double decimal_part = value - integer_part;

    // OTHERWISE DEAL WITH THE INTEGER PART
    if(integer_part == 0){
        integer_string[integer_index] = '0';
        integer_index += 1;
    }

    while(integer_part){
        int bit = integer_part % radix;
        integer_string[integer_index] = valid_characters[bit];
        integer_part /= radix;
        integer_index += 1;
    }

    // IF THE NO WAS NEGATIVE, ADD THE NEGATIVE SIGN TO THE INTEGER STRING
    if(is_negative){
        integer_string[integer_index] = '-';
        integer_index += 1;
    }

    // COMPACT AND REVERSE THE INTEGER STRING
    integer_string[integer_index] = '\0';
    char* compact_integer = realloc(integer_string, strlen(integer_string));

    if(compact_integer == NULL){
        fprintf(stderr, "Error allocating integer string memory");
        exit(EXIT_FAILURE);
    }

    char* number_string = Modified_String.reverse(compact_integer);

    // DEAL WITH THE DECIMAL PART
    decimal_string[decimal_index] = '.';
    decimal_index += 1;

    for(int i = 0; i < 4; i++){
        double resultant = decimal_part * radix;
        int bit = (int)floor(resultant);
        decimal_string[decimal_index] = valid_characters[bit];
        decimal_part = resultant - bit;
        decimal_index += 1;
    }

    // COMPACT THE DECIMAL STRING
    decimal_string[decimal_index] = '\0';
    char* compact_decimal = realloc(decimal_string, strlen(decimal_string));

    if(compact_decimal == NULL){
        fprintf(stderr, "Error allocating decimal string memory");
        exit(EXIT_FAILURE);
    }

    // JOIN THE TWO PARTS TOGETHER
    strcat(number_string, compact_decimal);
    
    return number_string;
}

Double_type Double_maker(double *value){
    if(value == NULL){
        fprintf(stderr, "Must provide a pointer to the value being stored");
        exit(EXIT_FAILURE);
    }

    Double_current.value = value;
    Double_current.toString = Double_maker_toString;
    Double_current.toDecimals = Double_maker_toDecimals;

    return Double_current;
}
// // DECLARING THE TODECIMALS FUNCTION
// double _toDecimals_Double(double value, int digits){
//     // CHECKING IF RIGHT PARAMS WERE GIVEN
//     if(digits <= 0){
//         fprintf(stderr, "The no of significant digits should be at least one");
//         exit(EXIT_FAILURE);
//     }

//     double power = pow(10, digits);
//     double rounded_number = round((double)value * power) / power;

//     return rounded_number;
// }

// // THE DOUBLE STRUCT
// Double_type Double = {
//     .toString = _toString_Double,
//     .toDecimals = _toDecimals_Double
// };