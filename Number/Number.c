// THIS FILE CONTAINS:
    // 1. Number type enum, which contains the types the _Number data can contain
    // 2. _Number data type struct, which SHOULDNT be accessed without the constructor
    // 3. Number constructor, which returns a _Number data type with all its properties, which are:
        // 1. value -->   The primitive numeric value of the data type
        // 5. number_type --> The numeric representation of the type the number is
        // 2. toString(radix=10) -> The function that returns a string representation of the number
        // 3. toDecimals(number=1) -> The function that rounds off a number to a specified number of decimal places
        // 4. toDigits(number=0) -> The function that rounds off a number to specified digits
        // 6. getNumberType() -> Returns the string representation of the type of the number value, as int, float, double or long

// the constructor takes TWO params:
    // 1. value --> A boolean to store in the data struct and manipulate with the accessor methods
    // 2. data_type -> The type of number you want to process

// the enum contains 4 types of numbers, which are:
    // 1. INT_TYPE --> For integers
    // 2. FLOAT_TYPE -> For floats
    // 3. DOUBLE_TYPE -> For double
    // 4. LONG_TYPE --> For long integers
    // 4. SHORT_TYPE --> For short integers

// IMPORTING NECESSARY FILES
#include <stdio.h>
#include <stdlib.h>

// DECLARING THE NUMBER_TYPE ENUM
typedef enum NUMBER_TYPE{
    INT_TYPE,
    FLOAT_TYPE,
    DOUBLE_TYPE,
    LONG_TYPE
} NUMBER_TYPE;

// DECLARING THE _NUMBER TYPE STRUCT CONTAINING THE VALUE, PROPS AND METHODS
typedef struct _Number{
    NUMBER_TYPE number_type;
    void* value;
}_Number;

// A _NUMBER TYPE CONSTRUCTOR
_Number* Number(NUMBER_TYPE number_type, void* value){
    // DECLARING THE VARIABLE WITH THE NUMBER TYPE
    _Number* number = (_Number*)malloc(sizeof(_Number));

    if (number == NULL){
        printf("Error allocating memory for number data type");
        exit(EXIT_FAILURE);
    }

    // ASSIGNING THE OTHER PROPERTIES
    number->number_type = number_type;
    number->value = value;

    return number;
}