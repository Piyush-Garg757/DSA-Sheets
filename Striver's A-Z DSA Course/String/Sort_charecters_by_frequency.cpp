/*Sort Characters By Frequency
Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.
Return the sorted string. If there are multiple answers, return any of them.

Example 1:
Input: s = "tree"
Output: "eert"
Explanation: 'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.

Example 2:
Input: s = "cccaaa"
Output: "aaaccc"
Explanation: Both 'c' and 'a' appear three times, so both "cccaaa" and "aaaccc" are valid answers.

Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:
Input: s = "Aabb"
Output: "bbAa"
Explanation: "bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.*/

class Solution
{
public:
    string frequencySort(string s)
    {
        vector<pair<int, char>> v;
        vector<int> freq(256);
        for (char c : s)
            freq[c]++;
        for (int i = 0; i < 256; i++)
        {
            if (freq[i])
                v.push_back({freq[i], char(i)});
        }
        sort(v.rbegin(), v.rend());
        string ans;
        for (auto x : v)
        {
            ans.append(x.first, x.second);
        }
        return ans;
    }
};
// TC - O(nlogn)  SC - O(n)