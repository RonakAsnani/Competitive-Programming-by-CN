#include <iostream>
using namespace std;

void merge(int *x, int s, int e, int m)
{
    // int m = (s + e) / 2;
    int output[e - s];
    int a[m - s];
    int f = 0;
    for (int p = s; p < m; p++)
    {
        a[p] = x[f];
        f++;
    }
    int b[e - (m + 1)];
    for (int p = 0; p < e - m - 1; p++)
    {
        b[p] = x[f];
        f++;
    }
    int i = 0, j = 0;
    int k = s;
    while (k < e && i < m && j < (e - m + 1))
    {
        if (a[i] < a[j])
        {
            output[k] = a[i];
            i++;
        }
        else
        {
            output[k] = a[j];
            j++;
        }
        k++;
    }
    while (j < (e - m + 1))
    {
        output[k] = a[j];
        k++;
    }
    while (i < m)
    {
        output[k] = a[i];
        k++;
    }
}

void ms(int s, int e, int *x)
{
    if (s >= e)
    {

        return;
    }
    int m = (s + e) / 2 - 1;
    ms(s, m, x);
    ms(m + 1, e, x);
    // int *output = new int[e - s];
    merge(x, s, e, m);
}

int main()
{
    int n = 7;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    ms(0, n, a);

    return 0;
}