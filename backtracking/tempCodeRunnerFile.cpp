#include <iostream>
#include <climits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int curr_len = 0;
        int max_curr = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '*')
            {
                curr_len++;
            }
            else
            {
                curr_len = 0;
            }
            max_curr = max(max_curr, curr_len);
        }
        if (max_curr >= k)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}