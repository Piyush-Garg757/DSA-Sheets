/*Surrounded Regions

You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:
Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
Explanation:
In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:
Input: board = [["X"]]
Output: [["X"]]*/


// Simple approach - boundary pe jo bhi dikhe uske liye dfs call kar de jisme modify kar rahe ho baad me matrix traverse karo aur jo jo unvisited bache hain unhein X bana do    aur usi time jo modify kiye the unhein O bana do
class Solution
{
public:
    int r[4] = {-1, 0, 1, 0};
    int c[4] = {0, 1, 0, -1};
    void dfs(int row, int col, vector<vector<char>> &a)
    {
        a[row][col] = 'P';
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < 4; i++)
        {
            int delrow = row + r[i];
            int delcol = col + c[i];
            if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m &&
                a[delrow][delcol] == 'O')
                dfs(delrow, delcol, a);
        }
    }
    void solve(vector<vector<char>> &a)
    {
        int n = a.size(), m = a[0].size();
        for (int i = 0; i < n; i++)
        {
            if (a[i][0] == 'O')
            {
                dfs(i, 0, a);
            }
            if (a[i][m - 1] == 'O')
            {
                dfs(i, m - 1, a);
            }
        }
        for (int j = 0; j < m; j++)
        {
            if (a[0][j] == 'O')
            {
                dfs(0, j, a);
            }
            if (a[n - 1][j] == 'O')
            {
                dfs(n - 1, j, a);
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 'O')
                    a[i][j] = 'X';
                else if (a[i][j] == 'P')
                    a[i][j] = 'O';
            }
        }
    }
};
// TC - O(n*m)  SC - O(n*m)