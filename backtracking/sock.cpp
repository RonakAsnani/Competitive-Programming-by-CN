#include <iostream>
using namespace std;

int ans = 0;

void check(int n, int m, int i, int j, int **a, int x, int k)
{
    if (x >= k)
    {
        ans++;
    }

    if ((i < n - 1 && j < m - 1 && ((x + a[i + 1][j + 1]) / 2 >= k)))
    {
        ans++;
    }
}

void calc(int n, int m, int **a, int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            check(n, m, i, j, a, a[i][j], k);
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        int **a = new int *[n];
        for (int i = 0; i < n; i++)
        {
            a[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                cin >> a[i][j];
            }
        }
        calc(n, m, a, k);
        cout << ans << endl;
    }
    return 0;
}