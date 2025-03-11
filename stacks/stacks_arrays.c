#include <stdio.h>
#define MAX_SIZE 101
int A[MAX_SIZE];

int top = -1; 



void push(int x){
    if (top == MAX_SIZE - 1){
        perror("ERROR: stack overflow\n");
        return;
    }
    A[++top] = x;
}

void pop(){
    if (top == MAX_SIZE - 1){
        perror("ERROR: No element to pop\n");
        return;
    }
    top = top-1;
}

int peek(){
    return A[top];
}
void print(){
    for (int i = 0; i <=top; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}



int main(){
    push(2);
    push(3);
    push(4);
    print();
}