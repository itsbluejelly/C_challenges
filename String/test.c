// IMPORTING NECESSARY LIBRARIES
#include <stdio.h>
#include "ModifiedString.c"

// A FUNCTION TO TEST NUMERIC STRINGS
// A FUNCTION TO TEST NORMAL STRINGS
void testNormalStrings(){
    // DECLARNG VARIABLES
    char input_string[100];
    char* actual_string;

    // TAKING INPUT
    printf("...Testing normal strings...\n");
    printf("Hello, please enter any sentence: ");
    fgets(input_string, strlen(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = '\0';

    // GENERATING STRING
    actual_string = malloc(strlen(input_string) + 1);
    strcpy(actual_string, input_string);
    String_type Normal_string = String_maker(&actual_string);

    // 1. GETTING VALUE
    printf("-> The value entered is: %s\n", *Normal_string.value);
    // 2. GETTING LENGTH OF STRING
    printf("-> The string '%s' has %d characters\n", actual_string, (int)Normal_string.length);
    // 3. GETTING STRING IN LOWERCASE AND UPPERCASE
    printf("-> The string in lowercase is: %s\n", Normal_string.lowercase);
    printf("-> The string in uppercase is: %s\n", Normal_string.uppercase);
    // 4. GETTING REVERSE OF THE STRING
    printf("-> The string in reverse is: %s", Normal_string.reverse());
}

// MAIN FUNCTION
int main(){
    testNormalStrings();
    return 0;
}