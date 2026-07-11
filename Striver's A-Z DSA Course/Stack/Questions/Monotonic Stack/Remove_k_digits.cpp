/*Remove K Digits

Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

Example 1:
Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.

Example 2:
Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.

Example 3:
Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.*/

class Solution
{
public:
    string removeKdigits(string a, int k)
    {
        stack<char> st;
        for (int i = 0; i < a.length(); i++)
        {
            if (st.empty() || a[i] - '0' >= st.top() - '0' || !k)
                st.push(a[i]);
            else
            {
                while (!st.empty() && k && st.top() - '0' > a[i] - '0')
                {
                    st.pop();
                    k--;
                }
                st.push(a[i]);
            }
        }
        while (k && !st.empty())
        {
            st.pop();
            k--;
        }
        if (st.empty())
            return "0";
        string ans(st.size(), ' ');
        for (int i = ans.length() - 1; i >= 0; i--)
        {
            ans[i] = st.top();
            st.pop();
        }
        int i = 0;
        while (i < ans.length() && ans[i] == '0')
            i++;
        if (i == ans.length())
            return "0";
        else
            return ans.substr(i);
    }
};
// TC - O(n)  SC - O(n)
// Simple intution jab tak bade ilte ja rahe hain push karte jao   jais ehi chota mila to humein chota pehle lana hai to bade ko pop karo aur fir chote ko push karo