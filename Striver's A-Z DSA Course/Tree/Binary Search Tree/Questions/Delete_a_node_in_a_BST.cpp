/*Delete Node in a BST

Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
Basically, the deletion can be divided into two stages:
Search for a node to remove.
If the node is found, delete the node.

Example 1:
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:
Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.

Example 3:
Input: root = [], key = 0
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
    TreeNode *find_min(TreeNode *root)
    {
        if (!root)
            return nullptr;
        while (root->left)
            root = root->left;
        return root;
    }
    TreeNode *searchBST(TreeNode *root, int val, TreeNode *&prev)
    {
        while (root && root->val != val)
        {
            prev = root;
            if (val > root->val)
                root = root->right;
            else
                root = root->left;
        }
        return root;
    }
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        TreeNode *prev = nullptr;
        TreeNode *target = searchBST(root, key, prev);
        if (!target)
            return root;
        if (!target->left && !target->right)
        {
            if (prev)
            {
                if (prev->left == target)
                    prev->left = nullptr;
                else
                    prev->right = nullptr;
                delete target;
            }
            else
            {
                delete target;
                return nullptr;
            }
        }
        else if (!target->left)
        {
            if (!prev)
            {
                root = root->right;
            }
            else if (prev->left == target)
            {
                prev->left = target->right;
            }
            else
            {
                prev->right = target->right;
            }
            delete target;
        }
        else if (!target->right)
        {
            if (!prev)
            {
                root = root->left;
            }
            else if (prev->left == target)
            {
                prev->left = target->left;
            }
            else
            {
                prev->right = target->left;
            }
            delete target;
        }
        else
        {
            if (!prev)
            {
                TreeNode *mini = find_min(root->right);
                mini->left = target->left;
                root = root->right;
            }
            else
            {
                if (prev->left == target)
                {
                    prev->left = target->right;
                }
                else
                {
                    prev->right = target->right;
                }
                TreeNode *mini = find_min(target->right);
                mini->left = target->left;
            }
            delete target;
        }
        return root;
    }
};
// TC -  O(h)  SC - O(1)
// Think about all the test cases and this is easy af