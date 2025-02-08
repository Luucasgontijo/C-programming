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
    newNode->data = data; //the node that will be inserted receive his data var.
    newNode->link = NULL; //  the newNode.link receives NULL value. In this moment it is the TAIL, the last item of linked list.
    if (n == 1){
        newNode->link = *pointerToHead;     //if we re trying to insert an node at position 1 (head) it link will be link to the actual HEAD, so if there was an head with adress 200, and we change it to this newNode, the newNode.link will be the adress of the old head.
        *pointerToHead = newNode;   // the head will be now the newNode (in first iteration it is NULL, because there is no head at this moment)
        return; 
    }
    struct node* temp = *pointerToHead; //if we re trying to insert a new node, and the position we re aiming is not the very first one (1), we define an TEMP node, and make it equal to the actual head.

    for (int i= 0; i <n-2; i++){   //if we are trying to insert an node in the position 2, this for will not run
        temp = temp->link;          //if n is a position other than 1 or 2, the temp will be the head.link now, so, the second item
    }
    newNode->link= temp->link; // the newNode->link will be equal to the link of the head(head pointing to second), now newNode is pointing to the second as well
    temp->link =newNode; // the head link now will be the newNode adress

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
    insertAtNthPosition(&head, 4, 1);
    insertAtNthPosition(&head, 6, 2);
    insertAtNthPosition(&head, 7, 1);
    insertAtNthPosition(&head, 8, 2);
    printLinkedList(head);




}