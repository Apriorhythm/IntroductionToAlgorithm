#include <iostream>

using namespace std;

/*
 * 矩阵乘法: C = A * B
 * order : 阶数
 */
void SquareMarixMultiply(int A[3][3], int B[3][3], int C[3][3], int order)
{
    for (int i = 0; i < order; i++)
        for (int j = 0; j < order; j++)
            for (int k = 0; k < order; k++)
                C[i][j] += A[i][k] * B[k][j];
}


void ShowMatrix(int M[3][3])
{
    int order = 3;
    for (int i = 0; i < order; i++)
    {
        for (int j = 0; j < order; j++)
            cout << M[i][j] << "\t";

        cout << endl;
    }


}

int main()
{
    int order = 3;
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 3, 3}
    };

    int C[3][3] = {0};

    SquareMarixMultiply(A, B, C, order);

    cout << "############# A #############" << endl;
    ShowMatrix(A);

    cout << "############# B #############" << endl;
    ShowMatrix(B);

    cout << "############# C #############" << endl;
    ShowMatrix(C);


    return 0;
}
