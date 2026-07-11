/*Remove Outermost Parentheses

A valid parentheses string is either empty "", "(" + A + ")", or A + B, where A and B are valid parentheses strings, and + represents string concatenation.
For example, "", "()", "(())()", and "(()(()))" are all valid parentheses strings.
A valid parentheses string s is primitive if it is nonempty, and there does not exist a way to split it into s = A + B, with A and B nonempty valid parentheses strings.
Given a valid parentheses string s, consider its primitive decomposition: s = P1 + P2 + ... + Pk, where Pi are primitive valid parentheses strings.
Return s after removing the outermost parentheses of every primitive string in the primitive decomposition of s.

Example 1:
Input: s = "(()())(())"
Output: "()()()"
Explanation:
The input string is "(()())(())", with primitive decomposition "(()())" + "(())".
After removing outer parentheses of each part, this is "()()" + "()" = "()()()".

Example 2:
Input: s = "(()())(())(()(()))"
Output: "()()()()(())"
Explanation:
The input string is "(()())(())(()(()))", with primitive decomposition "(()())" + "(())" + "(()(()))".
After removing outer parentheses of each part, this is "()()" + "()" + "()(())" = "()()()()(())".

Example 3:
Input: s = "()()"
Output: ""
Explanation:
The input string is "()()", with primitive decomposition "()" + "()".
After removing outer parentheses of each part, this is "" + "" = "".*/

class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        int n = s.length();
        int a = 0;
        int count = 0;
        string ans = "";
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '(')
            {
                if (!a)
                {
                    a = 1;
                }
                else
                {
                    ans.push_back(s[i]);
                    count++;
                }
            }
            else
            {
                count--;
                if (count < 0)
                {
                    a = 0;
                    count = 0;
                }
                else
                {
                    ans.push_back(s[i]);
                }
            }
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)