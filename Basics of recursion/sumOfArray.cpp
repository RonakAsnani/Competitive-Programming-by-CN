
/* Given an array of length N, you need to find and return the sum of all elements of the array.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Output Format :
Sum
Constraints :
1 <= N <= 10^3
Sample Input :
3
9 8 9
Sample Output :
26 */

#include <iostream>
using namespace std;

int suum(int n, int *a)
{
    if (n == 0)
    {
        return 0;
    }
    int x = suum(n - 1, a + 1);
    return x + a[0];
}

int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << suum(n, a) << endl;
    return 0;
}