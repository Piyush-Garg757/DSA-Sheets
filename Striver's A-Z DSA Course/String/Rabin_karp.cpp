/*Search Pattern (Rabin-Karp Algorithm)

Given two strings:
A text string in which you want to search.
A pattern string that you are looking for within the text.
Return all positions (0-based indexing) where the pattern occurs as a substring in the text.
Note: If the pattern does not occur in text, return an empty list.

Examples:

Input: text = "geeksforgeeks", pattern = "geek"
Output: [0, 8]
Explanation: The string "geek" occurs twice in text, one starts at index 0 and the other at index 8.

Input: text = "aabaacaadaabaaba", pattern = "aaba"
Output: [0, 9, 12]
*/

// Without rolling hash
class Solution
{
public:
    long long m = 1e9 + 9;
    int p = 7;
    int create_hash(string s)
    {
        int mul = 1;
        long long ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            ans = (ans + 1LL * (s[i] - 'a' + 1) * mul) % m;
            mul = (1LL * mul * p) % m;
        }
        return ans % m;
    }
    vector<int> rabinKarp(string &s, string &q)
    {
        // code here
        vector<int> ans;
        int pattern_hash = create_hash(q);
        for (int i = 0; i <= s.length() - q.length(); i++)
        {
            int hash = create_hash(s.substr(i, q.length()));
            if (hash == pattern_hash)
            {
                if (s.substr(i, q.length()) == q)
                    ans.push_back(i);
            }
        }
        return ans;
    }
};
// TC - O(nm)  SC - O(n)

// With rolling hash
class Solution
{
public:
    const long long MOD = 1e9 + 7;
    const long long P = 31;
    vector<int> rabinKarp(string &text, string &pattern)
    {
        int n = text.size();
        int m = pattern.size();
        vector<int> ans;
        if (m > n)
            return ans;
        vector<long long> power(n + 1);
        power[0] = 1;
        for (int i = 1; i <= n; i++)
            power[i] = (power[i - 1] * P) % MOD;
        vector<long long> pref(n + 1, 0);
        for (int i = 0; i < n; i++)
        {
            pref[i + 1] = (pref[i] + (text[i] - 'a' + 1) * power[i]) % MOD;
        }
        long long patternHash = 0;
        for (int i = 0; i < m; i++)
        {
            patternHash = (patternHash + (pattern[i] - 'a' + 1) * power[i]) % MOD;
        }
        for (int i = 0; i <= n - m; i++)
        {
            long long windowHash = (pref[i + m] - pref[i] + MOD) % MOD;
            if (windowHash == (patternHash * power[i]) % MOD)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
// TC - O(n+m)  SC - O(n+m)