/*Koko Eating Bananas
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
Return the minimum integer k such that she can eat all the bananas within h hours.

Example 1:
Input: piles = [3,6,7,11], h = 8
Output: 4

Example 2:
Input: piles = [30,11,23,4,20], h = 5
Output: 30

Example 3:
Input: piles = [30,11,23,4,20], h = 6
Output: 23*/

class Solution
{
public:
    int ispossible(vector<int> &a, int h, int k)
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] % k == 0)
                h -= a[i] / k;
            else
                h -= a[i] / k + 1;
        }
        return h >= 0;
    }
    int minEatingSpeed(vector<int> &a, int h)
    {
        int maxi = INT_MIN;
        for (int i = 0; i < a.size(); i++)
        {
            maxi = max(maxi, a[i]);
        }
        int low = 1, high = maxi, ans = -1;
        while (high >= low)
        {
            int mid = low + (high - low) / 2;
            if (ispossible(a, h, mid))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return ans;
    }
};
// TC - O(nlogn)  SC - O(1)