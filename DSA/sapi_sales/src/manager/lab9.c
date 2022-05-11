//
// Created by Kriszta Oniga on 4/15/2022.
//
#include "user_list.h"
void testUserListFunctionalities(){
    UserNode *head = NULL;

    freopen(CON, "r", stdin);

    int choice;
    while (1){
        printf("\n\n1. InsertFirst Operation\n");
        printf("2. InsertLat Operation\n");
        printf("3. FindElement Operation\n");
        printf("4. Print Operation\n");
        printf("5. RemoveFirst Operation\n");
        printf("6. RemoveLast Operation\n");
        printf("7. Exit\n");

        printf("Enter your choise of operation: ");
        scanf("%i", &choice);
        switch(choice){
            case 1: {
                printf("Insert first\n");
                BirthDate date1 = {1980,2,23};
                User *user1;
                createUser(&user1);
                setUsersData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, date1);
                insertFirst(&head, user1);
                break;
            }
            case 2: {
                printf("Insert last\n");
                BirthDate date2 = {2003,10,7};
                User *user2;
                createUser(&user2);
                setUsersData(user2,  "Jane Austin", TEACHER, FEMALE, ENGINEERING, date2);
                insertLast(head, user2);
                break;
            }
            case 3: {
                printf("User ID to find: ");
                int id;
                scanf("%i",&id);
                printf("Found at position: %i\n", findElementInList2(head,id));
                break;
            }
            case 4: {
                printUserList(head,"CON");
                break;
            }
            case 5: {
                printf("Remove first\n");
                int id = removeFirst2(&head);
                printf("User with id %i is succesfully deleted\n", id);
                break;
            }
            case 6: {
                printf("Remove last\n");
                int id = removeLast2(&head);
                printf("User with id %i is succesfully deleted\n", id);
                break;
            }
            case 7: {
                printf("Exit\n");
                deleteUserList(&head);
                exit(0);
            }
            default:{
                printf("Incorrect choice \n");
                break;
            }
        }
    }

}