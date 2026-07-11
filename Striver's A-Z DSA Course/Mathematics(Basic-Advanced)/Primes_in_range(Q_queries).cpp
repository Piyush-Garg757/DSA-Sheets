/*Primes in a Range

Given two integers l and r, find and return all prime numbers in the range [l, r] (inclusive).

Examples:

Input: l = 1, r = 10
Output: [2, 3, 5, 7]
Explanation:
The prime numbers between 1 and 10 are 2, 3, 5 and 7.

Input: l = 2, r = 5
Output: [2, 3, 5]
Explanation:
The prime numbers between 2 and 5 are 2, 3 and 5.*/

class Solution
{
public:
    vector<int> primeRange(int l, int r)
    {
        // code here
        vector<int> prime(r + 1, 1);
        prime[0] = prime[1] = 0;
        for (int i = 2; i * i <= r; i++)
        {
            if (prime[i])
            {
                for (int j = i * i; j <= r; j += i)
                {
                    prime[j] = 0;
                }
            }
        }
        vector<int> ans;
        for (int i = l; i < r + 1; i++)
        {
            if (prime[i])
                ans.push_back(i);
        }
        return ans;
    }
};
// TC - O(rlog(logr))  SC - O(r)

// Iss problem ka thoda tough version  - ismein Q queries de rakhi hain  matlab q l aur q r aur unn sabke beech ka count return karna hai vector mein
// 10^6 tak ke liye isprime vector bana lenge aur fir usmein prefix sum laga denge   fir har l aur r ke liye answer count hoga isprime[r] - isprime[l]  aur fir unn sabko vector mein push kar denge

#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1000000;
vector<int> prime(MAXN + 1, true);
void sieve()
{
    prime[0] = prime[1] = 0;

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= MAXN; j += i)
                prime[j] = 0;
        }
    }
    for (int i = 1; i <= MAXN; i++)
        prime[i] += prime[i - 1];
}
int main()
{
    sieve();
    int q;
    cin >> q;
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << pref[r] - pref[l - 1] << "\n";
    }
}
// TC - O(q) + O(MAXNlog(log(MAXN))) + O(MAXN)  SC - O(MAXN)