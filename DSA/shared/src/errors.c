//
// Created by Kriszta Oniga on 2/23/2022.
//
#include <stdio.h>
#include <stdlib.h>
#include "errors.h"

void printErrorMessage(enum ErrorType errorType) {
    switch(errorType){
        case MEMORY_ALLOCATION: {
            printf("\nSikertelen memoriafoglalas!!!\n");
            break;
        }
        case FILE_NOT_FOUND: {
            printf("\nSikertelen file megnyitas!!!\n");
            break;
        }
        case NULL_POINTER_EXCEPTION: {
            printf("\nNincs inicializalva!!!\n");
        }
        default: {
            printf("\nUndefined Error");
            break;
        }
    }
}

