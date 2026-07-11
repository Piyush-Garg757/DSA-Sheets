/*Ek element ke first aur last occurence ka index dena hai
[ 1,3,5,6,7,7,7,7,54,90 ]  ismein 7 ka last occurence is 7 and first occurence is 4   where first occurence is basically lower bound and last occurence is higher bound-1
so yeah we can do it this way but there must be a check wheter the number is ther ein array or not
so for checking that we check if a[lb]==x && lb!=n which ensures that the numner lies in the array*/

// Lower bound - Upper bound
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
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
    int first = lower_bound(arr.begin(), arr.end(), target) - arr.begin();
    if (first == n || arr[first] != target)
    {
        cout << "Target not present in array\n";
        return 0;
    }
    int last = upper_bound(arr.begin(), arr.end(), target) - arr.begin() - 1;
    cout << "First Occurrence Index: " << first << endl;
    cout << "Last Occurrence Index: " << last << endl;
    return 0;
}
// TC - O(logn)  SC - O(1)

// Plain binary search approach

#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cout << "Enter array size: ";
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

    int first = -1, last = -1;
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            first = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    if (first == -1)
    {
        cout << "Target not present in array\n";
        return 0;
    }
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target)
        {
            last = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    cout << "First Occurrence Index: " << first << endl;
    cout << "Last Occurrence Index: " << last << endl;
    return 0;
}
// TC - O(logn)  SC - O(1)

// Ishi mein push sakta hai ki ek number ke kitne occurences hain ek sorted array with duplicates mein    to uske answer last-first+1