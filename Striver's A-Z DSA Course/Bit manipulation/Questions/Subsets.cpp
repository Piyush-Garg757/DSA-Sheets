/*Subsets

Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]*/

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &a)
    {
        int n = a.size(), no_subsets = 1 << n;
        vector<vector<int>> ans;
        for (int i = 0; i < no_subsets; i++)
        {
            vector<int> v;
            for (int j = 0; j < n; j++)
            {
                if (i & (1 << j))
                    v.push_back(a[j]);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
// TC - O(n*2^n)  SC - O(n*2^n)

// Intution - ismein humne kya kiya hai sabse pehle to total number of subsets hote hain 2^n  to 1<<n hain total number of subsets  fir ab maan lo 3 elements hain to jaise bits mein ban nahi jata 0 0 0    0 0 1    0 1 0     0 1 1  aise hi 8 patterns ban jate hain na to ismein jab jab 1 ayega to hum uss number ko lenge nahi to nahi lenge   to bas 0 se no-subsets -1 tak loop chalaya jo basically iss case mein ye 8 values hongi   fi rusmein check kar rahe hain kaun kaunsi bit set hai  jo jo bit set hai uss uss number ko vector mein daal de rahe hain

// Reccursion approach - har element ke liye do options lo ya na lo to uss pattern ka style yahi hota hai remember it 
class Solution
{
public:
    void find(vector<int> &a, int idx, int n, vector<vector<int>> &ans, vector<int> &v)
    {
        if (idx >= n)
        {
            ans.push_back(v);
            return;
        }
        v.push_back(a[idx]);
        find(a, idx + 1, n, ans, v);
        v.pop_back();
        find(a, idx + 1, n, ans, v);
    }
    vector<vector<int>> subsets(vector<int> &a)
    {
        int n = a.size();
        vector<vector<int>> ans;
        vector<int> v;
        find(a, 0, n, ans, v);
        return ans;
    }
};
// TC - O(n*2^n)  SC - O(n)