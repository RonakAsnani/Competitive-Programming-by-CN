#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 5};
    map<int, int> m;
    for (int i = 0; i < 7; i++)
    {
        m[a[i]]++;
    }
    m.erase(1);
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
    {
        cout << it->first << " " << it->second << endl;
    }
    unordered_map<int, int> m1;
    // everything same just not ordered
    return 0;
}