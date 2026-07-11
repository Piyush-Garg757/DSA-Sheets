/*Maximum Depth of Binary Tree

Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2*/

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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
// TC - O(n)  SC - O(h)

// BFS Approach
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
    int maxDepth(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        queue<TreeNode *> q;
        int ans = 0;
        q.push(root);
        while (!q.empty())
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *a = q.front();
                q.pop();
                if (a->left)
                    q.push(a->left);
                if (a->right)
                    q.push(a->right);
            }
            ans++;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

/*For Maximum Depth of Binary Tree:

1. Recursive DFS
1 + max(leftDepth, rightDepth)
Worst Case Tree

A completely skewed tree:

1
 \
  2
   \
    3
     \
      4
Complexity
Time: O(n)
Space: O(n)

Why?

Recursion stack contains all n nodes at once.
Best/Balanced Case
        1
      /   \
     2     3
    / \   / \
   4  5  6  7
Space: O(log n) (height of balanced tree)
2. BFS (Level Order)
Worst Case Tree

A perfect/complete binary tree:

          1
       /     \
      2       3
    /  \     /  \
   4    5   6    7
  / \  / \ / \  / \
 ...
Complexity
Time: O(n)
Space: O(n)

Why?

The queue may contain an entire level.
Last level has about n/2 nodes.
Best Case (Skewed Tree)
1
 \
  2
   \
    3
Queue contains at most 1 node.
Space: O(1) (or O(h)=O(1) per level)
Interview Summary
Approach	Worst-case Time	Worst-case Space	Worst Case Tree
DFS (Recursive)	O(n)	O(n)	Skewed tree
BFS (Queue)	O(n)	O(n)	Perfect/Complete tree*/