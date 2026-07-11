#include <iostream>
using namespace std;

void reverse_array(int a[], int i, int j)
{
    if (i >= j)
        return;
    a[i] = a[i] + a[j] - (a[j] = a[i]);
    reverse_array(a, i + 1, j - 1);
}
void reverse_array_optimised(int a[], int i, int n)
{
    if (i >= n / 2)
        return;
    a[i] = a[i] + a[n - i - 1] - (a[n - i - 1] = a[i]);
    reverse_array_optimised(a, i + 1, n);
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
    reverse_array_optimised(a, 0, n );
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}