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
        if (p->userValue->id == userId)
            return userNode->userValue;
        p = p->next;
    }
    return NULL;
}

void insertFirst(UserNode **userNode, User *userValue) {
    UserNode *newNode;
    createUserNode(&newNode, userValue);
    newNode->next = (*userNode);//uj csomopont next mezoje tartalmazza a list elso elemenek a cimet
    (*userNode) = newNode;//az uj csompont lesz a lista elso eleme
}

void insertLast(UserNode *userNode, User *userValue) {
    UserNode *newNode;
    createUserNode(&newNode, userValue);
    UserNode *p = (userNode);
    while (p->next != NULL) {
        p = p->next;
    }
    p->next = newNode;
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
    return userNode;
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