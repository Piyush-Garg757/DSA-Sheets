/*Count Islands

Given a grid of size n*m (n is the number of rows and m is the number of columns in the grid) consisting of 'W's (Water) and 'L's (Land). Find the number of islands.
Note: An island is either surrounded by water or the boundary of a grid and is formed by connecting adjacent lands horizontally or vertically or diagonally i.e., in all 8 directions.

Examples:
Input: grid[][] = [['L', 'L', 'W', 'W', 'W'],
                ['W', 'L', 'W', 'W', 'L'],
                ['L', 'W', 'W', 'L', 'L'],
                ['W', 'W', 'W', 'W', 'W'],
                ['L', 'W', 'L', 'L', 'W']]
Output: 4
Explanation:
The image below shows all the 4 islands in the grid.

Input: grid[][] = [['W', 'L', 'L', 'L', 'W', 'W', 'W'],
                ['W', 'W', 'L', 'L', 'W', 'L', 'W']]
Output: 2
Explanation:
The image below shows 2 islands in the grid.
*/

class Solution
{
public:
    void bfs(int i, int j, vector<vector<char>> &a, vector<vector<int>> &visited)
    {
        visited[i][j] = 1;
        int n = a.size(), m = a[0].size();
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int delrow = row + i, delcol = col + j;
                    if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m && !visited[delrow][delcol] && a[delrow][delcol] == 'L')
                    {
                        q.push({delrow, delcol});
                        visited[delrow][delcol] = 1;
                    }
                }
            }
        }
    }
    int countIslands(vector<vector<char>> &a)
    {
        // Code here
        int n = a.size(), m = a[0].size(), ans = 0;
        vector<vector<int>> visited(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && a[i][j] == 'L')
                {
                    bfs(i, j, a, visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(n^2)
// Simple intution - bfs karo jo bhi L dikhe us node se aur bfs apne saath vale saare visited kar dega uske baad hi khatam hoga to uske baad jab dobra koi L mile yani ye dusra island hai  fir bfs karo aur ans++    aise hi dfs se bhi kar sakte hain

// Using dfs
class Solution
{
public:
    void dfs(int row, int col, vector<vector<char>> &a, vector<vector<int>> &visited)
    {
        visited[row][col] = 1;
        int n = a.size(), m = a[0].size();
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                int delrow = row + i, delcol = col + j;
                if (delrow >= 0 && delrow < n && delcol >= 0 && delcol < m && !visited[delrow][delcol] && a[delrow][delcol] == 'L')
                {
                    dfs(delrow, delcol, a, visited);
                }
            }
        }
    }
    int countIslands(vector<vector<char>> &a)
    {
        // Code here
        int n = a.size(), m = a[0].size(), ans = 0;
        vector<vector<int>> visited(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!visited[i][j] && a[i][j] == 'L')
                {
                    dfs(i, j, a, visited);
                    ans++;
                }
            }
        }
        return ans;
    }
};

// Leetcode version me upar neeche aage peeche vale hi eighbours mane jate hain to uss version ke liye
class Solution
{
public:
    void dfs(int row, int col, vector<vector<char>> &a)
    {
        a[row][col] = '0';
        int n = a.size(), m = a[0].size();
        for (int i = -1; i <= 1; i++)
        {
            int delrow = row + i, delcol = col;
            if (delrow >= 0 && delrow < n && a[delrow][delcol] == '1')
            {
                dfs(delrow, delcol, a);
            }
        }
        for (int j = -1; j <= 1; j++)
        {
            int delrow = row, delcol = col + j;
            if (delcol >= 0 && delcol < m && a[delrow][delcol] == '1')
            {
                dfs(delrow, delcol, a);
            }
        }
    }
    int numIslands(vector<vector<char>> &a)
    {
        int n = a.size(), m = a[0].size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '1')
                {
                    dfs(i, j, a);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// Also ismein visited alag se nahi banaya hai usi mein 1 se 0 karta ja raha hu