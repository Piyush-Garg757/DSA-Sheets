

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, mini = INT_MAX;
        cin >> n;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
        {
            cin >> a[i];
            mini = min(mini, a[i]);
        }
        long long ans = 0;
        for (long long i = 0; i < n; i++)
        {
            if (a[i] != mini)
                ans = max(ans, a[i] & mini);
        }
        cout << ans << "\n";
    }
}
// TC - O(nlogn)  SC - O(n)