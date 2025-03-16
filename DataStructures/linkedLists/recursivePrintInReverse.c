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

void printLinkedList(struct node* head){ //the way it is, i print the data of the node, and make a recursive call to print the data of the next node
    struct node* temp = head;    
    if (!head) return; //thats called implicit comparasion
    printf("%d ", temp->data);
    printLinkedList(temp->next);
    return;
}
void reversePrint(struct node* head){ //now, i make the recursive call before printing it, so the prints will start when head = NULL, (on tail)
    if (!head) return;
    reversePrint(head->next);
    printf("%d ", head->data);
}



int main(){
    head = NULL;
    insert(2);
    insert(3);
    insert(4);
    insert(5);
    insert(6);
    printLinkedList(head);
    printf("\n");
    // reverse();
    reversePrint(head);

} 