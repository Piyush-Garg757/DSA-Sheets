https://codeforces.com/problemset/problem/1696/B
/*NIT Destroys the Universe

For a collection of integers S, define mex(S) as the smallest non-negative integer that does not appear in S.
NIT, the cleaver, decides to destroy the universe. He is not so powerful as Thanos, so he can only destroy the universe by snapping his fingers several times.
The universe can be represented as a 1-indexed array a of length n. When NIT snaps his fingers, he does the following operation on the array:
He selects positive integers l and r such that 1≤l≤r≤n. Let w = mex({al, al+1, …, ar}). Then, for all l≤i≤r, set ai to w.
We say the universe is destroyed if and only if for all 1≤i≤n, ai = 0 holds.
Find the minimum number of times NIT needs to snap his fingers to destroy the universe. That is, find the minimum number of operations NIT needs to perform to make all elements in the array equal to 0.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤10^4). Description of the test cases follows.
The first line of each test case contains one integer n (1≤10^5).
The second line of each test case contains n integers a1, a2, …, an (0≤ai≤10^9).
It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, print one integer — the answer to the problem.

Example
Input
4
4
0 0 0 0
5
0 1 2 3 4
7
0 2 3 0 1 2 0
1
1000000000

Output
0
1
2
1

Note
In the first test case, we do 0 operations and all elements in the array are already equal to 0.
In the second test case, one optimal way is doing the operation with l=2, r=5.
In the third test case, one optimal way is doing the operation twice, respectively with l=4, r=4 and l=2, r=6.
In the fourth test case, one optimal way is doing the operation with l=1, r=1.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int steps = 0, last_zero_idx = -1;
        for (long long i = 0; i < n; i++)
        {
            if (a[i] == 0)
            {
                if (i == 0)
                {
                    last_zero_idx = i;
                    continue;
                }
                if (last_zero_idx != -1)
                {
                    if (i - last_zero_idx != 1)
                        steps++;
                }
                else
                    steps++;
                last_zero_idx = i;
            }
        }
        if (last_zero_idx != n - 1)
            steps++;
        steps = min(2, steps);
        cout << steps << "\n";
    }
}
// TC - O(n)  SC - O(1)