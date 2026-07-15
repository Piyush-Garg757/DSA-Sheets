

#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (long long i = 0; i < n; i++)
            cin >> a[i];
        sort(a.rbegin(), a.rend());
        vector<long long> ans;
        long long i = 0;
        while (ans.size() != n)
        {
            while (i < n && a[i] <= a[i + 1])
                i++;
            long long j = (i + 1) % n;
            while (a[j] <= 0)
                j = (j + 1) % n;
            long long diff = a[i] - a[j];
            if (diff % k == 0)
                a[i] -= k * (diff / k);
            else
                a[i] -= k * ((diff / k) + 1);
            if (a[i] <= 0)
                ans.push_back(i + 1);
            i = j;
        }
        for (long long i = 0; i < n; i++)
            cout << ans[i] << " ";
        cout << "\n";
    }
}
// TC - O(nlogn)  SC - O(1)