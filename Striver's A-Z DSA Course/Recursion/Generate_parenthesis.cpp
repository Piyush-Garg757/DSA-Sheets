/*Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]*/

class Solution
{
public:
    void solve(int n, int start, int end, vector<string> &ans, string &s)
    {
        if (start == 0 && end == 0)
        {
            ans.push_back(s);
            return;
        }
        if (start != 0 && end != 0)
        {
            s.push_back('(');
            solve(n, start - 1, end, ans, s);
            s.pop_back();
        }
        if (end > start)
        {
            s.push_back(')');
            solve(n, start, end - 1, ans, s);
            s.pop_back();
        }
        return;
    }
    vector<string> generateParenthesis(int n)
    {
        int start = n, end = n;
        vector<string> ans;
        string s = "";
        solve(n, start, end, ans, s);
        return ans;
    }
};
// TC - O((4^n)/(sqrt(n)))  SC - O(n)