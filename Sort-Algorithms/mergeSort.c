#include <stdio.h>


void printArray(int array[], int n){
    for (int i = 0; i< n; i++){
        printf("%d ", array[i]);
        printf(" ");
    }
    printf("\n");
}

void merge(int array[], int left, int middle, int right){
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int leftArray[n1], rightArray[n2];

    for (i = 0; i < n1; i++){
        leftArray[i] = array[left + i];
    }
    for (j = 0; j < n2; j++){
        rightArray[j] = array[middle + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2){
        if (leftArray[i] <= rightArray[j]){
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        array[k] = leftArray[i];
        i++;
        k++;
    }

    while (j < n2){
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right){ 
    //thats a recursive func
    //the base case is this conditional if:
    //if the left index is smaller than the right index, i can divide the array in two parts
    //thats the base case, because if the starting index (left) is greater than the ending index (right), it means that the array has only one element or none, and i dont need to divide it anymore, because it is alredy sorted

    if (left < right){
        int middle = left + (right - left) / 2;
        
        //the middle variable is calculated this way to prevent something called integer overflow, wich is when the sum of two integers is greater than the maximum value that can be stored in an integer variable. This results in the same as (left + rigth) / 2 but this way whe subtract right from the left first, and then divide by 2, wich gives me a smaller number, and then i add this number to the left index.

        mergeSort(array, left, middle);
        //Recursively Sort the First Half

        mergeSort(array, middle + 1, right);
        //Recursively Sort the First Half
        //at the very end it will fall outside this if condition, because it escaped the base case

        merge(array, left, middle, right);
    }

}


int main(){
    int array[] = {64, 25, 12, 22, 11};
    int n = sizeof(array) / sizeof(array[0]);
    
    printf("original array: \n");
    printArray  (array, n);

    mergeSort(array, 0, n-1);  
    //arguments explanation:
    //array[]: array to be sorted
    //0: left index, obviously starting from the first element of the array, wich is index 0
    //n-1: right index, wich is the last element of the array, wich is the size of the array - 1, because the index starts at 0

    printf("sorted array: \n");
    printArray  (array, n);
}