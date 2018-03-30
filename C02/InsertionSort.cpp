#include <iostream>

using namespace std;


void InsertionSort(int A[], int length)
{
    int key = 0;
    for (int i = 1; i < length; i++)
    {
        key = A[i];
        int j = i - 1;
        while (j >= 0)
        {
            if (A[j] > key)
                A[j + 1] = A[j];
            else
                break;
            j--;
        }
        A[j + 1] = key;
    }
}


int main()
{
    int A[5] = {25, 6, 3, 22, 50};
    InsertionSort(A, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " " << endl;
    }

    return 0;
}
