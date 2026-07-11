#include <iostream>
#include <vector>
using namespace std;
void merge(int a[], int low, int mid, int high)
{
    vector<int> v;
    int left = low, right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (a[left] < a[right])
            v.push_back(a[left++]);
        else
            v.push_back(a[right++]);
    }
    while (left <= mid)
        v.push_back(a[left++]);
    while (right <= high)
        v.push_back(a[right++]);
    for (int i = low; i <= high; i++)
    {
        a[i] = v[i - low];
    }
}
void mergesort(int a[], int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergesort(a, low, mid);
    mergesort(a, mid + 1, high);
    merge(a, low, mid, high);
}
int main()
{
    int n;
    cout << "Enter the number of elements in the array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    mergesort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
// TC - O(nlogn) (avg worst best)  SC - O(n)
// log n for breaking and n for merging