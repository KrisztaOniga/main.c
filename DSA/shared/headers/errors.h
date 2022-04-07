//
// Created by Kriszta Oniga on 2/23/2022.
//

#ifndef DSA_ERRORS_H
#define DSA_ERRORS_H

#include <stdlib.h>
#include <stdio.h>

enum ErrorType{
    MEMORY_ALLOCATION,
    FILE_NOT_FOUND,
    NULL_POINTER_EXCEPTION,
    ADD_PRODUCT_ERROR
};

void printErrorMessage(enum ErrorType);

#endif //DSA_ERRORS_H
