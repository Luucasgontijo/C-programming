#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int array[], int n){
    bool changeSensor = false;
    for (int j = 0; j < n-1 ; j++){
        if(changeSensor == true){
            break;
        }
        for (int i = 0; i < n-1-j; i++){
            if (array[i] > array[i+1]){
                int temp = array[i+1];
                array[i+1] = array[i];
                array[i] = temp;
                changeSensor = true;
            }
    }
    }
}

void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}


int main(){
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array) / sizeof(array[0]);

    printf("original array: ");
    printArray(array, n);

    bubbleSort(array, n);

    printf("sorted array: ");
    printArray(array, n);
}