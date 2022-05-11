//
// Created by Kriszta Oniga on 4/27/2022.
//
#include "user_bst.h"
#include <stdlib.h>
#include <stdio.h>

void testUserBSTFunctionalities(){
    UserTreeNode *root = NULL;

    freopen(CON, "r", stdin);

    int choice;
    while (1) {
        printf("\n 1. Insert Operation\n");
        printf("2. Search Operation\n");
        printf("3. InorderPrint Operation\n");
        printf("4. PreorderPrint Operation\n");
        printf("5. PostorderPrint Operation\n");
        printf("6. Minimum Operation\n");
        printf("7. Maximum Operation\n");
        printf("8. Delete Operation\n");
        printf("9. Destroy Operation\n");

        printf("Enter your choise of operation: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                BirthDate date1 = {1980, 2, 23};
                User *user1;
                createUser(&user1);
                setUsersData(user1, "John Peterson", STUDENT, MALE, COMPUTER_SCIENCE, date1);
                insert(&root, user1);
                BirthDate date2 = {2003,10,7};

                User *user2;
                createUser(&user2);
                setUsersData(user2,  "Jane Austin", TEACHER, FEMALE, ENGINEERING, date2);
                insert(&root, user2);
                break;
            }
            case 2: {
                printf("Search by name: \n");
                char name[20];
                scanf("\n%[^\n]", name);
                if(search2(root, name)){
                    printf("The %s can be found in the tree\n", name);
                }
                else {
                    printf("The %s can't be found in the tree\n", name);
                }

                printf("Search by ID: \n");
                printf("User ID to find: ");
                int id;
                scanf("%d", &id);
                if(search(root, id)){
                    printf("The %i id can be found in the tree\n", id);
                }
                else {
                    printf("The %i id can't be found in the tree\n", id);
                }
                break;
            }
            case 3: {
                printf("Inorder:\n");
                inorderPrint(root, CON);
                break;
            }
            case 4: {
                printf("Preorder:\n");
                preorderPrint(root, CON);
                break;
            }
            case 5: {
                printf("Postorder:\n");
                postorderPrint(root, CON);
                break;
            }
            case 6: {
                printf("Minimum:\n");
                User *minUser;
                createUser(&minUser);
                minUser = minimum(root);
                printUser(minUser, CON);
                break;
            }
            case 7: {
                printf("Maximum:\n");
                User *maxUser;
                createUser(&maxUser);
                maxUser = maximum(root);
                printUser(maxUser, CON);
                break;
            }
            case 8: {
                printf("Delete by ID: ");
                printf("User ID to delete: ");
                int id;
                scanf("%d", &id);
                delete(&root, id);

//                printf("Delete by name:");
//                char name[20];
//                scanf("\n%[^\n]", name);
//                root = delete2(&root, name);
                break;
            }
            case 9: {
                destroy(&root);
                return;}
            default:{
                printf("Incorrect choice \n");
                break;
            }

        }
    }
}

