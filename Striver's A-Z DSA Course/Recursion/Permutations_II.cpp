/*Permutations II

Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]*/

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
        unordered_set<int> used;
        for (int i = index; i < a.size(); i++)
        {
            if (used.count(a[i]))
                continue;
            used.insert(a[i]);
            swap(a[i], a[index]);
            permute(ans, a, index + 1);
            swap(a[i], a[index]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int> &a)
    {
        vector<vector<int>> ans;
        permute(ans, a, 0);
        return ans;
    }
};
// TC - O(n*n!)  SC - O(n*n!)