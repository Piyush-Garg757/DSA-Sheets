/*Two Sum IV - Input is a BST

Given the root of a binary search tree and an integer k, return true if there exist two elements in the BST such that their sum is equal to k, or false otherwise.

Example 1:
Input: root = [5,3,6,2,4,null,7], k = 9
Output: true

Example 2:
Input: root = [5,3,6,2,4,null,7], k = 28
Output: false*/

// Brute force
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
    void inorder(TreeNode *r, vector<int> &ans)
    {
        if (!r)
            return;
        inorder(r->left, ans);
        ans.push_back(r->val);
        inorder(r->right, ans);
    }
    bool findTarget(TreeNode *root, int k)
    {
        vector<int> ans;
        inorder(root, ans);
        int i = 0, j = ans.size() - 1;
        while (i < j)
        {
            if (ans[i] + ans[j] == k)
                return true;
            else if (ans[i] + ans[j] > k)
                j--;
            else
                i++;
        }
        return false;
    }
};
// TC - O(n)  SC - O(n)

// Optimal sol - idea taken from bst iterator
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
    void push_all1(stack<TreeNode *> &st1, TreeNode *root)
    {
        if (!root)
            return;
        while (root)
        {
            st1.push(root);
            root = root->left;
        }
    }
    void push_all2(stack<TreeNode *> &st2, TreeNode *root)
    {
        if (!root)
            return;
        while (root)
        {
            st2.push(root);
            root = root->right;
        }
    }
    bool findTarget(TreeNode *root, int k)
    {
        stack<TreeNode *> st1;
        stack<TreeNode *> st2;
        push_all1(st1, root);
        push_all2(st2, root);
        while (st1.top()->val < st2.top()->val)
        {
            int n1 = st1.top()->val, n2 = st2.top()->val;
            int sum = n1 + n2;
            if (sum == k)
                return true;
            if (sum > k)
            {
                TreeNode *n2 = st2.top();
                st2.pop();
                push_all2(st2, n2->left);
            }
            else
            {
                TreeNode *n1 = st1.top();
                st1.pop();
                push_all1(st1, n1->right);
            }
        }
        return false;
    }
};
// TC - O(n)  SC - O(h)