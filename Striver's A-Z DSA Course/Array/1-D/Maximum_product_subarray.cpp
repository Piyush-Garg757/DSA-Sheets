/*Maximum Product Subarray

Given an integer array nums, find a subarray that has the largest product, and return the product.
The test cases are generated so that the answer will fit in a 32-bit integer.
Note that the product of an array with a single element is the value of that element.

Example 1:
Input: nums = [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.

Example 2:
Input: nums = [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.*/

// Most optimal approach
class Solution
{
public:
    int maxProduct(vector<int> &a)
    {
        long long prefix = 1, suffix = 1;
        int n = a.size();
        long long maxi = LLONG_MIN;
        for (int i = 0; i < n; i++)
        {
            if (prefix == 0)
                prefix = 1;
            if (suffix == 0)
                suffix = 1;
            prefix *= a[i];
            suffix *= a[n - i - 1];
            maxi = max(maxi, max(prefix, suffix));
        }
        return maxi;
    }
};
// TC - O(n)  SC - O(1)

/*intution -- agar even nehgatives ya all positives aaye to koi dikat nahi hogi   odd negatives aa gaye to hi dikkat hai bas    uss case mein humari array 2 part mein at jayegi ya to min negative element ke right vsle ka prod ans hoga ya to left side vale ka  dono case ein answer ya to suffix prod ya to prefix prod se hi mil raha hai  to hum iterate karte rahegne aur unkja max lete rahenge    kahi agar 0 aa jaye to reset kar so prefix sufffix ko kyuki 0 ek tarahse ans ko khatamm kar raha hai to use chod dena hai */