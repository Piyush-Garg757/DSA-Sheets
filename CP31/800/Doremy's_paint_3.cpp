https : // codeforces.com/problemset/problem/1890/A
/*Doremy's Paint 3
An array b1, b2, …, bn of positive integers is good if all the sums of two adjacent elements are equal to the same value. More formally, the array is good if there exists a k such that
b1 + b2 = b2 + b3 = … = bn−1 + bn = k.
Doremy has an array a of length n. Now Doremy can permute its elements (change their order) however she wants. Determine if she can make the array good.

Input
The input consists of multiple test cases.
The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.
The description of the test cases follows.
The first line of each test case contains a single integer n (2 ≤ n ≤ 100) — the length of the array a.
The second line of each test case contains n integers a1, a2, …, an (1 ≤ ai ≤ 10^5).
There are no constraints on the sum of n over all test cases.

Output
For each test case, print "Yes" (without quotes), if it is possible to make the array good, and "No" (without quotes) otherwise.
You can output the answer in any case (upper or lower). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive responses.

Example
Input
5
2
8 9
3
1 1 2
4
1 1 4 5
5
2 3 3 3 3
4
100000 100000 100000 100000

Output
Yes
Yes
No
No
Yes

Note
In the first test case, [8, 9] and [9, 8] are good.
In the second test case, [1, 2, 1] is good because
a1 + a2 = a2 + a3 = 3.
In the third test case, it can be shown that no permutation is good.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int n1 = -1, n2 = -1;
        int countn1 = 0, countn2 = 0;
        bool ans = true;
        for (int i = 0; i < n; i++)
        {
            if (n1 == -1)
            {
                n1 = a[i];
                countn1 = 1;
            }
            else if (n2 == -1 && a[i] != n1)
            {
                n2 = a[i];
                countn2 = 1;
            }
            else if (a[i] != n2 && a[i] != n1)
            {
                ans = false;
                break;
            }
            else if (a[i] == n1)
                countn1++;
            else if (a[i] == n2)
                countn2++;
        }
        if (ans != false && ((max(countn1, countn2) - min(countn1, countn2) <= 1) || (countn1 == n) || (countn2 == n)))
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }
}
// TC - O(n)  SC - O(1)

// Intution   a1+a2 = a2+a3  this means a1 = a3   aise hi sare alternate number barabar hie chahiye to do ya us se kam hi unique numbers hone chahiye aur baaki consitions test case se observe karke