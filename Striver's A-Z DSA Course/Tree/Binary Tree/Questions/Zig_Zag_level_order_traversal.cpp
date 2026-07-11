/*Binary Tree Zigzag Level Order Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values. (i.e., from left to right, then right to left for the next level and alternate between).

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: [[3],[20,9],[15,7]]

Example 2:
Input: root = [1]
Output: [[1]]

Example 3:
Input: root = []
Output: []*/

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        int dir = 1;
        while (!q.empty())
        {
            int size = q.size();
            vector<int> v(size);
            for (int i = 0; i < size; i++)
            {
                TreeNode *a = q.front();
                q.pop();
                int idx = i;
                if (dir == -1)
                    idx = size - i - 1;
                v[idx] = a->val;
                if (a->left)
                    q.push(a->left);
                if (a->right)
                    q.push(a->right);
            }
            ans.push_back(v);
            dir *= -1;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)