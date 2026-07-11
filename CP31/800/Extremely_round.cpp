https://codeforces.com/problemset/problem/1766/A
/*Extremely Round
Let's call a positive integer extremely round if it has only one non-zero digit.
You are given an integer n.
You have to calculate the number of extremely round integers x such that:
1 ≤ x ≤ n

Input
The first line contains one integer t (1 ≤ t ≤ 10^4) — the number of test cases.
Then, t lines follow.
The i-th of them contains one integer n (1 ≤ n ≤ 999999) — the description of the i-th test case.

Output
For each test case, print one integer — the number of extremely round integers x such that:
1 ≤ x ≤ n

Example
Input
5
9
42
13
100
111

Output
9
13
10
19
19*/

#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long p = 1;
        int j = 0;
        while (p * 10 <= n) {
            p *= 10;
            j++;
        }
        int count = 9 * j + (n / p);
        cout << count << "\n";
    }
}
// TC - O(logn)  SC - O(1)