/*Subsets II

Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]

Example 2:
Input: nums = [0]
Output: [[],[0]]*/

class Solution
{
public:
    void find(vector<int> &a, int idx, int n, vector<vector<int>> &ans,
              vector<int> &v)
    {
        ans.push_back(v); // koi sum vum vala constraint nahi hai saare subsets push karne hain isiloye seedhe push kar diya bina koi condition ke 
        for (int i = idx; i < n; i++)
        {
            if (i > idx && a[i] == a[i - 1])
                continue;
            v.push_back(a[i]);
            find(a, i + 1, n, ans, v);
            v.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> ans;
        vector<int> v;
        sort(a.begin(), a.end());
        find(a, 0, n, ans, v);
        return ans;
    }
};
// TC - O(n*2^n)  SC - O(n*2^n)