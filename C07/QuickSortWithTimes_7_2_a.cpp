#include <iostream>

using namespace std;

int count = 0;

int Partion(int A[], int p, int r)
{
   int i = p;

   for (int j = p; j < r; j++)
   {
        if (A[j] < A[r])
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
            i++;
        }
   }
   int temp = A[i];
   A[i] = A[r];
   A[r] = temp;

   return i;
}

void QuickSort(int A[], int p, int r)
{
    if (p < r)
    {
        count++;
        int q = Partion(A, p, r);
        QuickSort(A, p, q - 1);
        QuickSort(A, q + 1, r);
    }
}

int main()
{

//  int A[5] = {13, 19, 9, 5, 12};
    int A[20] = {13, 13, 13, 13, 13,13, 13, 13, 13, 13,13, 13, 13, 13, 13,13, 13, 13, 13, 13};


    QuickSort(A, 0, 19);

    for (int i = 0; i < 20; i++)
        cout << "(" << i << ")" << A[i] << " ";

    cout << endl << "Times: " << count << endl;

    return 0;
}
