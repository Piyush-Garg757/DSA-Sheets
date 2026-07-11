https://codeforces.com/problemset/problem/1903/A
/*Halloumi Boxes
Theofanis is busy after his last contest, as now, he has to deliver many halloumis all over the world. 
He stored them inside n boxes and each of which has some number ai written on it.
He wants to sort them in non-decreasing order based on their number, however, his machine works in a strange way. 
It can only reverse any subarray† of boxes with length at most k.
Find if it's possible to sort the boxes using any number of reverses.
† Reversing a subarray means choosing two indices i and j (where 1 ≤ i ≤ j ≤ n) and changing the array:
a1, a2, …, an
to
a1, a2, …, ai−1, aj, aj−1, …, ai, aj+1, …, an−1, an
The length of the subarray is then:
j − i + 1

Input
The first line contains a single integer t (1 ≤ t ≤ 100) — the number of test cases.
Each test case consists of two lines.
The first line of each test case contains two integers n and k 
(1 ≤ k ≤ n ≤ 100) — the number of boxes and the length of the maximum reverse that Theofanis can make.
The second line contains n integers:
a1, a2, …, an
(1 ≤ ai ≤ 10^9) — the number written on each box.

Output
For each test case, print YES (case-insensitive), if the array can be sorted in non-decreasing order, or NO (case-insensitive) otherwise.
Example

Input
5
3 2
1 2 3
3 1
9 9 9
4 4
6 4 2 1
4 3
10 3 830 14
2 1
3 1

Output
YES
YES
YES
YES
NO

Note
In the first two test cases, the boxes are already sorted in non-decreasing order.
In the third test case, we can reverse the whole array.
In the fourth test case, we can reverse the first two boxes and the last two boxes.
In the fifth test case, it can be shown that it's impossible to sort the boxes.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int b = 0;
        for (int i = 0; i < n - 1   ; i++)
        {
            if (a[i] <= a[i + 1])
                continue;
            else
            {
                b = 1;
                break;
            }
        }
        if (k == 1 && b == 1)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
}
// TC - O(n)  SC - O(1)
 
// Socha kaise  - bubble sort mein yahi to use hota hai its just k is always 2 in that case  to bas k-1 mein nahi ho payega and we have to check whether already sorted or not   so that even if k=1 but it is already sorted then answer should be YES