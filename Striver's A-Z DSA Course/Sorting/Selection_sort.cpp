#include <iostream>
using namespace std;

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
    for (int i = 0; i < n - 1; i++)
    {
        int min=i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        a[i] = a[i] + a[min] - (a[min] = a[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}
// TC - O(n2) (best avg worst)