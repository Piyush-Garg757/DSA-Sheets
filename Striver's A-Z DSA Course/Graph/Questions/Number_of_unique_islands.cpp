/*Number of Distinct Islands

Given a grid grid[][] of size n × m, consisting of characters 'L' and 'W', where 'L' represents Land and 'W' represents Water, find the number of distinct islands in the grid. An island is a group of one or more land cells connected horizontally or vertically.
Two islands are considered distinct if their shapes are different.
Two islands have the same shape if one can be translated to match the other exactly. Rotation and reflection are not allowed.

Examples :
Input: grid[][] = [['L', 'W', 'W'], ['W', 'W', 'L'], ['L', 'W', 'W']]
Output: 1
Explanation: The grid contains three islands. All these islands have the same shape (a 1 × 1 block of land), so they are counted
as a single distinct island.

Input: grid[][] = [['L', 'L', 'W', 'L', 'L'], ['L', 'W', 'W', 'W', 'W'], ['W', 'W', 'L', 'W', 'L'], ['L', 'W', 'W', 'L', 'L']]
Output: 4
Explanation: There are five islands in the grid. Two islands have the same shape (a 1 × 1 block of land), while the other three have different shapes. Therefore, the number of distinct island shapes is 4.*/


// Idea is simple - jaise islands vale question mein karte the vese hi karna hia but ab unique islands batane hian to vector banake set mein push karenge aur set to unique elements hi rakhta hai to vo duplicate graphs ko ek hi baar count karega aur humein set ke size se answer mil jayega      par_row aur par_col vala system ye hai ki jaise 00 aur 01 hai aur aage jake 20 aue 21 aate hain to ye identical hai but identical banane ke liye 20-20 and 21-20 so they become 00 and 01 and hence are stored once 
class Solution
{
public:
    void dfs(int row, int col, int par_row, int par_col, vector<vector<char>> &a, vector<pair<int, int>> &v)
    {
        a[row][col] = 'W';
        int r[] = {-1, 0, 1, 0};
        int c[] = {0, 1, 0, -1};
        v.push_back({row - par_row, col - par_col});
        for (int i = 0; i < 4; i++)
        {
            int delrow = row + r[i];
            int delcol = col + c[i];
            if (delrow >= 0 && delrow < a.size() && delcol >= 0 && delcol < a[0].size() && a[delrow][delcol] == 'L')
            {
                dfs(delrow, delcol, par_row, par_col, a, v);
            }
        }
    }
    int countDistinctIslands(vector<vector<char>> &a)
    {
        // code here
        int n = a.size(), m = a[0].size();
        set<vector<pair<int, int>>> st;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 'L')
                {
                    vector<pair<int, int>> v;
                    dfs(i, j, i, j, a, v);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};
// TC - O(m*n)*log(m*n)  SC - O(m*n)