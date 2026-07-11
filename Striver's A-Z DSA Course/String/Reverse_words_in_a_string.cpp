/*Reverse Words in a String

Given an input string s, reverse the order of the words.
A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
Return a string of the words in reverse order concatenated by a single space.
Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.*/

class Solution
{
public:
    void reverse(string &s, int i, int j)
    {
        while (i < j)
        {
            swap(s[i], s[j]);
            i++;
            j--;
        }
    }
    void remove_spaces(string &s)
    {
        string temp = "";
        int i = 0, n = s.length();
        while (i < n && s[i] == ' ')
            i++;
        while (i < n)
        {
            if (s[i] != ' ')
            {
                temp.push_back(s[i]);
            }
            else
            {
                temp.push_back(' ');
                while (i < n && s[i] == ' ')
                    i++;
                i--;
                if (i == n - 1)
                    temp.pop_back();
            }
            i++;
        }
        s = temp;
    }
    string reverseWords(string s)
    {
        int n = s.length();
        int i = 0, j = 0;
        while (i < n && j < n)
        {
            while (i < n && s[i] == ' ')
                i++;
            j = i;
            while (j < n && s[j] != ' ')
                j++;
            reverse(s, i, j - 1);
            i = j;
        }
        reverse(s, 0, n - 1);
        remove_spaces(s);
        return s;
    }
};
// TC - O(n)  SC - O(n)
// isi mein agar remove spaces ke liye in place karte hain to
void removeSpaces(string &s)
{
    int n = s.length();
    int i = 0;
    int j = 0;
    // Skip leading spaces
    while (i < n && s[i] == ' ')
        i++;
    while (i < n)
    {
        // Copy current word
        while (i < n && s[i] != ' ')
            s[j++] = s[i++];
        // Skip spaces after the word
        while (i < n && s[i] == ' ')
            i++;
        // Add one space only if another word exists
        if (i < n)
            s[j++] = ' ';
    }
    s.resize(j);
}
// TC - O(n)  SC - O(1)