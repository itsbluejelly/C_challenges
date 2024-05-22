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
#include "./Float/Float.c"
#include "./Double/Double.c"
#include "./Long_Double/Long_Double.c"
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
    char test_string[100];
    size_t string_size;

    // GETTING THE STRING VALUE
    printf("Please enter a sentence here: ");
    fgets(test_string, sizeof(test_string), stdin);
    test_string[strcspn(test_string, "\n")] = '\0';

    char *actual_string = (char *)malloc(strlen(test_string) + 1);

    if(actual_string == NULL){
        fprintf(stderr, "Error allocating memory for actual compact string\n");
        exit(EXIT_FAILURE);
    }

    strcpy(actual_string, test_string);
    printf("\n-> Recorded string is: %s\n", actual_string);

    // 1. CALCULATING THE LENGTH OF THE STRING
    string_size = Modified_String.length(actual_string);
    printf("-> The string has a length of: %lld characters\n", string_size);

    // 2. GETTING THE STRING IN LOWERCASE
    printf("-> The string in all lowcase is: %s\n", Modified_String.toLower(actual_string));
    // 3. CONVERTING THE STRING TO UPPERCASE
    printf("-> The string in all uppercase is: %s", Modified_String.toUpper(actual_string));
    // 4. REVERSING THE STRING

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

void testFloat(){
    // DECLARING VARIABLES
    float value, result;
    int radix, digits;

    // 1. TESTING FLOAT.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%f", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char *string_number = Float.toString(value, radix);
    printf("The value of %.4f as a string is %s\n", value, string_number);

    // 2. TESTING FLOAT.TODECIMALS()
    printf("Now, please enter any number of decimals to round your number towards: ");
    scanf("%d", &digits);

    result = Float.toDecimals(value, digits);
    printf("The number %f rounded off to %d decimal places is: %.*f\n", value, digits, digits, result);
}

void testDouble(){
    // DECLARING VARIABLES
    double value, result;
    int radix, digits;

    // 1. TESTING DOUBLE.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%lf", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char *string_number = Double.toString(value, radix);
    printf("The value of %.4lf as a string is %s\n", value, string_number);

    // 2. TESTING DOUBLE.TODECIMALS()
    printf("Now, please enter any number of decimals to round your number towards: ");
    scanf("%d", &digits);

    result = Double.toDecimals(value, digits);
    printf("The number %lf rounded off to %d decimal places is: %.*lf\n", value, digits, digits, result);
}

void testLongDouble(){
    // DECLARING VARIABLES
    long double value;
    int radix;

    // TESTING LONG_DOUBLE.TOSTRING()
    printf("Hello world, please enter any number: ");
    scanf("%Lf", &value);
    printf("Now, please enter any number from 2 and 36 as the base: ");
    scanf("%d", &radix);

    char *string_number = Double.toString(value, radix);
    printf("The value of %.4Lf as a string is %s\n", value, string_number);
}

int main()
{
    // testBoolean();
    // testInt();
    testString();
    // testShortInt();
    // testLongInt();
    // testUnsignedInt();
    // testLongLongInt();
    // testUnsignedLongInt();
    // testFloat();
    // testDouble();
    // testLongDouble();
    return 0;
}