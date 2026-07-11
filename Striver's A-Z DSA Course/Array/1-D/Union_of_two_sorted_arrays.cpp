// Brute force
// ismein set lenge aur dono arrays ko traverse kare hue elements set mein daal denge fir end mein set meein se ek array mein copy kar denge

// Two pointer approach
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the size of array1\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array1\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << "Enter the size of array2\n";
    cin >> m;
    int b[m];
    cout << "Enter the elements of the array2\n";
    for (int i = 0; i < m; i++)
        cin >> b[i];
    vector<int> c;
    int i = 0, j = 0;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            if (c.empty() || c.back() != a[i])
                c.push_back(a[i]);
            i++;
        }
        else if (b[j] < a[i])
        {
            if (c.empty() || c.back() != b[j])
                c.push_back(b[j]);
            j++;
        }
        else // a[i] == b[j]
        {
            if (c.empty() || c.back() != a[i])
                c.push_back(a[i]);
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (c.empty() || c.back() != a[i])
            c.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        if (c.empty() || c.back() != b[j])
            c.push_back(b[j]);
        j++;
    }

    cout << "Merged unique array: ";
    for (int x : c)
        cout << x << " ";
    cout << "\n";

    return 0;
}
// TC - O(n + m)  SC - O(n + m)