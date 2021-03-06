//
// Created by Kriszta Oniga on 2/23/2022.
//

#ifndef DSA_PRODUCT_H
#define DSA_PRODUCT_H

#include <sys/utime.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
//Termekekkel kapcsolatos fuggvenyek deklaracioja
enum ProductType {
    VEGETABLE,
    FRUIT,
    SCHOOL,
    OBJECT
};

typedef struct Product {
    int id;
    char name[20];
    enum ProductType type;
    unsigned int amount;
    time_t creationDate;
}Product;

char* getProductType(enum ProductType type);

void createProduct( Product ** product);

void setProductData(
        Product *product,
        char name [20],
        enum ProductType type,
        unsigned int amount);

void printProduct(Product * product, char * destination);

void deleteProduct(Product **product);

#endif //DSA_PRODUCT_H