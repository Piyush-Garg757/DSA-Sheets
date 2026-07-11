/*Prefix to Postfix Conversion

You are given a string s that represents the prefix form of a valid mathematical expression. Convert it to its postfix form.

Examples:

Input: s = "+AB"
Output: "AB+"
Explanation: In postfix form, operands come first followed by operator.
Prefix to Infix: +AB becomes A + B
Infix to Postfix: A + B becomes AB+

Input: s = "*+ABC"
Output: AB+C*
Explanation:
Prefix to Infix: *+ABC becomes (A + B)*C
Infix to Postfix: (A + B)*C becomes AB+C*

Input: s = "*-A/BC-/AKL"
Output: "ABC/-AK/L-*"
Explanation:
Prefix to infix: *-A/BC-/AKL becomes (A - (B / C)) * ((A / K) - L)
Convert left part to Postfix: (A - (B / C)) becomes ABC/-
Convert right part to Postfix: ((A / K) - L) becomes AK/L-
Combine both with * to get ABC/-AK/L-**/

// Just reverse string or traverse from end to start and order is top1 top2 operator
class Solution
{
public:
    string preToPost(string &s)
    {
        // code here
        reverse(s.begin(), s.end());
        stack<string> st;
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                st.push(string(1, s[i]));
            }
            else
            {
                string temp = "";
                string s1 = st.top();
                st.pop();
                string s2 = st.top();
                st.pop();
                temp += s1;
                temp += s2;
                temp += string(1, s[i]);
                st.push(temp);
            }
        }
        string ans = st.top();
        st.pop();
        return ans;
    }
};
// TC - O(n)  SC - O(n)