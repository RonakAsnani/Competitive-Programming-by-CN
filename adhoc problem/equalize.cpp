#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s, t;
    cin >> s;
    cin >> t;
    int i = 0;
    int ans = 0;
    while (i < n)
    {
        if (s[i] != t[i])
        {
            if (i < n - 1 && s[i] != s[i + 1] && s[i + 1] != t[i + 1])
            {
                int temp = s[i];
                s[i] = s[i + 1];
                s[i + 1] = temp;
                ans++;
                i = i + 2;
            }
            else
            {
                s[i] = t[i];
                ans++;
                i++;
            }
        }
        else
        {
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}