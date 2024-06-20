/*
    This file contains the
        1. Enum declaration for the value type passed in the create function of the Boolean_maker
        2. Struct declaration for the Boolean type
        3. Struct declaration for the pool property in the Boolean_maker type
        4. Struct declaration for the get property in the Boolean_maker_pool type
        5. Struct declaration for the Boolean_maker type
        6. Struct declaration for the Boolean_pool type
        5. A constructor for the modified boolean
        6. Helper function declarations for the Boolean_type struct

    NB: THIS IS NOT IMPORTED, BUT RATHER IMPORT Boolean.c

    STANDARDS:
        1. The struct defined holds the value and helper functions
        2. All private helper functions(those NOT meant for the struct) and variables follow the pattern "_Boolean_(name)" to prevent naming issues
        3. All private variables within the Boolean struct produced are prefixed with 2 underscores, as they are private
        4. The helper functions(those MEANT for the struct) are defined in the format "_Boolean_maker_(helper fn)", to prevent naming issues
        5. The enum types contained within the Boolean_type struct are prefixed with "BOOLEAN_(name)_TYPE" to prevent naming conflicts
        6. The struct types meant for the Boolean_maker_type follow the pattern "Boolean_maker_type_(name)" to prevent naming conflicts
*/

#pragma once

// IMPORTING NECESSARY LIBRARIES
#include <stdbool.h>

/**
 * The enum definition for the type of pointer passed in the Boolean_maker, it consists of:
 *  1. array -> For array pointers
 *  2. non-array -> For non-array pointers
 *  3. string-array -> For an array of strings
*/
typedef enum BOOLEAN_VALUE_TYPE
{
    /**
     * This is used for array types, which are pointers-to-pointers.
     * @attention 1. To pass an array, you will have to replace the values in the array with their pointers
     * @attention 2. To pass an array of strings, you will have to use BOOLEAN_VALUE_TYPE_STRING_ARRAY
     */
    BOOLEAN_VALUE_TYPE_ARRAY,

    /**
     * This is used for non-array types, which are pointers-to-value.
     * @attention To pass a string, you will have to use this type
     */
    BOOLEAN_VALUE_TYPE_NON_ARRAY,

    // This is used for an array of strings
    BOOLEAN_VALUE_TYPE_STRING_ARRAY
} BOOLEAN_VALUE_TYPE;

/**
 * The struct definition for the boolean type that contains these properties:
 * 1. value -> A pointer to the value held within the boolean struct
 * 2. type -> A property that holds the type of the pointer stored in the type
 * 3. ID -> A property that holds the unique identifier for the boolean struct
 * 4. boolValue() -> A method that checks if the value held is true or false
 */
typedef struct Boolean_type{
    // A pointer to the value, or an array, of any type held within the boolean struct -> Type void*
    void* value;

    /*
        A property that holds the type of the pointer stored in the type, it can be of type:
            1. BOOLEAN_VALUE_TYPE_NON_ARRAY -> For singular values and arrays
            2. BOOLEAN_VALUE_TYPE_ARRAY -> For array of pointers types, except array of strings
            3. BOOLEAN_VALUE_TYPE_STRING_ARRAY -> For an array of strings
    */
    BOOLEAN_VALUE_TYPE type;

    // A unique number given to each Boolean data type, for identification -> Type int
    int ID;

    /**
     * A function that checks if the stored value held is true or false
     * @return True if the value is true-ish and False if false-y -> Type bool
     */
    bool (*boolValue)();
}Boolean_type;

/**
 * The struct declaration for the pool property of the Boolean_maker type, which holds the following:
 *  1. resize() -> A method that resizes the Boolean pool
 *  2. focus() -> A method that focuses on a particular Boolean data type
 *  3. clearAll() -> A method that deletes all stored Boolean data types
 *  4. reserve() -> A method that allocates a certain number of Boolean data types within the pool
 *  5. get -> A property that holds all the getter properties and methods
 */
typedef struct Boolean_maker_type_pool{
    /**
     * A method which resizes the Boolean pool to a certain size, if the size is higher than the one previously declared it adds the extra slots and if less than, it removes the most recent added types
     * @param number The new number of Boolean data types to reserve -> Type int
     */
    void (*resize)(int number);

    /**
     * A method which focuses on a particular Boolean data type, so as to call the internal methods appropriately, if there are multiple data types declared
     * @param ID The unique identifier of the Boolean data type to focus on -> Type int
     */
    void (*focus)(int ID);

    /**
     * A method which cleares all the stored Boolean data types in the pool, and frees the pool from memory
     * @attention Though not mandatory, it is suggested to use this function only when you have more than one data types in your pool, to clear a singular data type, look into the ```finalize()``` method
     */
    void (*clearAll)();

    /**
     * A method that allocates a certain number of Boolean data types within the pool
     * @attention Though not mandatory, it is suggested to use this method only when you want to prepare multiple data types in the same bool, to declare only one kindly look into the ```initialize()``` method
     * @param number The number of Boolean data types to reserve -> Type int
     */
    void (*reserve)(int number);

    // A property that holds all the getter properties and methods
    Boolean_maker_type_pool__get get;
}Boolean_maker_type_pool;

