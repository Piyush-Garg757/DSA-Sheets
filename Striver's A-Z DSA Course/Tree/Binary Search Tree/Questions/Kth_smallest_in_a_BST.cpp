/*Kth Smallest Element in a BST

Given the root of a binary search tree, and an integer k, return the kth smallest value (1-indexed) of all the values of the nodes in the tree.

Example 1:
Input: root = [3,1,4,null,2], k = 1
Output: 1

Example 2:
Input: root = [5,3,6,2,4,null,null,1], k = 3
Output: 3*/

// Simple observation - inorder traversal of a BST is sorted
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
    int kthSmallest(TreeNode *root, int k)
    {
        stack<TreeNode *> st;
        int ans;
        while (true)
        {
            if (root)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top();
                st.pop();
                k--;
                if (!k)
                {
                    ans = root->val;
                    break;
                }
                root = root->right;
            }
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)
// Morris use karke sc O(1) kar sakte hain
// Kth largetds pucha ho to ek bar saare nodes count karo fir n-kth return kar do