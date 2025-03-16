#include <stdio.h>

void insertionSort(int array[], int n){
    for (int i = 1; i < n; i++){
        int currentNum = array[i];
        int j = i-1;
        
        while (j >= 0 && array[j] > currentNum){  //if the left item index is greater or equal to 0 and my currentNum is smaller than the one i am comparing, i walk to the left of the array
            array[j + 1] = array[j];
            j--;
        }
        array[j+1] = currentNum;
    }
}


void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(){
    int array[] = {11, 64, 22, 2, 66};
    int n = sizeof(array) / sizeof(array[0]);
    insertionSort(array, n);
    printArray(array, n);
}

