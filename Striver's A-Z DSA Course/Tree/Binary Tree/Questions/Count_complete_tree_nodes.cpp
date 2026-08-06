/*Count Complete Tree Nodes

Given the root of a complete binary tree, return the number of the nodes in the tree.
According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
Design an algorithm that runs in less than O(n) time complexity.

Example 1:
Input: root = [1,2,3,4,5,6]
Output: 6

Example 2:
Input: root = []
Output: 0

Example 3:
Input: root = [1]
Output: 1*/

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
    int find_left_height(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + find_left_height(root->left);
    }
    int find_right_height(TreeNode *root)
    {
        if (!root)
            return 0;
        return 1 + find_right_height(root->right);
    }
    int countNodes(TreeNode *root)
    {
        if (!root)
            return 0;
        int lh = find_left_height(root);
        int rh = find_right_height(root);
        if (lh == rh)
            return (1ll << lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};
// TC - O((log(n))^2)  SC - O(logn)