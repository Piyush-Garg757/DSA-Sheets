https://codeforces.com/problemset/problem/1896/A
/*Jagged Swaps

You are given a permutation† a of size n. You can do the following operation:
Select an index i from 2 to n−1 such that a[i−1] < a[i] and a[i] > a[i+1]. Swap a[i] and a[i+1].
Determine whether it is possible to sort the permutation after a finite number of operations.
A permutation is an array consisting of n distinct integers from 1 to n in arbitrary order. For example, [2,3,1,5,4] is a permutation, but [1,2,2] is not a permutation (2 appears twice in the array) and [1,3,4] is also not a permutation (n = 3 but there is 4 in the array).

---

**Input**
Each test contains multiple test cases. The first line contains the number of test cases t (1 ≤ t ≤ 5000). Description of the test cases follows.
The first line of each test case contains a single integer n (3 ≤ n ≤ 10) — the size of the permutation.
The second line of each test case contains n integers a₁, a₂, …, aₙ (1 ≤ aᵢ ≤ n) — the elements of permutation a.

---

**Output**
For each test case, print "YES" if it is possible to sort the permutation, and "NO" otherwise.
You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as a positive answer).

---

**Example**

Input
6
3
1 2 3
5
1 3 2 5 4
5
5 4 3 2 1
3
3 1 2
4
2 3 1 4
5
5 1 2 3 4

Output
YES
YES
NO
NO
NO
NO

---

**Note**

In the first test case, the permutation is already sorted.
In the second test case, we can choose index i = 2 as 1 < 3 and 3 > 2 to form [1,2,3,5,4]. Then, we can choose index i = 4 as 3 < 5 and 5 > 4 to form [1,2,3,4,5].
In the third test case, it can be proven that it is impossible to sort the permutation.
*/

// My first approach - Brute force
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
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (a[i] > a[i - 1] && a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                i = 0;
            }
        }
        int sorted = 1;
        for (int i = 1; i < n; i++)
        {
            if (a[i] < a[i - 1])
            {
                sorted = 0;
                break;
            }
        }
        if (sorted == 1)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
// TC - O(n^2)  SC - O(1)


// Optimal approach 
#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];

        if (a[0 ] == 1)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}
// TC - O(1)  SC - O(1)
/*🔑 Key Observation

Operation sirf tab allowed hai jab:

a[i-1] < a[i] > a[i+1]   (i.e., peak)

Aur swap hota hai a[i] ↔ a[i+1].

👉 Matlab:

Tum sirf bade element ko right push kar sakte ho (peak hone pe)
Left movement almost restricted hai
🧠 Why 1 matters?
1 smallest hai → kabhi peak nahi ban sakta
Iska matlab:
👉 1 ko actively move nahi kar sakte
👉 Wo sirf indirectly shift ho sakta hai
🚨 Case 1: a[1] != 1 → IMPOSSIBLE

Example:

[2, 1, 3]
1 index 1 pe hai (0-based)
Kya usko index 0 pe laa sakte ho?
❌ Nahi — kyunki 1 kabhi peak nahi banega

👉 So stuck → NO

✅ Case 2: a[1] == 1 → ALWAYS POSSIBLE

Ab magic yaha hai 👇

Intuition:
1 already correct relative position pe hai
Ab baaki numbers (2...n) ko sort karna hai_*/