//
// Created by Kriszta Oniga on 4/27/2022.
//

#ifndef MAIN_C_USER_BST_H
#define MAIN_C_USER_BST_H

#include "user.h"
typedef struct UserTreeNode
{ User* info;
    struct UserTreeNode *left, *right;
} UserTreeNode;

void create(UserTreeNode**);
void insert(UserTreeNode**, User*);
bool search(UserTreeNode*, int);
void inorderPrint(UserTreeNode*, char*);
void preorderPrint(UserTreeNode*, char*);
void postorderPrint(UserTreeNode*, char*);
User* minimum(UserTreeNode*);
User* maximum(UserTreeNode*);
UserTreeNode* delete(UserTreeNode**, int);
void destroy(UserTreeNode**);

#endif //MAIN_C_USER_BST_H
