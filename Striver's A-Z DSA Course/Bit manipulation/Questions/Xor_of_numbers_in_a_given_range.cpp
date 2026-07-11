/*XOR of a Number Range

Given two integers l and r, find the XOR of elements of the range [l, r].

Example:

Input: l = 4, r = 8
Output: 8
Explanation: The value of (4 ^ 5 ^ 6 ^ 7 ^ 8) = 8.

Input: l = 2, r = 4
Output: 5
Explanation: The value of (2 ^ 3 ^ 4) = 5.

Input: l = 5, r = 9
Output: 5
Explanation: The value of (5 ^ 6 ^ 7 ^ 8 ^ 9) = 5.*/

class Solution
{
public:
    int xr(int n)
    {
        if (n % 4 == 1)
            return 1;
        if (n % 4 == 2)
            return n + 1;
        if (n % 4 == 3)
            return 0;
        return n;
    }
    int findXOR(int l, int r)
    {
        // code here
        return xr(l - 1) ^ xr(r);
    }
};
// TC - O(1)  SC - O(1)
// Observation 1 se n tak elments ka xor karein to jo function mein logic likha hao vo paya gaya   to iss observation ke basis pe sol hai