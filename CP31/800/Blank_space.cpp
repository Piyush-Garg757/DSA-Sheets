https://codeforces.com/problemset/problem/1829/B
/*Blank Space

You are given a binary array a of n elements, a binary array is an array consisting only of 0s and 1s.
A blank space is a segment of consecutive elements consisting of only 0s.
Your task is to find the length of the longest blank space.

Input

The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.
The first line of each test case contains a single integer n (1 ≤ n ≤ 100) — the length of the array.
The second line of each test case contains n space-separated integers ai (0 ≤ ai ≤ 1) — the elements of the array.

Output

For each test case, output a single integer — the length of the longest blank space.

Example

Input
5
5
1 0 0 1 0
4
0 1 1 1
1
0
3
1 1 1
9
1 0 0 0 1 0 0 0 1

Output
2
1
1
0
3*/

// My first thought
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int i = 0, j = 0, b = 0, start = -1, maxi = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                if (b == 0)
                {
                    start = i;
                    b = 1;
                }
            }
            else
            {
                if (b == 1)
                {
                    maxi = max(maxi, i - start);
                    b = 0;
                }
            }
        }
        if (b == 1)
        {
            maxi = max(maxi, n - start);
        }
        cout << maxi << endl;
    }
}
// TC - O(n)  SC - O(1)

// Less engineered
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
        int maxi = 0, cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x == 0)
            {
                cnt++;
                maxi = max(maxi, cnt);
            }
            else
            {
                cnt = 0;
            }
        }
        cout << maxi << endl;
    }
}
// TC - O(n)  SC - O(1)