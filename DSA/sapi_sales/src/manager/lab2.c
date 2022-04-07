//
// Created by Kriszta Oniga on 2/23/2022.
//
#include "lab2.h"
#include "useful.h"
#include "product.h"
//fuggvenyek definicioja
void testUserFunctionalities() {
    User *user1,*user2,*user3;
    createUser(&user1);
    createUser(&user2);
    createUser(&user3);

    BirthDate date1 = {1980,2,23};
    BirthDate date2 = {2003,10,7};
    BirthDate date3 = {1990,3,14};

    setUsersData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, date1);
    setUsersData(user2,  "Jane Austin", TEACHER, FEMALE, ENGINEERING, date2);
    setUsersData(user3, "Jakob Brown", STUDENT, MALE, MATHEMATICS_INFORMATICS, date3);

    printUser(user1,"CON");
    printUser(user2,"CON");
    printUser(user3,"CON");

    deleteUser(&user1);
    deleteUser(&user2);
    deleteUser(&user3);
}
void testProductFunctionalities(){

    Product *product1, *product2, *product3;

    createProduct(&product1);
    createProduct(&product2);
    createProduct(&product3);

    setProductData(product1, "Apple", FRUIT, 10);
    setProductData(product2, "Book", SCHOOL, 4);
    setProductData(product3,"Tomato", VEGETABLE, 20);

    printProduct(product1, CON);
    printProduct(product2, CON);
    printProduct(product3, CON);

    deleteProduct(&product1);
    deleteProduct(&product2);
    deleteProduct(&product3);
}
