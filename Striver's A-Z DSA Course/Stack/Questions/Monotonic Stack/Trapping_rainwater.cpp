/*Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

Example 1:
Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.

Example 2:
Input: height = [4,2,0,3,2,5]
Output: 9*/

// Not optimal but easy to understand - water tabhi ayega jab right ya left mein koi badi building ho to hum right ki aur left ki badi buildings katrack rakhte hain aur ir dono mein se minimum meinnse a[i] minus kkar dete hain vo ek particulaer building ka water aya trapped vala   aise hi har building ke liye karke sum kar dete hain
class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        if (n == 0)
            return 0;
        vector<int> prefixMax(n), suffixMax(n);
        prefixMax[0] = height[0];
        for (int i = 1; i < n; i++)
        {
            prefixMax[i] = max(prefixMax[i - 1], height[i]);
        }
        suffixMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffixMax[i] = max(suffixMax[i + 1], height[i]);
        }
        int water = 0;
        for (int i = 0; i < n; i++)
        {
            water += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        return water;
    }
};
// TC - O(n)  SC - O(n)

// Optimal approach - basically jo pehle separate arrays se kar rahe the vo ab 2 pointer se karenge
class Solution
{
public:
    int trap(vector<int> &a)
    {
        int n = a.size();
        int l = 0, r = n - 1, lmax = INT_MIN, rmax = INT_MIN, ans = 0;
        while (l < r)
        {
            lmax = max(lmax, a[l]);
            rmax = max(rmax, a[r]);
            if (lmax < rmax)
            {
                ans += lmax - a[l++];
            }
            else
                ans += rmax - a[r--];
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)