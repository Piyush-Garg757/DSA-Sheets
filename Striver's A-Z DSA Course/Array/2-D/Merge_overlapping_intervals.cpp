/* (1, 3) (2, 6) (8, 9) (9, 11) (8, 10) (2, 4) (15, 18) (16, 17)
 ye ye intervals hain inmein se overlapping intervals ko merge karna hai
 jaise (1, 3) (2, 6) (2, 4) -> (1, 6) isi type se saare karne hain*/

// Brute force
/* At first we sort the matrix
to ye aise sort hoga ki 1st ke according hoga aur jinke 1st same honge unke 2nd dekhega uske according karega
 after being sorted -> (1, 3) (2, 4) (2, 6) (8, 9) (8, 10) (9, 11) (15, 18) (16, 17)

Uske baad aage ke sab intervals se compare karo
Agar overlap ho raha hai → merge karo.
Agar overlap nahi ho raha → break
Merged interval ko answer mein daalo.
Jo intervals merge ho gaye, unko skip kar do.
⏱ Time Complexity: O(n²)
📦 Space Complexity: O(n)

overlap condition -> next.start <= current.end

🧪 Dry Run (Step-by-Step)
Step 1:
Current = (1,3)
Compare with:
(2,4) → overlap → merge → (1,4)
(2,6) → overlap → merge → (1,6
(8,9) → no overlap → STOP
✅ Add to result: (1,6)
Step 2:
Next unvisited interval = (8,9)
Compare with:
(8,10) → overlap → merge → (8,10)
(9,11) → overlap → merge → (8,11)
(15,18) → no overlap → STOP
✅ Add to result: (8,11)
Step 3:
Next = (15,18)
Compare with:
(16,17) → overlap → merge → (15,18)
✅ Add to result: (15,18)
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of intervals\n";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    cout << "Enter the intervals\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = a[i][0];
        int end = a[i][1];
        for (int j = i + 1; j < n; j++)
        {
            if (a[j][0] <= end)
            {
                end = max(end, a[j][1]);
                i = j;
            }
            else
                break;
        }
        ans.push_back({start, end});
    }
    cout << "Merged intervals:\n";
    for (auto it : ans)
        cout << it[0] << " " << it[1] << "\n";
    return 0;
}
// TC - O(2*n) + O(nlogn)  SC - O(n)(just for storing answer no extra space)

// Optimal sol
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of intervals\n";
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    cout << "Enter the intervals\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || a[i][0] > ans.back()[1])
        {
            ans.push_back(a[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], a[i][1]);
        }
    }
    cout << "Merged intervals:\n";
    for (auto it : ans)
        cout << it[0] << " " << it[1] << "\n";
    return 0;
}
// TC - O(n)  SC - O(n)