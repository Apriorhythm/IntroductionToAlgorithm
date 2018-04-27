#include <iostream>

using namespace std;

void MaxHeapify(int A[], int root, int heapSize)
{
    int left, right, largest;
    left = root * 2;
    right = root * 2 + 1;
    largest = root;

    if (left <= heapSize && A[left] > A[largest])
        largest = left;

    if (left <= heapSize && A[right] > A[largest])
        largest = right;

    if (largest != root)
    {
        int temp = A[largest];
        A[largest] = A[root];
        A[root] = temp;

        MaxHeapify(A, largest, heapSize);
    }
}

void BuildMaxHeap(int A[], int heapSize)
{
    for (int i = heapSize / 2; i > 0; i--)
        MaxHeapify(A, i, heapSize);
}


int main()
{
    int length = 11;
    int A[11] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    /* 6.3-1
    int length = 10;
    int A[10] = {0, 5, 3, 17, 10, 84, 19, 6, 22, 9};
    */

    BuildMaxHeap(A, length - 1);

    for (int i = 1; i < length; i++)
        cout << "(" << i << ")" << A[i] << " ";

    cout << endl;
    return 0;
}
