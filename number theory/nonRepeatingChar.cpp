#include <iostream>
#include <string>
#include <map>
using namespace std;

char rep(string s)
{
    map<char, int> m;
    for (int i = 0; i < s.length(); i++)
    {
        int curr = s[i];
        m[curr]++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (m[s[i]] == 1)
        {
            return s[i];
        }
    }
    return s[0];
}

int main()
{

    return 0;
}