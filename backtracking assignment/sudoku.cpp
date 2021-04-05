/* Given a 9*9 sudoku board, in which some entries are filled and others are 0 (0 indicates that the cell is empty), you need to find out whether the Sudoku puzzle can be solved or not i.e. return true or false.
Input Format :
9 Lines where ith line contains ith row elements separated by space
Output Format :
 true or false
Sample Input :
9 0 0 0 2 0 7 5 0 
6 0 0 0 5 0 0 4 0 
0 2 0 4 0 0 0 1 0 
2 0 8 0 0 0 0 0 0 
0 7 0 5 0 9 0 6 0 
0 0 0 0 0 0 4 0 1 
0 1 0 0 0 5 0 8 0 
0 9 0 0 7 0 0 0 4 
0 8 2 0 4 0 0 0 6
Sample Output :
true */

#include <iostream>
using namespace std;
int n = 9;

bool finder(int **a, int &row, int &col)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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

bool checker(int **a, int row, int col, int val)
{
    for (int i = 0; i < n; i++)
    {
        if (a[row][i] == val)
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (a[i][col] == val)
        {
            return false;
        }
    }
    int u = row / 3;
    int t = col / 3;
    for (int i = u * 3; i < (u + 1) * 3; i++)
    {
        for (int j = t * 3; j < (t + 1) * 3; j++)
        {
            if (a[i][j] == val)
            {
                return false;
            }
        }
    }

    return true;
}

bool solver(int **a)
{
    int row, col;
    if (!finder(a, row, col))
    {
        return true;
    }
    for (int i = 1; i < 10; i++)
    {
        if (checker(a, row, col, i))
        {
            a[row][col] = i;
            if (solver(a))
            {
                return true;
            }
            else
            {
                a[row][col] = 0;
            }
        }
    }
    return false;
}

int main()
{
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    if (solver(a))
    {
        cout << true << endl;
    }
    else
    {
        cout << false << endl;
    }
    return 0;
}