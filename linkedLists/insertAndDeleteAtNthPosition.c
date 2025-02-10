#include <stdio.h>
#include <stdlib.h>

//this will insert an node at the end of the list, and delete it at Nth position

struct node {
    int data;
    struct node* next;
};

struct node* head; //global var

void insert(int data){ 
    //i didn't pass head as argument because it is a global var in this file)
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL){
        head = newNode;
        return;
    }
    struct node* temp = head;    
    while (temp->next != NULL){
        temp = temp->next ;
    }
    temp->next = newNode;
}

void printLinkedList(struct node* head){
    struct node* temp = head;    
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

void deleteNode(int n){
    struct node* temp = head;    
    if (n==1){
        head = temp->next;
        free(temp);
        return; //or else statement
    }
    for (int i = 1; i < n-1; i++){
        temp = temp->next;
    }
    struct node* temp2 = temp->next;    
    temp->next = temp2->next;
    free(temp2);
    printf("the %dº node was sucessfully been deleted\n", n);
}

int main(){
    head = NULL;
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    printLinkedList(head);
    int n;
    printf("enter a position\n");
    scanf("%d", &n);
    deleteNode(n);
    printLinkedList(head);

} 