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

void HeapSort(int A[], int heapSize)
{
    for (int i = heapSize - 1; i > 0; i--)
    {
        cout << A[1] << " ";
        A[1] = A[i];
        // i为数组A的长度，已经排除了A[i]元素，
        // 因为BuildMaxHeap调用使用的是数组长度减一
        BuildMaxHeap(A, i);
    }
}

int main()
{
    int length = 11;
    int A[11] = {0, 4, 1, 3, 2, 16, 9, 10, 14, 8, 7};

    BuildMaxHeap(A, length - 1);

    cout << "Original Heap:" << endl;
    for (int i = 1; i < length; i++)
        cout << "(" << i << ")" << A[i] << " ";
    cout << endl;
    cout << "Sorted:" << endl;
    HeapSort(A, length);

    cout << endl;
    return 0;
}
