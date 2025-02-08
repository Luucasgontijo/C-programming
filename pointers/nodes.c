#include <stdlib.h>
#include <stdio.h>


struct node{
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
void insertAtNthPosition(struct node** pointerToHead, int data, int n){
    struct node* newNode = (struct node*)malloc(sizeof(struct node*));
    newNode->data = data;
    newNode->link = NULL;
    if (n == 1){
        newNode->link = *pointerToHead;
        *pointerToHead = newNode;
        return;
    }
    struct node* temp2 = *pointerToHead;

    for (int i= 0; i <n-2; i++){
        temp2 = temp2->link;
    }
    newNode->link= temp2->link;
    temp2->link =newNode;

}


void printLinkedList(struct node* head){
    struct node* temp = head;
    while (temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->link;
    }
    printf("NULL\n");
}


int main(){
    struct node* head = NULL;
    insertAtBeginning(&head, 5); //I PASS THE HEAD'S MEMORY ADRESS AS ARGUMENT, BECAUSE HEAD IS A LOCAL VARIABLE TO MAIN ˆˆˆ
    insertAtBeginning(&head, 4);
    insertAtBeginning(&head, 3);

    printLinkedList(head);
    printf("\n");

    head = NULL;
    insertAtNthPosition(&head, 2, 1);
    insertAtNthPosition(&head, 3, 2);
    insertAtNthPosition(&head, 4, 1);
    insertAtNthPosition(&head, 5, 2);
    printLinkedList(head);




}