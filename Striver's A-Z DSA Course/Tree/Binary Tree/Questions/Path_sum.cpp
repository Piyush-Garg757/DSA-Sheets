    /*Path Sum

    Given the root of a binary tree and an integer targetSum, return true if the tree has a root-to-leaf path such that adding up all the values along the path equals targetSum.
    A leaf is a node with no children.

    Example 1:
    Input: root = [5,4,8,11,null,13,4,7,2,null,null,null,1], targetSum = 22
    Output: true
    Explanation: The root-to-leaf path with the target sum is shown.

    Example 2:
    Input: root = [1,2,3], targetSum = 5
    Output: false
    Explanation: There are two root-to-leaf paths in the tree:
    (1 --> 2): The sum is 3.
    (1 --> 3): The sum is 4.
    There is no root-to-leaf path with sum = 5.

    Example 3:
    Input: root = [], targetSum = 0
    Output: false
    Explanation: Since the tree is empty, there are no root-to-leaf paths.*/

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
        bool solve(TreeNode *root, int k, int sum)
        {
            sum += root->val;
            if (!root->left && !root->right)
            {
                if (sum == k)
                    return true;
                return false;
            }
            if (root->left)
                if (solve(root->left, k, sum))
                    return true;
            if (root->right)
                if (solve(root->right, k, sum))
                    return true;
            return false;
        }
        bool hasPathSum(TreeNode *root, int k)
        {
            if (!root)
                return false;
            int sum = 0;
            return solve(root, k, sum);
        }
    };
    // TC - O(n)  SC - O(h)