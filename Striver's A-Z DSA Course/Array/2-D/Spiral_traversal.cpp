// Spiral order mein print karna hai
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number of rows\n";
    cin >> n;
    cout << "Enter the number of columns\n";
    cin >> m;
    int a[n][m];
    cout << "Enter the elements of the matrix\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << "\n";
    int s_row = 0, s_column = 0, e_row = n - 1, e_column = m - 1, count = n * m;
    while (count > 0)
    {
        for (int j = s_column; j <= e_column && count > 0; j++)
        {
            cout << a[s_row][j] << " ";
            count--;
        }
        s_row++;
        for (int i = s_row; i <= e_row && count > 0; i++)
        {
            cout << a[i][e_column] << " ";
            count--;
        }
        e_column--;
        for (int j = e_column; j >= s_column && count > 0; j--)
        {
            cout << a[e_row][j] << " ";
            count--;
        }
        e_row--;
        for (int i = e_row; i >= s_row && count > 0; i--)
        {
            cout << a[i][s_column] << " ";
            count--;
        }
        s_column++;
    }
    return 0;
}
// TC - O(n*m)  SC - O(1)