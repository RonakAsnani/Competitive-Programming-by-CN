#include <iostream>
using namespace std;

int partition(int *a, int s, int e)
{
    int pivot = a[e];
    int i = s - 1;
    for (int j = s; j < e; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        }
    }
    int temp = a[i + 1];
    a[i + 1] = a[e];
    a[e] = temp;
    return i + 1;
}

void quicksort(int *a, int s, int e)
{
    if (s < e)
    {
        int pi = partition(a, s, e);
        quicksort(a, s, pi - 1);
        quicksort(a, pi + 1, e);
    }
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
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}