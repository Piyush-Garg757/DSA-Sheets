/*Rotting Oranges

You are given an m x n grid where each cell can have one of three values:
0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.
Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.

Example 1:
Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4

Example 2:
Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.

Example 3:
Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.*/

class Solution
{
public:
    int bfs(vector<vector<int>> &a, queue<pair<pair<int, int>, int>> &q,
            int fresh_count)
    {
        int min_time = 0;
        int n = a.size(), m = a[0].size();
        while (!q.empty())
        {
            int time = q.front().second;
            int row = q.front().first.first;
            int col = q.front().first.second;
            min_time = max(min_time, time);
            q.pop();
            for (int i = -1; i <= 1; i += 2)
            {
                int delrow = row + i;
                if (delrow >= 0 && delrow < n && a[delrow][col] == 1)
                {
                    a[delrow][col] = 2;
                    fresh_count--;
                    q.push({{delrow, col}, time + 1});
                }
            }
            for (int j = -1; j <= 1; j += 2)
            {
                int delcol = col + j;
                if (delcol >= 0 && delcol < m && a[row][delcol] == 1)
                {
                    a[row][delcol] = 2;
                    fresh_count--;
                    q.push({{row, delcol}, time + 1});
                }
            }
        }
        if (fresh_count)
            return -1;
        return min_time;
    }
    int orangesRotting(vector<vector<int>> &a)
    {
        queue<pair<pair<int, int>, int>> q;
        int n = a.size(), m = a[0].size(), fresh_count = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 2)
                {
                    q.push({{i, j}, 0});
                }
                else if (a[i][j] == 1)
                {
                    fresh_count++;
                }
            }
        }
        return bfs(a, q, fresh_count);
    }
};
// TC - O(n*m)  SC - O(n*m)