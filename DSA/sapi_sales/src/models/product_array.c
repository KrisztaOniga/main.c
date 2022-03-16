//
// Created by Kriszta Oniga on 3/9/2022.
//

#include "product_array.h"
#include "product.h"
#include "errors.h"
#include "messages.h"

void createProductArray(ProductArray **productArray, unsigned int maxProducts) {
    *productArray = (ProductArray *) malloc(1 * sizeof(ProductArray));
    if (!(*productArray))
        printErrorMessage(MEMORY_ALLOCATION);

    (*productArray)->Products = (Product **) malloc(maxProducts * sizeof(Product *));
    if (!(*productArray)->Products) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*productArray)->Capacity = maxProducts;
    (*productArray)->NumberOfProducts = 0;
}
void deleteProductArray(ProductArray **productArray){
    if(*productArray != NULL){
        for( int i = 0; i < (*productArray) -> Capacity; ++i){
            deleteProduct(&(*productArray) -> Products[i]);
        }
    }
    (*productArray) -> Capacity = 0;
    free((*productArray) -> Products);
    free((*productArray));
    *productArray = NULL;
    printDeletedMessage(PRODUCT);
}
bool addNewProduct(ProductArray* productArray , Product *newProduct){
    if(productArray -> NumberOfProducts < productArray -> Capacity){
        productArray -> Products[productArray -> NumberOfProducts] = newProduct;
        productArray -> NumberOfProducts ++;
        return true;
    }
    return false;
}

void printProductArray(ProductArray *productArray, char *destination){
    freopen(destination, "w", stdout);
    for(int i = 0; i < (*productArray).NumberOfProducts; ++i){
        printProduct(productArray -> Products[i], "CON");
    }
    freopen("CON", "w", stdout);
}


