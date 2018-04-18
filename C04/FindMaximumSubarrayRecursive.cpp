#include <iostream>

using namespace std;

// 寻找跨越中间元素的最大子串
int FindMaxCrossSubarray(int *A, int low, int mid, int high)
{
    if (A[mid] < 0)
    {
        return 0;
    }
    else
    {
        int tempSum = 0;
        int leftSum = 0;
        for (int i = mid; i >= low; i--)
        {
            leftSum += A[i];
            leftSum = leftSum > tempSum ? leftSum : tempSum;
        }

        tempSum = 0;
        int rightSum = 0;
        for (int i = mid + 1; i <high; i++)
        {
            rightSum += A[i];
            rightSum = rightSum > tempSum ? rightSum : tempSum;
        }

        return (leftSum + rightSum);
    }
}

// 仅返回最大子串的和，没有序号
int FindMaximumSubarray(int *A, int low, int high)
{
    if (low == high)
    {
        return A[low];
    }
    else
    {
        int mid = (low + high) / 2;
        int leftMax = FindMaximumSubarray(A, low, mid);
        int rightMax = FindMaximumSubarray(A, mid + 1, high);
        int crossMax = FindMaxCrossSubarray(A, low, mid, high);

        if (rightMax >= leftMax && rightMax >= crossMax)
            return rightMax;
        else if (leftMax >= rightMax && leftMax >= crossMax)
            return leftMax;
        else
            return crossMax;
    }


}


int main()
{
    int length = 10;
    int *A = new int[length] {-10, 25, 2, 3, 4, -5, -23, 3, 7, -21};
    int max = FindMaximumSubarray(A, 0, length - 1);

    cout << "#####################" << endl;
    cout << "Max = " << max << endl;
    cout << "#####################" << endl;

    getchar();
    return 0;
}
