#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define N 10

// Swap function to swap two elements
void swap(int A[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

bool bbsrt(int A[N])
{
    bool swapped = true;
    while (swapped) {
        swapped = false;
        for (int i = 0; i < N - 1; i++) {
            // Compare adjacent elements and swap if in incorrect order (descending order)
            if (A[i] < A[i + 1]) {
                swap(A, i, i + 1);
                swapped = true;
            }
        }
    }

    // Print the sorted array
    for (int i = 0; i < N; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    return true;  // Return true after sorting
}

int main()
{
    int A[N];
    srand(time(NULL));

    // Initialize the array with random values between 1 and 100
    for (int i = 0; i < N; i++) {
        A[i] = 1 + rand() % 100;
    }

    // Call the sorting function
    bbsrt(A);

    return 0;
}
