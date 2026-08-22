/*01 Matrix

Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.
The distance between two cells sharing a common edge is 1.

Example 1:
Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]

Example 2:
Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]*/

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> ans(n, vector<int>(m));
        queue<pair<pair<int, int>, int>> q;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0)
                {
                    q.push({{i, j}, 0});
                    ans[i][j] = 0;
                }
            }
        }
        while (!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            q.pop();
            for (int i = -1; i <= 1; i += 2)
            {
                int delrow = r + i;
                if (delrow >= 0 && delrow < n && a[delrow][c] == 1)
                {
                    a[delrow][c] = 0;
                    q.push({{delrow, c}, t + 1});
                    ans[delrow][c] = t + 1;
                }
            }
            for (int i = -1; i <= 1; i += 2)
            {
                int delcol = c + i;
                if (delcol >= 0 && delcol < m && a[r][delcol] == 1)
                {
                    a[r][delcol] = 0;
                    q.push({{r, delcol}, t + 1});
                    ans[r][delcol] = t + 1;
                }
            }
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(n^2)