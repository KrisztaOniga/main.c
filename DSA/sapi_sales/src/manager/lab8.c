//
// Created by Kriszta Oniga on 4/6/2022.
//
#include "lab8.h"
#include "useful.h"
#include "user_queue.h"
#include <stdio.h>

void testUserQueueFunctionalities(){
    UserQueue *userQueue;

    createUserQueue(&userQueue, 3);

    freopen(CON, "r", stdin);

    int choice;
    while (1){
        printf("\n\n1. Enqueue Operation\n");
        printf("2. Dequeue Operation\n");
        printf("3. FindElement Operation\n");
        printf("4. isEmpty Operation\n");
        printf("5. isFull Operation\n");
        printf("6. Print Operation\n");
        printf("7. Exit\n");

        printf("Enter your choise of operation: ");
        scanf("%i", &choice);
        switch(choice){
            case 1: {
                /*User *user;
                createUser(&user);
                printf("Name:");
                scanf("\n%[^\n]", user->name);
                printf("Specialization:");
                scanf("%i", &user->specialization);
                printf("Gender:");
                scanf("%i", &user->gender);
*/
                User *user1, *user2, *user3;

                createUser(&user1);
                createUser(&user2);
                createUser(&user3);

                BirthDate date1 = {1980,2,23};
                BirthDate date2 = {2003,10,7};
                BirthDate date3 = {1990,3,14};

                setUsersData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, date1);
                setUsersData(user2,  "Jane Austin", TEACHER, FEMALE, ENGINEERING, date2);
                setUsersData(user3, "Jakob Brown", STUDENT, MALE, MATHEMATICS_INFORMATICS, date3);

                enqueue(userQueue, user1);
                enqueue(userQueue, user2);
                enqueue(userQueue, user3);

                break;
            }
            case 2: {
                dequeue(userQueue);
                break;
            }
            case 3: {
                printf("User ID to find: ");
                int id;
                scanf("%i",&id);
                printf("Found at position: %i\n", findElementInQueue(userQueue,id));
                break;
            }
            case 4: {
                (queueIsEmpty(userQueue) ? (printf("The queue is empty\n")) : printf("The queue is not empty"));
                break;
            }
            case 5: {
                (queueIsFull(userQueue) ? (printf("The queue is full\n")) : printf("The queue is not full"));
                break;
            }
            case 6: {
                if(!queueIsEmpty(userQueue))
                    printQueue(userQueue, "CON");
                break;
            }
            case 7: {
                deleteQueue(&userQueue);
                exit(0);
            }
            default:{
                printf("Incorrect choice \n");
                break;
            }
        }
    }
}
