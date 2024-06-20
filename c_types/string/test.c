// IMPORTING NECESSARY LIBRARIES
#include <stdio.h>
#include "ModifiedString.c"

// A FUNCTION TO TEST NUMERIC STRINGS
void testNumericStrings(){
    printf("<------Numerical string tests------>\n");
    // DECLAINR VARIABLES
    char input_string[100];
    char *actual_string, *replacer_string;
    char** split_strings;
    int radix;
    String_type* decimal_string;

    // CREATING STRING DATA TYPES
    printf("\t1. Hello there, please enter a decimal of any choice: ");
    scanf("%s", input_string);
    input_string[strcspn(input_string, "\n")] = '\0';

    printf("\t2. Nice, what is the base of this decimal number: ");
    scanf(" %d", &radix);

    printf("\t3. Finally, what is the number you would like to replace the string with: ");
    replacer_string = malloc(strlen(input_string) + 1);
    scanf(" %s", replacer_string);

    actual_string = malloc(strlen(input_string) + 1);
    strcpy(actual_string, input_string);

    decimal_string = String_maker(actual_string);

    // 1. TESTING CONVERSION TO DECIMAL
    printf("\n\t<---Testing string to decimal conversion--->\n");
    
    printf(
        "\t\t-> The string '%s' converted to decimal is: %lf\n", 
        actual_string, decimal_string->get.decimalNumber(radix)
    );

    // 2. TESTING CONVERSION TO STRING
    printf("\t<---Testing string to integer conversion--->\n");

    printf(
        "\t\t-> The string '%s' converted to an integer is: %d\n", 
        actual_string, decimal_string->get.wholeNumber(radix)
    );

    // 3. TESTING SPLITTING
    printf("\t<---Testing splitting functionality--->\n");
    split_strings = decimal_string->get.splits('.', 2);

    for(int i = 0; split_strings[i] != NULL; i++){
        printf("\t\t-> The string in index %d is: %s\n", i, split_strings[i]);
    }

    // // 4. TESTING THE REMAINING SETTER METHODS
    printf("\t<---Testing setter methods--->\n");
    
    printf("\t\t<-Value->\n");
    printf("\t\t\t-> The stored string was previously: %s\n", decimal_string->get.value);
    decimal_string->set.value(replacer_string);
    printf("\t\t\t-> It is now: %s\n", decimal_string->get.value);
    printf("\t\t\t-> The tracked value is changed to: %s\n", decimal_string->get.__copy);
    
    printf("\t\t<-Lowercase->\n");
    printf("\t\t\t-> The stored string was previously: %s\n", decimal_string->get.value);
    decimal_string->set.toLowercase();
    printf("\t\t\t-> It is now: %s\n", decimal_string->get.value);
    printf("\t\t\t-> The tracked value is changed to: %s\n", decimal_string->get.__copy);
    
    printf("\t\t<-Uppercase->\n");
    printf("\t\t\t-> The stored string was previously: %s\n", decimal_string->get.value);
    decimal_string->set.toUppercase();
    printf("\t\t\t-> It is now: %s\n", decimal_string->get.value);
    printf("\t\t\t-> The tracked value is changed to: %s\n", decimal_string->get.__copy);
    
    printf("\t\t<-Reverse->\n");
    printf("\t\t\t-> The stored string was previously: %s\n", decimal_string->get.value);
    decimal_string->set.toReverse();
    printf("\t\t\t-> It is now: %s\n", decimal_string->get.value);
    printf("\t\t\t-> The tracked value is changed to: %s\n", decimal_string->get.__copy);

    // FREEING MEMORY
    decimal_string->utils.clear();
    free(actual_string);
    free(replacer_string);
}

