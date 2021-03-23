#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int n = 6;
    int a[n] = {4, 7, 8, 1, 3, 2};
    for (int i = 0; i < n; i++)
    {
        int m = i;
        for (int j = i; j < n; j++)
        {
            if (a[m] > a[j])
            {
                m = j;
            }
        }
        int temp = a[m];
        a[m] = a[i];
        a[i] = temp;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}