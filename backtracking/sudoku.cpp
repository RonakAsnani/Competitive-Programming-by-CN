#include <iostream>
using namespace std;

bool checker(int **a, int x, int row, int col)
{
    for (int i = 0; i < 9; i++)
    {
        if (a[i][col] == x)
        {
            return false;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        if (a[row][i] == x)
        {
            return false;
        }
    }
    int t = row / 3;
    int u = col / 3;
    for (int i = t * 3; i < 3 * (t + 1); i++)
    {
        for (int j = u * 3; j < 3 * (u + 1); j++)
        {
            if (a[i][j] == x)
            {
                return false;
            }
        }
    }
    return true;
}

bool findempty(int **a, int &row, int &col)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (a[i][j] == 0)
            {
                row = i;
                col = j;
                return true;
            }
        }
    }
    return false;
}

bool solver(int **a)
{
    int row, col;
    if (!findempty(a, row, col))
    {
        return true;
    }
    for (int i = 1; i < 10; i++)
    {
        if (checker(a, i, row, col))
        {
            a[row][col] = i;
            if (solver(a))
            {
                return true;
            }
            a[row][col] = 0;
        }
    }
    return false;
}

int main()
{
    int **a = new int *[9];
    for (int i = 0; i < 9; i++)
    {
        a[i] = new int[9];
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            a[i][j] = s[j] - '0';
        }
    }
    if (solver(a))
    {
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << a[i][j];
            }
            cout << endl;
        }
    };
    return 0;
}