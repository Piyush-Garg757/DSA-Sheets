/*Merge Intervals

Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Example 3:
Input: intervals = [[4,7],[1,4]]
Output: [[1,7]]
Explanation: Intervals [1,4] and [4,7] are considered overlapping.*/

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &a)
    {
        sort(a.begin(), a.end());
        vector<vector<int>> ans;
        int sidx = -1, eidx = -1;
        for (int i = 0; i < a.size(); i++)
        {
            if (sidx == -1)
            {
                sidx = a[i][0];
                eidx = a[i][1];
            }
            else if (i != 0 && a[i][0] <= eidx)
            {
                eidx = max(eidx, a[i][1]);
            }
            else
            {
                ans.push_back({sidx, eidx});
                sidx = a[i][0];
                eidx = a[i][1];
            }
        }
        ans.push_back({sidx, eidx});
        return ans;
    }
};
// TC - O(n)  SC - O(n^2)