//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "lab2.h"
#include "useful.h"
#include "product.h"
//fuggvenyek definicioja
void testUserFunctionalities() {
    User *user1, *user2, *user3;

    createUser(&user1);
    createUser(&user2);
    createUser(&user3);

    setUserData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, 1900 + rand() % 69 + 20, rand() % 11 + 1,
                rand() % 30 + 1);
    setUserData(user2, "Jane Austin", TEACHER, FEMALE, ENGINEERING, 1900 + rand() % 69 + 20, rand() % 11 + 1,
                rand() % 30 + 1);
    setUserData(user3, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, 1900 + rand() % 69 + 20, rand() % 11 + 1,
                rand() % 30 + 1);

    printUser(user1, CON);
    printUser(user2, CON);
    printUser(user3, CON);

    deleteUser(&user1);
    deleteUser(&user2);
    deleteUser(&user3);

}
void testProductFunctionalities(){

    Product *product1, *product2, *product3;

    createProduct(&product1);
    createProduct(&product2);
    createProduct(&product3);

    setProductData(product1, "Apple", FRUIT, 10, 5);
    setProductData(product2, "Book", SCHOOL, 4, 4);
    setProductData(product3,"Tomato", GROCERY, 20, 3);

    printProduct(product1, CON);
    printProduct(product2, CON);
    printProduct(product3, CON);

    deleteProduct(&product1);
    deleteProduct(&product2);
    deleteProduct(&product3);
}
