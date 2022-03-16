//
// Created by Kriszta Oniga on 3/9/2022.
//

#include "lab3.h"
#include "user.h"
#include "user_array.h"
#include "product_array.h"
#include "product.h"

void testUserArray(){
    User *user1, *user2, *user3;
    UserArray *userArray1;

    createUser(&user1);
    createUser(&user2);
    createUser(&user3);


    setUserData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, 1900 + rand() % 69 + 20, rand() % 11 + 1,rand() % 30 + 1);
    setUserData(user2, "Jane Austin", TEACHER, FEMALE, ENGINEERING, 1900 + rand() % 69 + 20, rand() % 11 + 1,rand() % 30 + 1);
    setUserData(user3, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, 1900 + rand() % 69 + 20, rand() % 11 + 1,rand() % 30 + 1);

    createUserArray(&userArray1, 5);

    addNewUser(userArray1, user1);
    addNewUser(userArray1, user2);
    addNewUser(userArray1, user3);


    getUserAtPosition(userArray1, 1);

    //deleteUserArray(&userArray1);

    if(userArray1 == NULL)
        printDeletedMessage(USER);

    printUserArray(userArray1,"CON");
}
void testProductArray(){
    Product *product1, *product2;
    ProductArray *productArray1;

    createProduct(&product1);
    createProduct(&product2);

    setProductData(product1, "Apple", FRUIT, 10, 5);
    setProductData(product2, "Book", SCHOOL, 4, 4);

    createProductArray(&productArray1, 4);

    addNewProduct(productArray1, product1);
    addNewProduct(productArray1, product2);


    //deleteProductArray(&productArray1);

    if(productArray1 == NULL)
        printDeletedMessage(PRODUCT);

    printProductArray(productArray1, "CON");
}