https://codeforces.com/problemset/problem/1582/B
/*Luntik and Subsequences

Luntik came out for a morning stroll and found an array a of length n. He calculated the sum s of the elements of the array (s=∑ni=1ai). Luntik calls a subsequence of the array a nearly full if the sum of the numbers in that subsequence is equal to s−1.
Luntik really wants to know the number of nearly full subsequences of the array a. But he needs to come home so he asks you to solve that problem!
A sequence x is a subsequence of a sequence y if x can be obtained from y by deletion of several (possibly, zero or all) elements.

Input
The first line contains a single integer t (1≤t≤1000) — the number of test cases. The next 2⋅t lines contain descriptions of test cases. The description of each test case consists of two lines.
The first line of each test case contains a single integer n (1≤n≤60) — the length of the array.
The second line contains n integers a1,a2,…,an (0≤ai≤10^9) — the elements of the array a.

Output
For each test case print the number of nearly full subsequences of the array.

Example

Input
5
5
1 2 3 4 5
2
1000 1000
2
1 0
5
3 0 2 1 1
5
2 1 0 3 0

Output
1
0
2
4
4

Note
In the first test case, s=1+2+3+4+5=15, only (2,3,4,5) is a nearly full subsequence among all subsequences, the sum in it is equal to 2+3+4+5=14=15−1.
In the second test case, there are no nearly full subsequences.
In the third test case, s=1+0=1, the nearly full subsequences are (0) and () (the sum of an empty subsequence is 0).*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, oc = 0, zc = 0;
        cin >> n;
        vector<long long> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                oc++;
            else if (a[i] == 0)
                zc++;
        }
        cout << (1ll << zc) * oc << "\n";
    }
}
// TC - O(n)  SC - O(1)