#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h> // For usleep function

// Function to swap two elements
void swap(void *a, void *b, size_t size) {
    char temp[size];
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
}

// Function to partition the array and return the pivot index
int partition(void *arr, int low, int high, size_t size, int (*cmp)(const void *, const void *)) {
    char *pivot = (char *)arr + high * size;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (cmp((char *)arr + j * size, pivot) <= 0) {
            i++;
            swap((char *)arr + i * size, (char *)arr + j * size, size);
        }
    }
    swap((char *)arr + (i + 1) * size, (char *)arr + high * size, size);
    return i + 1;
}

// Function to implement Quick Sort
void quickSort(void *arr, int low, int high, size_t size, int (*cmp)(const void *, const void *)) {
    if (low < high) {
        int pi = partition(arr, low, high, size, cmp);
        quickSort(arr, low, pi - 1, size, cmp);
        quickSort(arr, pi + 1, high, size, cmp);
    }
}

// Comparison function for integers
int int_cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Comparison function for characters (ASCII comparison)
int char_cmp(const void *a, const void *b) {
    return (*(char *)a - *(char *)b);
}

// Function to print an array of integers
void printIntArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to print an array of characters
void printCharArray(char arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%c ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    clock_t start, end;
    double cpu_time_used;

    printf("******************************************************QUICK SORTING****************************************************\n");
    printf("\nAuthor: HEMANTH P\n"); // Replace with your name
    printf("Date: July 17, 2024\n"); // Replace with current date or your preferred date
    printf("\n************************************************************************************************************************\n");

    printf("\nPlease Enter number of elements: ");
    scanf("%d", &n);

    int choice;
    printf("\nPlease Enter 1 to sort integers, 2 to sort characters: ");
    scanf("%d", &choice);

    if (choice == 1) {
        int intArr[n];
        printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &intArr[i]);
        }

        printf("\nOriginal integer array:\n");
        printIntArray(intArr, n);

        start = clock();
        quickSort(intArr, 0, n - 1, sizeof(int), int_cmp);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nSorting integer array...\n");
        usleep(2000000); // Delay for 2 seconds (2000000 microseconds)

        printf("\nSorted integer array:\n");
        printIntArray(intArr, n);
        printf("Time taken to sort the integer array: %f seconds\n", cpu_time_used);
    }
    else if (choice == 2) {
        char charArr[n];
        printf("Enter %d characters:\n", n);
        for (int i = 0; i < n; i++) {
            scanf(" %c", &charArr[i]);
        }

        printf("\nOriginal character array:\n");
        printCharArray(charArr, n);

        start = clock();
        quickSort(charArr, 0, n - 1, sizeof(char), char_cmp);
        end = clock();
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

        printf("\nSorting character array...\n");
        usleep(2000000); // Delay for 2 seconds (2000000 microseconds)

        printf("\nSorted character array:\n");
        printCharArray(charArr, n);
        printf("Time taken to sort the character array: %f seconds\n", cpu_time_used);
    }
    else {
        printf("Invalid choice.\n");
    }

    return 0;
}
