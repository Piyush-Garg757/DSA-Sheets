/*  arr1 = [1, 3, 5, 7]   arr2 = [0, 2, 6, 8, 9]
  ismein karna kya hai finalyy inko aisa bana dena hai
  arr1 = [0, 1, 2, 3]   arr2 = [5, 6, 7, 8, 9]
*/

// Bruteforce -> using third array

// Optimal sol 1
/*first array ka last ko 2nd ke first se compare karenge aur kyuki aarrays sorted hain to agar 2nd array ka smallest iske largets se chota hai to use ismein hona chahiye na ki usmein so we swap
then we do i-- and j++ and repeat   once we find a point where condition fails, we can say now elements are in their correct arrays and then we sort both the arrays and return them*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the size of array1\n";
    cin >> n;
    int a[n];
    cout << "Enter elements of first array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the size of array2\n";
    cin >> m;
    int b[m];
    cout << "Enter elements of second array\n";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    int i = n - 1, j = 0;
    while (i >= 0 && j < m)
    {
        if (a[i] > b[j])
        {
            swap(a[i], b[j]);
            i--;
            j++;
        }
        else
            break;
    }
    sort(a, a + n);
    sort(b, b + m);
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
    for (int i = 0; i < m; i++)
        cout << b[i] << " ";
    return 0;
}
// TC - O(min(m,n)) + O(nlogn) + O(mlogm)  SC - O(1)

// Optimal sol 2 -> gap method
/*
1. Dono sorted arrays arr1 (size n) aur arr2 (size m) ko mentally ek single array maan lo jiska size n + m hai.
2. Initial gap nikaalo = ceiling of (n + m) / 2.
3. Jab tak gap > 0 ho:
    Left pointer = 0
    Right pointer = left + gap
    Jab tak right < (n + m):
4. Agar left < n aur right < n ho
    → dono elements arr1 me hain, compare arr1[left] aur arr1[right].
    Agar left < n aur right >= n ho
    → left arr1 me aur right arr2 me hai, compare arr1[left] aur arr2[right - n].
    Agar left >= n ho
    → dono elements arr2 me hain, compare arr2[left - n] aur arr2[right - n].
    Agar left wala element bada ho
    → swap kar do.
    Left aur right dono ko 1 step aage badhao.
5. Ek pass complete hone ke baad gap ko half kar do (ceiling ke saath).
6. Jab gap 1 se kam ho jaaye, loop stop kar do.
7. Is process ke baad:
    arr1 me sab chhote elements sorted honge
    arr2 me sab bade elements sorted honge
    bina extra space ke merge ho jaata hai.*/

#include <bits/stdc++.h>
using namespace std;

// swap if element in arr1 is greater than element in arr2
void swapIfGreater(vector<long long> &arr1, vector<long long> &arr2, int ind1, int ind2)
{
    if (arr1[ind1] > arr2[ind2])
    {
        swap(arr1[ind1], arr2[ind2]);
    }
}
int main()
{
    int n, m;
    cout << "Enter size of array1\n";
    cin >> n;
    cout << "Enter size of array2\n";
    cin >> m;
    vector<long long> arr1(n), arr2(m);
    cout << "Enter elements of array1\n";
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    cout << "Enter elements of array2\n";
    for (int i = 0; i < m; i++)
        cin >> arr2[i];
    // length of both arrays combined
    int len = n + m;
    // initial gap
    int gap = (len / 2) + (len % 2);
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // arr1 and arr2
            if (left < n && right >= n)
            {
                swapIfGreater(arr1, arr2, left, right - n);
            }
            // arr2 and arr2
            else if (left >= n)
            {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }
            // arr1 and arr1
            else
            {
                swapIfGreater(arr1, arr1, left, right);
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        // update gap
        gap = (gap / 2) + (gap % 2);
    }
    cout << "Merged arrays:\n";
    for (auto x : arr1)
        cout << x << " ";
    cout << "\n";
    for (auto x : arr2)
        cout << x << " ";
    return 0;
}
// TC - O(log(n+m)*(n+m))  SC - O(1)

// For interviews and all gap method is better