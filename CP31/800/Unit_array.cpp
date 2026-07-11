https://codeforces.com/problemset/problem/1834/A
/*Unit Array
time limit per test: 1 second
memory limit per test: 256 megabytes
Given an array a of length n, which elements are equal to −1 and 1. 
Let's call the array a good if the following conditions are held at the same time:
1. a1 + a2 + … + an ≥ 0
2. a1 ⋅ a2 ⋅ … ⋅ an = 1
In one operation, you can select an arbitrary element of the array ai and change its value to the opposite. In other words:
- if ai = −1, you can assign the value ai := 1
- if ai = 1, then assign the value ai := −1
Determine the minimum number of operations you need to perform to make the array a good. 
It can be shown that this is always possible.

Input
Each test consists of multiple test cases.
The first line contains a single integer t (1 ≤ t ≤ 500) — the number of test cases.
The description of the test cases follows.
The first line of each test case contains a single integer n (1 ≤ n ≤ 100) — the length of the array a.
The second line of each test case contains n integers a1, a2, …, an (ai = ±1) — the elements of the array a.

Output
For each test case, output a single integer — the minimum number of operations that need to be done to make the array a good.
Example

Input
7
4
-1 -1 1 -1
5
-1 -1 -1 1 1
4
-1 1 -1 1
3
-1 -1 -1
5
1 1 1 1 1
1
-1
2
-1 -1

Output
1
1
0
3
0
1
2*/

// My first approach - Bit over complicated
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, onec = 0, negc = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 1)
                onec++;
            else
                negc++;
        }
        int l = onec - negc;
        int count = 0;
        if (l >= 0 && (l % 2 == 0 || negc == 0)) // saare 1 hain for eg 1 1 1 1 1  ismein l%2!=0 but count should be 0 thats why negc ==0 condition
            count = 0;
        else if (l < 0)
        {
            if (n % 2 == 0)
            {
                count = n / 2 - onec;
            }
            else
            {
                count = n / 2 - onec + 1;
            }
        }
        if ((n - onec - count) % 2) // -1 odd hain to 
            count++;
        cout << count << "\n";
    }
}
// TC - O(n)  SC - O(1)

// simple approach
/*while(negc >onec && negc%2!-0)
{
    count++;
    onec++;
    negc--;
}*/