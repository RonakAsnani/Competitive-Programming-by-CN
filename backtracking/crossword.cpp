/* CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA */

#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define n 10

void print(char **a)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j];
        }
        cout << endl;
    }
}

bool valid_vertical(char **a, int i, int j, string word)
{
    int r = i;
    for (int q = 0; q < word.length(); q++)
    {
        if (a[r][j] == '-' || a[r][j] == word[q])
        {
            r++;
        }
        if (r > 9)
        {
            return false;
        }
        if (a[r][j] == '+' || (a[r][j] != '-' && a[r][j] != word[q]))
        {
            return false;
        }
    }
    return true;
}
bool valid_hor(char **a, int r, int c, string word)
{
    int col = c;
    for (int i = 0; i < word.length(); i++)
    {
        if (a[r][col] == '-' || a[r][col] == word[i])
        {
            col++;
        }
        if (col > 9)
        {
            return false;
        }
        if (a[r][col] == '+' || (a[r][col] != '-' && a[r][col] != word[i]))
        {
            return false;
        }
    }
    return true;
}

void set_vertical(char **a, int r, int c, vector<bool> &helper, string word)
{
    int row = r;
    for (int i = 0; i < word.length(); i++)
    {
        if (a[row + i][c] == '-')
        {
            a[row + i][c] = word[i];
            helper.push_back(true);
        }
        else
        {
            helper.push_back(false);
        }
    }
}

void set_hor(char **a, int r, int c, vector<bool> &v, string word)
{
    int col = c;
    for (int i = 0; i < word.length(); i++)
    {
        if (a[r][col + i] == '-')
        {
            a[r][col + i] = word[i];
            v.push_back(true);
        }
        else
        {
            v.push_back(false);
        }
    }
}

void reset_vertical(char **a, int r, int c, vector<bool> v)
{
    int row = r;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            a[row + i][c] = '-';
        }
    }
}

void reset_hor(char **a, int r, int c, vector<bool> v)
{
    int col = c;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            a[r][col + i] = '-';
        }
    }
}

bool crossword(char **a, vector<string> v, int index)
{
    if (index >= v.size())
    {
        print(a);
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] == '-' || a[i][j] == v[index][0])
            {
                if (valid_vertical(a, i, j, v[index]))
                {
                    vector<bool> helper;
                    set_vertical(a, i, j, helper, v[index]);

                    if (crossword(a, v, index + 1))
                    {
                        return true;
                    }
                    reset_vertical(a, i, j, helper);
                }
                if (valid_hor(a, i, j, v[index]))
                {
                    vector<bool> helper;
                    set_hor(a, i, j, helper, v[index]);

                    if (crossword(a, v, index + 1))
                    {
                        return true;
                    }
                    reset_hor(a, i, j, helper);
                }
            }
        }
    }
    return false;
}

int main()
{
    char **a = new char *[n];
    for (int i = 0; i < n; i++)
    {
        a[i] = new char[n];
        string s;
        cin >> s;
        for (int j = 0; j < s.length(); j++)
        {
            a[i][j] = s[j];
        }
    }
    string s;
    cin >> s;
    vector<string> v;
    for (int i = 0; i < s.length(); i++)
    {
        int j = i;
        while (s[j] != ';' && j < s.length())
        {
            j++;
        }
        v.push_back(s.substr(i, j - 1));
        i = j;
        j++;
    }
    bool x = crossword(a, v, 0);

    return 0;
}