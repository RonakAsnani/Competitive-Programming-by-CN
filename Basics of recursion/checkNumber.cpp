/* Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
Do this recursively.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
true or false
Constraints :
1 <= N <= 10^3
Sample Input :
3
9 8 10
8
Sample Output :
true */

#include <iostream>
using namespace std;

bool find(int n, int *a, int x)
{
    if (n == 0)
    {
        return false;
    }
    if (a[0] == x)
    {
        return true;
    }
    return find(n - 1, a + 1, x);
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
    int x;
    cin >> x;
    cout << find(n, a, x);
    return 0;
}