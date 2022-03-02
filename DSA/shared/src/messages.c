//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "messages.h"
#include <stdio.h>
#include <stdlib.h>
void printDescriptionMessage(enum LabType messageType){
    switch (messageType) {
        case LAB2:
            printf("~~~~~~~~~~");
            printf("Labor 2 feladatok");
            printf("~~~~~~~~~~");
            break;
        case LAB3:
            printf("~~~~~~~~~~");
            printf("Labor 3 feladatok");
            printf("~~~~~~~~~~");
            break;
        default: {
            printf("\nUndefined description\n");
            break;
        }
    }
}
