/*Combination Sum II

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.
Each number in candidates may only be used once in the combination.
Note: The solution set must not contain duplicate combinations.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]*/

class Solution
{
public:
    void find(vector<int> &a, int idx, int n, vector<vector<int>> &ans, vector<int> &v, int curr_sum, int k)
    {
        if (curr_sum == k)
        {
            ans.push_back(v);
            return;
        }
        if (curr_sum > k || idx == n)
            return;
        for (int i = idx; i < n; i++)
        {
            if (i > idx && a[i] == a[i - 1]) // so that duplicates na aaye
                continue;
            if (curr_sum + a[i] > k) // no need to continue kyuki  sorted hai to aage vale saare bade hi honge to kyu jana hai aage
                break;
            v.push_back(a[i]);
            find(a, i + 1, n, ans, v, curr_sum + a[i], k);
            v.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int> &a, int k)
    {
        int n = a.size();
        vector<vector<int>> ans;
        vector<int> v;
        sort(a.begin(), a.end());
        find(a, 0, n, ans, v, 0, k);
        return ans;
    }
};
// TC - O(n*2^n)  SC - O(n)
// Learnings - for loop apne aap hi not take handle kar leta hai to agar for loop se kar rahe ho to not take vala call lagana nahi hota            duplicates na aaye vo hatane ke liye ek hi line add karni kaafi hoti hai aur ismein vo add karni thi isiliye for loop se kara aur isiliye hi sort bhi kara ki same vale elements aage peeche aa jaye


// Kuch aur additional cheezein
// agar ek hi vector return karna ho na ki sab to dhyaan rakho bool mein karne se hoga pehla vector milte hi true return karo aur neeche ke calls mein consition lagao ki agar true return kare to vo bhi true return karde   bas itna sa change karne se ek hi return karega na ki sab  -   ye yaad rakhne ki cheez hai ye procedure

bool printS(int ind, vector<int> &ds, int s, int sum, int arr[], int n) {

    if (ind == n) {
        // condition satisfied
        if (s == sum) {
            for (auto it : ds)
                cout << it << " ";
            cout << endl;
            return true;
        }
        // condition not satisfied
        else
            return false;
    }

    ds.push_back(arr[ind]);
    s += arr[ind];

    if (printS(ind + 1, ds, s, sum, arr, n) == true) {
        return true;
    }

    s -= arr[ind];
    ds.pop_back();

    // not pick
    if (printS(ind + 1, ds, s, sum, arr, n) == true)
        return true;

    return false;
}

int main() {

    int arr[] = {1, 2, 1};
    int n = 3;

    vector<int> ds;

    printS(0, ds, 0, 2, arr, n);

    return 0;
}