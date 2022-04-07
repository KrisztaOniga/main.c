//
// Created by Kriszta Oniga on 4/6/2022.
//
#include "user_queue.h"
#include "errors.h"
#include "user.h"
#include "messages.h"

void createUserQueue(UserQueue **userQueue, unsigned int maxSize) {
    *userQueue = (UserQueue *) malloc(1 * sizeof(UserQueue));
    if (!(*userQueue))
        printErrorMessage(MEMORY_ALLOCATION);

    (*userQueue)->users = malloc(maxSize * sizeof(User *));
    if (!(*userQueue)->users) {
        printErrorMessage(MEMORY_ALLOCATION);
    }

    (*userQueue)->rear = -1;
    (*userQueue)->front = -1;
    (*userQueue)->size = maxSize;

    for (int i = 0; i < (*userQueue)->size; ++i) {
        (*userQueue)->users[i] = malloc(1 * sizeof(User));
    }

}

bool queueIsEmpty(UserQueue *userQueue) {
    if (!userQueue) {
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    return (userQueue->front == -1 && userQueue->rear == -1 );
}

bool queueIsFull(UserQueue *userQueue) {
    if (!userQueue) {
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    //return userQueue -> rear == userQueue -> size - 1;
    return (userQueue->rear == userQueue->size - 1 && userQueue->front == 0) || userQueue->front == userQueue->rear + 1;

}

void enqueue(UserQueue *userQueue, User *user) {
    if (queueIsFull(userQueue))
        printf("Queue is full\n");
    else {
        userQueue->rear++;
        userQueue->users[userQueue->rear] = user;
        userQueue->rear = (userQueue->rear + 1) % (userQueue->size);
    }
}

void dequeue(UserQueue *userQueue) {
    if (queueIsEmpty(userQueue)) {
        printf("Queue is empty\n");
        return;
    }
    else {
        userQueue->users[userQueue->front] = NULL;
        userQueue->front = (userQueue->front + 1) % (userQueue->size);
        userQueue->front ++;
    }
}

int findElementInQueue(UserQueue *userQueue, int userId){
    for (int i = 0; i < userQueue->size; ++i) {
        if(userQueue->users[i]->id == userId)
            return i;
    }
    return -1;
}

void printQueue(UserQueue *userQueue, char *destination) {
    if (!(queueIsEmpty(userQueue))) {
        for (int i = userQueue->front; i < userQueue->rear; ++i)
            printUser(userQueue->users[i], CON);
    }
}

void deleteQueue(UserQueue **userQueue) {
    if ((*userQueue)) {
        for (int i = 0; i < (*userQueue)->size; ++i) {
            if ((*userQueue)->users[i] != NULL)
                free((*userQueue)->users[i]);
        }
        free((*userQueue)->users);
        free(*userQueue);
        printDeletedMessage(USER_QUEUE);
    }
}