/**
 * The struct declaration for the get property of the Boolean_maker_pool type, which includes:
 *  1. isIncluded() -> A method which checks whether a memory address is stored in the maker
 *  2. valueOf() -> A method which returns the Boolean data type of a specified ID
 *  3. total -> A property that returns the number of Boolean data types stored
 *  4. totalSize -> A property that holds the size of the maker in bytes
 */
typedef struct Boolean_maker_type_pool_get{
    // A property that holds the number of Boolean data types stored -> Type int
    int total;
    // A property that holds the size of the maker in bytes -> Type size_t
    size_t totalSize;

    /**
     * A method which checks whether a memory address is stored in the pool
     * @param address The address of any type to search for -> Type void*
     * @return True if the memory address is found, and false if otherwise -> Type bool
     */
    bool (*includes)(void* address);

    /**
     * A method which returns the Boolean data type of a specified ID
     * @param ID The unique identifier of the searched Boolean type -> Type int
     * @returns The memory address of the found data type, or a null address if absent -> Type void*
     */
    void* (*getValueOf)(int ID);
} Boolean_maker_type_pool__get;

/**
 * The struct type for the Boolean maker which consists of these methods and properties:
 *  1. pool -> The property that holds all the pool methods
 *  2. initialize() -> It initializes the maker to hold only one Boolean data type
 *  3. finalize() -> It cleares only one Boolean data type and destroys the pool
 *  4. clear() -> It cleares a specified data type from memory
 *  5. create() -> It creates one Boolean data type and adds it to the pool
 */
typedef struct Boolean_maker_type{
    // This property holds all the pool methods
    Boolean_maker_type_pool pool;

    /**
     * A method that initializes the pool to hold only one Boolean data type strictly
     * @returns The memory address of the Boolean type generated -> Type Boolean_type*
     * @attention This function is suitable for a use case for one Boolean data type alone, if u are planning to prepare multiple data type instances we suggest looking into the ```reserve()``` method to prevent repetitive calls
     */
    Boolean_type *(*initialize)();

    /**
     * A function that cleares a boolean pool from memory which only contains one Boolean data type
     * @attention This function only works if you initialized your pool with the ```initialize()``` function, as it doesnt clear multiple data type instances
     */
    void (*finalize)();

    /**
     * A function to clear a specified Boolean data type from the pool
     * @attention This function is suitable if you want to clear one of many Boolean data types,created via the reserve function, if you want to remove one out of one data type, look into the ```finalize()``` function to prevent unnecessary calculations
     * @attention 2. The method automatically calls the ```focus()``` method on the first datatype declared, if none is found then it cleares the pool from memory
     * @param address The memory address of the Boolean data type to remove -> Type Boolean_type*
     */
    void (*clear)(Boolean_type *address);

    /**
     * A function used to create a boolean type
     * @attention 1. Though not mandatory, this function is suitable for use in generating the data types after calling the reserve function, if you want to create only one data type, look into the initialize function
     * @attention 2. The method automatically calls the ```focus()``` method on the newly created struct
     * @param value The address of a value, or an array, of any type to modify and return with the added functions -> Type void*
     * @param type The type of pointer passed in, whether a pointer to a specific value or array -> Type BOOLEAN_VALUE_TYPE
     * @return The address of a struct that contains the value and the added functions -> Type Boolean_type*
     */
    Boolean_type *(*create)(void *value, BOOLEAN_VALUE_TYPE type);
}Boolean_maker_type;

/**
 * The struct type for the Boolean_pool, which contains these properties:
 *  1. current -> Holds the focused boolean data type
 *  2. data -> Holds an array of stored Boolean data types
 *  3. total -> Holds the total number of data types stored
 */
typedef struct Boolean_pool_type{
    // A property that holds the focused boolean data type
    Boolean_type* current;
    // A property that holds an array of stored Boolean data types
    Boolean_type** value;
    // A property that holds the total number of data types stored
    int total;
}Boolean_pool_type;

// /**
//  * A function that constructs the Boolean_type struct
//  * @param value 
//  */
// Boolean_type* Boolean_maker(void* value, BOOLEAN_VALUE_TYPE type);

// /**
//  * A helper function that checks if the stored value is true or false
//  * @attention Please use this within the Boolean_maker function, as it is internal
//  * @return The string "true" if true and "false" if false -> Type char*
//  */
// char* _Boolean_maker_boolValue();

// /**
//  * A helper function that cleares the current Boolean_type instance
//  * @attention Please use this within the Boolean_maker function, as it is internal
//  */
// void _Boolean_maker_clear();