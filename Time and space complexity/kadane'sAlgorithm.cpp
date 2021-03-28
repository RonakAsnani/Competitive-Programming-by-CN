#include <iostream>
using namespace std;

int kadane(int *a, int n)
{
    int curr_sum = 0;
    int best_sum = 0;
    for (int i = 0; i < n; i++)
    {
        curr_sum += a[i];
        if (best_sum < curr_sum)
        {
            best_sum = curr_sum;
        }
        if (curr_sum < 0)
        {
            curr_sum = 0;
        }
    }
    return best_sum;
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
    return 0;
}