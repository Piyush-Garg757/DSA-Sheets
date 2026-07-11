#include <iostream>
using namespace std;

int main()
{
    int n, k;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the value of k\n";
    cin >> k;
    k %= n;
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[(i + k) % n] = a[i];
    }
    for (int i = 0; i < n; i++)
    {
        a[i] = temp[i];
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
// But sabse zyada optimal approach vahi hia ki 3 baar reverse karo