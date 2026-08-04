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