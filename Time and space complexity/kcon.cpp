#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll kadane(int a[], int n)
{
    ll currsum = 0;
    ll max_so_far = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        currsum = currsum + a[i];
        if (max_so_far < currsum)
        {
            max_so_far = currsum;
        }
        if (currsum < 0)
        {
            currsum = 0;
        }
    }
    return max_so_far;
}
ll maxsub(int a[], int n, int k)
{
    ll kadane_sum = kadane(a, n);
    if (k == 1)
    {
        return kadane_sum;
    }
    ll curr_prefix = 0, curr_suffix = 0;
    ll max_prefix = INT_MIN, max_suffix = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        curr_prefix = curr_prefix + a[i];
        max_prefix = max(max_prefix, curr_prefix);
    }
    ll total_sum = curr_prefix;
    ll ans;
    for (int i = n - 1; i >= 0; i--)
    {
        curr_suffix += a[i];
        max_suffix = max(max_suffix, curr_suffix);
    }
    if (total_sum < 0)
    {
        ans = max(max_suffix + max_prefix, kadane_sum);
    }
    else
    {
        ans = max(max_suffix + max_prefix + total_sum * (k - 2), kadane_sum);
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        t--;
        int n, k;
        cin >> n >> k;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << maxsub(a, n, k) << endl;
    }
    return 0;
}