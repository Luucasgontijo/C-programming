#include "../utils.h"

typedef struct bstNode {
    int data;
    struct bstNode* left;
    struct bstNode* right;
} bstNode;

bstNode* createNode(int data){
    bstNode* newNode = (bstNode*)malloc(sizeof(bstNode));
    
    newNode->data = data;
    newNode->left = newNode->right  = NULL;
    
    return newNode;
}

void recursionInsert(bstNode** root, int data){
    if ((*root) == NULL){
        (*root) = createNode(data);
        return;
    }
    else if (data <= (*root)->data){
        recursionInsert(&(*root)->left, data);

    } else {
        recursionInsert(&(*root)->right, data);
    }
    return;
}


void inorderTraversal(bstNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}




int main(){
    bstNode* root = NULL;
    recursionInsert(&root, 50);
    recursionInsert(&root, 30);
    recursionInsert(&root, 70);
    recursionInsert(&root, 20);
    recursionInsert(&root, 40);
    recursionInsert(&root, 60);
    recursionInsert(&root, 80);

        
    inorderTraversal(root);


}