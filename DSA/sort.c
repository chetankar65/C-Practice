#include <stdio.h>
#include <stdlib.h>

void shellSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);

int main() {
    int data[] = {9, 8, 3, 7, 5, 6, 4, 1};
    int size = sizeof(data) / sizeof(data[0]);
    //shellSort(data, size);

    //selectionSort(data, size);

    insertionSort(data, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }

    printf("\n");
}

//effective version of insertion sort
void shellSort(int arr[], int n) {
    // rearrange elements according to intervals n, n/2, n/4
    for (int interval = n/2; interval > 0 ; interval /= 2) {
        for (int i = interval; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }

            arr[j] = temp;
        }
    }
}

// selection minimum element and replacing current element
void selectionSort(int arr[], int n) {
    int i, j, indexMin;

    for (i = 0; i < n-1; i++) {
        indexMin = i;

        for (j = i+1; j < n; j++) {
            if (arr[indexMin] > arr[j]) {
                indexMin = j;
            }
        }

        // swapping the elements
        int temp = arr[i];
        arr[i] = arr[indexMin];
        arr[indexMin] = temp;
    }
}

// left half sorted, right half not sorted
void insertionSort(int arr[], int n) {
    int i, j;
    for (i = 1; i < n; i++) {
        int temp = arr[i];

        j = i - 1;

        while (j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }

        arr[j+1] = temp;
    }
}
