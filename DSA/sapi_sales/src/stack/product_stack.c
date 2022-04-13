//
// Created by Kriszta Oniga on 3/16/2022.
//
#include "product_array.h"
#include "product.h"
#include "product_stack.h"
#include "messages.h"
#include "errors.h"

void createProductStack(ProductStack **productStack, unsigned int capacity){
    *productStack = (ProductStack *) malloc(1 * sizeof(ProductStack));
    if (!(*productStack))
        printErrorMessage(MEMORY_ALLOCATION);

    (*productStack) -> Products = malloc(capacity * sizeof(Product *));
    if (!(*productStack) -> Products) {
        printErrorMessage(MEMORY_ALLOCATION);
    }

    (*productStack) -> top = -1;
    (*productStack) -> capacity = capacity;

    for(int i = 0; i < (*productStack) -> capacity; ++i){
        (*productStack) -> Products[i] = malloc(1 * sizeof(Product));
    }


   for(int i = 0; i < (*productStack) -> capacity; ++i){
       (*productStack) -> Products[i] = NULL;
   }
}
void push(ProductStack *productStack, Product *product){
    if(stackIsFull(productStack))
        printf("Stack is full\n");
    else {
        productStack -> top++;
        productStack -> Products[productStack -> top] = product;
    }
}
void pop(ProductStack *productStack) {
    if (stackIsEmpty(productStack))
        printf("Stack is empty\n");
    else {
        //deleteProduct(&productStack->Products[productStack->top]);
        productStack->Products[productStack->top] = NULL;
        productStack->top--;
    }
}
Product *top(ProductStack *productStack){
    if (stackIsEmpty(productStack))
        printf("Stack is empty\n");
    else{
        return productStack->Products[productStack -> top];
    }
    return NULL;
}

bool stackIsEmpty(ProductStack *productStack){
    if(!productStack){
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    return productStack -> top == -1;
}
bool stackIsFull(ProductStack *productStack){
    if(!productStack){
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    return productStack -> top == productStack -> capacity - 1;
}
void deleteProductStack(ProductStack **productStack){
    if((*productStack)){
        for(int i = 0; i < (*productStack) -> capacity; ++i){
            if((*productStack) -> Products[i] != NULL)
                free((*productStack)->Products[i]);
        }
        free((*productStack)->Products);
        free(*productStack);
        printDeletedMessage(PRODUCT_STACK);
    }
}