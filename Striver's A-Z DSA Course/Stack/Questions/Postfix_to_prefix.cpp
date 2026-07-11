/*Postfix to Prefix Conversion

You are given a string s that represents the postfix form of a valid mathematical expression. Convert it to its prefix form.

Examples :

Input: s = "ab+"
Output: "+ab"
Explanation: In prefix form, operator comes before operands.
Postfix to Infix: ab+ becomes a + b
Infix to Prefix: a + b becomes +ab

Input: s = "ab+c*"
Output: "*+abc"
Explanation:
Postfix to Infix: ab+ becomes (a + b), then with c gives (a + b)*c
Infix to Prefix: (a + b) becomes +ab, then with c gives *+abc

Input: s = "ABC/-AK/L-*"
Output: "*-A/BC-/AKL"
Explanation:
Postfix to infix: ABC/-AK/L-* becomes (A - (B / C)) * ((A / K) - L)
Convert left part to Prefix: (A - (B / C)) becomes -A/BC
Convert right part to Prefix: ((A / K) - L) becomes -/AKL
Combine both with * to get *-A/BC-/AKL*/

// SAme as post to in but remove for () as they will not be there and order is operator top2 top1
class Solution
{
public:
    string postToPre(string s)
    {
        // code here
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
                temp += string(1, s[i]);
                temp += s2;
                temp += s1;
                st.push(temp);
            }
        }
        string ans = st.top();
        st.pop();
        return ans;
    }
};
// TC - O(n)  SC - O(n)