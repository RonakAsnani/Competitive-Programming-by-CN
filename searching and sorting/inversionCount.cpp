/*Inversion Count
Send Feedback
For a given integer array/list of size N, find the total number of 'Inversions' that may exist.
An inversion is defined for a pair of integers in the array/list when the following two conditions are met.
A pair (arr[i], arr[j]) is said to be an inversion when,
1. arr[i] > arr[j] 
2. i < j

Where 'arr' is the input array/list, 'i' and 'j' denote the indices ranging from [0, N).
Input format :
The first line of input contains an integer N, denoting the size of the array.

The second line of input contains N integers separated by a single space, denoting the elements of the array.
Output format :
The only line of output prints the total count of inversions in the array.
Note:
You are not required to print anything. Return the total number of inversion count.
Constraints :
1 <= N <= 10^5 
1 <= arr[i] <= 10^9

Time Limit: 1sec
Sample Input 1 :
3
3 2 1
Sample Output 1 :
3
Explanation of Sample Input 1:
We have a total of three pairs which satisfy the condition of inversion. (3, 2), (2, 1) and (3, 1).
Sample Input 2 :
5
2 5 1 3 4
Sample Output 2 :
4

@csalgoe Output 2 :
4*/

#include <iostream>
#include <algorithm>
using namespace std;

int inversion(int st, int en, int *a)
{
    int count = 0;
    if (st < en)
    {
        int mid = (en + st) / 2;
        int left_count = inversion(st, mid, a);
        int right_count = inversion(mid + 1, en, a);
        int i = st, j = mid;
        while (i <= mid && j <= en)
        {
            if (a[i] > a[j])
            {
                count += mid - i;
                j++;
            }
            else
            {
                i++;
            }
        }
        sort(a + st, a + en);
        count += left_count + right_count;
    }
    return count;
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
    int st = 0;
    int en = n - 1;
    cout << inversion(st, en, a) << endl;

    return 0;
}