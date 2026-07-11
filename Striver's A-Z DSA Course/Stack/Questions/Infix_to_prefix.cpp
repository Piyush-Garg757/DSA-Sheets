/*Infix To Prefix Notation

You are given a string s representing an infix expression. Convert this infix expression to a prefix expression.
Infix expression: The expression of the form a op b. When an operator is in between every pair of operands.
Prefix expression: The expression of the form op a b. When an operator comes before its two operands.
Note: The precedence order is as follows: (^) has the highest precedence and is evaluated from right to left. (* and /) come next with left to right associativity, and (+ and -) have the lowest precedence with left to right associativity.

Examples:
Input: s = "a*(b+c)/d"
Output: /*a+bcd
Explaination: The infix expression is a*(b+c)/d. First, inside the brackets, b + c becomes +bc. Now the expression looks like a*(+bc)/d. Next, multiply a with (+bc), so it becomes *a+bc. Finally, divide this result by d, so it becomes /*a+bcd.

Input: s = "(a-b/c)*(a/k-l)"
Output: *-a/bc-/akl
Explaination: The infix expression is (a-b/c)*(a/k-l). First, inside the brackets, b/c becomes /bc and a/k becomes /ak.Now the expression looks like (a-/bc) * (/ak-l).Next, handle the subtractions: a-/bc becomes -a/bc, and /ak-l becomes -/akl. Finally, multiply the two results: (-a/bc * -/akl) becomes *-a/bc-/akl.*/


//  string reverse karo -> reversed string mein ( ko ) se replace karo and vice versa and then infix to postfix vala hi pura karo same to same fir jo string mile use reverse karke return kar do
// ek aur important cheez ^ ki precedence ismein change hogi kyuki ye prefix hai to bas aha conditions mien pehle !='^' tha vahan == ho jayega
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
                        while (!st.empty() && st.top() != '(' && ((priority(s[i]) < priority(st.top())) || (priority(s[i]) == priority(st.top()) && s[i] == '^')))
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
    void reverse(string &s)
    {
        int i = 0, j = s.length() - 1;
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    string infixToPrefix(string &s)
    {
        // code here
        reverse(s);
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
                s[i] = ')';
            else if (s[i] == ')')
                s[i] = '(';
        }
        string ans = infixToPostfix(s);
        reverse(ans);
        return ans;
    }
};
// TC - O(n)  SC - O(n)