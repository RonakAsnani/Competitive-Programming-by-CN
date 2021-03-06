/* Given a random integer array A of size N. Find and print the pair of elements in the array which sum to 0.
Array A can contain duplicate elements.
While printing a pair, print the smaller element first.
That is, if a valid pair is (6, -6) print "-6 6". There is no constraint that out of 5 pairs which have to be printed in 1st line. You can print pairs in any order, just be careful about the order of elements in a pair.
Input format :
Line 1 : Integer N (Array size)
Line 2 : Array elements (separated by space)
Output format :
Line 1 : Pair 1 elements (separated by space)
Line 2 : Pair 2 elements (separated by space)
Line 3 : and so on
Constraints :
0 <= N <= 10^4
Sample Input:
5
2 1 -2 2 3
Sample Output :
-2 2
-2 2 */

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
            m[a[i]] = a[i];
            if (m.count(0 - a[i]) > 0)
            {
                if (a[i] > 0)
                {
                    cout << -(a[i]) << " " << a[i] << endl;
                }
                else
                {
                    cout << a[i] << " " << -(a[i]) << endl;
                }
            }
        }
        else
        {
            if (m.count(0 - a[i]) > 0)
            {
                if (a[i] > 0)
                {
                    cout << -(a[i]) << " " << a[i] << endl;
                }
                else
                {
                    cout << a[i] << " " << -(a[i]) << endl;
                }
            }
        }
    }
    return 0;
}