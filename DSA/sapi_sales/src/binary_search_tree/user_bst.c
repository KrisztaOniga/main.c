//
// Created by Kriszta Oniga on 4/27/2022.
//
#include "user_bst.h"
#include "messages.h"
#include "errors.h"

void create(UserTreeNode** userTreeNode){
    (*userTreeNode) = (UserTreeNode *) malloc(sizeof(UserTreeNode));
    if (!(*userTreeNode)) {
        printErrorMessage(MEMORY_ALLOCATION);
    }
    (*userTreeNode)->left = NULL;
    (*userTreeNode)->right = NULL;
}
void insert(UserTreeNode** userTreeNode, User* info){
    if((*userTreeNode) == NULL){
        create(&(*userTreeNode));
        (*userTreeNode)->info = info;
    }
    else{
        if( (*userTreeNode)->info->id > info->id)
            insert(&(*userTreeNode)->left, info);
        else
            insert(&(*userTreeNode)->right, info);
    }
}

bool search(UserTreeNode* userTreeNode, int ID){
    if(userTreeNode == NULL)
        return false;
    else {
        if( ID < userTreeNode->info->id)
            search(userTreeNode->left, ID);
        else{
            if(ID > userTreeNode->info->id)
                search(userTreeNode->right, ID);
            else{
                return true;
            }
        }
    }
    return 0;
}

UserTreeNode* minValueNode(UserTreeNode* userTreeNode){
    UserTreeNode *temp = userTreeNode;
    while(temp && temp->left != NULL)
        temp = temp->left;
    return temp;

}
UserTreeNode* delete(UserTreeNode** userTreeNode, int ID) {
    if ((*userTreeNode) == NULL)
        return *userTreeNode;
    if (ID < (*userTreeNode)->info->id)
        (*userTreeNode)->left = delete(&(*userTreeNode)->left, ID);

    else if (ID > (*userTreeNode)->info->id)
        (*userTreeNode)->right = delete(&(*userTreeNode)->right, ID);
    else {
        if ((*userTreeNode)->left == NULL && (*userTreeNode)->right == NULL)
            return NULL;
        else if ((*userTreeNode)->right == NULL) {
            UserTreeNode *temp = (*userTreeNode)->right;
            free((*userTreeNode));
            return temp;
        } else if ((*userTreeNode)->left == NULL) {
            UserTreeNode *temp = (*userTreeNode)->left;
            free((*userTreeNode));
            return temp;
        }
    UserTreeNode *temp = minValueNode((*userTreeNode)->right);
    (*userTreeNode)->info = temp->info;
    (*userTreeNode)->right = delete( &(*userTreeNode)->right, (int)temp->info->id);
    }
    return *userTreeNode;
}
void destroy(UserTreeNode** userTreeNode){
    if((*userTreeNode) == NULL)
        return;
    destroy(&(*userTreeNode)->right);
    destroy(&(*userTreeNode)->left);
    destroy(&(*userTreeNode));
}