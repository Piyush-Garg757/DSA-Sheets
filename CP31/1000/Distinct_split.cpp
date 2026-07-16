https://codeforces.com/problemset/problem/1791/D
/*Distinct Split

Let's denote the f(x) function for a string x as the number of distinct characters that the string contains. For example, f(abc)=3, f(bbbbb)=1, and f(babacaba)=3.
Given a string s, split it into two non-empty strings a and b such that f(a)+f(b) is the maximum possible. In other words, find the maximum possible value of f(a)+f(b) such that a+b=s (the concatenation of string a and string b is equal to string s).

Input
The input consists of multiple test cases. The first line contains an integer t (1≤t≤10^4) — the number of test cases. The description of the test cases follows.
The first line of each test case contains an integer n (2≤n≤2⋅10^5) — the length of the string s.
The second line contains the string s, consisting of lowercase English letters.
It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, output a single integer — the maximum possible value of f(a)+f(b) such that a+b=s.

Example

Input
5
2
aa
7
abcabcd
5
aaaaa
10
paiumoment
4
aazz

Output
2
7
2
10
3

Note
For the first test case, there is only one valid way to split "aa" into two non-empty strings "a" and "a", and f(a)+f(a)=1+1=2.
For the second test case, by splitting "abcabcd" into "abc" and "abcd" we can get the answer f(abc)+f(abcd)=3+4=7, which is the maximum possible.
For the third test case, it doesn't matter how we split the string, the answer will always be 2.*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, ans = 0, idx = -1;
        cin >> n;
        string s;
        cin >> s;
        vector<int> freq_map(26, 0);
        for (int i = 0; i < n; i++)
        {
            if (freq_map[s[i] - 'a'] != 1)
            {
                ans++;
                freq_map[s[i] - 'a'] = 1;
            }
            else
            {
                idx = i;
                break;
            }
        }
        if (idx != -1)
        {
            fill(freq_map.begin(), freq_map.end(), 0);
            for (int i = idx; i < n; i++)
            {
                if (freq_map[s[i] - 'a'] != 1)
                {
                    ans++;
                    freq_map[s[i] - 'a'] = 1;
                }
            }
        }
        cout << ans << "\n";
    }
}
// TC - O(n)  SC - O(1)