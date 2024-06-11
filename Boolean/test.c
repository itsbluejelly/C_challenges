// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    // IMPORTING CUSTOM BOOLEAN LIBRARY
#include "Boolean.c"

// A FUNCTION TO TEST A NUMBER WITH BOOLEAN
void testNumber(){
    int number_value;

    printf("Hello, please enter any integer to test: ");
    scanf("%d", &number_value);

    Boolean_type* bool_number = Boolean_maker(&number_value);

    printf(
        "Numbers\n\t1. Number stored: %d\n\t2. The number '%d' is '%s'\n",
        *(int*)bool_number->value, number_value, bool_number->boolValue()
    );

    bool_number->clear();
}

// A FUNCTION TO TEST A CHARACTER WITH BOOLEAN
void testCharacter(){
    char character_value;

    printf("Hello, enter the character to test: ");
    scanf("\n%c", &character_value);

    Boolean_type* bool_character = Boolean_maker(&character_value);

    printf(
        "Characters\n\t1. Character stored: %c\n\t2. The character '%c' is '%s'\n",
        *(char *)bool_character->value, character_value, bool_character->boolValue()
    );

    bool_character->clear();
}

// A FUNCTION TO TEST A STRING WITH BOOLEAN FUNCTIONALITY
void testString(){ 
    char string_value[100]; 
    char* actual_string;

    printf("Hello, please enter the string to test: ");
    fgets(string_value, strlen(string_value), stdin);
    string_value[strcspn(string_value, "\n")] = '\0';
    actual_string = malloc(strlen(string_value) + 1);
    strcpy(actual_string, string_value);

    Boolean_type* bool_string = Boolean_maker(actual_string);

    printf(
        "Strings\n\t1. String stored: %s\n\t2. The string '%s' is '%s'\n", 
        (char*)bool_string->value, actual_string, bool_string->boolValue()
    );

    bool_string->clear();
}

// MAIN FUNCTION
int main(){
    testString();
    testNumber();
    testCharacter();
    return 0;
}