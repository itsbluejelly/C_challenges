// A FILE TO TEST OUT THE DATA TYPES😀
// NB. ALWAYS REMEMBER TO FREE THE MEMORY OF ANY DATA TYPE AFTER USE

// IMPORTING NECESSARY FILES
#include <stdio.h>
#include <stdlib.h>

// IMPORTING DATA TYPES
#include "./Boolean/Boolean.c"

void testBoolean(){
    // DECLARING VARIABLES
    int value;

    printf("Hello world, please enter any value: ");
    scanf("%d", &value);

    // CREATING A BOOLEAN DATA TYPE
    _Boolean* boolValue = Boolean(value);
    printf("%d\n%s\n", boolValue->value, boolValue->valueOf());

    free(boolValue);
}

int main()
{
    testBoolean();
    return 0;
}