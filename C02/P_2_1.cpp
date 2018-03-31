#include <iostream>

using namespace std;

void InsertionSort(int A[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int key = A[i];
        int j = i;
        while (j > 0)
        {
            if (A[j] > key)
            {
                A[j + 1] = A[j];
            }
            j--;
        }
        A[j] = key;
    }
}


void Merge(int A[], int start, int mid, int end)
{
    int length1 = mid - start + 1;
    int length2 = end - mid + 1;
    int T1[length1];
    int T2[length2];

    for (int i = 0; i < length1; i++)
        T1[i] = A[start + i];
    for (int i = 0; i < length2; i++)
        T2[i] = A[mid + 1 + i];
    

    int i1 = 0, i2 = 0, index = start;
    while (i1 < length1 && i2 < length2)
    {
        if (T1[i1] < T2[i2])
            A[index++] = T1[i1++];
        else
            A[index++] = T2[i2++];
    }
 
    while (i1 < length1)
        A[index++] = T1[i1++];

    while (i2 < length2)
        A[index++] = T2[i2++];
}

void MergeSort(int A[], int start, int end)
{
    if (start >= end)
        return;

    int mid = (start + end) / 2;
    MergeSort(A, start, mid);
    MergeSort(A, mid + 1, end);
    Merge(A, start, mid, end);
}


int main()
{
    int length = 5;
    int A[length] = {12, 16, 15, 11, 14};
    MergeSort(A, 0, length - 1);

    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    

    return 0;
}



