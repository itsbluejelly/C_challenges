// A FILE TO TEST OUT THE DATA HELPER TYPES😀

// IMPORTING NECESSARY FILES
#include <stdio.h>
#include <stdlib.h>

// IMPORTING DATA TYPES
#include "./Boolean/Boolean.c"
#include "./Number/Number.c"
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

// void testNumber(){
//     // DECLARING VARIABLES
//     int value;

//     printf("Hello world, please enter any number: ");
//     scanf("%d", &value);

//     // CREATING A NUMBER DATA TYPE
//     _Number* numberValue = Number(INT_TYPE, &value);
//     printf("The stored value: %d\nThe stored type: %d\n", *(int*)(numberValue->value), numberValue->number_type);

//     free(numberValue);
// }

void testString(){
    // DECLARING VARIABLES
    char input_string[100];

    printf("Hello there, kindly enter your input string: ");
    scanf("%s", input_string);

    // MODIFYING THE STRING TO GET ITS EXACT VALUE
    char* actual_string = (char*)malloc(strlen(input_string));

    if(actual_string == NULL){
        printf("Error accessing memory");
        return;
    }

    actual_string = strcpy(actual_string, input_string);
    char* reversed_string = Modified_String.reverse(actual_string);
    printf("Reversed string: %s", reversed_string);

    free(actual_string);
}

int main()
{
    // testBoolean();
    // testNumber();
    testString();
    return 0;
}