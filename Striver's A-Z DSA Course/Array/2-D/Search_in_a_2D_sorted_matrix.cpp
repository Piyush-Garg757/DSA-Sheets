// Matrix sorted hai matlab ek row ka last number agli row ke first number se chota hai
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n * m - 1;

        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int row = mid / m;
            int col = mid % m;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] < target)
                low = mid + 1;
            else
                high = mid - 1;
        }
        return false;
    }
};
// TC - O(log(n+m))  SC - O(1)

// rows aur columns dono sorted hain

/*Intution
1 2 3
2 4 5
4 6 8

sarting from upper 3 as it is largest in row but smallest in column so if we want to find 6 we ca eliminate this row as largest is smaller than k  similarly we can eliminate columns*/

class Solution
{
public:
    vector<int> searchMatrix(vector<vector<int>> &mat, int target)
    {
        int n = mat.size();
        int m = mat[0].size();

        int row = 0;
        int col = m - 1;

        while (row < n && col >= 0)
        {
            if (mat[row][col] == target)
            {
                return {row, col};
            }
            else if (mat[row][col] < target)
            {
                row++;
            }
            else
            {
                col--;
            }
        }
        return {-1, -1}; 
    }
};
// TC - O(n+m)  SC - O(1)