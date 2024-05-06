// A FILE TO TEST OUT THE DATA TYPES😀
// NB. ALWAYS REMEMBER TO FREE THE MEMORY OF ANY DATA TYPE AFTER USE

// IMPORTING NECESSARY FILES
#include <stdio.h>
#include <stdlib.h>

// IMPORTING DATA TYPES
#include "./Boolean/Boolean.c"
#include "./Number/Number.c"

void testBoolean(){
    // DECLARING VARIABLES
    int value;

    printf("Hello world, please enter any value: ");
    scanf("%d", &value);

    // CREATING A BOOLEAN DATA TYPE
    _Boolean* boolValue = Boolean(value);
    printf("%d\n%s\n", boolValue->value, boolValue->boolValue());

    free(boolValue);
}

void testNumber(){
    // DECLARING VARIABLES
    int value;

    printf("Hello world, please enter any number: ");
    scanf("%d", &value);

    // CREATING A NUMBER DATA TYPE
    _Number* numberValue = Number(INT_TYPE, &value);
    printf("The stored value: %f\nThe stored type: %d\n", *(float*)(numberValue->value), numberValue->number_type);

    free(numberValue);
}

int main()
{
    // testBoolean();
    testNumber();
    return 0;
}