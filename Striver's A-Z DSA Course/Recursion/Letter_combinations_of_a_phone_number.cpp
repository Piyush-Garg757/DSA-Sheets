/*Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = "2"
Output: ["a","b","c"]*/

class Solution
{
public:
    void solve(string a, map<int, vector<char>> &mpp, vector<string> &ans,
               string s, int n, int idx)
    {
        if (idx == n)
        {
            ans.push_back(s);
            return;
        }
        int digit = a[idx] - '0';
        for (int i = 0; i < mpp[digit].size(); i++)
        {
            s.push_back(mpp[digit][i]);
            solve(a, mpp, ans, s, n, idx + 1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string a)
    {
        if (a.empty())
            return {};
        int n = a.length(), idx = 0;
        map<int, vector<char>> mpp;
        mpp[2] = {'a', 'b', 'c'};
        mpp[3] = {'d', 'e', 'f'};
        mpp[4] = {'g', 'h', 'i'};
        mpp[5] = {'j', 'k', 'l'};
        mpp[6] = {'m', 'n', 'o'};
        mpp[7] = {'p', 'q', 'r', 's'};
        mpp[8] = {'t', 'u', 'v'};
        mpp[9] = {'w', 'x', 'y', 'z'};
        vector<string> ans;
        string s = "";
        solve(a, mpp, ans, s, n, idx);
        return ans;
    }
};
// TC - O(4^n)  SC - O(l)