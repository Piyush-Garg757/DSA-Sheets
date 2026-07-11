/*2D mein peak element vo hai jo apne aage peeche upar neeche har element se bada ho*/

// Brute force -> jar element ke liye upar neeche aage peeche check karo   TC - O(n*m*4)
// Slight optimisation -> find max element in array   TC - O(n*m)

// Optimal sol

class Solution
{
public:
    int findMaxRow(vector<vector<int>> &mat, int col)
    {
        int maxRow = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            if (mat[i][col] > mat[maxRow][col])
            {
                maxRow = i;
            }
        }
        return maxRow;
    }
    vector<int> findPeakGrid(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0, high = m - 1;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = findMaxRow(mat, mid);
            int left, right;
            if (mid - 1 >= 0)
            {
                left = mat[row][mid - 1];
            }
            else
            {
                left = -1;
            }
            if (mid + 1 < m)
            {
                right = mat[row][mid + 1];
            }
            else
            {
                right = -1;
            }
            if (mat[row][mid] > left && mat[row][mid] > right)
            {
                return {row, mid};
            }
            else if (mat[row][mid] < right)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        return {-1, -1};
    }
};
// TC - O(n*logm)  SC - O(1)

/*
🔹 Key Observation (sabse important)

Agar hum ek column fix kar lein

Aur us column ka maximum element dekh lein
→ to upar aur neeche koi bada ho hi nahi sakta
(kyunki wo already column ka max hai)

👉 Isliye humein sirf LEFT & RIGHT compare karna hota hai

🔹 Binary Search kyu columns pe?

Columns bhi sorted nahi hote, but peak property ka benefit milta hai

Left/right comparison se pata lag jaata hai peak kis side hogi

Isse search space har step mein aadha ho jaata hai

🔹 Step-by-Step Logic
1️⃣ Column pe binary search start

low = 0

high = last column index

2️⃣ Mid column choose karo

mid = (low + high) / 2

3️⃣ Mid column ka maximum element nikaalo

Us column ke har row ko scan karo

Jis row pe value sabse badi ho → wahi candidate

Reason:

Upar & neeche se to bada hi hai

4️⃣ Left & Right neighbour check karo

Agar left column exist karta hai → uski value lo

Agar right column exist karta hai → uski value lo

Boundary case mein neighbour ko −1 treat karo

5️⃣ Peak condition check

Agar
current > left AND current > right

👉 Peak mil gaya, answer return

6️⃣ Binary search direction decide karo

Agar right bada hai
→ peak right side mein hogi
→ low = mid + 1

Warna
→ peak left side mein hogi
→ high = mid - 1

7️⃣ Loop tab tak chalao jab tak answer mile
🔹 Why direction always correct hoti hai?

Agar neighbour bada hai → wahan se higher path exist karta hai

Peak hamesha bigger neighbour ki direction mein hoti hai

Isliye binary search safe hai*/