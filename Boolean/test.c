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

    Boolean_type* bool_number = Boolean_maker(&number_value, BOOLEAN_VALUE_TYPE_NON_ARRAY);
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

    Boolean_type* bool_character = Boolean_maker(&character_value, BOOLEAN_VALUE_TYPE_NON_ARRAY);
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

    Boolean_type* bool_string = Boolean_maker(actual_string, BOOLEAN_VALUE_TYPE_NON_ARRAY);
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

    char* strings_array[2] = {"hello", "hi"};
    int* number_array[3], number_value = 1, bad_number=0;
    char** wrong_strings = malloc(sizeof(char*));
    int** wrong_numbers = malloc(sizeof(int*));

    wrong_strings[0] = "";
    number_array[0] = &number_value;
    wrong_numbers[0] = &bad_number;

    Boolean_type *bool_strings = Boolean_maker(strings_array, BOOLEAN_VALUE_TYPE_STRING_ARRAY);
    printf("\n\t<---Testing value method--->\n");

    printf("\t\t<-Right strings array->\n");
    printf(
        "\t\t\t-> Value of 1st element stored stored: %s\n\t\t\t-> The value '%s' is '%s'\n", 
        *(char**)bool_strings->value, strings_array[0], bool_strings->boolValue()
    );

    printf("\t\t<-Wrong strings array->\n");
    bool_strings->value = wrong_strings;
    printf(
        "\t\t\t-> Value of 1st element stored stored: %s\n\t\t\t-> The value '%s' is '%s'\n", 
        *(char**)bool_strings->value, wrong_strings[0], bool_strings->boolValue()
    );

    Boolean_type *bool_numbers = Boolean_maker(number_array, BOOLEAN_VALUE_TYPE_ARRAY);
    printf("\t\t<-Right numbers array->\n");
    printf(
        "\t\t\t-> Value of 1st element stored stored: %d\n\t\t\t-> The value '%d' is '%s'\n", 
        **(int**)bool_numbers->value, *number_array[0], bool_numbers->boolValue()
    );

    printf("\t\t<-Wrong numbers array->\n");
    bool_numbers->value = wrong_numbers;
    printf(
        "\t\t\t-> Value of 1st element stored stored: %d\n\t\t\t-> The value '%d' is '%s'\n", 
        **(int**)bool_numbers->value, *wrong_numbers[0], bool_numbers->boolValue()
    );

    bool_numbers->clear();
    bool_strings->clear();
    free(wrong_numbers);
    free(wrong_strings);
}

// MAIN FUNCTION
int main(){
    // testString();
    // testNumber();
    // testCharacter();
    testArray();
    return 0;
}