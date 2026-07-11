/*No. of subarrays batani hain jinka xor k ho*/

// Brute force vahi generate all subarrays and check
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int xor_sum = 0;
            for (int l = i; l <= j; l++)
            {
                xor_sum ^= arr[l];
            }
            if (xor_sum == k)
                count++;
        }
    }
    cout << "Number of subarrays with XOR " << k << " is: " << count << endl;
    return 0;
}
// TC - O(n^3)  SC - O(1)

// Better sol
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        int xor_sum = 0;
        for (int j = i; j < n; j++)
        {
            xor_sum ^= arr[j];
            if (xor_sum == k)
                count++;
        }
    }
    cout << "Number of subarrays with XOR " << k << " is: " << count << endl;
    return 0;
}
// TC - O(n^2)  SC - O(1)

// Most Optimal sol
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements of the array:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    int xr = 0;
    map<int, int> mpp;
    mpp[xr]++; // initialize with {0:1}
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        xr ^= a[i];
        int x = xr ^ k;
        cnt += mpp[x];
        mpp[xr]++;
    }
    cout << "Number of subarrays with XOR " << k << " is: " << cnt << endl;
    return 0;
}
// TC - O(n)  SC - O(n)