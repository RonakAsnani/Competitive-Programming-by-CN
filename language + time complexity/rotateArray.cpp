/* Given a random integer array of size n, write a function that rotates the given array by d elements (towards left)
Change in the input array itself. You don't need to return or print elements.
Input format :
Line 1 : Integer n (Array Size)
Line 2 : Array elements (separated by space)
Line 3 : Integer d
Output Format :
Updated array elements (separated by space)
Constraints :
1 <= N <= 1000
1 <= d <= N
Sample Input :
7
1 2 3 4 5 6 7
2
Sample Output :
3 4 5 6 7 1 2 */

#include <iostream>
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
    int d;
    cin >> d;
    int index;
    bool f = false;
    int k = 0;
    int b[n];
    for (int i = 0; i < n; i++)
    {
        if (f)
        {
            b[k] = a[i];
            k++;
        }
        if (a[i] == d)
        {
            index = i;
            f = true;
        }
    }
    for (int i = 0; i <= index; i++)
    {
        b[k] = a[i];
        k++;
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = b[i];
        cout << a[i] << " ";
    }
    return 0;
}