/*Prefix to Infix Conversion

You are given a string S of size N that represents the prefix form of a valid mathematical expression. The string S contains only lowercase and uppercase alphabets as operands and the operators are +, -, *, /, %, and ^.Convert it to its infix form.

Example 1:

Input:
*-A/BC-/AKL
Output:
((A-(B/C))*((A/K)-L))
Explanation:
The above output is its valid infix form.*/

// reverse kar do -> postfix to infix lagao -> reverse kar do -> ( ka ) and vice versa
class Solution
{
public:
    string postToInfix(string &s)
    {
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
                temp += "(";
                temp += s2;
                temp += string(1, s[i]);
                temp += s1;
                temp += ")";
                st.push(temp);
            }
        }
        string ans = st.top();
        st.pop();
        return ans;
    }
    string preToInfix(string s)
    {
        // Write your code here
        reverse(s.begin(), s.end());
        string ans = postToInfix(s);
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < ans.length(); i++)
        {
            if (ans[i] == '(')
                ans[i] = ')';
            else if (ans[i] == ')')
                ans[i] = '(';
        }
        return ans;
    }
};
// TC - O(N)  SC - O(n)