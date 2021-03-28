#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        long prod[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long lp = 1;
        for (int i = 0; i < n; i++)
        {
            prod[i] = lp;
            lp = lp * a[i];
        }
        long rp = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            prod[i] = rp * prod[i];
            rp = rp * a[i];
        }
        for (int i = 0; i < n; i++)
        {
            cout << prod[i] << " ";
        }
        cout << endl;
    }
    return 0;
}