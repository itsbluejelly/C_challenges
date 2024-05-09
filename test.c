// A FILE TO TEST OUT THE DATA HELPER TYPES😀

// IMPORTING NECESSARY FILES
#include <stdio.h>
#include <stdlib.h>

// IMPORTING DATA TYPES
#include "./Boolean/Boolean.c"
#include "./Number/Int/Int.c"
#include "./String/ModifiedString.c"

// A FUNCTION TO TEST BOOLEANS
void testBoolean(){
    // DECLARING VARIABLES
    int value;

    printf("Hello world, please enter any value: ");
    scanf("%d", &value);

    char* isTrue = Boolean.boolValue(value);
    printf("%d is %s\n", value, isTrue);
}

void testNumber(){
    // DECLARING VARIABLES
    int value, radix, digits, result;

    // 1. TESTING INT.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%d", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char* string_number = Int.toString(value, radix);
    printf("The value of %d as a string is %s\n", value, string_number);

    // 2. TESTING INT.TODIGITS()
    printf("Now, please enter any number of digits to round your number towards: ");
    scanf("%d", &digits);

    result = Int.toDigits(value, digits);
    printf("The number %d rounded off to %d dp is: %d\n", value, digits, result);
}

void testString(){
    // DECLARING VARIABLES
    char input_string[100];

    // GETTING THE INPUT STRING
    printf("Hello there, kindly enter your input string: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    // MODIFYING THE STRING TO GET ITS EXACT VALUE
    char* actual_string = (char*)malloc(strlen(input_string));

    if(actual_string == NULL){
        printf("Error accessing memory");
        return;
    }

    // TRANSFERRING CONTENT TO MODIFIES STRING AND CALLING ITS METHODS
    strcpy(actual_string, input_string);
    char* reversed_string = Modified_String.reverse(actual_string);
    printf("Reversed string: %s\n", reversed_string);

    free(actual_string);
}

int main()
{
    // testBoolean();
    // testNumber();
    testString();
    return 0;
}