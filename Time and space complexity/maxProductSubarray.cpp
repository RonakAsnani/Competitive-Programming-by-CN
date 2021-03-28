#include <iostream>
using namespace std;

int maxpro(int a[], int n)
{
    int max_ending_here = 1;
    int min_ending_here = 1;
    int max_so_far = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > 0)
        {
            max_ending_here = max_ending_here * a[i];
            min_ending_here = min(1, min_ending_here * a[i]);
        }
        if (a[i] == 0)
        {
            max_ending_here = 1;
            min_ending_here = 0;
        }
        if (a[i] < 0)
        {
            int temp = max_ending_here;
            min_ending_here = temp * a[i];
            max_ending_here = max(1, min_ending_here * a[i]);
        }
        max_so_far = max(max_so_far, max_ending_here);
    }
    return max_so_far;
}