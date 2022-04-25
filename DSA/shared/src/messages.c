//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "messages.h"
#include <stdio.h>
#include <stdlib.h>
void printDescriptionMessage(enum LabType messageType){
    switch (messageType) {
        case LAB2:
            printf("**********************************************\n");
            printf("Testing basic User and Product functionalities\n");
            printf("**********************************************\n");
            break;
        case LAB3:
            printf("**************************************************\n");
            printf("Testing UserArray and ProductArray functionalities\n");
            printf("**************************************************\n");
            break;
        case LAB5:
            printf("****************************************\n");
            printf("Testing ProductStack functionalities\n");
            printf("****************************************\n");
            break;
        case LAB8:
            printf("*********************************\n");
            printf("Testing UserQueue functionalities\n");
            printf("*********************************\n");
            break;
        case LAB9:
            printf("*********************************\n");
            printf("Testing UserList functionalities\n");
            printf("*********************************\n");
            break;
        default: {
            printf("\nUndefined description\n");
            break;
        }
    }
}
void printDeletedMessage(enum DelMess DeletedMessage) {
    switch (DeletedMessage) {
        case PRODUCT: {
            printf("!!!!!");
            printf("Product deleted");
            printf("!!!!!\n");
            break;
        }
        case USER: {
            printf("!!!!!");
            printf("User deleted");
            printf("!!!!!\n");
            break;
        }
        case USER_ARRAY: {
            printf("!!!!!");
            printf("UserArray deleted");
            printf("!!!!!\n");
            break;
        }
        case PRODUCT_ARRAY: {
            printf("!!!!!");
            printf("ProductArray deleted");
            printf("!!!!!\n");
            break;
        }
        case PRODUCT_STACK: {
            printf("!!!!!");
            printf("ProductStack deleted");
            printf("!!!!!\n");
            break;
        }
        case USER_QUEUE: {
            printf("!!!!!");
            printf("UserQueue deleted");
            printf("!!!!!\n");
            break;
        }
        case USER_LIST: {
            printf("!!!!!");
            printf("UserList deleted");
            printf("!!!!!\n");
            break;
        }

        default:
            printf("Undefined description\n");
            break;
    }
}
