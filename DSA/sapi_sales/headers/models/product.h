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

enum ProductType{
    GROCERY,
    FRUIT,
    SCHOOL,
    OBJECT
};

typedef struct {
    int id;
    char *name;
    enum ProductType type;
    unsigned int amount;
    time_t creationDate;
    int price;
}Product;


char* getProductType(enum ProductType type);

void createProduct(Product** product);
void setProductData(Product *product, char *name, enum ProductType type, unsigned int amount, int price);
void printProduct(Product* product, char* destination);
void deleteProduct(Product **product);

#endif //DSA_PRODUCT_H