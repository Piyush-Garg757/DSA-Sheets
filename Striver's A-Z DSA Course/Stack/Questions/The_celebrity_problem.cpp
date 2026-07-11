/*The Celebrity Problem

A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.
Note: Follow 0-based indexing.

Examples:

Input: mat[][] = [[1, 1, 0],
                 [0, 1, 0],
                [0, 1, 1]]
Output: 1
Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.

Input: mat[][] = [[1, 1],
                [1, 1]]
Output: -1
Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.

Input: mat[][] = [[1]]
Output: 0*/

// My first and obvious approach brute force
class Solution
{
public:
    int celebrity(vector<vector<int>> &a)
    {
        // code here
        int n = a.size();
        vector<int> potential;
        for (int i = 0; i < n; i++)
        {
            int count = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] == 0)
                    count++;
            }
            if (count == n - 1)
            {
                potential.push_back(i);
            }
        }
        for (int i = 0; i < potential.size(); i++)
        {
            int person = potential[i], count = 0;
            for (int j = 0; j < n; j++)
            {
                if (a[j][person] == 1)
                    count++;
            }

            if (count == n)
                return person;
        }
        return -1;
    }
};
// TC - O(n^2)  SC - O(n)

// Optimal sol
class Solution
{
public:
    int celebrity(vector<vector<int>> &a)
    {
        // code here
        int n = a.size();
        int top = 0, down = n - 1;
        while (top < down)
        {
            if (a[top][down] == 1)
            {
                top++;
            }
            else
                down--;
        }
        if (top > down)
            return -1;
        int row = down, col = down, count = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i][col] != 1)
                return -1;
        }
        for (int j = 0; j < n; j++)
        {
            if (a[row][j] == 1)
                count++;
        }
        if (count != 1)
            return -1;
        return down;
    }
};
// TC - O(n)  SC - O(1)
// Intuiton simple hai - do pointer lo ek first row ke 0 pe aur ek last row ke 0 pe agar a[top][down] == 1 ,  matlab top down ko jannta hai to top to answer ho nahi sakta   aur agar aisa nahi hai to down answer nahi ho sakta kyuki top use nahi janta to down-- aise karke agar top aur down kisi ek index pe aake milte hain to vo ek potential candidate hai celebrity hone k eliye fir hum uske liye check kar lete hai uss partcular row aur col ko traverse karke