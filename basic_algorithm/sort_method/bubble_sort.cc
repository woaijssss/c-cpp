
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

void BubbleSort(int* a, const int& len)
{
        for (int i = 0; i < len-1; i++) {
                for (int j = 0; j < len-1-i; j++) {
                        if (a[j] > a[j+1]) { // 相邻元素两两对比
                                int temp = a[j+1]; // 元素交换
                                a[j+1] = a[j];
                                a[j] = temp;
                        }
                }
        }
}

int main(void)
{
        int a[] = {2, 3, 9, 2, 3, 8, 9, 5, 8, 10, 12, 94, 20, 39, 11};
        PrintArray(a, 15);
        BubbleSort(a, 15);
        PrintArray(a, 15);

        return 0;
}
