#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility> // swap
using namespace std;

struct Interval
{
    int st;
    int et;
};
bool compare(Interval i1, Interval i2)
{
    return i1.st < i2.st;
}
int main()
{
    // Interval a[] = {{6, 4}, {3, 2}, {4, 6}, {8, 13}};
    // sort(a, a + 4, compare);
    int arr[] = {1, 4, 3, 5, 2, 7};
    sort(arr, arr + 6);
    for (int i = 0; i < 6; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << binary_search(arr, arr + 6, 3) << endl;
    cout << lower_bound(arr, arr + 6, 7) - arr << endl;
    cout << upper_bound(arr, arr + 6, 7) - arr << endl;
    // for (int i = 0; i < 4; i++)
    // {
    //     cout << a[i].st << " " << a[i].et << endl;
    // }
    cout << __gcd(10, 6) << endl;
    cout << pow(2, 5) << endl;

    int x = 10;
    int y = 12;
    swap(x, y);
    cout << x << " " << y << endl;
    return 0;
}