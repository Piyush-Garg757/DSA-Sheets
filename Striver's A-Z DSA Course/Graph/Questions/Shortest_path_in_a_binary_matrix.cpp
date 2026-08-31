/*Shortest Path in Binary Matrix

Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
All the visited cells of the path are 0.
All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
The length of a clear path is the number of visited cells of this path.

Example 1:
Input: grid = [[0,1],[1,0]]
Output: 2

Example 2:
Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
Output: 4

Example 3:
Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
Output: -1*/


// ise normal bfs se kar sakte hain jo ki kiya hi hua hai 
// Ise dijkstras se bhi soch sakte hain   but ismein ek baat dhyaan dene vali hai ki queue mein push har baar increasing distance me hi hoga pehle 1 vale sare fir 2 fir 3 aise aise to humein priority queue ki need nahi hai ismein   we can use a normal queue and doing dijkstras with normal queue will sound like bfs just like you can see below
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &a)
    {
        int n = a.size();
        if (a[0][0] || a[n - 1][n - 1])
            return -1;
        queue<pair<int, pair<int, int>>> q;
        q.push({1, {0, 0}});
        a[0][0] = 1;
        while (!q.empty())
        {
            int row = q.front().second.first;
            int col = q.front().second.second;
            int d = q.front().first;
            if (row == n - 1 && col == n - 1)
                return d;
            q.pop();
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    int delrow = row + i;
                    int delcol = col + j;
                    if (delrow < n && delcol < n && delrow >= 0 &&
                        delcol >= 0 && a[delrow][delcol] == 0)
                    {
                        q.push({d + 1, {delrow, delcol}});
                        a[delrow][delcol] = 1;
                    }
                }
            }
        }
        return -1;
    }
};
// TC - O(n^2)  SC - O(n^2)