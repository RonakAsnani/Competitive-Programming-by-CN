#include <bits/stdc++.h>
#include <vector>
#include <map>
using namespace std;

char getchar(int i)
{
    return (char)(i + 97);
}

void printpal(string s)
{
    map<char, vector<int>> m;
    for (int i = 0; i < s.length(); i++)
    {
        m[s[i]].push_back(i);
    }
    int odd_feq_count = 0;
    for (int i = 0; i < 26; i++)
    {
        if ((m[getchar(i)].size() % 2) != 0)
        {
            odd_feq_count++;
        }
    }
    if (odd_feq_count >= 2)
    {
        cout << "-1";
        return;
    }
    int ans[s.length()];
    int start = 0;
    int end = s.length() - 1;
    for (int i = 0; i < 26; i++)
    {
        char c = getchar(i);
        for (int j = 0; j < m[c].size(); j++)
        {
            if (m[c].size() - j == 1)
            {
                ans[s.length() / 2] = m[c][j];
                continue;
            }
            ans[start] = m[c][j];
            ans[end] = m[c][j + 1];
            start++;
            end--;
        }
    }
    for (int i = 0; i < s.length(); i++)
    {
        cout << ans[i] + 1;
    }
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        printpal(s);
        cout << endl;
    }
    return 0;
}