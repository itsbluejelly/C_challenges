# The C methods

This project is aimed to solve an issue with efficiency and data structures in C.

## Problems

- **An issue with repititveness in code**: In C programs, there tends to be a repititive manner in solving common issues, such as looping through a list and accessing a specific element.

- **Creating a uniform manner of programming**: Since C is a low-level language which is not opinionated on how activities are carried out. This tends to be a problem during debugging since there is no reliable source of error.

## Solution

To create object-like data types which contain in-house methods on how to handle the stored data, while not shifting the culture around C.

## Example code

```C
// IMPORTING NECESSARY LIBRARIES
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// DEFINING THE HIDDEN BOOLEAN STRUCT WITH ALL ITS PROPERTIES
typedef struct _Boolean{
    bool value; // THE VALUE TO MANIPULATE
    char* (*boolValue)(void); // A FUNCTION TO TELL IF THE VALUE IS TRUE OR FALSE
} _Boolean;

_Boolean function Boolean(bool value){
    // CARRYING OUT LOGIC
    return boolean;
    
}

bool isTrue = Boolean(100);
printf(isTrue.value) // 1
printf(isTrue.boolValue()) // true
```

## Folder structure

The project is structured in such a way that each folder has its own data type, these ones are as follows:

|   | Folder  | Description                                                                                  |
|---|---------|----------------------------------------------------------------------------------------------|
|   | Boolean | *A data type that contains all methods involving booleans and manipulates the boolean value* |

## Overview of data types

1. ### Boolean

| Methods                                                                     | Properties                                                                                       |
|-----------------------------------------------------------------------------|--------------------------------------------------------------------------------------------------|
| **value**<br>  Returns the stored value in bit form, 0 for false and 1 for true | **boolValue()**<br>  Returns the stored value status as "true" if truthy and "false" if falsy |

### Note

> This project is mainly for experimentation and not a strong dislike on how one can choose to code their programs in C. Please take it as an opportunity taken to experiment and test the waters on C's data structures and types 

