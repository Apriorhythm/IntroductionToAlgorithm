/*
 * 数列A的值全部在0.01~0.99之间
 */
#include <iostream>

using namespace std;

struct BuketList
{
    float value;
    BuketList *next;
};

void BuketSort(float *A, int length)
{
    // 初始化
    BuketList *mainList = new BuketList[10];
    for (int i = 0; i < 10; i++)
    {
        mainList[i].value = 0;
        mainList[i].next = NULL;
    }

    // 装入桶中
    for (int i = 0; i < length; i++)
    {
        BuketList *newNode = new BuketList();
        newNode->value = A[i];
        // 注意不要写成 (int)A[i]*10
        newNode->next = mainList[(int)(A[i] * 10)].next;
        mainList[(int)(A[i] * 10)].next = newNode;
    }

    // 对桶中的数字进行排列,使用插入排序
    for (int i = 0; i < 10; i++)
    {
        BuketList *current = &mainList[i];
        while (current->next != NULL)
        {
            BuketList *traveler = current->next;
            if (traveler->value < current->value)
            {
                float temp = traveler->value;
                traveler->value = current->value;
                current->value = temp;
            }
            current = current->next;
        }
    }

    // 收集
    for (int i = 0, j = 0; i < 10; i++)
    {
        BuketList *traveler = mainList[i].next;
        while (traveler)
        {
            A[j++] = traveler->value;
            traveler = traveler->next;
        }
    }
    
}

int main()
{
    int length = 11;

    float *A = new float[length] {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.25, 0.21, 0.12, 0.23, 0.68};

    BuketSort(A, length);

    for (int i = 0; i < length; i++)
        cout << A[i] << " ";

    return 0;
}
