https://codeforces.com/problemset/problem/1837/A
/*Grasshopper on a Line

You are given two integers x and k.
Grasshopper starts at point 0 on the OX axis.
In one move, it can jump some integer distance that is NOT divisible by k,
either to the left or to the right.
What is the smallest number of moves required for the grasshopper to reach point x?
Also print the moves.
If there are multiple answers, print any of them.

Input
The first line contains a single integer t (1 ≤ t ≤ 1000) — the number of test cases.
Each test case contains two integers x and k (1 ≤ x ≤ 100; 2 ≤ k ≤ 100) —
the target point and the restriction on jumps.

Output
For each test case:
In the first line, print a single integer n — the minimum number of moves.
In the second line, print n integers.
Each integer represents a jump:
- Positive → jump to the right
- Negative → jump to the left

Conditions:
- Each jump must NOT be divisible by k
- Final position after all jumps must be exactly x
- Each jump must be in range [−10^9, 10^9]
It is guaranteed that a solution always exists.

Example

Input
3
10 2
10 3
3 4

Output
2
7 3
1
10
1
3*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x, k;
        cin >> x >> k;

        if (x % k != 0)
        {
            cout << 1 << "\n";
            cout << x << "\n";
        }
        else
        {
            cout << 2 << "\n";
            cout << x - 1 << " " << 1 << "\n";
        }
    }
}
// TC - O(1)  SC - O(1)