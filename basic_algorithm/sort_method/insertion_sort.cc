
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

void InsertionSort(int* a, const int& len)
{
        int pre_index, current;
        for (int i = 1; i < len; i++) {
                pre_index = i-1;
                current = a[i];
                while (pre_index >= 0 && a[pre_index] > current) {
                        a[pre_index+1] = a[pre_index];
                        pre_index--;
                }
                a[pre_index+1] = current;
        }
}

int main(void)
{
        int a[] = {2, 3, 9, 2, 3, 8, 9, 5, 8, 10, 12, 94, 20, 39, 11};
        PrintArray(a, 15);
        InsertionSort(a, 15);
        PrintArray(a, 15);

        return 0;
}
