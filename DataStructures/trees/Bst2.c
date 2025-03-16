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

#define MAX(a, b) ((a) > (b) ? (a) : (b))


int findHeight(bstNode* root){
    if (root == NULL){
        return -1;
    }
    return MAX(findHeight(root->left),findHeight(root->right) +1);

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

int minVal(bstNode** root){
    bstNode* curr = (*root);
    while (curr->left){
        curr = curr->left;
    }
    return curr->data;
}
int maxVal(bstNode** root){
    bstNode* curr = (*root);
    while (curr->right){
        curr = curr->right;
    }
    return curr->data;
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

    
    int val = findHeight(root);
    printf("%d", val);
    // inorderTraversal(root);
}