/*Shortest Job first

The shortest job first (SJF) or shortest job next, is a scheduling policy that selects the waiting process with the smallest execution time to execute next. Given an array of integers bt[] of size n. Array bt[] denotes the burst time of each process. Calculate the average waiting time of all the processes and return the nearest integer which is smaller or equal to the output.
Note: Consider all process are available at time 0.

Examples:
Input: bt[] = [4,3,7,1,2]
Output: 4
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 4.

Input: bt[] = [1,2,3,4]
Output: 2
Explanation: After sorting burst times by shortest job policy, calculated average waiting time is 2.*/

class Solution
{
public:
    int solve(vector<int> &bt)
    {
        // code here
        sort(bt.begin(), bt.end());
        int wt = 0;
        int ans = 0;
        for (int i = 1; i < bt.size(); i++)
        {
            wt = wt + bt[i - 1];
            ans += wt;
        }
        return ans / bt.size();
    }
};
// TC - O(nlogn)  SC - O(1)