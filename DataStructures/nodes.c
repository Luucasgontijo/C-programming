#include <stdlib.h>
#include <stdio.h>


struct node{
    int data;
    struct node* link;
};

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
   
    insertAtNthPosition(&head, 4, 1);
    insertAtNthPosition(&head, 6, 2);
    insertAtNthPosition(&head, 7, 1);
    insertAtNthPosition(&head, 8, 2);
    printLinkedList(head);

}