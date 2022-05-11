//
// Created by Kriszta Oniga on 5/11/2022.
//

#ifndef MAIN_C_PRODUCT_HASH_H
#define MAIN_C_PRODUCT_HASH_H

#include "product.h"

typedef struct Hash {
    Product** table;
    int capacity, elements;
} Hash;

void createHash(Hash** pHash,int capacity);
void insertHash(Hash* hash, Product* product);
void printHashTable(Hash* hash);
int searchHashTable(Hash* hash, int id);
void deleteFromHashTable(Hash* hash, int id);
void freeHashTable(Hash** pHash);

#endif //MAIN_C_PRODUCT_HASH_H
