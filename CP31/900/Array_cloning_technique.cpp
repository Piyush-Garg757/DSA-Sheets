https://codeforces.com/problemset/problem/1665/B
/*Array Cloning Technique

You are given an array a of n integers. Initially there is only one copy of the given array.
You can do operations of two types:
1. Choose any array and clone it. After that there is one more copy of the chosen array.
2. Swap two elements from any two copies (maybe in the same copy) on any positions.
You need to find the minimal number of operations needed to obtain a copy where all elements are equal.

Input
The input consists of multiple test cases. The first line contains a single integer t (1≤t≤10^4) — the number of test cases. Description of the test cases follows.
The first line of each test case contains a single integer n (1≤n≤10^5) — the length of the array a.
The second line of each test case contains n integers a1,a2,…,an (−10^9≤ai≤10^9) — the elements of the array a.
It is guaranteed that the sum of n over all test cases does not exceed 10^5.

Output
For each test case output a single integer — the minimal number of operations needed to create at least one copy where all elements are equal.

Example
Input
6
1
1789
6
0 1 3 3 7 0
2
-1000000000 1000000000
4
4 3 2 1
5
2 5 7 6 3
7
1 1 1 1 1 1 1

Output
0
6
2
5
7
0

Note
In the first test case all elements in the array are already equal, that's why the answer is 0.
In the second test case it is possible to create a copy of the given array. After that there will be two identical arrays:
[ 0 1 3 3 7 0 ]
and
[ 0 1 3 3 7 0 ]
After that we can swap elements in a way so all zeroes are in one array:
[ 0 0– 0– 3 7 0 ]
and
[ 1– 1 3 3 7 3– ]
Now let's create a copy of the first array:
[ 0 0 0 3 7 0 ],
[ 0 0 0 3 7 0 ]
and
[ 1 1 3 3 7 3 ]
Let's swap elements in the first two copies:
[ 0 0 0 0– 0– 0 ],
[ 3– 7– 0 3 7 0 ]
and
[ 1 1 3 3 7 3 ]
Finally, we made a copy where all elements are equal and made 6 operations.
It can be proven that no fewer operations are enough.*/

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
        unordered_map<int, int> mp;
        int cd_count = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            mp[a[i]]++;
            cd_count = max(cd_count, mp[a[i]]);
        }
        if (cd_count == n)
        {
            cout << "0\n";
            continue;
        }
        else
        {
            int steps = 0;
            while (cd_count < n)
            {
                steps++;
                steps += min(cd_count, n - cd_count);
                cd_count = cd_count * 2;
            }
            cout << steps << "\n";
        }
    }
}
// TC - O(n)  SC - O(n)