//
// Created by Kriszta Oniga on 3/9/2022.
//

#ifndef MAIN_C_PRODUCT_ARRAY_H
#define MAIN_C_PRODUCT_ARRAY_H

#include "product.h"
#include <stdbool.h>

typedef struct {
    Product **products;
    unsigned int maxProducts;
} ProductArray;

void createProductArray(ProductArray **productArray, unsigned int maxProducts);

void deleteProductArray(ProductArray **productArray);

bool addNewProduct(ProductArray *productArray, Product *newProduct, int position);

int findElementInArray(ProductArray *productArray, int productId);

Product *getProductAtPosition(ProductArray *productArray, int position);

#endif //MAIN_C_PRODUCT_ARRAY_H
