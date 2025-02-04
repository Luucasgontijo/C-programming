#include <stdio.h>

void selectionSort(int array[], int n){

    for (int i = 0; i < n-1; i++){
        int minIndex = i;
        for (int j = i + 1; j < n; j++){
            if (array[j] < array[minIndex]){
                minIndex = j;
            }
            int temp = array[i];
            array[i] = array[minIndex];
            array[minIndex] = temp;
    }   
    }
    for (int i = 0; i < n; i++){
        printf("%d\n", array[i]);
    }
}

int main(){
    int array[] = {64, 25, 12, 22, 11};
    int n = sizeof(array) / sizeof(array[0]);
    selectionSort(array, n);
}

