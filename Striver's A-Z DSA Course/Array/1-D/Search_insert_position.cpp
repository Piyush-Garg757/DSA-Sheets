/*ek array mein element kaha jayega insert karein to vo position nikalni hai which is nothing but lower bound */

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
    cout << ans << endl;
    return 0;
}
// TC - O(logn)  SC - O(1)