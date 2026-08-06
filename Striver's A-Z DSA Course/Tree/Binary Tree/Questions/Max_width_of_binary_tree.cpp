/*Maximum Width of Binary Tree

Given the root of a binary tree, return the maximum width of the given tree.
The maximum width of a tree is the maximum width among all levels.
The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes that would be present in a complete binary tree extending down to that level are also counted into the length calculation.
It is guaranteed that the answer will in the range of a 32-bit signed integer.

Example 1:
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).

Example 2:
Input: root = [1,3,2,5,null,null,9,6,null,7]
Output: 7
Explanation: The maximum width exists in the fourth level with length 7 (6,null,null,null,null,null,7).

Example 3:
Input: root = [1,3,2,5]
Output: 2
Explanation: The maximum width exists in the second level with length 2 (3,2).*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    int widthOfBinaryTree(TreeNode *root)
    {
        if (!root)
            return 0;
        queue<pair<TreeNode *, long long>> q;
        q.push({root, 0});
        int ans = 0;
        while (!q.empty())
        {
            long long size = q.size();
            long long mini = q.front().second;
            int first, last;
            for (long long i = 0; i < size; i++)
            {
                TreeNode *n = q.front().first;
                long long curr_id = q.front().second - mini;
                q.pop();
                if (i == 0)
                    first = curr_id;
                if (i == size - 1)
                    last = curr_id;
                if (n->left)
                    q.push({n->left, 2 * curr_id + 1});
                if (n->right)
                    q.push({n->right, 2 * curr_id + 2});
            }
            ans = max(ans, last - first + 1);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

/*Problem kya keh rahi hai?
Tree ka maximum width nikalna hai.
Example:
        1
      /   \
     2     3
    /       \
   4         7
Agar sirf nodes count karoge to last level par
4     7
2 nodes hain.
Lekin actual width 4 hai.
Kyuki beech me do positions khaali hain.
4   X   X   7
Isliye hume missing nodes bhi count karne padenge.
Missing nodes ko kaise count kare?
Hum tree ko imagine karte hain ki ye Complete Binary Tree hai.
Jaise heap hota hai.
             1
          /     \
        2         3
      /   \     /   \
     4     5   6     7
Har node ki ek fixed position hoti hai.
Agar koi node missing hai to uski position fir bhi exist karti hai.
Isi wajah se width nikal sakte hain.
0-Based Indexing
Root se start karte hain.
         1
Index:
         0
Ab children.
Rule:
left = 2*i + 1
right = 2*i + 2
Root ka index = 0
Left
2*0+1 = 1
Right
2*0+2 = 2
Tree ban gaya
           0
        /     \
       1       2
Ab node 1 ke children
Index = 1
Left
2*1+1 = 3
Right
2*1+2 = 4
Node 2 ke children
Index = 2
Left
5
Right
6
Complete tree
                 0
           /           \
          1             2
       /     \       /     \
      3       4     5       6
Ye exactly heap indexing hai.
Agar kuch nodes missing ho?
Tree
          1
       /     \
      2       3
     /         \
    4           7
Index assign karte hain.
          0
       /     \
      1       2
     /         \
    3           6
Notice
4 ka index = 3
7 ka index = 6
Beech me
4
5
positions khaali hain.
Width
6-3+1 = 4
Exactly answer.
Formula kahan se aaya?
Suppose parent ka index hai
i
Complete tree me har parent ke do children hote hain.
Array representation:
Parent
      i
Uske baad next level start hoti hai.
Har parent do jagah occupy karta hai.
Isliye
left = 2*i+1
right = 2*i+2
Ye heap ka standard formula hai.
1-Based Indexing
Bahut books me ye use hoti hai.
Root
1
Children
left = 2*i
right = 2*i+1
Example
Root
1
Left
2
Right
3
Next
4
5
6
7
Tree

                 1
            /         \
           2           3
        /     \      /    \
       4       5    6      7
Compare
Zero Based
Root = 0
left = 2*i+1
right = 2*i+2
Produces
0
1 2
3 4 5 6
7 8 9...
One Based
Root = 1
left = 2*i
right = 2*i+1
Produces
1
2 3
4 5 6 7
8 9...
Dono me width same aati hai?
Bilkul.
Example
Last level
Zero based
3      6
Width
6-3+1 = 4
One based
4      7
Width
7-4+1 = 4
Answer same.
Sirf numbering change hui hai.
mini kyu subtract karte hain?
Maan lo bahut deep tree hai.
Index ho sakte hain
1024
1025
1030
Hum level ke first node ko 0 bana dete hain.
mini = q.front().second;
curr = index - mini;
To
1024 -> 0
1025 -> 1
1030 -> 6
Width
Old
1030-1024+1 = 7
New
6-0+1 = 7
Answer same, lekin numbers chhote ho gaye aur overflow ka risk bahut kam ho gaya.
Puri algorithm ka intuition
Har node ko complete binary tree wali position (index) do.
Har level ke first aur last node ka index note karo.
Width = last - first + 1.
Har level ke baad mini subtract karke indices normalize kar do, taaki numbers unnecessarily bade na hote jayen.

Yehi wajah hai ki BFS + indexing wala approach is problem ka standard aur optimal solution mana jata hai.*/