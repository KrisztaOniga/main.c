//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "product.h"
#include "errors.h"
//Fuggvenyek definicioja

char* getProductType(enum ProductType type){
    switch(type){
        case GROCERY:
            return "Grocery";
        case FRUIT:
            return "Fruit";
        case  SCHOOL:
            return "School";
        case OBJECT:
            return "Object";
        default:
            return "Undefined";
    }
}
void createProduct(Product ** product) {
    *product = (Product *) malloc(sizeof(Product));
    if(!(*product)){
        printErrorMessage(MEMORY_ALLOCATION);
    }
}

void setProductData(Product *product, char *id, char *name, enum ProductType type, unsigned int amount, int price){
    strcpy(product -> id, id);
    strcpy(product -> name, name);
    product -> type = type;
    product -> amount = amount;
    product -> creationDate = time(NULL);
    product -> price = price;
}

void PrintProduct(Product *product, CON ){
    printf("%s details:\n"
           "\t - ID: %s\n"
           "\t - TYPE: %s\n"
           "\t - AMOUNT: %u\n"
           "\t - CREATION DATE: %ld\n",
           product -> name,
           product -> id,
           getProductType(product -> type),
           product -> amount,
           product -> creationDate,
           product -> price);
}