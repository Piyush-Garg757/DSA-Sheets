/*Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:
0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

Example 1:
Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [2,3,0,1,4]
Output: 2*/

// My first approach
class Solution
{
public:
    int jump(vector<int> &a)
    {
        int n = a.size();
        int i = 0, count = 0;
        if (n == 1)
            return 0;
        while (i < n)
        {
            if (a[i] >= n - i - 1)
            {
                count++;
                break;
            }
            int maxi = INT_MIN, idx = -1;
            for (int j = i + 1; j <= a[i] + i; j++)
            {
                if (a[j] + j - i > maxi)
                {
                    maxi = a[j] + j - i;
                    idx = j;
                }
            }
            i = idx;
            count++;
        }
        return count;
    }
};
// TC - O(n^2)  SC - O(1)

// Optimal approach - ek near aur far pointer rakha hai har baar ek range nikalte hian aur jab far last tak pahuhc jaye to jumps return kar do   jaise a(0) ke liye koya fir near to far ke nest pe jayega kyuki next range usi se shuru hogi aur far jayega maximum possible idx tak  aise hi karte karte jumps increase karenge aur end mein return
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int near = 0, far = 0, jumps = 0;
        while (far < nums.size() - 1)
        {
            int farthest = 0;
            for (int i = near; i <= far; i++)
            {
                farthest = max(farthest, i + nums[i]);
            }
            near = far + 1;
            far = farthest;
            jumps++;
        }
        return jumps;
    }
};
// TC - O(n)  SC - O(1)