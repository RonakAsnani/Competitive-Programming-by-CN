#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

vector<int> rem(vector<int> input)
{
    set<int> s;
    vector<int> result;

    for (int i = 0; i < input.size(); i++)
    {
        if (s.find(input[i]) == s.end())
        {
            s.insert(input[i]);
            result.push_back(input[i]);
        }
    }
    return result;
}

// by sorting

vector<int> rem2(vector<int> input)
{
    vector<int> result;
    sort(input.begin(), input.end());
    result.push_back(input[0]);
    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] != input[i - 1])
        {
            result.push_back(input[i]);
        }
    }
}

int main()
{

    return 0;
}