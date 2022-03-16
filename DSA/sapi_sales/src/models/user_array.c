//
// Created by Kriszta Oniga on 3/9/2022.
//
#include "user_array.h"
#include "user.h"


void createUserArray(UserArray **userArray, unsigned int maxUsers){
    *userArray = (UserArray *) malloc(1 * sizeof(UserArray));
    if(!(*userArray))
        printErrorMessage(MEMORY_ALLOCATION);
    (*userArray) -> Users = (User **)malloc(maxUsers * sizeof (User *));
    if(!(*userArray) -> Users){
        printErrorMessage(MEMORY_ALLOCATION);
    }
    for( int i = 0; i < maxUsers; ++i)
        (*userArray) -> Users[i] = (User *)malloc(maxUsers * sizeof (User));

    (*userArray) -> Capacity = maxUsers;
    (*userArray) -> NumberOfUsers = 0;
}
void deleteUserArray(UserArray **userArray){
    if(*userArray != NULL){
        for( int i = 0; i < (*userArray) -> Capacity; ++i){
            deleteUser(&(*userArray) -> Users[i]);
        }
    }
    (*userArray) -> Capacity = 0;
    free((*userArray) -> Users);
    free((*userArray));
    *userArray = NULL;
    printDeletedMessage(USER);
}
bool addNewUser(UserArray* userArray, User* newUser){
    if(userArray -> NumberOfUsers < userArray -> Capacity){
        userArray -> Users[userArray->NumberOfUsers] = newUser;
        userArray -> NumberOfUsers ++;
        return true;
    }
    return false;
}
User* getUserAtPosition(UserArray* userArray, int position){
    return userArray -> Users[position];
}
void printUserArray(UserArray *userArray, char *destination ){
    freopen(destination, "w", stdout);
    for(int i = 0; i < (*userArray).NumberOfUsers; ++i){
        if(userArray -> Users[i] != NULL)
            printUser(userArray -> Users[i], "CON");
    }
    freopen("CON", "w", stdout);
}
int searchById(UserArray *userArray, int userid) {
    for( int i = 0; i < userArray->Capacity; ++i)
        if(userArray -> Users[i] -> id == userid)
            return i;
}

