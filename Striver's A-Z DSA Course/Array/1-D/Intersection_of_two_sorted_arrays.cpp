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
            i++;
        else if (b[j] < a[i])
            j++;
        else
        {
            c.push_back(a[i]);
            i++;
            j++;
        }
    }
    for (int x : c)
        cout << x << " ";
    cout << "\n";
    return 0;
}
// TC - O(n + m)  SC - SC = O(min(n, m))