//
// Created by Kriszta Oniga on 3/9/2022.
//
#include "user_array.h"
#include "user.h"
#include "messages.h"
#include "errors.h"

void createUserArray(UserArray **userArray, unsigned int maxUsers) {
    *userArray = (UserArray*) malloc(sizeof (UserArray));
    if(!(*userArray)){
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*userArray)->users = (User**) malloc(maxUsers*sizeof(User*));
    if(!(*userArray)->users){
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*userArray)->maxUsers = maxUsers;
    for (int i = 0; i < (*userArray)->maxUsers; ++i) {
        (*userArray)->users[i] = NULL;
    }
}

bool addNewUser(UserArray *userArray, User *newUser, int position) {
    if(userArray != NULL && userArray->maxUsers > position && position >= 0 && newUser != NULL){
        userArray->users[position] = newUser;
        return true;
    }
    return false;
}

void readUsers(UserArray *userArray, char *from) {
    if(!freopen(from, "r", stdin))
        exit(-1);
    int nrOfUsers;
    scanf("%i\n", &nrOfUsers);
    for (int i = 0; i < nrOfUsers; ++i) {
        User* newUser;
        createUser(&newUser);
        scanf("%[^\n]", newUser->name);
        scanf("%i", &newUser->type);
        scanf("%i", &newUser->specialization);
        scanf("%i", &newUser->gender);
        scanf("%i%i%i\n", &newUser->birthDate.year, &newUser->birthDate.month, &newUser->birthDate.day);
        readUserProducts(newUser);
        addNewUser(userArray, newUser, i);
    }
    freopen(CON, "r", stdin);
}

void printUsers(UserArray *userArray, char *destination) {
    freopen(destination, "w", stdin);
    printf("All users: \n");
    for (int i = 0; i < userArray->maxUsers; ++i) {
        if (userArray->users[i] != NULL) {
            printUser(userArray->users[i], destination);
        }
    }
    freopen(CON,"w", stdin);
}

void deleteUserArray(UserArray **userArray) {
    if(*userArray != NULL){
        for (int i = 0; i < (*userArray)->maxUsers; ++i) {
            deleteUser(&(*userArray)->users[i]);
        }
        (*userArray)->maxUsers = 0;
        free((*userArray)->users);
        free((*userArray));
        *userArray = NULL;
        printDeletedMessage(USER_ARRAY);
    }
}