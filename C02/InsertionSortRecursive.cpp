#include <iostream>

using namespace std;

/*
* end = TheLengthOfArray(A) - 1
*/
void InsertionSortRecursive(int A[], int end)
{
	if (end == 0)
		return;

	InsertionSortRecursive(A, end - 1);

	int key = A[end];
	int i = end - 1;
	while (i >= 0 && A[i] > key)
	{
		A[i + 1] = A[i];
		i--;
	}

	i += 1;
	A[i] = key;
}


int main()
{
	//int A[5] = {12, 15, 11, 16, 17};
	int A[10] = { 12, 15, 66, 7, 15, 18, 100, 11, 16, 17 };
	InsertionSortRecursive(A, 9);

	for (int i = 0; i < 10; i++)
	{
		cout << A[i] << " " << endl;
	}

	getchar();

	return 0;
}

