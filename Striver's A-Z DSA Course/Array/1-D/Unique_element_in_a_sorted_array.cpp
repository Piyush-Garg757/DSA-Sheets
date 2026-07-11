/*Ek sorted array mein ek element hoga jo ek baar aa raha hoga baaki sab 2 baar a raahe honge uss ek element ko batana hai*/

// Brute force XOR -> O(n)

// Optimal -> Binary Search
/* Elements ->1 1 2 2 3 4 4 5 5
   Indices  ->0 1 2 3 4 5 6 7 8
   Parity   ->e o e o e o e o e
   To humne ye dekha ki single element se pehle pairs (e,o) aise aa rahe the but uske baad (o,e) aise aa rahe hain  ishhi cheez ki help lenge   
   To hum ye keh sakte hain ki jab pairs (e,o) follow karenge tab humara answer right side mein hoga aur jab (o,e) ke pair mein aa rahe hain tab humara answer left side mein hoga*/

class Solution
{
public:
    int singleNonDuplicate(vector<int> &a)
    {
        int n = a.size();
        if (n == 1)
            return a[0];
        if (a[0] != a[1])
            return a[0];
        if (a[n - 1] != a[n - 2])
            return a[n - 1];
        int low = 1, high = n - 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] != a[mid - 1] && a[mid] != a[mid + 1])
                return a[mid];
            // Check for left side and indication to move to right side
            if (mid % 2 == 1 && a[mid] == a[mid - 1] ||
                mid % 2 == 0 && a[mid] == a[mid + 1])
                low = mid + 1;
            // Else move to left side
            else
                high = mid - 1;
        }
        return -1;
    }
};
// TC - O(logn)  SC - O(1)