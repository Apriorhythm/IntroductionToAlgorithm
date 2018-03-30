#include <iostream>

using namespace std;


void Merge(int A[], int start, int mid, int end)
{
    /* Calculate the length of elements */
    int length1 = mid - start + 1;
    int length2 = end - mid + 1;
    int T1[length1];
    int T2[length2];

    /* Copy all data to T1 and T2 */
    for (int i = 0; i < length1; i++)
        T1[i] = A[start + i];

    for (int i = 0; i < length2; i++)
        T2[i] = A[mid + i + 1];

    /* Merge to A */
    int index = start;
    int i1 = 0;
    int i2 = 0;
    while (i1 < length1 && i2 < length2)
    {
        if (T1[i1] < T2[i2])
        {
            A[index] = T1[i1];
            i1++;
        }
        else
        {
            A[index] = T2[i2];
            i2++;
        }

        index++;
    }

    /* Add left elements to A */
    if (i1 < length1)
    {
        while (i1 < length1)
        {
            A[index] = T1[i1];
            index++;
            i1++;
        }
    }
    
    if (i2 < length2)
    {
        while (i2 < length2)
        {
            A[index] = T2[i2];
            index++;
            i2++;
        }
    }
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
    cout << endl << "############################" << endl;
    cout << "Start";
    cout << endl << "############################" << endl;

    int length = 5;
    int A[length] = {13, 12, 16, 11, 17};

    MergeSort(A, 0, length - 1);

    for (int i = 0; i < length; i++)
        cout << A[i] << " ";

    cout << endl << "############################" << endl;
    cout << "End";
    cout << endl << "############################" << endl;

    return 0;
}
