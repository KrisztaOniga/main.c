//
// Created by Kriszta Oniga on 3/9/2022.
//

#ifndef MAIN_C_USER_ARRAY_H
#define MAIN_C_USER_ARRAY_H

#include "user.h"
#include <stdbool.h>
typedef struct{
    User** Users;
    int Capacity;
    int NumberOfUsers;
}UserArray;

void createUserArray(UserArray **userArray, unsigned int maxUsers);
void deleteUserArray(UserArray **userArray);
bool addNewUser(UserArray* userArray, User* newUser);
User* getUserAtPosition(UserArray* userArray, int position);
void printUserArray(UserArray *userArray, char *destination);

#endif //MAIN_C_USER_ARRAY_H
