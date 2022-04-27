//
// Created by Kriszta Oniga on 4/27/2022.
//
#include "user_bst.h"
void testUserBSTFunctionalities(){
    UserTreeNode *userTreeNode = NULL;

    freopen(CON, "r", stdin);

    int choice;
    while (1) {
        printf("\n\n1. Create Operation\n");
        printf("2. Insert Operation\n");
        printf("3. Search Operation\n");
        printf("4. Exit\n");

        printf("Enter your choise of operation: ");
        scanf("%i", &choice);
        switch (choice) {
            case 1: {
                create(&userTreeNode);
                break;
            }
            case 2: {
                BirthDate date1 = {1980, 2, 23};
                User *user1;
                createUser(&user1);
                setUsersData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, date1);
                insert(&userTreeNode, user1);
                break;
            }
            case 3: {
                printf("User ID to find: ");
                int id;
                scanf("%i", &id);
                search(userTreeNode, id);
                exit(0);
            }
        }
    }
}

