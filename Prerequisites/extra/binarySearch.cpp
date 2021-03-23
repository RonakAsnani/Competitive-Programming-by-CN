#include <iostream>
using namespace std;

int search(int s, int e, int *a, int x)
{
    if (s > e)
    {
        return -1;
    }
    int m = (s + e) / 2 - 1;
    if (a[m] == x)
    {
        return m;
    }
    if (a[m] > x)
    {
        return search(s, m - 1, a, x);
    }
    if (a[m] < x)
    {
        return search(m + 1, e, a, x);
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int x;
    cin >> x;
    cout << search(0, n - 1, a, x) << endl;
    return 0;
}