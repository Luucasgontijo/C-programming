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
    int **ptr2 = &ptr1;ı
}

int main(){
    ex1();

    int y = 5;
    int *ptr = &y;
    int **ptr2 = &ptr;  // Pointer to pointer
    modifyValue(ptr2);  // Modify the value of y through pointer-to-pointer
    printf("y after modifyValue = %d\n", y);  // Print the modified value of y

    return 0;
}