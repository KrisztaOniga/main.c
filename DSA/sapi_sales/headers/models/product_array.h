//
// Created by Kriszta Oniga on 3/9/2022.
//

#ifndef MAIN_C_PRODUCT_ARRAY_H
#define MAIN_C_PRODUCT_ARRAY_H

#include "product.h"
#include <stdbool.h>

typedef struct{
    Product** Products;
    int Capacity;
    int NumberOfProducts;
}ProductArray;

void createProductArray(ProductArray **productArray, unsigned int maxProducts);
void deleteProductArray(ProductArray **productArray);
bool addNewProduct(ProductArray* productArray , Product *newProduct);
void printProductArray(ProductArray *productArray, char *destination);

#endif //MAIN_C_PRODUCT_ARRAY_H
