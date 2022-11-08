#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);

int main() {
    int size = 7;
    int arr[] = {8, 7, 6, 1, 0, 9, 2};
    quickSort(arr, 0, size);

    int step;
    for (step = 0; step < size; step++) {
        printf("%d, ", arr[step]);
    }

    printf("\n");
}

void swap(int *a, int *b) { // input the address of the elements in the function
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int i, j;

    i = low - 1;
    int pivot = arr[high];
    for (j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;

            swap(&arr[i], &arr[j]);
            //swapping two elements
        } 
    }

    // swap the pivot element with the greater element at i
    swap(&arr[i + 1], &arr[high]);
  
    // return the partition point
    return (i + 1);
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // find the pivot element such that
        // elements smaller than pivot are on left of pivot
        // elements greater than pivot are on right of pivot
        int pi = partition(arr, low, high);
        
        // recursive call on the left of pivot
        quickSort(arr, low, pi - 1);
        
        // recursive call on the right of pivot
        quickSort(arr, pi + 1, high);
  }
}
