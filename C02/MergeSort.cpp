#include <iostream>

using namespace std;


void Merge(int A[], int start, int mid, int end)
{
	/* Calculate the length of elements */
	/*
	 * 注意：
	 *	length1包含mid元素
	 *  length2不包含mid元素
	 */
	int length1 = mid - start + 1;
	int length2 = end - mid;
	int *T1 = new int[length1];
	int *T2 = new int[length2];

	/* Copy all data to T1 and T2 */
	for (int i = 0; i < length1; i++)
		T1[i] = A[start + i];

	for (int i = 0; i < length2; i++)
		T2[i] = A[mid + i + 1];

	/* Merge to A */
	int i1 = 0, i2 = 0, index = start;
	while (i1 < length1 && i2 < length2)
	{
		if (T1[i1] < T2[i2])
			A[index++] = T1[i1++];
		else
			A[index++] = T2[i2++];
	}

	/* Add left elements to A */
	while (i1 < length1)
		A[index++] = T1[i1++];

	while (i2 < length2)
		A[index++] = T2[i2++];
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
	int *A = new int[length]{ 12, 16, 15, 11, 14 };

	MergeSort(A, 0, length - 1);

	for (int i = 0; i < length; i++)
		cout << A[i] << " ";

	cout << endl << "############################" << endl;
	cout << "End";
	cout << endl << "############################" << endl;

	getchar();
	return 0;
}
