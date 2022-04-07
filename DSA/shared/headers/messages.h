//
// Created by Kriszta Oniga on 2/23/2022.
//

#ifndef DSA_MESSAGES_H
#define DSA_MESSAGES_H

#include <stdlib.h>
#include <stdio.h>

enum LabType {
    LAB2,
    LAB3,
    LAB4,
    LAB5,
    LAB6,
    LAB8,
};
enum DelMess {
    USER,
    PRODUCT,
    USER_ARRAY,
    PRODUCT_ARRAY,
    PRODUCT_STACK,
    USER_QUEUE
};

void printDescriptionMessage(enum LabType);
void printDeletedMessage(enum DelMess);

#endif //DSA_MESSAGES_H
