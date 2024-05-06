// THIS FILE CONTAINS:
    // 1. _Boolean data type struct, which SHOULDNT be accessed without the constructor
    // 2. Boolean constructor, which returns a _Boolean data type with all its properties, which are:
        // 1. value -->   The primitive bit representation of the data type, as either 1 or 0
        // 2. boolValue() -> The function that returns whether the value is true or false, as the string keywords

// the constructor takes ONE param:
    // 1. value --> A boolean to store in the data struct and manipulate with the accessor methods

// IMPORTING NECESSARY LIBRARIES
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// DEFINING THE HIDDEN BOOLEAN STRUCT WITH ALL ITS PROPERTIES
typedef struct _Boolean
{
    bool value;             // THE VALUE TO MANIPULATE
    char* (*boolValue)(void); // A FUNCTION TO TELL IF THE VALUE IS TRUE OR FALSE
} _Boolean;

// A FUNCTION TO GENERATE THE BOOLEAN DATA TYPE WITH ALL THE PROPERTIES
_Boolean* Boolean(bool value)
{
    // FUNCTION FOR _BOOLEAN->BOOLVALUE()
    char* _boolValue(){
        if (value)
        {
            return "true";
        }
        else
        {
            return "false";
        }
    }

    // ALLOCATING MEMORY FOR THE BOOLEAN DATA TYPE
    _Boolean* boolean = (_Boolean*)malloc(sizeof(_Boolean));

    if (boolean == NULL)
    {
        printf("Error allocating memory for boolean data type");
        exit(EXIT_FAILURE);
    }

    // GIVING THE VALUES
    boolean->value = value;
    boolean->boolValue = _boolValue;

    return boolean;
}