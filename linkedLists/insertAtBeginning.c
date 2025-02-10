#include <stdlib.h>
#include <stdio.h>


struct node {
    int data;
    struct node* link;
};

void insertAtBeginning(struct node** pointerToHead, int data){          
    // here, i receive a POINTER TO POINTER, because i passed &head in main as this func argument. Since head is a pointer to a struct, &head is a pointer to the pointer that points to the struct, if i have received just header, i would had an VALUE, an copy of the pointer and when the func receives a value it receives an actual copy of it, not the real one. When the func receives an pointer, it receives the memory adress to the original one, that way, the changes that have been made inside the func will remain in main scope 
    //i could also have defined head globally, this way, i could change it from this scope
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->link = *pointerToHead;
    *pointerToHead = newNode;
}

void printLinkedList(struct node* head){
    struct node* temp = (struct node*)malloc(sizeof(struct node*));
    temp  = head;
    while (temp->link != NULL){
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL");
    return;
}

int main() {
    struct node* head = (struct node*)malloc(sizeof(struct node*));
    head->link = NULL;

    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 7);
    insertAtBeginning(&head, 1);
    printLinkedList(head);
    return 0;
}