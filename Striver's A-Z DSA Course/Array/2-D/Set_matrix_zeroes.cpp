// ek matrix hai bas 0 and 1 ki usmein jahan bhi 0 dikh jaye uss puri row aur column ko 0 kar do

// Brute force
// hum kya karenge matrtix ko iterate karenge aur jahan bhi 0 dikh gaya uss row aur column mein jitne bhi 1 honge unhein -1 kar denge        aise karke pure iteration ke baad fir iterate karenge aur jitne bhi -1 mile use 0 kar denge
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
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                for (int j = 0; j < m; j++)
                {
                    if (a[i][j] != 0)
                        a[i][j] = -1;
                }
                for (int i = 0; i < n; i++)
                {
                    if (a[i][j] != 0)
                        a[i][j] = -1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == -1)
                a[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// TC - O(n *m) * O(n + m) + O(n *m) -> O(n^3)  SC - O(1)

// Better solution
// ismein kya karenge ki do arrays banayenge aur ek baar matrix ko iterate karte hue jisrow mein 0 aya uss row ka track rakhenge row array mein aur aise hi column array mein karenge   aise karne ke baad hum matrix ko dobra iterate karenge aur check karenge uss row ya column mein mark to nai kar rakha
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
    int row[n] = {0}, column[m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                row[i] = 1;
                column[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] == 1 || column[j] == 1)
            {
                a[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// TC - O(n*m*2)  SC - O(n) + O(m)

// Optimal solution
// TC to kam kar nahi sakte kyuki 2d array hai   sc ko hi kam kar sakte hain
// ab tak jo do separate arrays le rahe the unhein ab matrix ki first row aur first column lenge
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
    int col0 = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 0)
            {
                a[i][0] = 0;
                if (j != 0)
                {
                    a[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (a[i][0] == 0 || a[0][j] == 0)
            {
                a[i][j] = 0;
            }
        }
    }
    if (a[0][0] == 0)
    {
        for (int j = 0; j < m; j++)
        {
            a[0][j] = 0;
        }
    }
    if (col0 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            a[i][0] = 0;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// TC - O(n^2)  SC - O(1)