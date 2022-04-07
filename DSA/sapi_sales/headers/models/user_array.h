//
// Created by Kriszta Oniga on 3/9/2022.
//

#ifndef MAIN_C_USER_ARRAY_H
#define MAIN_C_USER_ARRAY_H

#include "user.h"
#include <stdbool.h>
typedef struct {
    User** users;
    unsigned int maxUsers;
}UserArray;

void createUserArray (UserArray **userArray, unsigned int maxUsers);

void deleteUserArray (UserArray **userArray);

bool addNewUser(UserArray *userArray, User* newUser, int position);

User* getUserPosition(UserArray *userArray, int position);

void readUsers(UserArray* userArray, char* from);

void printUsers(UserArray* userArray, char* destination);

#endif //MAIN_C_USER_ARRAY_H
