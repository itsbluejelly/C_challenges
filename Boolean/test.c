// IMPORTING NECESSAR LIBRARIES
#include <stdio.h>
#include "Boolean.c"

// A FUNCTION TO TEST FOR BOOLEAN FUNCTIONALITY
void testBoolean(){
    // DECLARING VARIABLES
    int value;

    printf("Hello world, please enter any value: ");
    scanf("%d", &value);

    Boolean_type Boolean = Boolean_maker(&value);
    char* isTrue = Boolean.boolValue();

    printf("Value stored: %d\n", *(int*)Boolean.value);
    printf("%d is %s\n", value, isTrue);
}

// MAIN FUNCTION
int main(){
    testBoolean();
    return 0;
}