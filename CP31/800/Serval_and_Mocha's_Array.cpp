https : // codeforces.com/problemset/problem/1789/A
/*Serval and Mocha's Array

Mocha likes arrays, and Serval gave her an array consisting of positive integers as a gift.
Mocha thinks that for an array of positive integers a, it is good iff the greatest common divisor of all the elements in a is no more than its length.
And for an array of at least 2 positive integers, it is beautiful iff all of its prefixes whose length is no less than 2 are good.

For example:
• [3, 6] is not good, because gcd(3, 6) = 3 is greater than its length 2.
• [1, 2, 4] is both good and beautiful, because all of its prefixes whose length is no less than 2, which are [1, 2] and [1, 2, 4], are both good.
• [3, 6, 1] is good but not beautiful, because [3, 6] is not good.
Now Mocha gives you the gift array a of n positive integers, and she wants to know whether array a could become beautiful by reordering the elements in a.
It is allowed to keep the array a unchanged.

Input
Each test contains multiple test cases.
The first line contains the number of test cases t (1 ≤ t ≤ 500).
The description of the test cases follows.
The first line of each test case contains a single integer n (2 ≤ n ≤ 100) — the length of array a.
The second line of each test case contains n integers
a1, a2, …, an
(1 ≤ a1, a2, …, an ≤ 10^6) — the elements of array a.

Output
For each test case, print Yes if it is possible to reorder the elements in a to make it beautiful, and print No if not.
You can output Yes and No in any case (for example, strings yEs, yes, Yes and YES will be recognized as a positive response).

Example
Input
6
2
3 6
3
1 2 4
3
3 6 1
3
15 35 21
4
35 10 35 14
5
1261 227821 143 4171 1941

Output
No
Yes
Yes
No
Yes
Yes

Note
In the first test case, neither [3, 6] nor [6, 3] are beautiful, so it's impossible to obtain a beautiful array by reordering the elements in a.
In the second test case, [1, 2, 4] is already beautiful. Keeping the array a unchanged can obtain a beautiful array.*/

#include <bits/stdc++.h>
using namespace std;

int get_hcf(int a, int b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    int c = min(a, b);
    int d = max(a, b);
    return get_hcf(d % c, c);
}
/*int get_hcf(int a, int b)
{
    if (b == 0)
        return a;

    return get_hcf(b, a % b);
}*/
// This is the standard euclidian code for calculating hcf of two numbers it handles max min itself 
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
        bool ans = false;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (get_hcf(a[i], a[j]) <= 2)
                {
                    ans = true;
                    break;
                }
            }
        }
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
// TC - O(n² log(maxA))  SC - O(1)  where maxA shows maximum element of the array

// Intuiton - agar kinhi do numbers ka hcf x hai to usmein agar 3rd numer add karke teen ka hcf nikale to vo x se kam hi ho sakta hai ya x reh sakta hai x se badh katai nahi sakta    iss question mein pehla jo pair banega uski hcf <=2 hi ho sakti hai to aage usme numbers add karte raho 2 ya us se kam hi ayega hcf humesha   matlb hume saare prefix check karne ki need nhi hai bas 1st prefic check kar lo   agar kaise bhi koi do numbers puri  array  mein aise dhudnh liye  jinka hcf 2 ya 1 hai to answer yes hoga   aur agar nahi dhundh paye to answer is no