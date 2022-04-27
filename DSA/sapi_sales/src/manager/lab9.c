//
// Created by Kriszta Oniga on 4/15/2022.
//
#include "user_list.h"
void testUserListFunctionalities(){
    UserNode *userNode;

    freopen(CON, "r", stdin);

    int choice;
    while (1){
        printf("\n\n1. Create Operation\n");
        printf("2. InsertFirst Operation\n");
        printf("3. InsertLat Operation\n");
        printf("4. FindElement Operation\n");
        printf("5. RemoveFirst Operation\n");
        printf("6. RemoveLast Operation\n");
        printf("7. Print Operation\n");
        printf("8. Delete Operation\n");
        printf("9. Exit\n");

        printf("Enter your choise of operation: ");
        scanf("%i", &choice);
        switch(choice){
            case 1: {

                BirthDate date1 = {1980,2,23};
                User *user1;
                createUser(&user1);
                setUsersData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, date1);

                createUserNode(&userNode, user1);
                break;
            }
            case 2: {
                BirthDate date1 = {1980,2,23};
                User *user1;
                createUser(&user1);
                setUsersData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, date1);
                insertFirst(&userNode, user1);
                break;
            }
            case 3: {
                BirthDate date2 = {2003,10,7};
                User *user2;
                createUser(&user2);
                setUsersData(user2,  "Jane Austin", TEACHER, FEMALE, ENGINEERING, date2);
                insertLast(userNode, user2);
                break;
            }
            case 4: {
                printf("User ID to find: ");
                int id;
                scanf("%i",&id);
                printf("Found at position: %i\n", findElementInList(userNode,id));
                break;
            }
            case 5: {
                removeFirst(&userNode);
                break;
            }
            case 6: {
                removeLast(userNode);
                break;
            }
            case 7: {
                printUserList(userNode,"CON");
                break;
            }
            case 8: {
                deleteUserList(&userNode);
                exit(0);
            }
            default:{
                printf("Incorrect choice \n");
                break;
            }
        }
    }

}