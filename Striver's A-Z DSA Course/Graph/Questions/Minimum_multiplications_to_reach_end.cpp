/*Minimum Multiplications to reach End

Given two integers, start and end, along with an array of integers arr[]. In one operation, you can multiply the current value by any element from arr[], and then take the result modulo 1000 to obtain a new value.
Find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Examples :
Input: arr[] = [2, 5, 7], start = 3, end = 30
Output: 2
Explanation:
Step 1: 3*2 = 6 % 1000 = 6
Step 2: 6*5 = 30 % 1000 = 30

Input: arr[] = [3, 4, 65], start = 7, end = 175
Output: 4
Explanation:
Step 1: 7 * 3 = 21 % 1000 = 21
Step 2: 21 * 3 = 63 % 1000 = 63
Step 3: 63 * 65 = 4095 % 1000 = 95
Step 4: 95 * 65 = 6175 % 1000 = 175

Input: arr[] = [2, 4], start = 3, end = 5
Output: -1
Explanation: Starting from 3 and multiplying by 2 or 4 always produces even numbers after the first step. Since 5 is odd, it can never be reached.*/

class Solution
{
public:
    int minSteps(vector<int> &a, int start, int end)
    {
        // code here
        queue<pair<int, int>> q;
        vector<int> visited(1000, 0);
        q.push({0, start});
        visited[start] = 1;
        while (!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second;
            q.pop();
            if (node == end)
                return steps;
            for (int i = 0; i < a.size(); i++)
            {
                int newval = (node * a[i]) % 1000;
                if (!visited[newval])
                {
                    visited[newval] = 1;
                    q.push({steps + 1, newval});
                }
            }
        }
        return -1;
    }
};
// TC - O(1000*a.size())  SC - O(1000)