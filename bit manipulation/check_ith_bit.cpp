#include <iostream>
using namespace std;

int main()
{
    int n, i;
    cin >> n >> i;
    int x = 1;
    int z = n & 1 << i;
    if (z == 0)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
    }
    return 0;
}