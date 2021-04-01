/* You are given a N*N maze with a rat placed at maze[0][0]. Find and print all paths that rat can follow to reach its destination i.e. maze[N-1][N-1]. Rat can move in any direc­tion ( left, right, up and down).
Value of every cell in the maze can either be 0 or 1. Cells with value 0 are blocked means rat can­not enter into those cells and those with value 1 are open.
Input Format
Line 1 : Integer N
Next N Lines : Each line will contain ith row elements (separated by space)
Output Format :
One Line for every possible solution. 
Every line will have N*N maze elements printed row wise and are separated by space. Only cells that are part of solution path should be 1, rest all cells should be 0.
Sample Input 1 :
3
1 0 1
1 0 1
1 1 1
Sample Output 1 :
1 0 0 1 0 0 1 1 1 
Sample Output 1 Explanation :
Only 1 path is possible
Sample Input 2 :
3
1 0 1
1 1 1
1 1 1
Sample Output 2 :
1 0 0 1 1 1 1 1 1 
1 0 0 1 0 0 1 1 1 
1 0 0 1 1 0 0 1 1 
1 0 0 1 1 1 0 0 1 
Sample Output 2 Explanation :
4 paths are possible */

#include <iostream>
using namespace std;

void maze(int n, int **a, int row, int col, int **out)
{

    if (row == n - 1 && col == n - 1)
    {
        out[row][col] = 1;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << out[i][j] << " ";
            }
        }
        cout << endl;
        out[row][col] = 0;
        return;
    }
    out[row][col] = 1;
    // up
    if (a[row][col] == 0)
    {
        return;
    }
    if (row - 1 >= 0 && a[row - 1][col] == 1 && out[row - 1][col] == 0)
    {

        //out[row - 1][col] = 1;
        maze(n, a, row - 1, col, out);
    }
    // down
    if (row + 1 < n && a[row + 1][col] == 1 && out[row + 1][col] == 0)
    {
        // out[row + 1][col] = 1;
        maze(n, a, row + 1, col, out);
    }
    // left
    if (col - 1 >= 0 && a[row][col - 1] == 1 && out[row][col - 1] == 0)
    {
        // out[row][col - 1] = 1;
        maze(n, a, row, col - 1, out);
    }
    if (col + 1 < n && a[row][col + 1] == 1 && out[row][col + 1] == 0)
    {
        // out[row][col + n] = 1;
        maze(n, a, row, col + 1, out);
    }
    out[row][col] = 0;
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
            cin >> a[i][j];
        }
    }
    int **out = new int *[n];
    for (int i = 0; i < n; i++)
    {
        out[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            out[i][j] = 0;
        }
    }

    int row = 0, col = 0;
    // out[row][col] = 1;
    maze(n, a, row, col, out);
    return 0;
}