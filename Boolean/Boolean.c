// IMPORTING NECESSARY LIBRARIES
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// DEFINING THE HIDDEN BOOLEAN STRUCT WITH ALL ITS PROPERTIES
typedef struct _Boolean
{
    bool value;             // THE VALUE TO MANIPULATE
    char* (*valueOf)(void); // A FUNCTION TO TELL IF THE VALUE IS TRUE OR FALSE
} _Boolean;

// A FUNCTION TO GENERATE THE BOOLEAN DATA TYPE WITH ALL THE PROPERTIES
_Boolean *Boolean(bool value)
{
    // FUNCTION FOR _BOOLEAN->VALUEOF()
    char* _valueOf()
    {
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
    boolean->valueOf = _valueOf;

    return boolean;
}