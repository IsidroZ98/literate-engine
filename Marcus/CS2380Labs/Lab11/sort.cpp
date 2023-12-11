// Team #20 CSCI 2380 FALL 2023 HOMEWORK #11
// Edgar Hernandez
// Marcus Gutierrez
// 11/28/23
// Gustavo Dietrich 
////////////////////////////////////////////////////////////////
#include "sort.h"

// insertion sort implemented, 2 indices sorts left to right
void insertionsort(int *A, int left, int right) {
    int in, out;
  // left + 1 means it starts at second then goes through all the way to the right
    for (out = left + 1; out <= right; out++) {
        int temp = A[out];
        in = out;
        // 
        while (in > left && A[in - 1] >= temp) // takes into account elements in left, if greater then temp moves to right
          {
            A[in] = A[in - 1];
            in--;
        }
        A[in] = temp;
    }
}

// swap function implemented, takes 2 elements 
void swap(int *a1, int *a2) {
    int temp2 = *a1;
    *a1 = *a2;
    *a2 = temp2;
}

// middle select function implemented
int medianSelect(int *A, int left, int right) {
    int center = (left + right) / 2;
  // middle finder, dietrich talked about this with the phone book method cutting down in the middle and going from there instead of starting from one end or another
    if (A[left] > A[center])
        swap(&A[left], &A[center]);
// swap function if left is greater then center to make ensure left is less then
    if (A[left] > A[right])
        swap(&A[left], &A[right]);
// similar swap function but for right
    if (A[center] > A[right])
        swap(&A[center], &A[right]);
  // swap function but with center to make sure less then right
    swap(&A[center], &A[right - 1]);
    return A[right - 1];
}

// partition function implemented
int partition(int *A, int left, int right, long pivot) {
    int leftPtr = left;
    int rightPtr = right - 1; 
// establish our ptrs
    while (true) {
        while (A[++leftPtr] < pivot);
        while (A[--rightPtr] > pivot);
        if (leftPtr >= rightPtr)
            break;
      else // while loop that doesnt end until the left and right ptrs cross paths 
            swap(&A[leftPtr], &A[rightPtr]);
      // swap function that gets them into the postition 
    }
    swap(&A[leftPtr], &A[right - 1]);
    return leftPtr;
  // move pivot to its final set position, return for location post partitioning update
}

// quicksort function implemented
void quickSort(int* A, int left, int right) {
    int size = right - left + 1;
    // get our size of the array that is going to be quicksorted
    if (size <= 10) {
        insertionsort(A, left, right); // if less then 10 switch to insertionsort method (efficiency is key!) 
    } else {
        // recall our medianselect function to choose pivot
        int pivot = medianSelect(A, left, right);
        // partition array, use recursion to sort both sides
        int partitionIndex = partition(A, left, right, pivot);
        quickSort(A, left, partitionIndex - 1);
        quickSort(A, partitionIndex + 1, right);
    }
}

// true false to ensure the array is actually sorted
bool checkArraySort(int *A, int len) {
    for (int i = 0; i < len - 1; i++) {
        if (A[i] > A[i + 1]) {
            return false;
        }
    }
    return true;
}

// end with our quicksort function
void sort(int* A, int len) {
    quickSort(A, 0, len - 1);
}

/*
binary trees
pointer = data member, where we point the nodes
root node is the first node at the top of the binary tree
we then have a descending tree of root nodes going in different directions
sometimes the nodes have 1, 2 or no nodes hanging from another
when there are no nodes under the node ends 

notes from 11/28 class


*/