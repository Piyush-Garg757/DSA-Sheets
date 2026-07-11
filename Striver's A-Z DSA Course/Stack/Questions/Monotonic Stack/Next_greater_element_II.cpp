/*Next Greater Element II

Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Example 1:
Input: nums = [1,2,1]
Output: [2,-1,2]
Explanation: The first 1's next greater number is 2;
The number 2 can't find next greater number.
The second 1's next greater number needs to search circularly, which is also 2.

Example 2:
Input: nums = [1,2,3,4,3]
Output: [2,3,4,-1,4]*/

// Intution - asume kar liya ki same array is array ke end se dobara shuru ho gayi aur nayi jo final array banegi uske last element se same procedure laga diya
class Solution
{
public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for (int i = 2 * n - 1; i >= 0; i--)
        {
            int idx = i % n;
            while (!st.empty() && st.top() <= nums[idx])
                st.pop();
            if (i < n && !st.empty())
                ans[idx] = st.top();
            st.push(nums[idx]);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)