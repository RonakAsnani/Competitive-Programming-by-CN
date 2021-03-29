#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s = "ronak";
    string s1(s, 2, 4);
    string s2 = s.substr(1, 4);
    cout << s1 << endl;
    cout << s << endl;
    cout << s2 << endl;

    if (s1.compare(s2) == 0)
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}