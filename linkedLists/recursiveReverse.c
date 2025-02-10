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

void reverse(struct node* temp){
    //thats a recursive function to reverse the linked list wich head has been given
    if (!temp->next){  //thats the base case, when the recursion reach the tail (last node), the temp->next will be NULL, since there is no other node after that, so, since we re trying to reverse the list, the tail will now be the head.
        head = temp;  
        return; //the tail is now the head, we ve reached the recursion end, now we return and the recursion call now will be of the previous node, wich stoped at the recursive call bellow
    }
    reverse(temp->next);  //where all the recursives calls stopped prior to the last one 
    struct node* q = temp->next; // in the first recursive callback, temp->next will be the adress of the tail, so we define q as it
    q->next = temp; //and now, q->next (the adress wich head will point, is equal to the adress of the current node)
    temp->next = NULL; //and the temp->next (adress wich current will point) to NULL, since we need one more step of the recursion to know the previous node adress.
    //when whe reach the last recursive call, it .next will be null, and this node will turn itself in the tail of the list
    
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
    reverse(head);
    printLinkedList(head);

} 