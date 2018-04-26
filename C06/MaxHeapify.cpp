#include <iostream>

using namespace std;



void MaxHeapify(int A[], int root, int heapSize)
{
    int left, right, largest;
    left = root * 2;
    right = root * 2 + 1;
    largest = root;

    if (left < heapSize && A[left] > A[largest])
        largest = left;

    if (left < heapSize && A[right] > A[largest])
        largest = right;

    if (largest != root)
    {
        int temp = A[largest];
        A[largest] = A[root];
        A[root] = temp;

        MaxHeapify(A, largest, heapSize);
    }
}

int main()
{
    int A[14] = {27, 17, 3, 16, 13, 10, 1, 5, 7, 12, 4, 8, 9, 0};
    // 书本是MaxHeapify(A, 3)，3 - 1是因为树的序号从1开始，数组从0开始
    MaxHeapify(A, 3 - 1, 14);

    for (int i = 0; i < 14; i++)
        cout << "(" << i + 1 << ")" << A[i] << " ";

    cout << endl;
    return 0;
}
