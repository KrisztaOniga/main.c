//
// Created by Kriszta Oniga on 5/11/2022.
//
#include "product_hash.h"
#include "errors.h"

void createHash(Hash **pHash, int capacity) {
    (*pHash) = (Hash *) malloc(sizeof(Hash));
    if (!(*pHash)) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*pHash)->table = (Product **) malloc(capacity * sizeof(Product *));
    if (!(*pHash)->table) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    for (int i = 0; i < capacity; ++i) {
        createProduct(&(*pHash)->table[i]);
        (*pHash)->table[i]->id = -1;
    }
    (*pHash)->capacity = capacity;
    (*pHash)->elements = 0;
}

void insertHash(Hash *hash, Product *product) {
    int key = product->id % hash->capacity;
    int helper = key, i=0;
    while (i!=key) {
        if (hash->table[helper]->id != -1) {
            printf("\nMar foglalt");
            return;
        }
        if (helper == hash->capacity) {
            printf("\nHiba!");
            return;
        }
        i++;
        helper=(key+i)%hash->capacity;
    }
    if (helper != hash->capacity) {
        hash->table[helper] = product;
        hash->elements++;
    }
}

void printHashTable(Hash *hash) {
    for (int i = 0; i < hash->capacity; ++i) {
        if (hash->table[i]->id != -1) {
            printProduct(hash->table[i], "CON");
        }
    }
}

int searchHashTable(Hash *hash, int id) {
    int j, i = 0;
    do {
        j = (id + i) % hash->capacity;
        if (hash->table[j]->id == id) {
            return j;
        } else {
            ++i;
        }
    } while (hash->table[j]->id != -1 && (i != hash->capacity));
    return -1;//nincs benne az elem
}

void deleteFromHashTable(Hash *hash, int id){
    for(int i = 0; i < hash->capacity; ++i){
        if(hash->table[i]->id == id){
            free(hash->table[i]);
            hash->table[i]->id = -1;
        }
    }
}

void freeHashTable(Hash **pHash){
    if((*pHash)){
        for (int i = 0; i < (*pHash)->capacity; ++i) {
            free(&(*pHash)->table[i]);
        }
        free((*pHash)->table);
        free((*pHash));
    }
}