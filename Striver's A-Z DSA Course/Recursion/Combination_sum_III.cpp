/*Combination Sum III

Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
Only numbers 1 through 9 are used.
Each number is used at most once.
Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.

Example 1:
Input: k = 3, n = 7
Output: [[1,2,4]]
Explanation:
1 + 2 + 4 = 7
There are no other valid combinations.

Example 2:
Input: k = 3, n = 9
Output: [[1,2,6],[1,3,5],[2,3,4]]
Explanation:
1 + 2 + 6 = 9
1 + 3 + 5 = 9
2 + 3 + 4 = 9
There are no other valid combinations.

Example 3:
Input: k = 4, n = 1
Output: []
Explanation: There are no valid combinations.
Using 4 different numbers in the range [1,9], the smallest sum we can get is 1+2+3+4 = 10 and since 10 > 1, there are no valid combination.*/

class Solution
{
public:
    void find(int idx, int size, vector<vector<int>> &ans, vector<int> &v,
              int curr_sum, int n, int k)
    {
        if (v.size() == k)
        {
            if (curr_sum == n)
            {
                ans.push_back(v);
            }
            return;
        }
        if (curr_sum > n || idx == size)
            return;
        for (int i = idx; i < size; i++)
        {
            if (curr_sum + i + 1 > n)
                break;
            v.push_back(i + 1);
            find(i + 1, size, ans, v, curr_sum + i + 1, n, k);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> ans;
        vector<int> v;
        find(0, 9, ans, v, 0, n, k);
        return ans;
    }
};
// TC - O(2^9)  SC - O(n)