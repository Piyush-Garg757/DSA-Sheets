https://codeforces.com/problemset/problem/1438/B
/*Valerii Against Everyone

You're given an array b of length n. Let's define another array a, also of length n, for which ai=2^bi (1≤i≤n).
Valerii says that every two non-intersecting subarrays of a have different sums of elements. You want to determine if he is wrong.
More formally, you need to determine if there exist four integers l1,r1,l2,r2 that satisfy the following conditions:
• 1≤l1≤r1<l2≤r2≤n;
• al1+al1+1+…+ar1 = al2+al2+1+…+ar2.
If such four integers exist, you will prove Valerii wrong. Do they exist?
An array c is a subarray of an array d if c can be obtained from d by deletion of several (possibly zero or all) elements from the beginning and several (possibly zero or all) elements from the end.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤t≤100). Description of the test cases follows.
The first line of every test case contains a single integer n (2≤n≤1000).
The second line of every test case contains n integers b1,b2,…,bn (0≤bi≤10^9).

Output
For every test case, if there exist two non-intersecting subarrays in a that have the same sum, output "YES" on a separate line. Otherwise, output "NO" on a separate line.
Also, note that each letter can be in any case.

Example

Input
2
6
4 3 0 1 2 0
2
2 5

Output
YES
NO

Note
In the first case, a=[16,8,1,2,4,1]. Choosing l1=1, r1=1, l2=2 and r2=6 works because:
16 = 8+1+2+4+1
In the second case, you can verify that there is no way to select two such subarrays.*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());
        bool ans = false;
        for (long long i = 1; i < n; i++)
        {
            if (a[i] == a[i - 1])
            {
                ans = true;
                break;
            }
        }
        if (ans)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
// TC - O(nlogn)  SC - O(n)
// By observation humein ye samajh aya ki agar kuch 2^s ka sum kisi badi 2^ ke equal banana hai to vo need a duplicate number at any point   agar vo nahi hai to nahi ban sakti   aur agar duplicate hain hi to l1=r1  l2=r2  fir to humein overlapping hai ki nahi vo bhi check karne ki need nahi hai    to problem itni si reh gayi ki array mein duplicates hai ki nahi vo check karo