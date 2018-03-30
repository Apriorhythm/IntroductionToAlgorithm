/* Ascendant */

#include <iostream>

using namespace std;


void SelectionSort(int A[], int length)
{
    for (int i = 0; i < length; i++)
    {
        int mini = i;
        for (int j = i + 1; j < length; j++)
        {
            if (A[j] < A[mini])
            {
                mini = j;
            }
        }
        int temp = A[i];
        A[i] = A[mini];
        A[mini] = temp;
    }
}


int main()
{
    int A[5] = {13, 12, 16, 11, 17};
    SelectionSort(A, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << A[i] << " " << endl;
    }

    return 0;
}
