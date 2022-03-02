//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "lab2.h"
//fuggvenyek definicioja
void testUserFunctionalities(){
    User *user1, *user2, *user3;

    createUser(&user1);
    createUser(&user2);
    createUser(&user3);

    setUserData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, 2002, 02, 18);
    setUserData(user2, "Jane Austin", TEACHER, FEMALE, ENGINEERING, 1996, 04, 6);
    setUserData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, 2002, 8, 8);

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

    setProductData(product1,"MS1", "Apple", FRUIT, 10);
    setProductData(product2,"MS2", "Book", SCHOOL, 4);
    setProductData(product3,"MS3", "Tomato", GROCERY, 20);

    printProduct(product1, CON);
    printProduct(product2, CON);
    printProduct(product3, CON);

    deleteProduct(product1);
    deleteProduct(product2);
    deleteProduct(product3);
}
