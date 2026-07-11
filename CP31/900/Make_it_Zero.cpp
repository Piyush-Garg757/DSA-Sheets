https://codeforces.com/problemset/problem/1869/A
/*Make It Zero

During Zhongkao examination, Reycloer met an interesting problem, but he cannot come up with a solution immediately. Time is running out! Please help him.
Initially, you are given an array a consisting of n≥2 integers, and you want to change all elements in it to 0.
In one operation, you select two indices l and r (1≤l≤r≤n) and do the following:
Let s = al ⊕ al+1 ⊕ … ⊕ ar, where ⊕ denotes the bitwise XOR operation;
Then, for all l≤i≤r, replace ai with s.
You can use the operation above in any order at most 8 times in total.
Find a sequence of operations, such that after performing the operations in order, all elements in a are equal to 0. It can be proven that the solution always exists.

Input
The first line of input contains a single integer t (1≤t≤500) — the number of test cases. The description of test cases follows.
The first line of each test case contains a single integer n (2≤n≤100) — the length of the array a.
The second line of each test case contains n integers a1,a2,…,an (0≤ai≤100) — the elements of the array a.

Output
For each test case, in the first line output a single integer k (0≤k≤8) — the number of operations you use.
Then print k lines, in the i-th line output two integers li and ri (1≤li≤ri≤n) representing that you select li and ri in the i-th operation.
Note that you do not have to minimize k. If there are multiple solutions, you may output any of them.

Example
Input
6
4
1 2 3 0
8
3 1 4 1 5 9 2 6
6
1 5 4 1 4 7
5
0 0 0 0 0
7
1 1 9 9 0 1 8
3
100 100 0

Output
1
1 4
2
4 7
1 8
6
1 2
3 4
5 6
1 3
4 6
1 6
0
4
1 2
6 7
3 4
6 7
1
1 2

Note
In the first test case, since 1⊕2⊕3⊕0=0, after performing the operation on segment [1,4], all the elements in the array are equal to 0.
In the second test case, after the first operation, the array becomes equal to [3,1,4,15,15,15,15,6], after the second operation, the array becomes equal to [0,0,0,0,0,0,0,0].
In the third test case:
Operation    a before                a after
1            [1,5––––,4,1,4,7]      → [4,4,4,1,4,7]
2            [4,4,4,1––––,4,7]      → [4,4,5,5,4,7]
3            [4,4,5,5,4,7––––]      → [4,4,5,5,3,3]
4            [4,4,5––––––,5,3,3]    → [5,5,5,5,3,3]
5            [5,5,5,5,3,3––––––]    → [5,5,5,5,5,5]
6            [5,5,5,5,5,5––––––––––––] → [0,0,0,0,0,0]
In the fourth test case, the initial array contains only 0, so we do not need to perform any operations with it.*/

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
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        if (n % 2 == 0)
        {
            cout << "2\n";
            cout << "1 " << n << "\n";
            cout << "1 " << n << "\n";
        }
        else
        {
            cout << "4\n";
            cout << "1 " << n - 1 << "\n";
            cout << "1 " << n - 1 << "\n";
            cout << n - 1 << " " << n << "\n";
            cout << n - 1 << " " << n << "\n";
        }
    }
}
// TC - O(1)  SC - O(1)

// Approach - even length ki array hai to 1 se n do baar operation karte hi kaam ho jayega as firdt time me jo bhi xor ayega sabhi numbers usi se replace ho jayenge and since even numbers hain to next operation mein sabka xor karte hi sab 0 ban jayenge    aise hi odd mein 1 se n-1 pe do baar operation lagao to 1 se n-1 sab 0 ban gaye bas n vala reh gaya ab do baar n-1 se n pe operation lagao   to vo bhi pura 0 ban gaya    main ye hai ki do baar operation lagane pe 0 ban jayega even length ki array pe    odd mein ek element aisa pakad liya jispe 4 baar lag gaya aur uski help se sara ho gaya