/*
 * Hoare和算法导论第一个介绍的Partition区别
 * Hoare: A[p ... j]   <=         A[j+1 ... r]
 * 导论 : A[p ... j-1] <= A[j] <= A[j+1 ... r]
 * 也就是说，轴心元素是否在其最终位置
*/

#include <iostream>

using namespace std;

int Partion(int A[], int p, int r)
{
    int povit = A[p];
    int i = p - 1;
    int j = r + 1;

    while (true)
    {
        do
            i++;
        while (A[i] < povit);

        do
            j--;
        while (A[j] > povit);

        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        else
        {
            return j;
        }
    }
}

void QuickSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = Partion(A, p, r);
        // 注意：q元素也是要加入排序的
        QuickSort(A, p, q);
        QuickSort(A, q + 1, r);
    }
}

int main()
{

    int A[12] = {13, 19, 9, 5, 12, 8, 7, 5, 11, 2, 6, 21};

    QuickSort(A, 0, 11);

    for (int i = 0; i < 12; i++)
        cout << "(" << i << ")" << A[i] << " ";


    return 0;
}
