//
// Created by Kriszta Oniga on 4/6/2022.
//
#include "lab8.h"
#include "useful.h"
#include "user_queue.h"

void testUserQueueFunctionalities(){
    UserQueue userQueue;
    createUserQueue(&userQueue, QUEUE_CAPACITY);
    freopen(CON, "r", stdin);

    User *user1,*user2;
    createUser(&user1);
    createUser(&user2);

    BirthDate date1 = {1980,2,23};
    BirthDate date2 = {2003,10,7};

    setUsersData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, date1);
    setUsersData(user2,  "Jane Austin", TEACHER, FEMALE, ENGINEERING, date2);

    enqueue(&userQueue, user1);
    enqueue(&userQueue, user2);

    printQueue(&userQueue, CON);


}
