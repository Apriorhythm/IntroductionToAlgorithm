#include <iostream>

using namespace std;

// n个输入中，每个值均在[0, k]内
void CountingSort(int *A, int *B, int length, int k)
{
    // 已经对C进行初始化为0
    int *C = new int[k] ();
    
    // 对A[i]每个独立的元素进行计数
    for (int i = 0; i < length; i++)
        C[A[i]]++;

    // 统计第i个元素前面共有多少个元素
    for (int i = 1; i < k; i++)
        C[i] = C[i] + C[i - 1];

    // 排序
    // 注意减一，因为数组从0开始，和导论不同
    for (int i = length - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
}

int main()
{
    int length = 8;

    int *A = new int[length] {2, 5, 3, 0, 2, 3, 0, 3};
    int *B = new int[length] ();

    // 找最大值
    int k = A[0];
    for (int i = 0; i < length; i++)
        if (A[i] > k)
            k = A[i];

    // k+1是因为0~5共有k=6个元素
    CountingSort(A, B, length, k + 1);

    for (int i = 0; i < length; i++)
        cout << B[i] << " ";

    return 0;
}
