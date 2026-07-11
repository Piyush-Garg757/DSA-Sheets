/*N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example 2:
Input: n = 1
Output: [["Q"]]*/

// Intution curr_col lwkw chalo aur har col mein optimally place karte chalo check karte hue ki yaha place kar sakte hai ya nahi aur aise hi aagr n tak pahhuch gaya curr_sol to matlab ki ek sol mila hai
class Solution
{
public:
    bool is_safe(int row, int col, vector<string> &v, int n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (v[i][j] == 'Q')
                {
                    if (row == i)
                        return false;
                    if (abs(row - i) == abs(col - j))
                        return false;
                }
            }
        }
        return true;
    }
    void solve(int n, vector<vector<string>> &ans, vector<string> &v,
               int curr_col)
    {
        if (curr_col == n)
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (is_safe(i, curr_col, v, n))
            {
                v[i][curr_col] = 'Q';
                solve(n, ans, v, curr_col + 1);
                v[i][curr_col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            v[i] = s;
        int curr_col = 0;
        solve(n, ans, v, curr_col);
        return ans;
    }
};
// TC - O(n^2*n!)  SC - O(n^2)

// Slight optimisation in is_safe - rather than checking all previous queens and eliminating positions in thr curr_col whih cant be filled we check which previous queen collide with the current one and if we cant find one we return true
class Solution
{
public:
    bool is_safe(int row, int col, vector<string> &v, int n)
    {
        int r = row, c = col;
        while (c >= 0)
        {
            if (v[r][c] == 'Q')
                return false;
            c--;
        }
        c = col;
        while (c >= 0 && r >= 0)
        {
            if (v[r][c] == 'Q')
                return false;
            c--;
            r--;
        }
        r = row, c = col;
        while (c >= 0 && r < n)
        {
            if (v[r][c] == 'Q')
                return false;
            c--;
            r++;
        }
        return true;
    }
    void solve(int n, vector<vector<string>> &ans, vector<string> &v,
               int curr_col)
    {
        if (curr_col == n)
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (is_safe(i, curr_col, v, n))
            {
                v[i][curr_col] = 'Q';
                solve(n, ans, v, curr_col + 1);
                v[i][curr_col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> v(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            v[i] = s;
        int curr_col = 0;
        solve(n, ans, v, curr_col);
        return ans;
    }
};
// TC - O(n*n!)  SC - O(n^2)

// Most optimal sol
class Solution
{
public:
    void solve(int n, vector<vector<string>> &ans, vector<string> &v, int curr_col, vector<int> &upperdiagonal,
               vector<int> &lowerdiagonal, vector<int> &leftrow)
    {
        if (curr_col == n)
        {
            ans.push_back(v);
            return;
        }
        for (int i = 0; i < n; i++)
        {
            if (lowerdiagonal[i + curr_col] == 0 &&
                upperdiagonal[n - 1 + curr_col - i] == 0 && leftrow[i] == 0)
            {
                v[i][curr_col] = 'Q';
                lowerdiagonal[i + curr_col] = 1;
                upperdiagonal[n - 1 + curr_col - i] = 1;
                leftrow[i] = 1;
                solve(n, ans, v, curr_col + 1, upperdiagonal, lowerdiagonal, leftrow);
                lowerdiagonal[i + curr_col] = 0;
                upperdiagonal[n - 1 + curr_col - i] = 0;
                leftrow[i] = 0;
                v[i][curr_col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        vector<vector<string>> ans;
        vector<string> v(n);
        vector<int> upperdiagonal(2 * n - 1, 0);
        vector<int> lowerdiagonal(2 * n - 1, 0);
        vector<int> leftrow(n, 0);
        string s(n, '.');
        for (int i = 0; i < n; i++)
            v[i] = s;
        int curr_col = 0;
        solve(n, ans, v, curr_col, upperdiagonal, lowerdiagonal, leftrow);
        return ans;
    }
};
// TC - O(n!)  SC - O(n^2)
/*1. leftRow[]
Suppose
0 1 2 3
---------
. . . .
. . . .
. . . .
. . . .
Hum column-wise queens place kar rahe hain.
Suppose queen rakh di
Q . . .
. . . .
. . . .
. . . .
Position
(row,col)
(0,0)
Ab
row 0
me aur queen nahi aa sakti.
To bas
leftRow[0]=1;
kar do.
Ab jab bhi kisi row me queen rakhni hogi
if(leftRow[row]==0)
matlab row khali hai.
Example
Row
0  <-- occupied
1
2
3
Array
leftRow
[1 0 0 0]
Bas.
Row check
O(1)

2. Lower Diagonal
Ye sabse important hai.
Board
0,0   0,1   0,2   0,3
1,0   1,1   1,2   1,3
2,0   2,1   2,2   2,3
3,0   3,1   3,2   3,3
Ab har cell ke liye
row+col
nikalo.
0 1 2 3
1 2 3 4
2 3 4 5
3 4 5 6
Observe karo.
Diagonal
(0,2)
(1,1)
(2,0)
Sabka
row+col
2
Same.
Dusra diagonal
(0,3)
(1,2)
(2,1)
(3,0)
Sabka
3
Same.
Matlab
Har lower diagonal ka unique ID hai
row+col
Isi liye
lowerDiagonal[row+col]
Example
Queen
(2,1)
row+col
3
To
lowerDiagonal[3]=1;
Ab jis bhi cell ka
row+col==3
hoga
wo unsafe hai.

3. Upper Diagonal
Ab doosri direction.
Board
0,0 0,1 0,2 0,3
1,0 1,1 1,2 1,3
2,0 2,1 2,2 2,3
3,0 3,1 3,2 3,3
Ab
col-row
nikalo.
0 1 2 3
-1 0 1 2
-2 -1 0 1
-3 -2 -1 0
Observe
(0,0)
(1,1)
(2,2)
(3,3)
Sabka
col-row
0
Same.
Dusra
(0,2)
(1,3)
Sabka
2
Same.
Problem
Negative values aa rahi hain.
-3
-2
-1
Array me negative index nahi hota.
To shift kar dete hain.
Maximum negative
-(n-1)
Minimum positive
+(n-1)
Range
-(n-1)
...
0
...
+(n-1)
Total values
2*n-1
Isliye
upperDiagonal[2*n-1]
banate hain.
Index banane ke liye
col-row
me
n-1
add kar dete hain.
Formula
n-1+col-row
Example
n=4
Queen
(3,1)
col-row
1-3=-2
Shift
3-2=1
Index
upperDiagonal[1]

Array sizes
Row
Need
0
1
2
...
n-1
So
vector<int> leftRow(n);
Lower diagonal
Possible values
0
1
...
2n-2
Count
2n-1
Hence
vector<int> lowerDiagonal(2*n-1);
Upper diagonal
Possible values after shifting
0
1
...
2n-2
Again
2n-1
Hence
vector<int> upperDiagonal(2*n-1);

Placement
Queen at
(row,col)
leftRow[row]=1;
lowerDiagonal[row+col]=1;
upperDiagonal[n-1+col-row]=1;
Removing (Backtracking)
leftRow[row]=0;
lowerDiagonal[row+col]=0;
upperDiagonal[n-1+col-row]=0;*/