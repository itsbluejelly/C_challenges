/*
    This file contains the
        1. Struct declaration that holds the struct type enclosing the double number
        2. A constructor for the modified double number
        3. Helper function declarations for the Double_type struct

    NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT Double.c

    STANDARDS:
        1. The struct defined holds the value and helper functions
        2. The helper functions are defined in the format "Double_maker_(helper fn)", to prevent naming issues
        3. Anything to do with the custom type should be prefixed with "Double_"
        4. Double has a storage of 8 bytes
*/

# pragma once

/**
 * The struct definition for the double type that contains these properties
 *  1. value --> A pointer to the double value held within the struct
 *  2. toString() --> Converts a decimal to a string
    3. toDecimals() --> rounds off a decimal to a string of specified decimal places
 */
typedef struct{
    // A pointer to the value held within the struct --> Type double*
    double *value;

    /**
     * A function to convert the stored number to a string
     * @param radix The base to convert the number to --> Type int
     * @return A string representation of the number, to 4 d.p --> Type char*
     */
    char* (*toString)(double value, int radix);

    /**
     * A function to round off the stored number to a specified no of decimal places
     * @param radix The number of decimal places to round off to --> Type int
     * @return The rounded-off number --> Type double
     */
    double (*toDecimals)(double value, int digits);
}Double_type;

/**
 * A function that constructs the Double_type struct
 * @param value An address to the double value to modify and return with the added functions -> Type double*
 * @return A struct that contains the value and the added functions -> Type Double_type
 */
Double_type Double_maker(double *value);

/**
 * A helper function that converts the stored number to a string
 * @attention Please use this within the Double_maker function,as it is internal
 * @param radix The base to convert the number to --> Type int
 * @return A string representation of the number, to 4 d.p --> Type char*
 */
char* Double_maker_toString(int radix);

/**
 * A helper function that rounds off the stored number to a specified no of decimal places
 * @attention Please use this within the Double_maker function,as it is internal
 * @param radix The number of decimal places to round off to --> Type int
 * @return The rounded-off number --> Type double
 */
double Double_maker_toDecimals(int digits);
