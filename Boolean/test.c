// IMPORTING NECESSARY FILES
    // IMPORTING LIBRARIES
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
    // IMPORTING CUSTOM BOOLEAN LIBRARY
#include "Boolean.c"

// A FUNCTION TO TEST A NUMBER WITH BOOLEAN
void testNumber(){
    printf("<------Testing numbers------>\n");
    int number_value;

    printf("\tHello, please enter any integer to test: ");
    scanf("%d", &number_value);

    Boolean_type* bool_number = Boolean_maker(&number_value);
    printf("\n\t<---Testing value method--->\n");

    printf(
        "\t\t->Number stored: %d\n\t\t-> The number '%d' is '%s'\n",
        *(int*)bool_number->value, number_value, bool_number->boolValue()
    );

    bool_number->clear();
}

// A FUNCTION TO TEST A CHARACTER WITH BOOLEAN
void testCharacter(){
    printf("<------Testing characters------>\n");
    char character_value;

    printf("\tHello, enter the character to test: ");
    scanf(" %c", &character_value);

    Boolean_type* bool_character = Boolean_maker(&character_value);
    printf("\n\t<---Testing value method--->\n");

    printf(
        "\t\t-> Character stored: %c\n\t\t-> The character '%c' is '%s'\n",
        *(char *)bool_character->value, character_value, bool_character->boolValue()
    );

    bool_character->clear();
}

// A FUNCTION TO TEST A STRING WITH BOOLEAN FUNCTIONALITY
void testString(){ 
    printf("<------Testing strings------>\n");
    char string_value[100]; 
    char* actual_string;

    printf("\tHello, please enter the string to test: ");
    fgets(string_value, strlen(string_value), stdin);
    string_value[strcspn(string_value, "\n")] = '\0';
    actual_string = malloc(strlen(string_value) + 1);
    strcpy(actual_string, string_value);

    Boolean_type* bool_string = Boolean_maker(actual_string);
    printf("\n\t<---Testing value method--->\n");

    printf(
        "\t\t-> String stored: %s\n\t\t-> The string '%s' is '%s'\n", 
        (char*)bool_string->value, actual_string, bool_string->boolValue()
    );

    bool_string->clear();
}

// A FUNCTION TO TEST ARRAYS
void testArray(){
    printf("<------Testing arrays------>\n");

    int** numbers_array = malloc(sizeof(int*));
    numbers_array[0] = (int*)NULL;
    Boolean_type* bool_array = Boolean_maker(numbers_array);

    printf("\n\t<---Testing value method--->\n");

    printf(
        "\t\t-> Value of 1st element stored stored: %s\n\t\t-> The value '%p' is '%s'\n", 
        (char*)bool_array->value, numbers_array[0], bool_array->boolValue()
    );

    bool_array->clear();
}

// MAIN FUNCTION
int main(){
    // testString();
    // testNumber();
    // testCharacter();
    testArray();
    return 0;
}