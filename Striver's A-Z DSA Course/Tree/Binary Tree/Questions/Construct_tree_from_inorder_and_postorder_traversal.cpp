/*Construct Binary Tree from Inorder and Postorder Traversal

Given two integer arrays inorder and postorder where inorder is the inorder traversal of a binary tree and postorder is the postorder traversal of the same tree, construct and return the binary tree.

Example 1:
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]

Example 2:
Input: inorder = [-1], postorder = [-1]
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
    TreeNode *solve(vector<int> &in, int in_start, int in_end, vector<int> &post, int post_start, int post_end, unordered_map<int, int> &mpp)
    {
        if (post_start > post_end || in_start > in_end)
            return nullptr;
        TreeNode *root = new TreeNode(post[post_end]);
        int idx = mpp[root->val];
        int rem = in_end - idx;
        root->left = solve(in, in_start, idx - 1, post, post_start, post_end - rem - 1, mpp);
        root->right = solve(in, idx + 1, in_end, post, post_end - rem, post_end - 1, mpp);
        return root;
    }
    TreeNode *buildTree(vector<int> &in, vector<int> &post)
    {
        unordered_map<int, int> mpp;
        for (int i = 0; i < post.size(); i++)
            mpp[in[i]] = i;
        TreeNode *root = solve(in, 0, in.size() - 1, post, 0, post.size() - 1, mpp);
        return root;
    }
};
// TC - O(n)  SC - O(n)