// A FUNCTION TO TEST NORMAL STRINGS
void testNormalStrings(){
    printf("<------Normal string tests------>\n");
    // DECLARING VARIABLES
    char input_string[100];
    char *actual_string, *old_substring, *new_substring, *chain_string = "testing 1234...";
    String_type *notchained_string, *chained_string;

        // CREATING STRING DATA TYPES
    printf("\t1. Hello there, please type in any sentence: ");
    scanf("%s", input_string);
    input_string[strcspn(input_string, "\n")] = '\0';

    printf("\t2. Ok, what substring inside it would you like to replace: ");
    old_substring = malloc(strlen(input_string) + 1);
    scanf(" %s", old_substring);
    old_substring[strcspn(old_substring, "\n")] = '\0';

    printf("\t3. Nice, what substring would you like to replace it with: ");
    new_substring = malloc(strlen(input_string) + 1);
    scanf(" %s", new_substring);
    new_substring[strcspn(new_substring, "\n")] = '\0';

    actual_string = malloc(strlen(input_string) + 1);
    strcpy(actual_string, input_string);

    notchained_string = String_maker(actual_string);
    chained_string = String_maker(chain_string);

    // 1. TESTING THE VALUE AND LENGTH PROPERTY
    printf("\n\t<---Value and length test--->\n");
    printf("\t\t-> The value of the stored string is: %s\n", notchained_string->get.value);
    printf("\t\t-> The string '%s' has %d characters\n", actual_string, (int)notchained_string->get.length);
    
    printf(
        "\t\t-> The value of the chained string is '%s' with %d characters\n", 
        chained_string->get.value, (int)chained_string->get.length
    );

    // 2. TESTING THE SETVALUE METHOD
    printf("\t<---Restting value test--->\n");
    chained_string->set.value(actual_string);

    printf(
        "\t\t-> The new value of the chained string is '%s' with %d characters\n",
        chained_string->get.value, (int)chained_string->get.length
    );

    // 3. TESTING THE UPPERCASE METHOD
    printf("\t<---Uppercase test--->\n");
    printf("\t\t-> The string in uppercase form is: %s\n", notchained_string->get.uppercase());
    printf("\t\t-> The stored string value never changed, still remains as: %s\n", notchained_string->get.value);

    // 4. TESTING THE LOWERCASE METHOD
    printf("\t<---Lowercase test--->\n");
    printf("\t\t-> The string in lowercase form is: %s\n", notchained_string->get.lowercase());
    printf("\t\t-> The stored string value never changed, still remains as: %s\n", notchained_string->get.value);

    // 5. TESTING THE REVERSE METHOD
    printf("\t<---Reverse test--->\n");
    printf("\t\t-> The string in reversed form is: %s\n", notchained_string->get.reversed());
    printf("\t\t-> The stored string value never changed, still remains as: %s\n", notchained_string->get.value);

    // 6. CHECKING IF THE SUBSTRING TO REPLACE EXISTS
    printf("\t<---Includes test--->\n");
    bool includeResults = notchained_string->get.isIncluded(old_substring[0]);
    includeResults ? printf("\t\t-> The substring exists\n") : printf("\t\t-> The substring doesnt exist\n");

    // 7. GETTING POSITION OF SUBSTRING
    printf("\t<---Position test--->\n");
    printf("\t\t-> The substring is in index: %d\n", notchained_string->get.position(old_substring[0]));

    // 8. TESTING THE REPLACE METHOD
    printf("\t<---Replace test--->\n");

    printf(
        "\t\t-> The string in replaced form is: %s\n", 
        notchained_string->get.replaced(old_substring, new_substring)
    );

    printf("\t\t-> The stored string value never changed, still remains as: %s\n", notchained_string->get.value);

    // CHAINING THE UPPERCASE, LOWERCASE, REVERSE AND REPLACE FUNCTIONS
    printf("\t<---Chaining tests--->\n");
    printf("\t\t-> The chained string is initially: %s\n", chained_string->get.value);

    chained_string
        ->replace(old_substring, new_substring)
        ->reverse()
        ->uppercase();

    printf("\t\t-> Chaining all methods gives the result: %s\n", chained_string->get.__copy);
    printf("\t\t-> The new length of the string is: %d\n", (int)chained_string->get.length);
    chained_string->utils.revert();
    printf("\t\t-> After reverting, the new length is: %d", (int)chained_string->get.length);

    // FREEING MEMORY
    chained_string->utils.clear();
    notchained_string->utils.clear();
    free(actual_string);
    free(old_substring);
    free(new_substring);
}

// MAIN FUNCTION
int main(){
    // testNormalStrings();
    testNumericStrings();
    return 0;
}