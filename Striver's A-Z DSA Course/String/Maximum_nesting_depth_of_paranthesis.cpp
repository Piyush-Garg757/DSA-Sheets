/*Maximum Nesting Depth of the Parentheses

Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

Example 1:
Input: s = "(1+(2*3)+((8)/4))+1"
Output: 3
Explanation:
Digit 8 is inside of 3 nested parentheses in the string.

Example 2:
Input: s = "(1)+((2))+(((3)))"
Output: 3
Explanation:
Digit 3 is inside of 3 nested parentheses in the string.

Example 3:
Input: s = "()(())((()()))"
Output: 3*/

class Solution
{
public:
    int maxDepth(string s)
    {
        int maxi = 0, count = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(')
            {
                count++;
                maxi = max(maxi, count);
            }
            else if (s[i] == ')')
            {
                count--;
            }
        }
        return maxi;
    }
};
// TC - O(n)  SC - O(1)