/*Combination Sum

Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.

Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]

Example 3:
Input: candidates = [2], target = 1
Output: []*/

class Solution
{
public:
    void find(vector<int> &a, int idx, int n, vector<vector<int>> &ans,
              vector<int> &v, int curr_sum, int k)
    {
        if (curr_sum == k)
        {
            ans.push_back(v);
            return;
        }
        if (curr_sum > k || idx == n)
            return;
        if (a[idx] <= k)
        {
            v.push_back(a[idx]);
            find(a, idx, n, ans, v, curr_sum + a[idx], k);
            v.pop_back();
        }
        find(a, idx + 1, n, ans, v, curr_sum, k);
    }
    vector<vector<int>> combinationSum(vector<int> &a, int k)
    {
        int n = a.size();
        vector<vector<int>> ans;
        vector<int> v;
        find(a, 0, n, ans, v, 0, k);
        return ans;
    }
};
// TC - O(k*2^n)  SC - O(n)
// Simple intution - pick not pick vala hi hai just same element ko multiple times pick kar sake isiliye usmein idx+1 nahi kiya aur agle mein kiya hai kyuki usmein ise skip kar diya

// Ek aur gyaan ki baat - yahi agar ye puch lete ki total kitnr banenge to
class Solution
{
public:
    int find(vector<int> &a, int idx, int n, vector<int> &v, int curr_sum,
             int k)
    {
        if (curr_sum == k)
        {
            return 1;
        }
        if (curr_sum > k || idx == n)
            return 0;
        v.push_back(a[idx]);
        int l = find(a, idx, n, v, curr_sum + a[idx], k);
        v.pop_back();
        int r = find(a, idx + 1, n, v, curr_sum, k);
        return l + r;
    }
    int combinationSum4(vector<int> &a, int k)
    {
        int n = a.size();
        vector<int> v;
        return find(a, 0, n, v, 0, k);
    }
};