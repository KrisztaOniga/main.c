//
// Created by Kriszta Oniga on 4/13/2022.
//
#include "user_list.h"
#include "messages.h"
#include "errors.h"

void createUserNode(UserNode **userNode, User *userValue) {
    *userNode = (UserNode *) malloc(sizeof(UserNode));//egy csomopont helyfoglalasa
    if (!(*userNode)) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*userNode)->next = NULL;//a kovetkezo elem cime Null, ez az egyetlen elem
    createUser(&(*userNode)->userValue);
    setUsersData((*userNode)->userValue, userValue->name, userValue->type,
                 userValue->gender, userValue->specialization, userValue->birthDate);

}

void printUserList(UserNode *userNode, char *destination) {
    UserNode *p = userNode;
    while (p != NULL) {
        printUser(p->userValue, CON);
        p = p->next;
    }
}

User *findElementInList(UserNode *userNode, int userId) {
    UserNode *p = userNode;
    while (p != NULL) {
        if (p->userValue->id == userId){
            return userNode->userValue;
        }
        p = p->next;
    }
    return NULL;
}

int findElementInList2(UserNode * userNode, int userID){
    int position = -1, index = 0;
    UserNode * current = userNode;
    while (current != NULL){
        if(current->userValue->id == userID){
            position = index;
            return position;
        }
        index ++;
        current = current->next;
    }
    return position;
}

void insertFirst(UserNode **userNode, User *userValue) {
    UserNode *newNode;
    createUserNode(&newNode, userValue);
    newNode->next = (*userNode);//uj csomopont next mezoje tartalmazza a list elso elemenek a cimet
    (*userNode) = newNode;//az uj csompont lesz a lista elso eleme
}

void insertLast(UserNode *userNode, User *userValue) {
    UserNode *newNode;
    UserNode *p = (userNode);

    while (p->next != NULL) {
        p = p->next;
    }
    createUserNode(&newNode, userValue);
    p->next = newNode;
}

void insertLast2(UserNode **userNode, User *userValue){
    if(*userNode == NULL){
        createUserNode(userNode, userValue);
        return;
    }

    UserNode *temp = *userNode;
    UserNode *newUser;

    while (temp->next != NULL){
        temp = temp->next;
    }
    createUserNode(&newUser, userValue);
    temp->next = newUser;

}

User *removeFirst(UserNode **userNode) {
    User *returnValue;
    UserNode *next_node = NULL;
    if (*userNode == NULL) {
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    next_node = (*userNode)->next;
    returnValue = (*userNode)->userValue;
    free(*userNode);
    *userNode = next_node;
    return returnValue;
}

int removeFirst2(UserNode **userNode){
    UserNode *temp = (*userNode);
    (*userNode) = (*userNode)->next;
    int deletedID = temp->userValue->id;
    deleteUser(&temp->userValue);
    free(temp);
    return deletedID;
}

User *removeLast(UserNode *userNode) {
    User *returnValue;
    if (userNode->next == NULL) {
        returnValue = userNode->userValue;
        free(userNode);
        return returnValue;
    }//ha csak egy csomopont van
    else {
        UserNode *last = userNode;
        UserNode *secondLast = userNode;
        while (last->next != NULL) {
            secondLast = last;
            last = last->next;
        }
        secondLast->next = NULL;
        free(last);
    }
    /*UserNode *current = userNode;
    while (current->next->next != NULL) {
        current = current->next;
    }
     */
    return userNode->userValue;
}
int removeLast2(UserNode **userNode){
    int deletedID = -1;
    if(*userNode == NULL){
        return deletedID;
    }
    if((*userNode)->next == NULL){
        deletedID = (*userNode)->userValue->id;
        deleteUser(&(*userNode)->userValue);
        free(*userNode);
        (*userNode) = NULL;
        return deletedID;
    }

    UserNode *temp = *userNode;
    while (temp->next != NULL){
        temp = temp->next;
    }
    deletedID = temp->userValue->id;
    deleteUser(&temp->userValue);
    free(temp);
    temp = NULL;
    return deletedID;
}

void deleteUserList(UserNode **userNode) {
    while (*userNode) {
        UserNode *current = *userNode;
        (*userNode) = (*userNode)->next;
        deleteUser(&current->userValue);
        free(current);
    }
    *userNode = NULL;
}

void deleteUserNode(UserNode **userNode, User *userValue) {
    UserNode *p = *userNode;
    UserNode *e = NULL;
    while (p != NULL && p->userValue != userValue) {
        e = p;
        p = p->next;
    }
    if (p != NULL) {
        if (e == NULL) {
            *userNode = p->next;
        } else {
            e->next = p->next;
        }
        free(p);
    } else {
        printf("Nincs ilyen elem");
    }
}