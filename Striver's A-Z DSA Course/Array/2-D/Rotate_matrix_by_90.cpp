// Brute force
// har element ko uski correct position pe pllace klarenge ek nayi matrix banake usmein
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    int a[n][n];
    cout << "Enter the elements of the matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\n";
    int b[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b[i][j] = a[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            a[i][j] = b[n - 1 - j][i];
            // a[i][j] = b[j][n-1-i];  is se anticlockwise rotation hota
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// TC - O(n^2)  SC - O(n^2)

// optimal solution
// by observation  pehle matrix ka transp0ose nikal do fir har row ko reverse kar do
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    int a[n][n];
    cout << "Enter the elements of the matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\n";
    // Transpose
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(a[i][j], a[j][i]);
        }
    }
    // Reversing every row
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            swap(a[i][j], a[i][n - 1 - j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// TC - O(n^2)  SC - O(1)