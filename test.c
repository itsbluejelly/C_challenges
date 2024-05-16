// A FILE TO TEST OUT THE DATA HELPER TYPES😀

// IMPORTING NECESSARY FILES
#include <stdio.h>
#include <stdlib.h>

// IMPORTING DATA TYPES
#include "./Boolean/Boolean.c"
#include "./Int/Int.c"
#include "./Short_Int/Short_Int.c"
#include "./Long_Int/Long_Int.c"
#include "./Unsigned_Int/Unsigned_Int.c"
#include "./Long_Long_Int/Long_Long_Int.c"
#include "./Unsigned_Long_Int/Unsigned_Long_Int.c"
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

void testInt(){
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
    printf("The number %d rounded off to %d significant figures is: %d\n", value, digits, result);
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

void testShortInt(){
    // DECLARING VARIABLES
    short int value, result;
    int radix, digits;

    // 1. TESTING SHORT_INT.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%hd", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char *string_number = Short_Int.toString(value, radix);
    printf("The value of %d as a string is %s\n", value, string_number);

    // 2. TESTING SHORT_INT.TODIGITS()
    printf("Now, please enter any number of digits to round your number towards: ");
    scanf("%d", &digits);

    result = Short_Int.toDigits(value, digits);
    printf("The number %d rounded off to %d significant figures is: %hd\n", value, digits, result);
}

void testLongInt(){
    // DECLARING VARIABLES
    long int value, result;
    int radix, digits;

    // 1. TESTING LONG_INT.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%ld", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char *string_number = Long_Int.toString(value, radix);
    printf("The value of %ld as a string is %s\n", value, string_number);

    // 2. TESTING LONG_INT.TODIGITS()
    printf("Now, please enter any number of digits to round your number towards: ");
    scanf("%d", &digits);

    result = Long_Int.toDigits(value, digits);
    printf("The number %ld rounded off to %d significant figures is: %ld\n", value, digits, result);
}

void testUnsignedInt(){
    // DECLARING VARIABLES
    unsigned int value, result;
    int radix, digits;

    // 1. TESTING UNSIGNED_INT.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%d", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char *string_number = Unsigned_Int.toString(value, radix);
    printf("The value of %d as a string is %s\n", value, string_number);

    // 2. TESTING UNSIGNED_INT.TODIGITS()
    printf("Now, please enter any number of digits to round your number towards: ");
    scanf("%d", &digits);

    result = Unsigned_Int.toDigits(value, digits);
    printf("The number %d rounded off to %d significant figures is: %d\n", value, digits, result);
}

void testLongLongInt(){
    // DECLARING VARIABLES
    long long int value, result;
    int radix, digits;

    // 1. TESTING LONG_LONG_INT.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%lld", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char *string_number = Long_Long_Int.toString(value, radix);
    printf("The value of %lld as a string is %s\n", value, string_number);

    // 2. TESTING LONG_LONG_INT.TODIGITS()
    printf("Now, please enter any number of digits to round your number towards: ");
    scanf("%d", &digits);

    result = Long_Long_Int.toDigits(value, digits);
    printf("The number %lld rounded off to %d significant figures is: %lld\n", value, digits, result);
}

void testUnsignedLongInt(){
    // DECLARING VARIABLES
    unsigned long int value, result;
    int radix, digits;

    // 1. TESTING UNSIGNED_LONG_INT.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%ld", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char *string_number = Unsigned_Long_Int.toString(value, radix);
    printf("The value of %ld as a string is %s\n", value, string_number);

    // 2. TESTING UNSIGNED_LONG_INT.TODIGITS()
    printf("Now, please enter any number of digits to round your number towards: ");
    scanf("%d", &digits);

    result = Unsigned_Long_Int.toDigits(value, digits);
    printf("The number %ld rounded off to %d significant figures is: %ld\n", value, digits, result);
}

int main()
{
    // testBoolean();
    // testInt();
    // testString();
    // testShortInt();
    // testLongInt();
    // testUnsignedInt();
    // testLongLongInt();
    testUnsignedLongInt();
    return 0;
}