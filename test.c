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
    printf("%d is %s", value, isTrue);
}

void testNumber(){
    // DECLARING VARIABLES
    int value, radix;

    printf("Hello world, please enter any number: ");
    scanf("%d", &value);

    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char* string_number = Int.toString(value, radix);
    printf("The value of %d as a string is %s", value, string_number);
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
    printf("Reversed string: %s", reversed_string);

    free(actual_string);
}

int main()
{
    // testBoolean();
    testNumber();
    // testString();
    return 0;
}