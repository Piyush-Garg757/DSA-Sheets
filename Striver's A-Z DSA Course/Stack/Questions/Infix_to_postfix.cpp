/*Infix to Postfix

You are given a string s representing an infix expression. Convert this infix expression to a postfix expression.
Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Postfix expression: The expression of the form a b op. When an operator is followed for every pair of operands.
Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left, (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

Examples :

Input: s = "a*(b+c)/d"
Output: abc+*d/
Explanation: The expression is a*(b+c)/d. First, inside the brackets, b+c becomes bc+. Now the expression looks like a*(bc+)/d. Next, multiply a with (bc+), so it becomes abc+* . Finally, divide this result by d, so it becomes abc+*d/.

Input: s = "a+b*c+d"
Output: abc*+d+
Explanation: The expression a+b*c+d is converted by first doing b*c -> bc*, then adding a -> abc*+, and finally adding d -> abc*+d+.

Input: s = "(a+b)*(c+d)"
Output: ab+cd+*
Explanation: The expression (a+b)*(c+d) is converted by first doing (a+b) -> ab+, then doing (c+d) -> cd+, and finally the expression ab+*cd+ becomes ab+cd+*. */

class Solution
{
public:
    int priority(char ch)
    {
        if (ch == '^')
            return 3;
        if (ch == '*' || ch == '/')
            return 2;
        if (ch == '+' || ch == '-')
            return 1;
        return -1;
    }
    string infixToPostfix(string &s)
    {
        // code here
        stack<char> st;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
            {
                ans += s[i];
            }
            else
            {
                if (s[i] == '(')
                    st.push(s[i]);
                else if (s[i] == ')')
                {
                    while (!st.empty() && st.top() != '(')
                    {
                        ans += st.top();
                        st.pop();
                    }
                    st.pop();
                }
                else
                {
                    if (st.empty() || st.top() == '(')
                        st.push(s[i]);
                    else
                    {
                        while (!st.empty() && st.top() != '(' && ((priority(s[i]) < priority(st.top())) || (priority(s[i]) == priority(st.top()) && s[i] != '^')))
                        {
                            ans += st.top();
                            st.pop();
                        }
                        st.push(s[i]);
                    }
                }
            }
        }
        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

// ismein ye condition thoda dhyaan rakhne vali hai while (!st.empty() && st.top() != '(' && ((priority(s[i]) < priority(st.top())) || (priority(s[i]) == priority(st.top()) && s[i] != '^')))