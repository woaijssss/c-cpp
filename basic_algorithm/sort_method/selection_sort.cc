
#include <stdio.h>
#include <iostream>
using namespace std;

void PrintArray(int* a, const int& len)
{
        for (int i = 0; i < len; i++) {
                printf("%d ", a[i]);
        }
        printf("\n");
}

void SelectionSort(int* a, const int& len)
{
        int min_index, temp;
        for (int i = 0; i < len-1; i++) {
                min_index = i;
                for (int j = i+1; j < len; j++) {
                        if (a[j] < a[min_index]) { // 寻找最小的数
                                min_index = j;     // 将最小数的索引保存
                        }
                }
                temp = a[i]; // 元素交换
                a[i] = a[min_index];
                a[min_index] = temp;
        }
}

int main(void)
{
        int a[] = {2, 3, 9, 2, 3, 8, 9, 5, 8, 10, 12, 94, 20, 39, 11};
        PrintArray(a, 15);
        SelectionSort(a, 15);
        PrintArray(a, 15);

        return 0;
}
