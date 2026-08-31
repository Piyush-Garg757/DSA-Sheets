/*Path With Minimum Effort

You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3:
Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
Output: 0
Explanation: This route does not require any effort.*/

// path aur minimum sunte hi dijkstra mann me ana chahiye aur ismein mimimum effort chahiye na ki minimum path length  to hum jaha har baar pq me d lete the yaha effort lenge aur uske according karenge pura
class Solution
{
public:
    int minimumEffortPath(vector<vector<int>> &a)
    {
        int n = a.size(), m = a[0].size();
        vector<vector<int>> effort(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                effort[i][j] = INT_MAX;
        }
        effort[0][0] = 0;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};
        while (!pq.empty())
        {
            int e = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            if (row == n - 1 && col == m - 1)
                return e;
            pq.pop();
            if (e > effort[row][col])
                continue;
            for (int i = 0; i < 4; i++)
            {
                int delrow = row + r[i];
                int delcol = col + c[i];
                if (delrow >= 0 && delcol >= 0 && delrow < n && delcol < m)
                {
                    int eff = max(abs(a[row][col] - a[delrow][delcol]), e);
                    if (effort[delrow][delcol] > eff)
                    {
                        effort[delrow][delcol] = eff;
                        pq.push({eff, {delrow, delcol}});
                    }
                }
            }
        }
        return -1;
    }
};
// TC - O(mnlog(mn))  SC - O(mn)