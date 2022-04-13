//
// Created by Kriszta Oniga on 4/13/2022.
//
#include "user_list.h"

void createUserNode(UserNode** userNode, User* userValue){
    *userNode = (UserNode *) malloc(sizeof(UserNode));
    (*userNode)->next = NULL;
    createUser(&(*userNode)->userValue);
    setUsersData((*userNode)->userValue, userValue->name, userValue->type,
                 userValue->gender,userValue->specialization, userValue->birthDate);

}

void printUserList(UserNode* userNode, char* destination){
    while(userNode != NULL){
        printUser(userNode->userValue, CON);
        userNode = userNode->next;
    }
}

User* findElementInList(UserNode* userNode, int userId){
    UserNode *p = userNode;
    while (p != NULL){
        if(p->userValue->id == userId)
            return userNode->userValue;
        p = p->next;
    }
}
void insertFirst(UserNode** userNode, User* userValue){
    UserNode *newNode;
    createUserNode(&newNode, userValue);
    newNode->next = *userNode;
    *userNode = newNode;
}
void insertLast(UserNode** userNode, User* userValue){
    UserNode *newNode;
    createUserNode(&newNode, userValue);
    //newNode->userValue = userValue;
    newNode->next = NULL;
    if(*userNode == NULL) {
        *userNode = newNode;
    }else{
        UserNode* p = *userNode;
        while (p->next != NULL){
            p = p->next;
        }
        p->next = newNode;
    }
}

User* removeFirst(UserNode** userNode){
    if(*userNode != NULL){
        UserNode* p = *userNode;
        *userNode = (*userNode)->next;
        free(p);
    }
}
User* removeLast(UserNode* userNode);
void deleteUserList(UserNode** userNode);