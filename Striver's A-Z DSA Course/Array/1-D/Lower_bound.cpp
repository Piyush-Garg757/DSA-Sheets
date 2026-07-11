/*Aisa min index return karna hai ek sorted array mein se such that a[idx]>=x*/

// brute -> iterating whole array

// Optimal sol -> Binary search
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Array size: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int target;
    cout << "Enter target: ";
    cin >> target;
    int low = 0, high = n - 1;
    int ans = n;
    while (low < high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    cout << "Lower bound index of " << target << " is: " << ans << endl;
    return 0;
}
// TC - O(logn)  SC - O(1)
/*
 // STL lower_bound returns iterator to first element >= target
    auto it = lower_bound(arr.begin(), arr.end(), target);
    int index = it - arr.begin(); // convert iterator to index
*/

// Aise hi we can do upper bound in which we want max index >x

// Inhi problems ko floor and ceil ke roop mein bhi de sakte hain in which ceil is smallest number such that a[idx]>=x which is basically lower bound and floor is largest number such that a[idx]<=x which can be done 