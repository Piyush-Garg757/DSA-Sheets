/*Maximum Meetings in One Room

Given two arrays s[] and f[], where s[i] denotes the start time and f[i] denotes the finish time of the i-th meeting. There is only one meeting room, find the maximum number of meetings that can be scheduled in the room such that no two selected meetings overlap in time. Return the indices(1-based) of the selected meetings in sorted (increasing) order.
Note: If two meetings can be chosen for the same slot then choose meeting that finishes earlier.

Examples:
Input: s[] = [1, 3, 0, 5, 8, 5], f[] = [2, 4, 6, 7, 9, 9]
Output: [1, 2, 4, 5]
Explanation:
We can attend the 1st meeting from (1 to 2), then the 2nd meeting from (3 to 4), then the 4th meeting from (5 to 7), and the last meeting we can attend is the 5th from (8 to 9). It can be shown that this is the maximum number of meetings we can attend.

Input: s[] = [3] , f[] = [7]
Output: [1]
Explanation:
Since there is only one meeting, we can attend the meeting.*/

class Solution
{
public:
    struct meeting
    {
        int f_time;
        int s_time;
        int idx;
    };
    static bool comp(meeting a, meeting b)
    {
        if (a.f_time == b.f_time)
            return a.idx < b.idx;
        return a.f_time < b.f_time;
    }
    vector<int> maxMeetings(vector<int> &s, vector<int> &f)
    {
        // code here
        vector<meeting> v;
        for (int i = 0; i < s.size(); i++)
        {
            meeting m;
            m.f_time = f[i];
            m.s_time = s[i];
            m.idx = i + 1;
            v.push_back(m);
        }
        sort(v.begin(), v.end(), comp);
        vector<int> ans;
        ans.push_back(v[0].idx);
        int ms = v[0].f_time;
        for (int i = 1; i < s.size(); i++)
        {
            if (v[i].s_time > ms)
            {
                ans.push_back(v[i].idx);
                ms = v[i].f_time;
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
// TC - O(nlogn)  SC - O(n)

// Isko  bina structure banaye bhi kar sakte the 
/*
Method 1: Nested Pair
Store:
{finish_time, {start_time, index}}
vector<pair<int, pair<int, int>>> v;
for (int i = 0; i < s.size(); i++) {
    v.push_back({f[i], {s[i], i + 1}});
}
sort(v.begin(), v.end());
Access:
v[i].first              // finish time
v[i].second.first       // start time
v[i].second.second      // index
Greedy:
vector<int> ans
ans.push_back(v[0].second.second);
int ms = v[0].first;
for (int i = 1; i < v.size(); i++) {
    if (v[i].second.first > ms) {
        ans.push_back(v[i].second.second);
        ms = v[i].first;
    }
}

Method 2: Vector of vectors (not recommended)
vector<vector<int>> v;
v.push_back({f[i], s[i], i + 1});
Then:
v[i][0] // finish
v[i][1] // start
v[i][2] // index
Works, but readability kharab ho jaati hai.

Method 3: Tuple
vector<tuple<int,int,int>> v;
for(int i=0;i<n;i++)
    v.push_back({f[i], s[i], i+1});
sort(v.begin(), v.end());
Access:
get<0>(v[i]) // finish
get<1>(v[i]) // start
get<2>(v[i]) // index

Interview Preference
Main order:
1. struct        ✅ Best readability
2. tuple         ✅ Good
3. nested pair   ⚠️ Common in CP
4. vector<int>   ❌ Avoid if possible*/