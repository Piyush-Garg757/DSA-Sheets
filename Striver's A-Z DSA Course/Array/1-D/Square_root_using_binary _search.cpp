int sqrtBS(int x)
{
    if (x == 0 || x == 1)
        return x;
    long long low = 1, high = x, ans = 0;
    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        if (mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
// TC - O(Logn)  SC - O(1)

// Ishi mein pucha ho nth root to

#include <bits/stdc++.h>
using namespace std;

// returns:
// 1 -> mid^n == m
// 0 -> mid^n < m
// 2 -> mid^n > m
int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2; // overflow / greater case
    }
    if (ans == m)
        return 1;
    return 0;
}
int NthRoot(int n, int m)
{
    int low = 1, high = m;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int midN = func(mid, n, m);
        if (midN == 1)
        {
            return mid;
        }
        else if (midN == 0)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}
int main()
{
    int n, m;
    cin >> n >> m;
    cout << NthRoot(n, m);
    return 0;
}
// TC - O(n*logn)  SC - O(1)