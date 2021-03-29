/* In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. If all the names are unique, print -1 instead.
Note: We don't have to mention names whose frequency is 1.
Input Format:
The only line of input will have a string ‘str’ with space separated first names of students.
Output Format:
Print the names of students along with their count if they are repeating. If no name is repeating, print -1
Constraints:
1 <= |str| <= 10^5
Time Limit: 1 second
Sample Input 1:
Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
Sample Output 1:
harshit 2
Ayush 3
Iti 2
Sample Input 2:
Abhishek Harshit Ayush Iti
Sample Output:
-1 */

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    string str;
    getline(cin, str);
    vector<string> v;
    string curr_name = "";
    unordered_map<string, int> m;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            curr_name += str[i];
        }
        else
        {

            if (m.count(curr_name) == 0)
            {
                m[curr_name] = 1;
                v.push_back(curr_name);
            }
            else
            {
                m[curr_name]++;
            }
            curr_name = "";
        }
    }
    if (m.count(curr_name) == 0)
    {
        m[curr_name] = 1;
        v.push_back(curr_name);
    }
    else
    {
        m[curr_name]++;
    }
    curr_name = "";

    bool ans = true;
    for (int i = 0; i < v.size(); i++)
    {
        if (m[v[i]] > 1)
        {
            cout << v[i] << " " << m[v[i]] << endl;
            ans = false;
        }
    }
    if (ans)
    {
        cout << -1 << endl;
    }
    return 0;
}
