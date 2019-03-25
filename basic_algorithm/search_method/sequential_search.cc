
#include <iostream>
using namespace std;

int SequenceSearch(int* a, const int& value, const int& n)
{
        for (int i = 0; i < n; i++) {
                if (a[i] == value)
                        return i;
        }
        return -1;
}

int main(void)
{
        int a[] = {2, 3, 9, 2, 3, 8, 9, 5, 8, 10, 12, 94, 20, 39, 11};
        cerr << SequenceSearch(a, 8, 15) << endl;

        return 0;
}
