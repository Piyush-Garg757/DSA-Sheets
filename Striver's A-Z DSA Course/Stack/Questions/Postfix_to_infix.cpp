/*Postfix to Infix Conversion

You are given a string that represents the postfix form of a valid mathematical expression. Convert it to its infix form.

Example:
Input:
ab*c+
Output:
((a*b)+c)
Explanation:
The above output is its valid infix form.*/

class Solution
{
public:
    string postToInfix(string &s)
    {
        // Write your code here
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
};
// TC - O(n)  SC - O(n)