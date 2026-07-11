// leaders unko kehte hain jinke right mein saare elements unse chote ho
// humara task hai ek array mein jitne bhi leaders hainunhein collect karke dena hai

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> v;
    int max = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] > max)
        {
            max = a[i];
            v.push_back(a[i]);
        }
    }
    for (int i : v)
        cout << i << " ";
    return 0;
}
// end mein sortedc order mein maange ya reversed order meion maange to vom sab kar sakte hain change
// TC - O(n)  SC - O(n)