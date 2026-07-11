/*Valid Anagram

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

Example 1:
Input: s = "anagram", t = "nagaram"
Output: true

Example 2:
Input: s = "rat", t = "car"
Output: false*/

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        vector<int> map(26, 0);
        if (s.length() != t.length())
            return false;
        for (int i = 0; i < s.length(); i++)
        {
            map[s[i] - 'a']++;
            map[t[i] - 'a']--;
        }
        for (int i = 0; i < 26; i++)
        {
            if (map[i] != 0)
                return false;
        }
        return true;
    }
};
// TC - O(n)  SC - O(1)