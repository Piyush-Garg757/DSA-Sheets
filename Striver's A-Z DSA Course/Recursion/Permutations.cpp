/*Permutations

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]*/

class Solution
{
public:
    void permute(vector<vector<int>> &ans, vector<int> &a, int index)
    {
        if (index == a.size())
        {
            ans.push_back(a);
            return;
        }
        for (int i = index; i < a.size(); i++)
        {
            swap(a[i], a[index]);
            permute(ans, a, index + 1);
            swap(a[i], a[index]);
        }
    }
    vector<vector<int>> permute(vector<int> &a)
    {
        vector<vector<int>> ans;
        permute(ans, a, 0);
        return ans;
    }
};
// TC - O(n*n!)  SC  - O(n!*n)