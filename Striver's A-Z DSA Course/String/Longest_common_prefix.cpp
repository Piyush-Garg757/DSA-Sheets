/*Longest Common Prefix

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.*/

class Solution
{
public:
    string longestCommonPrefix(vector<string> &a)
    {
        int n = a.size();
        string s = a[0];
        for (int i = 1; i < n; i++)
        {
            int j = 0;
            while (j < s.length() && j < a[i].length())
            {
                if (s[j] == a[i][j])
                {
                    j++;
                }
                else
                {
                    break;
                }
            }
            s = s.substr(0, j);
            if (s.length() == 0)
                return "";
        }
        return s;
    }
};
// TC - O(n*m)  SC - O(1)