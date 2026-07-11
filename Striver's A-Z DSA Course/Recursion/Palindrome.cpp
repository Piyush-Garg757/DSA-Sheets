#include <iostream>
using namespace std;

bool Check_Palindrome(int a[], int i, int n)
{
    if (i >= n / 2)
        return true;
    if (a[i] != a[n - i - 1])
    {
        return false;
    }
    Check_Palindrome(a, i + 1, n);
}
int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << Check_Palindrome(a, 0, n);
    return 0;
}