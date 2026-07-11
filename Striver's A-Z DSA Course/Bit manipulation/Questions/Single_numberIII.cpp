/*Single Number III

Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.
You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.

Example 1:
Input: nums = [1,2,1,3,2,5]
Output: [3,5]
Explanation:  [5, 3] is also a valid answer.

Example 2:
Input: nums = [-1,0]
Output: [-1,0]

Example 3:
Input: nums = [0,1]
Output: [1,0]*/

class Solution
{
public:
    vector<int> singleNumber(vector<int> &a)
    {
        long long xr = 0, n = a.size();
        for (int i = 0; i < n; i++)
            xr ^= a[i];
        long long mask = xr & (-xr); // extracting rightmost set bit kyuki vo ek 0 aur 1 se aai hogi to vo numbersko differentiate karne ke liye use ho sakti hai
        int xr1 = 0, xr2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] & mask)
                xr1 ^= a[i];
            else
                xr2 ^= a[i];
        }
        return {xr1, xr2};
    }
};
// TC - O(n)  SC - O(1)