/* Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde */

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    string s;
    cin >> s;
    string ans = "";
    unordered_map<char, int> m;
    for (int i = 0; i < s.size(); i++)
    {
        if (m.count(s[i]) == 0)
        {
            m[s[i]] = 1;
            ans += s[i];
        }
    }
    s = ans;
    cout << s << endl;
    return 0;
}