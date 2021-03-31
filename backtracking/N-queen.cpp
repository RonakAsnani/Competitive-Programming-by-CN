
/* You are given N, and for a given N x N chessboard, find a way to place N queens such that no queen can attack any other queen on the chess board. A queen can be killed when it lies in the same row, or same column, or the same diagonal of any of the other queens. You have to print all such configurations.
Input Format :
Line 1 : Integer N
Output Format :
One Line for every board configuration. 
Every line will have N*N board elements printed row wise and are separated by space
Note : Don't print anything if there isn't any valid configuration.
Constraints :
1<=N<=10
Sample Input 1:
4
Sample Output 1 :
0 1 0 0 0 0 0 1 1 0 0 0 0 0 1 0 
0 0 1 0 1 0 0 0 0 0 0 1 0 1 0 0  */

#include <iostream>
using namespace std;

bool row_check(int n, int row, int col, int **a)
{
    for (int i = row - 1; i >= 0; i--)
    {
        if (a[i][col] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (a[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
    {
        if (a[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}
void zero(int **a, int n, int row)
{
    for (int i = row; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }
}
void queen(int n, int **a, int row)
{
    if (row == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[i][j] << " ";
            }
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        zero(a, n, row);
        if (row_check(n, row, i, a))
        {
            a[row][i] = 1;
            queen(n, a, row + 1);
        }
    }
}

int main()
{
    int n;
    cin >> n;
    int **a = new int *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            a[i][j] = 0;
        }
    }

    queen(n, a, 0);
    return 0;
}