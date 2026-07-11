/*Same Tree

Given the roots of two binary trees p and q, write a function to check if they are the same or not.
Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.

Example 1:
Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
Input: p = [1,2,1], q = [1,1,2]
Output: false*/

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
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (!p && !q)
            return true;
        if (!p)
            return false;
        if (!q)
            return false;
        if (p->val != q->val)
            return false;
        return (isSameTree(p->right, q->right) && isSameTree(p->left, q->left));
    }
};
// TC - O(n)  SC - O(n)

/*Symmetric Tree

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true

Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false*/

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
    bool same(TreeNode *r1, TreeNode *r2)
    {
        if (!r1 && !r2)
            return true;
        if (!r1)
            return false;
        if (!r2)
            return false;
        if (r1->val != r2->val)
            return false;
        return (same(r1->right, r2->left) && same(r1->left, r2->right));
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return true;
        return same(root->right, root->left);
    }
};
// TC - O(n)  SC - O(n)

// isi mein agar iterative approach puchi ho same tree ke liye bfs ya dfs check kar lo dono trees ka
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        queue<TreeNode *> qu;

        qu.push(p);
        qu.push(q);

        while (!qu.empty())
        {
            TreeNode *first = qu.front();
            qu.pop();

            TreeNode *second = qu.front();
            qu.pop();

            if (!first && !second)
                continue;

            if (!first || !second)
                return false;

            if (first->val != second->val)
                return false;

            qu.push(first->left);
            qu.push(second->left);

            qu.push(first->right);
            qu.push(second->right);
        }

        return true;
    }
};