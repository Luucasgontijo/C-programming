#include <stdio.h>

void ex1(){
    int x = 10; 
    int *p = &x;
    int **q = &p;  // Pointer to pointer
    printf("x = %d\n", x);
    printf("p = %p\n", p);    // Print address stored in p
    printf("*p = %d\n", *p);  // Print value pointed to by p
    printf("q = %p\n", q);    // Print address stored in q
    printf("*q = %p\n", *q);  // Print value stored in q (which is the address of p)
    printf("**q = %d\n", **q); // Dereference q twice to get the value of x
}

void modifyValue(int **ptr){
    printf("original value = %d\n", **ptr);  // Dereference ptr twice to get the original value

    // Modify the value stored in the address that ptr points to
    **ptr = 3;   // Changing the value of y through pointer-to-pointer
    printf("new value = %d\n", **ptr);  // Print the new value
}

void ex3(){
    int x = 10;
    int *ptr1 = &x;
    int **ptr2 = &ptr1;
}
int test(){
    char C1[] = "hello";
    char* C2 = C1;
    printf("%c\n", C2[1]);
}



int main(){

    test();
}

