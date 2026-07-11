/* ismein hum binary search hi lagate hain but check karte hain ki left part ssorted hain mid ke ya right kyuki peak diagram banta hai  ismein jis se ye to sure ho jate hain ki ek part to sorted hoga hi*/

// Without duplicate elements
#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &a, int k)
{
    int n = a.size();
    int low = 0, high = n - 1, ans = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == k)
        {
            ans = mid;
            break;
        }
        // left part sorted
        if (a[low] <= a[mid])
        {
            if (a[low] <= k && k <= a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        // right part sorted
        else
        {
            if (a[mid] <= k && k <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    cout << search(a, k);
    return 0;
}
// TC - O(logn)  SC - O(1)

// With duplicates
/*To  duplicates mein problem kaha ayegi
yahan ayegi -> 3 1 2 3 3 3 3 3  ismein a[low]=a[mid]=a[high] to hum condition chech kaise karenge
to humein kaise bhi karke iss condition ko break karna hai

to hum kya karenge um low++ aur high-- kar denge kyuki we know that since all are equal they cant be the answer*/

#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &a, int k)
{
    int n = a.size();
    int low = 0, high = n - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (a[mid] == k)
            return mid;
        // ⭐ duplicates ka special case
        if (a[low] == a[mid] && a[mid] == a[high])
        {
            low++;
            high--;
        }
        else if (a[low] <= a[mid])
        {
            if (a[low] <= k && k < a[mid])
                high = mid - 1;
            else
                low = mid + 1;
        }
        else
        {
            if (a[mid] < k && k <= a[high])
                low = mid + 1;
            else
                high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int k;
    cin >> k;
    cout << search(a, k);
    return 0;
}
// TC - O(log n) but worst case O(n) jab condition har case pe ho   SC - O(1)