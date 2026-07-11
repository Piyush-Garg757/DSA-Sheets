/*Insert Interval

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.
Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).
Return intervals after the insertion.
Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].*/

// Not an optimal approach but works fine
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &a)
    {
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
    vector<vector<int>> insert(vector<vector<int>> &a, vector<int> &newInterval)
    {
        a.push_back(newInterval);
        sort(a.begin(), a.end());
        return merge(a);
    }
};
// TC - O(nlogn)  SC - O(n)

// Khud ke dimaag se banaya sol - new interval kaha add hona hai vo find karo kyuki array already sorted hai   aur fir merge vala code chala do     ab kaha pe insert hoga  isme dimaag lagaya   3 hi position ho sakti hain jo ki vondiyions mein likhi hain   unmein se kaunsi mein fit hota hai ye find kara
class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &a)
    {
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
    vector<vector<int>> insert(vector<vector<int>> &a, vector<int> &newInterval)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (newInterval[0] <= a[i][0] && newInterval[1] >= a[i][0])
            {
                a[i][0] = newInterval[0];
                a[i][1] = max(a[i][1], newInterval[1]);
                newInterval[0] = newInterval[1] = -1;
                break;
            }
            else if (newInterval[0] < a[i][0] && newInterval[1] < a[i][0])
            {
                a.insert(a.begin() + i, newInterval);
                newInterval[0] = newInterval[1] = -1;
                break;
            }
            else if (newInterval[0] <= a[i][1])
            {
                a[i][1] = max(a[i][1], newInterval[1]);
                newInterval[0] = newInterval[1] = -1;
                break;
            }
        }
        if (newInterval[0] != -1)
        {
            a.push_back(newInterval);
            return a;
        }
        return merge(a);
    }
};
// TC - O(n)  SC - O(n)

// Standard approach -  understandable
class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        while (i < n && intervals[i][1] < newInterval[0])
        {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < n && intervals[i][0] <= newInterval[1])
        {
            newInterval[0] = min(intervals[i][0], newInterval[0]);
            newInterval[1] = max(intervals[i][1], newInterval[1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i < n)
        {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)