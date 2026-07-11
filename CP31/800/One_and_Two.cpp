https://codeforces.com/problemset/problem/1788/A
/*A. One and Two

You are given a sequence a1, a2, ..., an. Each element of the sequence is either 1 or 2.
Find if there exists an integer k such that:
1 ≤ k ≤ n - 1
Product of first k elements = product of remaining elements
i.e.
a1 * a2 * ... * ak = a(k+1) * a(k+2) * ... * an
If multiple such k exist, print the smallest one.

---

Input
First line contains t (number of test cases)
(1 ≤ t ≤ 100)
For each test case:
* First line contains n (2 ≤ n ≤ 1000)
* Second line contains n integers: a1, a2, ..., an
 where each ai is either 1 or 2

---

Output
For each test case:
* Print -1 if no such k exists
* Otherwise print the smallest valid k

---

Example
Input:
3
6
2 2 1 2 1 2
3
1 2 1
4
1 1 1 1

Output:
2
-1
1

---

Explanation:

Test case 1:
k = 2 works because
2 * 2 = 1 * 2 * 1 * 2 = 4

Test case 2:
No valid k exists

Test case 3:
k = 1, 2, 3 all work → smallest is 1
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count_2 = 0, ans = -1;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] == 2)
                count_2++;
        }
        if (count_2 % 2 == 0)
        {
            int count_2_in = 0;
            for (int i = 0; i < n; i++)
            {
                if (a[i] == 2)
                    count_2_in++;
                if (2 * count_2_in == count_2)
                {
                    ans = i + 1;
                    break;
                }
            }
        }
        cout << ans << "\n";
    }
}
// TC - O(n)  SC - O(1)