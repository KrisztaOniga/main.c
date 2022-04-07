//
// Created by Kriszta Oniga on 3/9/2022.
//

#include "lab3.h"
#include "user.h"
#include "user_array.h"
#include "useful.h"
#include "product_array.h"
#include "product.h"

void testUserArray() {
    UserArray *userArray;

    createUserArray(&userArray, MAX_USERS);

    readUsers(userArray, FILE_IN_USERS_PRODUCTS);

    printUsers(userArray, CON);

    deleteUserArray(&userArray);
}