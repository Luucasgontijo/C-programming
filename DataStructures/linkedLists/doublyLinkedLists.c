#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

struct node* head = NULL;

struct node* getNode(int x){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void insertAtHead(int x){
    struct node* newNode = getNode(x);
    if (!head){
        head = newNode;
        return;
    } 
    (*head).prev = newNode;
    (*newNode).next= head;
    head = newNode;
}



void printLinkedList(struct node* head){
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp  = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL");
    return;
}



int main(){
    insertAtHead(4);
    insertAtHead(3);
    insertAtHead(2);

    printLinkedList(head);
}