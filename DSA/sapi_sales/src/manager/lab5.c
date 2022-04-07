//
// Created by Kriszta Oniga on 3/16/2022.
//

#include "stdio.h"
#include "product_stack.h"
#include "useful.h"

void testProductStackFunctionalities(){
    ProductStack  *productStack;

    createProductStack(&productStack, STACK_CAPACITY);

    freopen(CON, "r", stdin);

    int choice;
    while (1){
        printf("\n\n1. Push Operation\n");
        printf("2. Pop Operation\n");
        printf("3. Top Operation\n");
        printf("4. isEmpty Operation\n");
        printf("5. isFull Operation\n");
        printf("6. Exit\n");

        printf("Enter your choise of operation: ");
        scanf("%i", &choice);
        switch(choice){
            case 1: {
                Product *product;
                createProduct(&product);
                printf("Name:");
                scanf("\n%[^\n]", product->name);
                printf("Type:");
                scanf("%i", &product->type);
                printf("Amount:");
                scanf("%i", &product->amount);

                push(productStack, product);
                break;
            }
            case 2: {
                pop(productStack);
                break;
            }
            case 3: {
                printProduct(top(productStack), CON);
                break;
            }
            case 4: {
                if(stackIsEmpty(productStack)){
                    printf("The stack is empty\n");
                }
                else
                    printf("The stack is not empty\n");
                break;
            }
            case 5: {
                if(stackIsFull(productStack)){
                    printf("The stack is full\n");
                }
                else
                    printf("The stack is not full\n");
                break;
            }
            case 6: {
                deleteProductStack(&productStack);
                return;
            }
            default:
                printf("Incorrect choice \n");
        }
    }
}