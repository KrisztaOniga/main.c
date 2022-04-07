//
// Created by Kriszta Oniga on 3/9/2022.
//

#include "product_array.h"
#include "product.h"
#include "errors.h"
#include "messages.h"


void createProductArray(ProductArray **productArray, unsigned int maxProducts) {
    *productArray = (ProductArray*) malloc(sizeof (ProductArray));
    if(!(*productArray)){
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*productArray)->maxProducts = maxProducts;
    (*productArray)->products = (Product**) malloc(maxProducts*sizeof(Product*));
    if(!(*productArray)->products){
        printErrorMessage(MEMORY_ALLOCATION);
    }
    for (int i = 0; i < (*productArray)->maxProducts; ++i) {
        (*productArray)->products[i] = NULL;
    }
}

void deleteProductArray(ProductArray **productArray) {
    if(*productArray != NULL){
        for (int i = 0; i < (*productArray)->maxProducts; ++i) {
            deleteProduct(&(*productArray)->products[i]);
        }
        (*productArray)->maxProducts = 0;
        free((*productArray)->products);
        free((*productArray));
        *productArray = NULL;
        printDeletedMessage(PRODUCT_ARRAY);
    }
}

bool addNewProduct(ProductArray *productArray, Product *newProduct, int position) {
    if(!productArray || !newProduct || position < 0 || position >= productArray->maxProducts){
        printf("Incorrect position or array is not NULL!\n");
        return false;
    }
    productArray->products[position] = newProduct;
    return true;
}

Product *getProductAtPosition(ProductArray *productArray, int position) {
    if(!productArray || position < 0 || position >= productArray->maxProducts){
        printf("Incorrect position or array is not NULL!\n");
        return NULL;
    }
    return productArray->products[position];
}

int findElementInArray(ProductArray *productArray, int productId) {
    for (int i = 0; i < productArray->maxProducts; ++i) {
        if(productArray->products[i]->id == productId)
            return i;
    }
    return -1;
}