#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    long ans = 0;
    int i = 0, j = 1;
    while (j < n)
    {
        if (a[j] - a[i] >= k)
        {
            ans += n - j;
            i++;
        }
        else
        {
            j++;
        }
    }
    cout << ans << endl;
    return 0;
}