#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* head; 

void insert(int data){ 

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

void reverse(){
    struct node *current, *prev, *next;
    current = head;
    prev = NULL;

    while (current){ // not equal to NULL or 0 
        next = current->next; //navigate to the tail node 
        current->next = prev;

        prev = current;
        current = next;
    }
    head = prev;


}

int main(){
    head = NULL;
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    printLinkedList(head);
    reverse();
    printLinkedList(head);

} 