/*Rat in a Maze

Given a binary matrix maze[][] of size n × n containing values 0 and 1, find all possible paths for a rat to travel from the source cell (0, 0) to the destination cell (n - 1, n - 1). The rat can move in four directions: up(U), down(D), left(L), and right(R).
1 represents an open cell through which the rat can move.
0 represents a blocked cell that cannot be traversed.
The rat can move only through open cells and cannot visit the same cell more than once in a path. Return all valid paths as strings consisting of 'U', 'D', 'L', and 'R', representing the sequence of moves taken by the rat.
Note: Return the paths in lexicographically increasing order. If no valid path exists, return an empty list.

Examples:

Input: maze[][] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}}
Output: ["DDRDRR", "DRDDRR"]
Explanation: There are two valid paths from the source cell (0, 0) to the destination cell (3, 3).

Input: maze[][] = [[1, 0], [1, 0]]
Output: []
Explanation: No path exists as the destination cell (1, 1) is blocked.*/

class Solution
{
public:
    void solve(vector<vector<int>> &a, vector<string> &ans, string &s, int n, int curr_row, int curr_col)
    {
        if (curr_row == n - 1 && curr_col == n - 1)
        {
            ans.push_back(s);
            return;
        }
        a[curr_row][curr_col] = 0;
        if (curr_row != n - 1 && a[curr_row + 1][curr_col] == 1)
        {
            s.push_back('D');
            solve(a, ans, s, n, curr_row + 1, curr_col);
            s.pop_back();
        }
        if (curr_col != 0 && a[curr_row][curr_col - 1] == 1)
        {
            s.push_back('L');
            solve(a, ans, s, n, curr_row, curr_col - 1);
            s.pop_back();
        }
        if (curr_col != n - 1 && a[curr_row][curr_col + 1] == 1)
        {
            s.push_back('R');
            solve(a, ans, s, n, curr_row, curr_col + 1);
            s.pop_back();
        }
        if (curr_row != 0 && a[curr_row - 1][curr_col] == 1)
        {
            s.push_back('U');
            solve(a, ans, s, n, curr_row - 1, curr_col);
            s.pop_back();
        }
        a[curr_row][curr_col] = 1;
    }
    vector<string> ratInMaze(vector<vector<int>> &a)
    {
        // code here
        vector<string> ans;
        int n = a.size();
        string s = "";
        int curr_row = 0, curr_col = 0;
        if (a[0][0] == 0 || a[n - 1][n - 1] == 0)
            return ans;
        solve(a, ans, s, n, curr_row, curr_col);
        return ans;
    }
};
// TC - O(4^(n^2))  SC - O(n^2)

// a[curr_row][curr_col] = 0;  a[curr_row][curr_col] = 1;  ye isiliye lagaya kyuki maan lo 1 1
//                                                                                          1 1 hai to infinite recursion mein fas sakta hai isiliye jis node se guzar gaye use 0 mark karna zaruri hai aur agar backtracking ke time vapas 1 mark kar do