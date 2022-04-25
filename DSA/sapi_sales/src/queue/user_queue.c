//
// Created by Kriszta Oniga on 4/6/2022.
//
#include "user_queue.h"
#include "errors.h"
#include "user.h"
#include "messages.h"

void createUserQueue(UserQueue **userQueue, unsigned int maxSize) {
    *userQueue = (UserQueue *) malloc(sizeof(UserQueue));
    if (!(*userQueue))
        printErrorMessage(MEMORY_ALLOCATION);

    (*userQueue)->rear = -1;
    (*userQueue)->front = -1;
    (*userQueue)->size = maxSize;

    (*userQueue)->users = (User **) malloc(maxSize * sizeof(User *));
    if (!(*userQueue)->users) {
        printErrorMessage(MEMORY_ALLOCATION);
    }

    for (int i = 0; i < (*userQueue)->size; ++i) {
        (*userQueue)->users[i] = malloc(sizeof(User));
    }
}

bool queueIsEmpty(UserQueue *userQueue) {
    if (!userQueue) {
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }
    return (userQueue->front == -1 && userQueue->rear == -1);
}

bool queueIsFull(UserQueue *userQueue) {
    if (!userQueue) {
        printErrorMessage(NULL_POINTER_EXCEPTION);
    }

    return (userQueue->rear == userQueue->front - 1) ||
           (userQueue->front == 0 && userQueue->rear == userQueue->size - 1);
}

void enqueue(UserQueue *userQueue, User *user) {
    if (queueIsFull(userQueue))
        printf("Queue is full\n");
    else {
        if (queueIsEmpty(userQueue)) {
            userQueue->rear = 0;
            userQueue->front = 0;
        } else {
            userQueue->rear == userQueue->size - 1 ? userQueue->rear = 0 : userQueue->rear++;
        }
        userQueue->users[userQueue->rear] = user;
    }
}

void dequeue(UserQueue *userQueue) {
    if (queueIsEmpty(userQueue)) {
        printf("Queue is empty\n");
    }
    deleteUser(&userQueue->users[userQueue->front]);
    if (userQueue->rear == userQueue->front) {
        userQueue->rear = -1;
        userQueue->front = -1;
    } else {
        userQueue->front == userQueue->size - 1 ? userQueue->front = 0 : userQueue->front++;
    }
}

int findElementInQueue(UserQueue *userQueue, int userId) {
    int i = userQueue->front;
    while (1) {
        if (userQueue->users[i]->id == userId) {
            return i;
        }
        if (i == userQueue->rear)
            break;
        if (i == userQueue->size - 1) {
            i = 0;
        } else
            i++;
    }
    return -1;
}

int finElementInQueuebyUser(UserQueue * userQueue, User *user){
    for (int i = userQueue->front; i < userQueue->rear; ++i) {
        if(userQueue->users[i]->id == user->id &&
           strcmp((const char *) userQueue->users[i]->specialization, (const char *) user->specialization) == 0 &&
           strcmp((const char *) userQueue->users[i]->gender, user->name) == 0 &&
           strcmp((const char *) userQueue->users[i]->gender, (const char *) user->gender) == 0 &&
           userQueue->users[i]->birthDate.day == user->birthDate.day &&
                userQueue->users[i]->birthDate.month == user->birthDate.month &&
                userQueue->users[i]->birthDate.year == user->birthDate.year)
            return user->id;
        return 0;
    }
}

void printQueue(UserQueue *userQueue, char *destination) {
    int i = userQueue->front;
    while (1) {
        printUser(userQueue->users[i], destination);
        if (i == userQueue->rear)break;
        if (i == userQueue->size - 1) {
            i = 0;
        } else i++;
    }
//    if (!(queueIsEmpty(userQueue))) {
//        for (int i = userQueue->front; i <= userQueue->rear; ++i)
//            printUser(userQueue->users[i], CON);
//    }
}

void deleteQueue(UserQueue **userQueue) {
    if ((*userQueue)) {
        for (int i = 0; i < (*userQueue)->size; ++i) {
            if ((*userQueue)->users[i] != NULL)
                deleteUser(&(*userQueue)->users[i]);
        }
        free(*userQueue);
        printDeletedMessage(USER_QUEUE);
    }
}
