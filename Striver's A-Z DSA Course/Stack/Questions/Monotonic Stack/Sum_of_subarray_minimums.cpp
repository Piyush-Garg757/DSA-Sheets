/*Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.

Example 1:
Input: arr = [3,1,2,4]
Output: 17
Explanation:
Subarrays are [3], [1], [2], [4], [3,1], [1,2], [2,4], [3,1,2], [1,2,4], [3,1,2,4].
Minimums are 3, 1, 2, 4, 1, 1, 2, 1, 1, 1.
Sum is 17.

Example 2:
Input: arr = [11,81,94,43,3]
Output: 444*/

// hum kya karte hain har ek element ka contribution find out karte hain   like vo kaha se kaha tak minimum hoga jab tak uska next max ya prev min na aaye usi range mein minimum vahi hoga na to uss range ki jitni bhi subarray banengi usmein vo add hoga to hum nextsmaller aur prevsmaller array banate hain aur next smaller ka idx and prev smaller ka idx ye humari puri range ban gayi iss range mei humari jitni bhi subarray banengi usi a[i] se * kar do aur ans mein add karte jao
class Solution
{
public:
    vector<int> nextSmallerIndex(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerIndex(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    long long MOD = 1e9 + 7;
    int sumSubarrayMins(vector<int> &a)
    {
        vector<int> nxt = nextSmallerIndex(a);
        vector<int> prev = prevSmallerIndex(a);
        long long ans = 0;
        for (int i = 0; i < a.size(); i++)
        {
            ans = (ans + 1ll * (nxt[i] - i) * (i - prev[i]) * a[i]) % MOD;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)