/* Given an integer array of size 2N + 1. In this given array, N numbers are present twice and one number is present only once in the array.
You need to find and return that number which is unique in the array.
Note : Given array will always contain odd number of elements.
Input format :
Line 1 : Array size i.e. 2N+1
Line 2 : Array elements (separated by space)
Output Format :
Unique element present in the array
Constraints :
1 <= N <= 10^6
Sample Input :
7
2 3 1 6 3 6 2
Sample Output :
1 */

#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.count(a[i]) == 0)
        {
            m[a[i]] = 1;
        }
        else
        {
            m[a[i]]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (m[a[i]] == 1)
        {
            cout << a[i] << endl;
            return 0;
        }
    }
    return 0;
}