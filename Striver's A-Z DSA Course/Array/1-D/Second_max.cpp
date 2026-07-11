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
    int max = -1, smax = -1;
    for (int i = 0; i < n; i++)
    {
        if (a[i] > max)
        {
            smax = max;
            max = a[i];
        }
        else if (a[i] < max && a[i] > smax)
            smax = a[i];
    }
    cout << smax;
    return 0;
}