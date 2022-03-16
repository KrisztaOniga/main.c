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

    (*productStack) -> Products = (ProductStack **) malloc(capacity * sizeof(ProductStack *));
    if (!(*productStack) -> Products) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    for(int i = 0; i < (*productStack) -> capacity; ++i){
        (*productStack) -> Products[i] = (ProductStack *) malloc(capacity * sizeof(ProductStack));
    }

    (*productStack) -> top = -1;
    (*productStack) -> capacity = capacity;
}
void push(ProductStack *productStack, Product *product){
    if(stackIsFull(productStack))
        return;
    productStack -> Products[++productStack -> top] = product;
}
int pop(ProductStack *productStack){
    if (stackIsEmpty(productStack))
        return NULL;
    productStack->top--;
    return productStack->Products[productStack->top + 1];
}
int top(ProductStack *productStack){
    if (stackIsEmpty(productStack))
        return NULL;
    return productStack->Products[productStack -> top];
}

bool stackIsEmpty(ProductStack *productStack){
    if(productStack -> top == -1)
        return true;
    return false;
}
bool stackIsFull(ProductStack *productStack){
    if(productStack -> top == productStack -> capacity - 1)
        return true;
    return false;
}
void deleteProductStack(ProductStack **productStack){
    for(int i = 0; i < (*productStack) -> capacity; ++i){
        if((*productStack) -> Products[i] != NULL)
            free((*productStack)->Products[i]);
    }
    free((*productStack)->Products);
    free(*productStack);
}