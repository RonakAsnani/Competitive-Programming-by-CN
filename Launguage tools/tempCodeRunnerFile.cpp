#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getvoters(int a[], int n)
{
    sort(a, a + n);
    vector<int> voters;
    for (int i = 0; i < n;)
    {
        int count = 0;
        int j = i;
        while (j < n && (a[j] == a[i]))
        {
            count++;
            j++;
        }
        if (count >= 2)
        {
            voters.push_back(a[i]);
        }
        i = j;
    }
    return voters;
}

int main()
{
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int total = n1 + n2 + n3;
    int a[total];
    for (int i = 0; i < total; i++)
    {
        cin >> a[i];
    }
    vector<int> voters = getvoters(a, total);
    for (int i = 0; i < voters.size(); i++)
    {
        cout << voters[i] << endl;
    }

    return 0;
}