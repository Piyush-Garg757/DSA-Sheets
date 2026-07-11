https://codeforces.com/problemset/problem/1805/A
/*We Need the Zero

There is an array a consisting of non-negative integers. You can choose an integer x and denote b_i = a_i ⊕ x for all 1 ≤ i ≤ n, where ⊕ denotes the bitwise XOR operation. Is it possible to choose such a number x that the value of the expression b₁ ⊕ b₂ ⊕ … ⊕ bₙ equals 0?
It can be shown that if a valid number x exists, then there also exists x such that (0 ≤ x < 2⁸).

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 1000). The description of the test cases follows.
The first line of the test case contains one integer n (1 ≤ n ≤ 10³) — the length of the array a.
The second line of the test case contains n integers — array a (0 ≤ a_i < 2⁸).
It is guaranteed that the sum of n over all test cases does not exceed 10³.

Output
For each test case, print the integer x (0 ≤ x < 2⁸) if it exists, or −1 otherwise.

Example

Input
5
3
1 2 5
3
1 2 3
4
0 1 2 3
4
1 2 2 3
1
1

Output
6
0
3
-1
1

Note

In the first test case, after applying the operation with the number 6, the array b becomes [7, 4, 3], and 7 ⊕ 4 ⊕ 3 = 0.
There are other answers in the third test case, such as the number 0.
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k = 0;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            k ^= a[i];
        }
        if (n % 2 == 0 && k != 0)
            cout << "-1\n";
        else
            cout << k << "\n";
    }
}
// TC - O(n)  SC - O(1)