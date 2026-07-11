/*Largest Odd Number in String

You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.

Example 1:
Input: num = "52"
Output: "5"
Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.

Example 2:
Input: num = "4206"
Output: ""
Explanation: There are no odd numbers in "4206".

Example 3:
Input: num = "35427"
Output: "35427"
Explanation: "35427" is already an odd number.*/

class Solution
{
public:
    string largestOddNumber(string s)
    {
        int n = s.length();
        int i = n - 1;
        while (i >= 0)
        {
            if ((s[i] - '0') % 2 != 0)
            {
                return s.substr(0, i + 1);
            }
            i--;
        }
        return "";
    }
};
// TC - O(n)  SC - O(1)