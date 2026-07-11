/*Minimum Add to Make Parentheses Valid

A parentheses string is valid if and only if:
It is the empty string,
It can be written as AB (A concatenated with B), where A and B are valid strings, or
It can be written as (A), where A is a valid string.
You are given a parentheses string s. In one move, you can insert a parenthesis at any position of the string.
For example, if s = "()))", you can insert an opening parenthesis to be "(()))" or a closing parenthesis to be "())))".
Return the minimum number of moves required to make s valid.

Example 1:
Input: s = "())"
Output: 1

Example 2:
Input: s = "((("
Output: 3*/

// My first approach
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        stack<char> st;
        int count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                st.push(s[i]);
            }
            else
            {
                if (!st.empty())
                    st.pop();
                else
                    count++;
            }
        }
        while (!st.empty())
        {
            count++;
            st.pop();
        }
        return count;
    }
};
// TC - O(n)  SC - O(n)

// My optimsied approach
class Solution
{
public:
    int minAddToMakeValid(string s)
    {
        int count = 0, count1 = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                count1++;
            }
            else
            {
                if (count1)
                    count1--;
                else
                    count++;
            }
        }
        return count + count1;
    }
};
// TC - O(n)  SC - O(1)