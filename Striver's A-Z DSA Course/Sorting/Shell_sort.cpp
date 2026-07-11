/*Shell Sort = Improved Insertion Sort
Uses gap sequence
In-place
Not stable
Worst case O(n²) Best case O(nlogn)
Space O(1)*/

// only this much info is required   still here is code

#include <bits/stdc++.h>
using namespace std;

void shellSort(vector<int> &arr)
{
    int n = arr.size();

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

int main()
{
    vector<int> arr = {12, 34, 54, 2, 3};
    shellSort(arr);
    for (int x : arr)
        cout << x << " ";
}