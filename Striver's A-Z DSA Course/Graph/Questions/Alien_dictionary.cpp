/*Alien Dictionary

An alien language uses the lowercase English alphabet, but the order of its letters is unknown. You are given an array of strings words[] that is claimed to be sorted lexicographically according to the rules of the alien language.
Determine the order of the letters in the alien alphabet. If a valid ordering exists, return a string containing all unique letters in lexicographical order according to the alien language. Otherwise, return an empty string.
If a string s1 is lexicographically smaller than a string s2, and the first position at which they differ contains letter a in s1 and letter b in s2, then a must appear before b in the alien alphabet.
Note: The driver code prints true if the returned order is valid; otherwise, it prints false.

Examples:
Input: words[] = ["baa", "abcd", "abca", "cab", "cad"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "bdac".
The pair "baa" and "abcd" suggests 'b' appears before 'a' in the alien dictionary.
The pair "abcd" and "abca" suggests 'd' appears before 'a' in the alien dictionary.
The pair "abca" and "cab" suggests 'a' appears before 'c' in the alien dictionary.
The pair "cab" and "cad" suggests 'b' appears before 'd' in the alien dictionary.
So, 'b' -> 'd' -> 'a' -> 'c' is a valid ordering.

Input: words[] = ["caa", "aaa", "aab"]
Output: true
Explanation: A possible correct order of letters in the alien dictionary is "cab".
The pair "caa" and "aaa" suggests 'c' appears before 'a'.
The pair "aaa" and "aab" suggests 'a' appear before 'b' in the alien dictionary.
So, 'c' -> 'a' -> 'b' is a valid ordering.

Input: words[] = ["ab", "cd", "ef", "ad"]
Output: ""
Explanation: No valid ordering of letters is possible.
The pair "ab" and "ef" suggests "a" appears before "e".
The pair "ef" and "ad" suggests "e" appears before "a", which contradicts the ordering rules.*/


class Solution
{
public:
    string findOrder(vector<string> &a)
    {
        vector<int> present(26, 0);
        int n = 0;
        for (auto &word : a)
        {
            for (auto ch : word)
            {
                if (!present[ch - 'a'])
                {
                    present[ch - 'a'] = 1;
                    n++;
                }
            }
        }
        vector<int> adj[26];
        vector<int> indegree(26, 0);
        for (int i = 1; i < a.size(); i++)
        {
            int j = 0;
            string s1 = a[i - 1];
            string s2 = a[i];
            while (j < s1.size() && j < s2.size() && s1[j] == s2[j])
            {
                j++;
            }
            if (j == s2.size() && j < s1.size())
                return "";
            if (j < s1.size() && j < s2.size())
            {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';
                bool found = false;
                for (auto x : adj[u])
                {
                    if (x == v)
                    {
                        found = true;
                        break;
                    }
                }
                if (!found)
                {
                    adj[u].push_back(v);
                    indegree[v]++;
                }
            }
        }
        queue<int> q;
        for (int i = 0; i < 26; i++)
        {
            if (present[i] && indegree[i] == 0)
                q.push(i);
        }
        string ans;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            ans.push_back(node + 'a');
            for (auto x : adj[node])
            {
                indegree[x]--;
                if (indegree[x] == 0)
                    q.push(x);
            }
        }
        if (ans.size() != n)
            return "";
        return ans;
    }
};
// TC - O(v+e)  SC - O(v+e)

/*1. Problem actually keh kya rahi hai?

Humein kuch words diye hain jo alien language ke order mein sorted hain.

Example:

["baa", "abcd", "abca", "cab", "cad"]

Humein nahi pata alien alphabet mein:

a < b < c < d

hai ya kuch aur.

Humein words ki ordering dekhkar characters ka order discover karna hai.

2. Sabse important observation

Do adjacent words compare karo.

Why adjacent?

Because words already sorted hain. Agar:

word1 < word2

hai, to first position jahan dono different hain, wahi humein direct information deti hai.

Example:

baa
abcd

Compare:

b a a
a b c d
↑

First character hi different:

b vs a

Since "baa" pehle aaya hai:

b < a

So graph mein:

b → a
3. Sirf FIRST different character matter karta hai

Example:

abcd
abca

Compare:

a b c d
a b c a
      ↑

First 3 same hain.

First difference:

d vs a

Therefore:

d → a

Baaki characters se koi relation nahi nikalna.

Ye bahut important hai.

4. Isko graph mein convert karo

Example:

["baa", "abcd", "abca", "cab", "cad"]

Pairs:

Pair 1
baa
abcd

gives:

b → a
Pair 2
abcd
abca

gives:

d → a
Pair 3
abca
cab

gives:

a → c
Pair 4
cab
cad

gives:

b → d

So graph:

b → a
│
↓
d → a → c

Actually relations:

b → a
b → d
d → a
a → c

Now problem Alien Dictionary se Topological Sort problem ban gayi.

5. Topological Sort kyun?

Graph edge:

u → v

ka meaning hai:

Alien alphabet mein u ko v se pehle aana chahiye.

Exactly topological sort ka meaning:

Edge u → v hai to ordering mein u before v.

So graph banane ke baad simply topological sort karo.

6. Kahn's Algorithm use kar sakte hain

Indegree calculate karo.

Example:

b → d
b → a
d → a
a → c

Indegree:

b = 0
d = 1
a = 2
c = 1

Start:

queue = [b]

b nikala:

ans = b

b ke neighbors:

d → indegree 0
a → indegree 1

Queue:

[d]

Then d:

ans = bd

a ka indegree:

2 → 1

Then a:

ans = bda

Then c:

ans = bdac

Valid answer:

bdac
7. n wala tumhara bug

Tum pehle ye kar rahe the:

n = max(n, a[i][j] - 'a' + 1);

Ye number of unique characters nahi hai.

Example:

["db", "b", "cc"]

Characters:

d, b, c

Only 3 unique characters.

But:

d - 'a' + 1 = 4

So tum n = 4 kar dete ho.

Phir tum a ko bhi graph mein consider kar lete ho:

a, b, c, d

But a dictionary mein exist hi nahi karta.

Isliye presence array use karo:

vector<int> present(26, 0);

and:

present[ch - 'a'] = 1;

Then only present characters ko topological sort mein include karo.

8. Duplicate edge ka intuition

Suppose multiple word pairs se same relation milta hai:

a → b

aur later again:

a → b

Graph mein logically ye ek hi constraint hai.

Agar tum do baar:

indegree[b]++;

kar doge, to indegree 2 ho jayega.

But adjacency mein agar edge effectively ek hi baar process hui, to:

indegree[b]--;

sirf ek baar hoga.

Result:

indegree[b] = 1

and b kabhi queue mein nahi jayega.

Isliye duplicate edges avoid karna important hai.

9. Prefix case bhi important hai

Suppose:

["abc", "ab"]

Compare karte hue:

a b c
a b

Second word pehle aa raha hai but actually first word uska prefix hai.

Normal lexicographical ordering mein:

"ab" < "abc"

hona chahiye.

Therefore:

"abc" before "ab"

invalid hai.

So:

if (j == s2.size() && j < s1.size())
    return "";
10. Cycle ka meaning

Suppose relations milti hain:

a → b
b → c
c → a

Meaning:

a < b
b < c
c < a

Impossible.

Graph mein cycle hai.

Kahn's algorithm mein cycle hone par saare nodes process nahi honge.

Therefore:

if (ans.size() != numberOfUniqueCharacters)
    return "";*/