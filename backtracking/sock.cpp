#include <iostream>
using namespace std;

long long int ans = 0;

bool check(long long int n, long long int m, long long int i, long long int j, long long int **a, long long int x, long long int k, long long int **sum)
{

    long long int l = min(n - i, m - j);
    bool found = false;
    for (long long int q = 0; q < l; q++)
    {

        if ((i < n - q && j < m - q))
        {

            if (i >= 1 || j >= 1)
            {
                long long int s = sum[i + q][j + q] - sum[i - 1][j + q] - sum[i + q][j - 1] + sum[i - 1][j - 1];
                if (s / ((q + 1) * (q + 1)) >= k)
                {
                    ans++;
                }
            }
            else
            {
                if (sum[i + q][j + q] / ((q + 1) * (q + 1)) >= k)
                {
                    ans++;
                }
            }
        }
    }

    return true;
}

void calc(long long int n, long long int m, long long int **a, long long int k, long long int **sum)
{
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
            (check(n, m, i, j, a, a[i][j], k, sum));
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long int n, m, k;
        cin >> n >> m >> k;
        long long int **a = new long long int *[n];
        long long int **sum = new long long int *[n];
        for (long long int i = 0; i < n; i++)
        {
            a[i] = new long long int[m];
            sum[i] = new long long int[m];
            for (long long int j = 0; j < m; j++)
            {
                cin >> a[i][j];
                if (j == 0)
                {
                    sum[i][j] = a[i][j];
                }
                else
                {
                    sum[i][j] = a[i][j] + sum[i][j - 1];
                }
            }
        }
        for (int j = 0; j < m; j++)
        {
            for (int i = 1; i < n; i++)
            {
                sum[i][j] += sum[i - 1][j];
            }
        }
        // for (int j = 0; j < m; j++)
        // {
        //     for (int i = 0; i < n; i++)
        //     {
        //         cout << sum[j][i] << " ";
        //     }
        //     cout << endl;
        // }

        calc(n, m, a, k, sum);
        cout << ans << endl;
    }
    return 0;
}
