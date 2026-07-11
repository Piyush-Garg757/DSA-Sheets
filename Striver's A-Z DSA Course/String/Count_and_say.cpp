/*Count and Say

The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the run-length encoding of countAndSay(n - 1).
Run-length encoding (RLE) is a string compression method that works by replacing each maximal group of consecutive identical characters with the concatenation of the length of the group followed by the character itself. For example, to compress the string "3322251" we replace "33" with "23", replace "222" with "32", replace "5" with "15", and replace "1" with "11". Thus the compressed string becomes "23321511".
Given a positive integer n, return the nth element of the count-and-say sequence.

Example 1:
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = RLE of "1" = "11"
countAndSay(3) = RLE of "11" = "21"
countAndSay(4) = RLE of "21" = "1211"

Example 2:
Input: n = 1
Output: "1"
Explanation:
This is the base case.*/

class Solution
{
public:
    string rle(string s)
    {
        int count = 0;
        string ans = "";
        for (int i = 0; i < s.length(); i++)
        {
            if (i == 0)
                count++;
            else
            {
                if (s[i] == s[i - 1])
                    count++;
                else
                {
                    ans.push_back('0' + count);
                    ans.push_back(s[i - 1]);
                    count = 1;
                }
            }
        }
        ans.push_back('0' + count);
        ans.push_back(s[s.length() - 1]);
        return ans;
    }
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        return rle(countAndSay(n - 1));
    }
};
// TC - O(L)  SC - O(L)  where L is the length of final generated string