/*Construct Binary Tree from Preorder and Inorder Traversal

Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: preorder = [-1], inorder = [-1]
Output: [-1]*/

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
    TreeNode *solve(vector<int> &pre, int pre_start, int pre_end, vector<int> &in, int in_start, int in_end, unordered_map<int, int> &mpp)
    {
        if (pre_start > pre_end || in_start > in_end)
            return nullptr;
        TreeNode *root = new TreeNode(pre[pre_start]);
        int idx = mpp[root->val];
        int rem = idx - in_start;
        root->left = solve(pre, pre_start + 1, pre_start + rem, in, in_start, idx - 1, mpp);
        root->right = solve(pre, pre_start + rem + 1, pre_end, in, idx + 1, in_end, mpp);
        return root;
    }
    TreeNode *buildTree(vector<int> &pre, vector<int> &in)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < pre.size(); i++)
            mpp[in[i]] = i;
        TreeNode *root =
            solve(pre, 0, pre.size() - 1, in, 0, in.size() - 1, mpp);
        return root;
    }
};
// TC - O(n)  SC - O(n)