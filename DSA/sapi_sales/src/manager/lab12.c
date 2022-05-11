//
// Created by Kriszta Oniga on 5/11/2022.
//
#include "product_hash.h"
#include "useful.h"
#include "product.h"

void testProductHashTableFunctionalities(){
    Hash *hash = NULL;
    createHash(&hash, 8);
    freopen(CON, "r", stdin);

    int choice;
    while (1) {
        printf("\n 1. Insert Operation\n");
        printf("2. Print Operation\n");
        printf("3. Search Operation\n");
        printf("4. Delete Operation\n");
        printf("5. Free Operation\n");

        printf("Enter your choise of operation: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                Product *product1, *product2, *product3;

                createProduct(&product1);
                createProduct(&product2);
                createProduct(&product3);

                setProductData(product1, "Apple", FRUIT, 10);
                setProductData(product2, "Book", SCHOOL, 4);
                setProductData(product3,"Tomato", VEGETABLE, 20);
                insertHash(hash,product1);
                break;
            }
            case 2: {
                printHashTable(hash);
                break;
            }
            case 3: {
                printf("Search by ID: \n");
                printf("User ID to find: ");
                int id;
                scanf("%d", &id);
                if(searchHashTable(hash, id)){
                    printf("The %i id can be found in hash\n", id);
                }
                else {
                    printf("The %i id can't be found in hash\n", id);
                }
                break;
            }
            case 4: {
                printf("Delete by ID: ");
                printf("User ID to delete: ");
                int id;
                scanf("%d", &id);
                deleteFromHashTable(hash, id);
                break;
            }
            case 5: {
                freeHashTable(&hash);
                exit(0);
            }
            default:{
                printf("Incorrect choice \n");
                break;
            }

        }
    }
}

