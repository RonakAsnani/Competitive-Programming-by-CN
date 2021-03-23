#include <iostream>
using namespace std;

int main()
{
    int n = 6;
    int a[n] = {3, 6, 9, 1, 4, 2};

    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int key = a[i];
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = key;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}