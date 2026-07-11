https://codeforces.com/problemset/problem/1866/A
/*Ambitious Kid

Chaneka, Pak Chanek's child, is an ambitious kid, so Pak Chanek gives her the following problem to test her ambition.
Given an array of integers [A1, A2, A3, …, AN].
In one operation, Chaneka can choose one element, then increase or decrease the element's value by 1.
Chaneka can do that operation multiple times, even for different elements.
What is the minimum number of operations that must be done to make it such that:
A1 × A2 × A3 × … × AN = 0 ?

Input
The first line contains a single integer N (1 ≤ N ≤ 10^5).
The second line contains N integers A1, A2, A3, …, AN (−10^5 ≤ Ai ≤ 10^5).

Output
Print an integer representing the minimum number of operations required to make:
A1 × A2 × A3 × … × AN = 0.

Examples

Input
3
2 -6 5
Output
2

Input
1
-3
Output
3

Input
5
0 -1 0 1 0
Output
0

Note
In the first example:
Initially, A1 × A2 × A3 = 2 × (−6) × 5 = −60.

Operations:
Decrease A1 by 1 → A1 = 1 → product = −30
Decrease A1 by 1 → A1 = 0 → product = 0

In the third example:
The product is already 0, so no operations are needed.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int x;
    int ans = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        ans = min(ans, abs(x));
    }
    cout << ans << endl;
}
// TC - O(n)  SC - O(1)