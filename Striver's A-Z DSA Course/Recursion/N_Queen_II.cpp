/*N-Queens II

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.

Example 1:
Input: n = 4
Output: 2
Explanation: There are two distinct solutions to the 4-queens puzzle as shown.

Example 2:
Input: n = 1
Output: 1*/

class Solution
{
public:
    void solve(int n, int curr_col, vector<int> &upperdiagonal,
               vector<int> &lowerdiagonal, vector<int> &leftrow, int &ans)
    {
        if (curr_col == n)
        {
            ans += 1;
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (lowerdiagonal[i + curr_col] == 0 &&
                upperdiagonal[n - 1 + curr_col - i] == 0 && leftrow[i] == 0)
            {
                lowerdiagonal[i + curr_col] = 1;
                upperdiagonal[n - 1 + curr_col - i] = 1;
                leftrow[i] = 1;
                solve(n, curr_col + 1, upperdiagonal, lowerdiagonal, leftrow,
                      ans);
                lowerdiagonal[i + curr_col] = 0;
                upperdiagonal[n - 1 + curr_col - i] = 0;
                leftrow[i] = 0;
            }
        }
    }
    int totalNQueens(int n)
    {
        vector<int> upperdiagonal(2 * n - 1, 0);
        vector<int> lowerdiagonal(2 * n - 1, 0);
        vector<int> leftrow(n, 0);
        int curr_col = 0;
        int ans = 0;
        solve(n, curr_col, upperdiagonal, lowerdiagonal, leftrow, ans);
        return ans;
    }
};
// TC - O(n!)  SC - O(n) 