/*Rotated sorted array mein min nikalna hai    Unique elements*/

// Find pivot index and return pivot idx -1
class Solution
{
public:
    int findMin(vector<int> &a)
    {
        int pivot = -1;
        int n = a.size();
        int low = 0, high = n - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] >= a[0])
            {
                pivot = mid;
                low = mid + 1;
            }
            else
                high = mid - 1;
        }
        if (pivot == n - 1)
            return a[0];
        return a[pivot + 1];
    }
};
// TC - O(logn)  SC - O(1)

// Another approach
// Visualise using peak diagram
class Solution
{
public:
    int findMin(vector<int> &a)
    {
        int n = a.size();
        int low = 0, high = n - 1;
        if (a[low] <= a[high]) // already sorted
            return a[low];
        int ans = a[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            if (a[mid] >= a[0])
            {
                low = mid + 1;
            }
            else
            {
                ans = a[mid];
                high = mid - 1;
            }
        }
        return ans;
    }
};
// TC - O(logn)  SC - O(1)

// Another logic
/*
🔹 Step-by-step Logic
low = 0, high = n-1
→ poora array search space
ans = INT_MAX
→ minimum value store karne ke liye

🔁 While (low <= high) loop
🔸 Step 1: mid nikaalo
mid = (low + high) / 2

🔸 Step 2: Check karo kaunsa part sorted hai

✅ Case 1: arr[low] <= arr[mid]
👉 Left part sorted hai
Sorted part ka minimum hamesha arr[low] hota hai
Isliye:
ans = min(ans, arr[low])
Left part check ho gaya → discard it
low = mid + 1

✅ Case 2: arr[low] > arr[mid]
👉 Right part sorted hai
Minimum arr[mid] ho sakta hai
Isliye:
ans = min(ans, arr[mid])
LEft side mein aur chhota mil sakta hai
high = mid - 1
🔚 Loop ke baad
ans ke andar minimum element mil chuka hota hai
return ans*/

#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        // left part sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        // right part sorted
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << findMin(arr);
    return 0;
}
// TC - O(logn)  SC - O(1)

// Duplicates

class Solution
{
public:
    int findMin(vector<int> &a)
    {
        int n = a.size();
        int low = 0, high = n - 1;
        int ans = a[0];
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            ans = min(ans, a[mid]);
            if (a[low] == a[high])
            {
                low++;
                high--;
            }
            else if (a[low] <= a[mid])
            {
                ans = min(ans, a[low]);
                low = mid + 1;
            }
            else
            {
                ans = min(ans, a[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};
// TC - O(logn)  SC - O(1)

// Pucha ho how many times the array has been rotated to uska answer min ka idx ata hai