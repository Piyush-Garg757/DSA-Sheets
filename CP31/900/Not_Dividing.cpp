https://codeforces.com/problemset/problem/1794/B
/*Not Dividing

You are given an array of n positive integers a1,a2,…,an. In one operation, you can choose any number of the array and add 1 to it.
Make at most 2n operations so that the array satisfies the following property: ai+1 is not divisible by ai, for each i=1,2,…,n−1.
You do not need to minimize the number of operations.

Input
Each test contains multiple test cases. The first line contains the number of test cases t (1≤10^4). The description of the test cases follows.
The first line of each test case contains an integer n (1≤10^4) — the length of the given array.
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤10^9) — the given array.
It is guaranteed that the sum of n over all test cases does not exceed 5⋅10^4.

Output
For each test case, print the answer on a separate line.
In the only line, print n integers — the resulting array a after applying at most 2n operations.
We can show that an answer always exists under the given constraints. If there are multiple answers, print any of them.

Example
Input
3
4
2 4 3 6
3
1 2 3
2
4 2

Output
4 5 6 7
3 2 3
4 2

Note
In the first test case, the array [4,5,6,7] can be achieved by applying 2 operations to the first element, 1 operation to the second element, 3 operations to the third element, and 1 operation to the last element. The total number of operations performed is 7, which is less than the allowed 8 operations in this case.
In the second test case, the array [3,2,3] can be achieved by applying two operations to the first element. Another possible resulting array could be [2,3,5], because the total number of operations does not need to be minimum.
In the third test case, not applying any operations results in an array that satisfies the statement's property. Observe that it is not mandatory to make operations.*/

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
        if (a[0] == 1)
            a[0]++;
        for (int i = 1; i < n; i++)
        {
            if (a[i] == 1)
                a[i]++;
            if (a[i] % a[i - 1] == 0)
            {
                a[i]++;
                if (!((a[i] % 2 == 0 && a[i - 1] % 2 != 0) || (a[i] % 2 != 0 && a[i - 1] % 2 == 0)))
                {
                    a[i]++;
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
// TC - O(n)  SC - O(1)