// ismein brute force ye ki koi bhi sorting algo lagake sort karo
// better ye hai ki 0 1 aur 2 count kar lo aur fir uss hisaab se array ko fill kar do
// optimal hai 3 pointer approach jismein ek pointer 0 ke liye, ek 2 ke liye aur ek current element ke liye use karte hain
// Dutch flag algorithm 
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int low = 0, mid = 0, high = n - 1;
    while (mid <= high)
    {
        if (!a[mid])
        {
            swap(a[mid], a[low]);
            mid++;
            low++;
        }
        else if (a[mid] == 1)
        {
            mid++;
        }
        else if (a[mid] == 2)
        {
            swap(a[mid], a[high]);
            high--;
        }
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
// TC - O(n)  SC - O(1)