/*Palindrome Partitioning

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]*/

class Solution
{
public:
    bool ispalindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> &v, int idx, int n,
               string &s)
    {
        if (idx == n)
        {
            ans.push_back(v);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            if (ispalindrome(s.substr(idx, i + 1 - idx)))
            {
                v.push_back(s.substr(idx, i + 1 - idx));
                solve(ans, v, i + 1, n, s);
                v.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> v;
        int idx = 0;
        int n = s.length();
        solve(ans, v, idx, n, s);
        return ans;
    }
};
// TC - O(n*2^n)  SC - O(n)