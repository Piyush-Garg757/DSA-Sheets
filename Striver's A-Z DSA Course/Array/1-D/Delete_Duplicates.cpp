// Ek sorted array mein se duplicates delete karne hain aur usi array ko modify karna hai to delete ke baad saare unique elements ko sorted way mein store karna hai usi artay mein aur extra spaces mein 0 fill karna hai   aur finally kitne unique elements hain vo return karna hai

// Brute force
// ek set banate hain kyuki set mein unique values hi store hoti hain
#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array in sorted manner\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    set<int> st;
    for (int i = 0; i < n; i++)
    {
        st.insert(a[i]);
    }
    int index = 0;
    for (auto i : st)
    {
        a[index] = i;
        index++;
    }
    cout << index << "\n";
    for (int i = index; i < n; i++)
    {
        a[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
// TC - O(nlogn + n) kyuki set mein insertion mein n log n lagta hai aur n aage laga
// SC - O(n)

// Optimised
// Two pointer approach
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
    int i = 0, j = 1;
    while (j < n)
    {
        while (a[j] == a[i])
            j++;
        if (a[j] != a[i] && j < n)
        {
            a[++i] = a[j];
        }
    }
    cout << i + 1 << "\n";
    for (int k = i + 1; k < n; k++)
    {
        a[k] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
// TC - O(n)  SC -O(1)