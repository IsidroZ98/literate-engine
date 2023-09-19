////////////////////////////////////////////////////
// Team #18 CSCI 2380 SPRING 2023 HOMEWORK #11
// Marcus Gutierrez
// 4/24/23
// Gustavo Dietrich
//////////////////////////////////////////////////// 

/* NEEDS COMMENTS */
#include "sort.h"
#include <iostream> 

void insertionsort(int *A,int left, int right)
 {
    int in, out;
    for (out = left + 1; out <= right; out++)
    {
        int temp = A[out]; 
        in = out;
        while (in > left && A[in - 1] >= temp) 
        {
            A[in] = A[in - 1]; 
            in--; 
        }
        A[in] = temp; 
    }
}
void swap(int *a1, int *a2)
{
    int temp2 = *a1;
    *a1 = *a2; 
    *a2 = temp2; 
}

int medianSelect(int *A, int lef,int rig) 
{
    int center = (lef+ rig) / 2;

    if (A[lef] > A[center]) 
      swap(&A[lef], &A[center]); 
    if (A[lef] > A[rig]) 
      swap(&A[lef], &A[rig]); 

    if (A[center] > A[rig]) 
      swap(&A[center],&A[rig]); 

    swap(&A[center], &A[rig - 1]); 
    return A[rig - 1]; 
}

int partition(int *A,int left, int right, long pivot) 
{
    int leftPtr = left; 
    int rightPtr = right - 1; 

    while (true) 
    {
        while (A[++leftPtr] < pivot); 
        while (A[--rightPtr] > pivot); 
        if (leftPtr >= rightPtr) 
            break; 
        else 
            swap(&A[leftPtr], &A[rightPtr]); 
    }
    swap(&A[leftPtr], &A[right - 1]); 
    return leftPtr; 
}
 
void quickSort(int* A, int left, int hig)
{
  int size = hig - left + 1; 
    if (size <= 10){ 
        insertionsort(A, left, hig); 
    }
    else 
    {
        int pivot = medianSelect(A, left, hig);
        int part = partition(A, left, hig, pivot); 
        quickSort(A, left, part - 1); 
        quickSort(A, part + 1, hig); 
    }
}
 

bool checkArraySort(int *A, int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        if (A[i] > A[i + 1]) {
            return false; 
        }
    }
    return true; 
}

void sort(int* A, int len){
  
  quickSort(A, 0, len - 1);
}

// End of code || 9:12AM // 