/*Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

Example 1:
Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.

Example 2:
Input: matrix = [["0"]]
Output: 0

Example 3:
Input: matrix = [["1"]]
Output: 1*/

class Solution
{
public:
    int largestRectangleArea(vector<int> &a)
    {
        stack<int> st;
        int area = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (st.empty() || a[i] >= a[st.top()])
                st.push(i);
            else
            {
                int nse = i;
                while (!st.empty() && a[st.top()] >= a[i])
                {
                    int height = a[st.top()];
                    st.pop();
                    int pse = -1;
                    if (!st.empty())
                        pse = st.top();
                    area = max(area, height * (nse - pse - 1));
                }
                st.push(i);
            }
        }
        int n = a.size();
        while (!st.empty())
        {
            int height = a[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            area = max(area, height * (n - pse - 1));
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>> &a)
    {
        int n = a.size(), m = a[0].size(), ans = 0;
        vector<int> hist(m, 0);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == '1')
                    hist[j]++;
                else
                    hist[j] = 0;
            }
            ans = max(ans, largestRectangleArea(hist));
        }
        return ans;
    }
};
// TC - O(m*n)  SC - O(m)

/*Intution - Every row of the matrix can be treated as the base of a histogram.
Once you understand that, the whole solution becomes natural.

Step 1: Forget the matrix
Suppose the matrix is
1 0 1 0 0
1 0 1 1 1
1 1 1 1 1
1 0 0 1 0
Instead of finding rectangles directly in the matrix, think:
"Can I somehow convert every row into a histogram?"
Because you already know how to solve Largest Rectangle in Histogram.

Step 2: Build the histogram
Maintain
vector<int> hist(m,0);
Initially
0 0 0 0 0
Row 0
1 0 1 0 0
Update
1 0 1 0 0
This is literally a histogram.
Largest rectangle
height
1   1
█   █
Answer = 1
Row 1
Current row
1 0 1 1 1
Previous histogram
1 0 1 0 0
Update
2 0 2 1 1
Why?
Column 0
1
1
Two continuous ones.
Height becomes
2
Column 1
0
0
Reset
0
Column 2
1
1
Height
2
Column 3
0
1
Height
1
Column 4
0
1
Height
1
Histogram
2 0 2 1 1
Run Largest Rectangle.
Row 2
Current row
1 1 1 1 1
Previous histogram
2 0 2 1 1
Update
3 1 3 2 2
Now the histogram is
      █
█     █
█  █  █ █ █
█  █  █ █ █
-----------
3  1  3 2 2
Largest rectangle here is larger.
Row 3
Current row
1 0 0 1 0
Histogram
4 0 0 3 0
So after every row, we solve a histogram problem.
Exactly what your code does.

Why histogram works
Suppose we are at
Row 3
Every histogram height tells us
How many consecutive 1s end at this row?
Example
1
1
1
Height
3
That means any rectangle ending at this row can use this height.
So the histogram completely captures the information needed.*/