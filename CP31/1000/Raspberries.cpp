https://codeforces.com/problemset/problem/1883/C
/*Raspberries

You are given an array of integers a1,a2,…,an and a number k (2≤k≤5). In one operation, you can do the following:
Choose an index 1≤i≤n,
Set ai = ai + 1.
Find the minimum number of operations needed to make the product of all the numbers in the array a1⋅a2⋅…⋅an divisible by k.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤10^4) — the number of test cases. Then follows the description of the test cases.
The first line of each test case contains two integers n and k (2≤n≤10^5, 2≤k≤5) — the size of the array a and the number k.
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10).
It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, output the minimum number of operations needed to make the product of all the numbers in the array divisible by k.

Example
Input
15
2 5
7 3
3 3
7 4 1
5 2
9 7 7 3 9
5 5
5 4 1 2 3
7 4
9 5 1 5 9 5 1
3 4
6 3 6
3 4
6 1 5
3 4
1 5 9
4 4
1 4 1 1
3 4
3 5 3
4 5
8 9 9 3
2 5
1 6
2 5
10 10
4 5
1 6 1 1
2 5
7 7

Output
2
2
1
0
2
0
1
2
0
1
1
4
0
4
3

Note
In the first test case, we need to choose the index i=2 twice. After that, the array will be a=[7,5]. The product of all the numbers in the array is 35.
In the fourth test case, the product of the numbers in the array is 120, which is already divisible by 5, so no operations are needed.
In the eighth test case, we can perform two operations by choosing i=2 and i=3 in any order. After that, the array will be a=[1,6,10]. The product of the numbers in the array is 60.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        long long ans = INT_MAX;
        if (k != 4)
        {
            for (int i = 0; i < n; i++)
            {
                if (a[i] % k == 0)
                {
                    ans = 0;
                    break;
                }
                long long q = a[i] / k;
                ans = min(ans, k * (q + 1) - a[i]);
            }
        }
        else
        {
            int even = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] % 4 == 0)
                {
                    ans = 0;
                    break;
                }
                if (a[i] % 2 == 0)
                    even++;

                long long q = a[i] / 4;
                ans = min(ans, 4 * (q + 1) - a[i]);
            }
            if (ans != 0)
            {
                if (even >= 2)
                    ans = 0;
                else if (even == 1)
                    ans = min(ans, 1LL);
                else
                    ans = min(ans, 2LL);
            }
        }
        cout << ans << "\n";
    }
}
// TC - O(n)  SC - O(1)