#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct bstNode {
    int val;
    struct bstNode* left;
    struct bstNode* right;
} bstNode;

bstNode* newNode(int val){
    bstNode* Node = (bstNode*)malloc(sizeof(bstNode));
    Node->left = Node->right = NULL;
    Node->val = val;
    return Node;
}


// void insert(int val, bstNode** root){
//     if (*root == NULL){
//         (*root) = newNode(val);
//     }
//     else if (val <= (*root)->val) {
//         insert(val, &((*root)->left));
//     } else {
//         insert(val, &((*root)->right));
//     }
// }


void inorderTraversal(bstNode* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->val);
        inorderTraversal(root->right);
    }
}

bool search(bstNode* root, int val){
    if (!root) return false; 
    if (root->val == val) return true;
    else if (val <= root->val) return search(root->left, val);
    else return search(root->right, val);

    
}

bstNode* insert(bstNode* root, int val){
    bstNode* Node = newNode(val);
    if (root == NULL){
        return Node;
    }
    
    bstNode* current = root;
    bstNode* parent = NULL;

    while (current){
        parent = current;
        if (val < current->val){
            current= current->left;
        } else {
            current = current->right;
        }
    }

    if (val < parent->val){
        parent->left = Node;
    } else {
        parent->right = Node;
    }

    return root;

}

int main(){

    bstNode* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("Árvore em ordem: ");
    inorderTraversal(root);
    printf("\n");

    bool control = search(root, 45);

    printf("%d", control);
}
