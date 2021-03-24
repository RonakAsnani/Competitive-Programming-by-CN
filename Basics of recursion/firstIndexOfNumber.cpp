/* Given an array of length N and an integer x, you need to find and return the first index of integer x present in the array. Return -1 if it is not present in the array.
First index means, the index of first occurrence of x in the input array.
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x
Output Format :
first index or -1
Constraints :
1 <= N <= 10^3
Sample Input :
4
9 8 10 8
8
Sample Output :
1 */

#include <iostream>
using namespace std;

int find(int n, int *a, int x, int i)
{
    if (n == 0)
    {
        return -1;
    }
    if (a[i] == x)
    {
        return i;
    }
    return find(n - 1, a, x, i + 1);
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
    cout << find(n, a, x, 0);
    return 0;
}