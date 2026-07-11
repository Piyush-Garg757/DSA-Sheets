/*Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise.

Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.*/

// My First approach
class Solution
{
public:
    bool canJump(vector<int> &a)
    {
        int n = a.size(), i = 0;
        while (i < n)
        {
            int steps = a[i];
            if (steps >= n - i - 1)
                return true;
            int j = i;
            int idx = i, maxi = 0;
            while (steps)
            {
                j++;
                if (a[j] + j - i - 1 >= maxi)
                {
                    maxi = a[j] + j - i - 1;
                    idx = j;
                }
                steps--;
            }
            i = idx;
            if (a[i] == 0)
                return false;
        }
        return false;
    }
};
// TC - O(n^2)  SC - O(1)

// Optimal approach - ek to baat ye hai ki agar array mein 0 na ho to humesha pahuch hi jayenge end tak   aur hum optimal approach mein kya kar rahe haij hum na har element ke liye max_idx nikal rahe hainn jaha tak hum ja sakte hain   agar hum kahi aise idx pe aa jate hain jo max_idx se bada hai to matlab hum uss tak pahuch hi nahi sakte the varna max_idx already us se bada ya barabar hota   to hum false return kar dete  hai nahi to true
class Solution
{
public:
    bool canJump(vector<int> &a)
    {
        int max_idx = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (i > max_idx)
                return false;
            max_idx = max(max_idx, a[i] + i);
        }
        return true;
    }
};
// TC - O(n)  SC - O(1)