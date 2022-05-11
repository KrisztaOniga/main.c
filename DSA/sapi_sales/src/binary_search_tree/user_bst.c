//
// Created by Kriszta Oniga on 4/27/2022.
//

#include "user_bst.h"
#include "messages.h"
#include "errors.h"
#include <string.h>

void create(UserTreeNode **userTreeNode) {
    (*userTreeNode) = (UserTreeNode *) malloc(sizeof(UserTreeNode));
    if (!(*userTreeNode)) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*userTreeNode)->left = NULL;
    (*userTreeNode)->right = NULL;
}

void insert(UserTreeNode **pUserTreeNode, User *newUser) {
    if ((*pUserTreeNode) == NULL) {
        create(pUserTreeNode);
        (*pUserTreeNode)->info = newUser;
        return;
    }

    if (strcmp((*pUserTreeNode)->info->name, newUser->name) == -1) {
        insert(&((*pUserTreeNode)->right), newUser);
    } else {
        insert(&((*pUserTreeNode)->left), newUser);
    }
}

bool search(UserTreeNode *userTreeNode, int ID) {
    if (userTreeNode == NULL)
        return false;
    else {
        if (ID < userTreeNode->info->id)
            search(userTreeNode->left, ID);
        else {
            if (ID > userTreeNode->info->id)
                search(userTreeNode->right, ID);
            else {
                return true;
            }
        }
    }
    return 0;
}

bool search2(UserTreeNode *userTreeNode, char *name) {
    if (userTreeNode == NULL)
        return false;
    else {
        if (strcmp(name, userTreeNode->info->name) == -1)
            search(userTreeNode->left, name);
        else {
            if (strcmp(name, userTreeNode->info->name) == 1)
                search(userTreeNode->right, name);
            else {
                return true;
            }
        }
    }
    return 0;
}

void inorderPrint(UserTreeNode *userTreeNode, char *destination) {
    freopen(destination, "w", stdout);

    if (userTreeNode->left != NULL) {
        inorderPrint(userTreeNode->left, destination);
    }

    printUser(userTreeNode->info, destination);

    if (userTreeNode->right != NULL) {
        inorderPrint(userTreeNode->right, destination);
    }
    freopen(CON, "w", stdout);
}

void preorderPrint(UserTreeNode *userTreeNode, char *destination) {
    freopen(destination, "w", stdout);

    printUser(userTreeNode->info, destination);

    if (userTreeNode->left != NULL) {
        inorderPrint(userTreeNode->left, destination);
    }
    if (userTreeNode->right != NULL) {
        inorderPrint(userTreeNode->right, destination);
    }
    freopen(CON, "w", stdout);
}

void postorderPrint(UserTreeNode *userTreeNode, char *destination) {
    freopen(destination, "w", stdout);
    if (userTreeNode->left != NULL) {
        inorderPrint(userTreeNode->left, destination);
    }
    if (userTreeNode->right != NULL) {
        inorderPrint(userTreeNode->right, destination);
    }
    printUser(userTreeNode->info, destination);
    freopen(CON, "w", stdout);
}

User *minimum(UserTreeNode *userTreeNode) {
    UserTreeNode *p = userTreeNode;
    while (p->left != NULL) {
        p = p->left;
    }
    return p->info;
}

User *maximum(UserTreeNode *userTreeNode) {
    UserTreeNode *p = userTreeNode;
    while (p->right != NULL) {
        p = p->right;
    }
    return p->info;
}

UserTreeNode *minimumNode(UserTreeNode *pNode) {
    UserTreeNode *helper = pNode;
    while (helper->left != NULL) {
        helper = helper->left;
    }
    return helper;
}

UserTreeNode *delete(UserTreeNode **userTreeNode, int ID) {

    // Return if the tree is empty
    if ((*userTreeNode) == NULL)
        return *userTreeNode;

    // Find the node to be deleted
    if (ID < (*userTreeNode)->info->id)
        (*userTreeNode)->left = delete(&(*userTreeNode)->left, ID);

    else if (ID > (*userTreeNode)->info->id)
        (*userTreeNode)->right = delete(&(*userTreeNode)->right, ID);
    else { // If the node is with only one child or no child
        if ((*userTreeNode)->left == NULL && (*userTreeNode)->right == NULL)
            return NULL;
        else if (!(*userTreeNode)->right) {
            UserTreeNode *temp = (*userTreeNode)->left;
            free((*userTreeNode));
            return temp;
        } else if (!(*userTreeNode)->left) {
            UserTreeNode *temp = (*userTreeNode)->right;
            free((*userTreeNode));
            return temp;
        }
        // If the node has two children,
        // place the inorder successor in position of the node to be deleted
        UserTreeNode *temp = minimumNode((*userTreeNode)->right);
        (*userTreeNode)->info->id = temp->info->id;
        (*userTreeNode)->right = delete(&(*userTreeNode)->right, (int) temp->info->id);
    }
    return (*userTreeNode);
}

UserTreeNode *delete2(UserTreeNode **userTreeNode, char name) {

    // Return if the tree is empty
    if ((*userTreeNode) == NULL)
        return (*userTreeNode);

    // Find the node to be deleted
    if (strcmp(name, (*userTreeNode)->info->name) == -1)
        (*userTreeNode)->left = delete(&(*userTreeNode)->left, name);

    else if (strcmp(name, (*userTreeNode)->info->name) == 1)
        (*userTreeNode)->right = delete(&(*userTreeNode)->right, name);

    else {
        // If the node is with only one child or no child
        if ((*userTreeNode)->left == NULL && (*userTreeNode)->right == NULL)
            return NULL;
        else if (!(*userTreeNode)->right) {
            UserTreeNode *temp = (*userTreeNode)->left;
            free((*userTreeNode));
            return temp;

        } else if (!(*userTreeNode)->left) {
            UserTreeNode *temp = (*userTreeNode)->right;
            free((*userTreeNode));
            return temp;
        }
        // If the node has two children,
        // replace the inorder successor in position of the node to be deleted
        UserTreeNode *temp = minimumNode((*userTreeNode)->right);
        (*userTreeNode)->info = temp->info;
        (*userTreeNode)->right = delete(&(*userTreeNode)->right, temp->info->name);
    }
    return (*userTreeNode);
}


void destroy(UserTreeNode **userTreeNode) {
    if ((*userTreeNode)) {
        destroy(&(*userTreeNode)->right);
        destroy(&(*userTreeNode)->left);
        free((*userTreeNode));
        (*userTreeNode) = NULL;
    }
}