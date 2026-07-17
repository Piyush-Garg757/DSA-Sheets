https://codeforces.com/problemset/problem/1610/B
/*Kalindrome Array

An array [b1,b2,…,bm] is a palindrome if bi=bm+1−i for each i from 1 to m. An empty array is also a palindrome.
An array is called kalindrome if the following condition holds:
It's possible to select some integer x and delete some of the elements of the array equal to x, so that the remaining array (after gluing together the remaining parts) is a palindrome.
Note that you don't have to delete all elements equal to x, and you don't have to delete at least one element equal to x.
For example:
• [1,2,1] is kalindrome because you can simply not delete a single element.
• [3,1,2,3,1] is kalindrome because you can choose x=3 and delete both elements equal to 3, obtaining the array [1,2,1], which is a palindrome.
• [1,2,3] is not kalindrome.
You are given an array [a1,a2,…,an]. Determine if a is kalindrome or not.

Input
The first line contains a single integer t (1≤10^4) — the number of test cases. The description of the test cases follows.
The first line of each test case contains a single integer n (1≤n≤2⋅10^5) — the length of the array.
The second line of each test case contains n integers a1,a2,…,an (1≤ai≤n) — the elements of the array.
It's guaranteed that the sum of n over all test cases won't exceed 2⋅10^5.

Output
For each test case, print "YES" if a is kalindrome and "NO" otherwise. You can print each letter in any case.

Example

Input
4
1
1
2
1 2
3
1 2 3
5
1 4 4 1 4

Output
YES
YES
NO
YES

Note
In the first test case, the array [1] is already a palindrome, so it's a kalindrome as well.
In the second test case, we can choose x=2, delete the second element, and obtain the array [1], which is a palindrome.
In the third test case, it's impossible to obtain a palindrome.
In the fourth test case, you can choose x=4 and delete the fifth element, obtaining [1,4,4,1]. You also can choose x=1, delete the first and the fourth elements, and obtain [4,4,4].*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &a, int x)
{
    int i = 0, j = a.size() - 1;
    while (i < j)
    {
        while (i < j && a[i] == x)
            i++;
        while (i < j && a[j] == x)
            j--;
        if (a[i] != a[j])
            return false;
        i++;
        j--;
    }
    return true;
}

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
            cin >> a[i];
        int i = 0, j = n - 1;
        while (i < j && a[i] == a[j])
        {
            i++;
            j--;
        }
        if (i >= j)
            cout << "YES\n";
        else if (check(a, a[i]) || check(a, a[j]))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
// TC - O(n)  SC - O(1)