#include <iostream>

using namespace std;

void qSort(int a[], int left, int right)
{
        for (size_t i = 0; i < 5; i++) {
                cout << a[i] << " ";
        }
        cout << endl;

        if (left >= right) {        // 如果左边索引大于或者等于右边的索引就代表已经整理完成一个组
                return;
        }

        int i = left;
        int j = right;
        int key = a[i];         // 用字表的第一个记录作为枢轴

        while (i < j) {      // 控制在当组内寻找一遍
                /* 寻找结束的条件就是：
                 * （1）找到一个小于或者大于key的数（大于或小于取决于你想升序还是降序）
                 * （2）没有符合条件1的，并且i与j的大小没有反转
                 */
                while (i < j && a[j] >= key) {
                        j--;
                }

                /* 找到一个这样的数后就把它赋给前面的被拿走的i的值（如果第一次循环且key是a[left]，那么就是给key）*/
                a[i] = a[j];     // 将比第一个小的移到低端

                /* 这是i在当组内向前寻找，同上， 不过注意与key的大小关系停止循环和上面相反;
                 * 因为排序思想是把数往两边扔
                 * 所以左右两边的数大小与key的关系相反
                 */
                while (i < j && a[i] <= key) {
                        i++;
                }

                a[j] = a[i];     // 将比第一个大的移到高端
        }

        a[i] = key;             // 当在当组内找完一遍以后就把中间数key回归
        qSort(a, left, i - 1);  // 最后用同样的方式对分出来的左边的小组进行同上的做法
        qSort(a, i + 1, right); // 用同样的方式对分出来的右边的小组进行同上的做法
        // 当然最后可能会出现很多分左右，直到每一组的i = j 为止
}

int main(void)
{
        int a[] = {57, 68, 59, 52, 72, 28, 96, 33, 24};
        cout << sizeof(a) << endl;
        cout << sizeof(a) / sizeof(a[0]) << endl;

        qSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);/*这里原文第三个参数要减1否则内存越界*/

        return 0;
}

