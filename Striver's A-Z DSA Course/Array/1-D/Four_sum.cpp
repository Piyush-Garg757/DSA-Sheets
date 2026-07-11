/*quadruplets must be unique*/

// Brute force
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of array\n";
    for (int i = 0; i < n; i++)
        cin >> a[i];
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (a[i] + a[j] + a[k] + a[l] == 0)
                    {
                        vector<int> temp = {a[i], a[j], a[k], a[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    cout << "Unique quadruplets with sum 0:\n";
    for (auto v : st)
    {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// TC - O(n^4*logk)  SC - O(k)

// Better sol -> Hashing
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of array\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int target = 0;
    set<vector<int>> st;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            unordered_set<int> hashset;
            for (int k = j + 1; k < n; k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                int fourth = target - sum;

                if (hashset.find(fourth) != hashset.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashset.insert(nums[k]);
            }
        }
    }
    cout << "Unique quadruplets with sum 0:\n";
    for (auto v : st)
    {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// TC - O(n^3*logk)  SC - O(k)

// Most Optimal sol
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    vector<int> nums(n);
    cout << "Enter the elements of array\n";
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int target = 0;
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum == target)
                {
                    ans.push_back({nums[i], nums[j], nums[k], nums[l]});
                    k++;
                    l--;
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }
    cout << "Unique quadruplets with sum 0:\n";
    for (auto v : ans)
    {
        for (int x : v)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// TC - O(n^3) + O(nlogn) -> O(n^3)  SC - O(1)