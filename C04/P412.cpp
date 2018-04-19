#include <iostream>

using namespace std;

int FindMaxSubarraySum(int *A, int length)
{
    int maxSum = 0;

    for (int i = 0; i < length; i++)
    {
        int tempSum = 0;
        for (int j = i; j >= 0; j--)
        {
            tempSum += A[j];
            maxSum = tempSum > maxSum ? tempSum : maxSum;
        }
    }

    return maxSum;
}

int main()
{
    int length = 10;
    int *A = new int[length] {-10, 25, 2, 3, 4, -5, -23, 3, 7, -21};
    int max = FindMaxSubarraySum(A, length);

    cout << "#####################" << endl;
    cout << "Max = " << max << endl;
    cout << "#####################" << endl;

    getchar();
    return 0;
}
