//height balanced tab hota hai jab har node ke liye abs(rightheight - leftheight)<=1 ho

/*Balanced Binary Tree

Given a binary tree, determine if it is height-balanced.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: true

Example 2:
Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

Example 3:
Input: root = []
Output: true*/

// Brute force ki har node ke liye height vala function call kare aur check karo

// Most optimal sol
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
    int height(TreeNode *root)
    {
        if (root == nullptr)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
            return -1;
        return max(lh, rh) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        int ans = height(root);
        return ans != -1;
    }
};
// TC - O(n)  SC - O(n)
// bas height vale function mein ek check laga diya ki agar kahi bhi height ka diff > 1 hua to return -1  aur uska use karne ke liye lh==-1 aur rh==-1 vala check lagaya