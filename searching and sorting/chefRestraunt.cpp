#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            int start, end;
            cin >> start >> end;
            v.push_back(make_pair(start, end));
        }
        sort(v.begin(), v.end());
        while (m--)
        {
            int curr_time;
            cin >> curr_time;
            int position = lower_bound(v.begin(), v.end(), make_pair(curr_time, 0)) - v.begin();
            if (position == 0)
            {
                int ans = v[0].first - curr_time;
                cout << ans << endl;
                        }
            else
            {
                int ans = -1;
                if (v[position - 1].second > curr_time)
                {
                    ans = 0;
                }
                else if (position < v.size())
                {
                    ans = v[position].first - curr_time;
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}