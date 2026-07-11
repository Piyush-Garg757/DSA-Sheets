/*Triplets unique hone chahiye*/
// aur ismein hum ye dekh rahe hain ki kin triplets ka sum 0 ayega   same approaches kisi target k ke liye bhi lag sakti hain

// Brute force
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];

    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (a[i] + a[j] + a[k] == 0)
                {
                    vector<int> temp = {a[i], a[j], a[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    cout << "Unique triplets:\n";
    for (auto v : st)
    {
        cout << v[0] << " " << v[1] << " " << v[2] << "\n";
    }
    return 0;
}
// TC - O(n^3*logk)  SC - O(k)

// Better approach -> Hashing
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        set<int> hashset;
        for (int j = i + 1; j < n; j++)
        {
            int third = -(a[i] + a[j]);
            if (hashset.find(third) != hashset.end())
            {
                vector<int> temp = {a[i], a[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(a[j]);
        }
    }
    cout << "Unique triplets:\n";
    for (auto v : st)
    {
        cout << v[0] << " " << v[1] << " " << v[2] << "\n";
    }
    return 0;
}
// TC - O(n^2*logk)  SC - O(k)

// Most Optimal sol
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i] == a[i - 1])
            continue;
        int j = i + 1, k = n - 1;
        while (j < k)
        {
            int sum = a[i] + a[j] + a[k];
            if (sum > 0)
            {
                k--;
            }
            else if (sum < 0)
            {
                j++;
            }
            else
            {
                cout << a[i] << " " << a[j] << " " << a[k] << "\n";
                j++;
                k--;
                while (j < k && a[j] == a[j - 1])
                    j++;
                while (j < k && a[k] == a[k + 1])
                    k--;
            }
        }
    }
    return 0;
}
// TC - O(n^2) + O(nlogn) -> O(n^2)  SC - O(n)