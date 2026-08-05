/*Root to Leaf Paths

Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.
Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

Examples:
Input: root = [1, 2, 3, 4, 5, N, N]
ex-3
Output: [[1, 2, 4], [1, 2, 5], [1, 3]]
Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 -> 4, 1 -> 2 -> 5 and 1 -> 3

Input: root = [1, 2, 3]
Output: [[1, 2], [1, 3]]
Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 and 1 -> 3
Input: root = [10, 20, 30, 40, 60, N, N]
Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
Explanation: All the possible paths from root node to leaf nodes are: 10 -> 20 -> 40, 10 -> 20 -> 60 and 10 -> 30*/

/* Definition for Node
class Node {
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution
{
public:
    bool isleaf(Node *root)
    {
        return (!root->right && !root->left);
    }
    void solve(Node *root, vector<vector<int>> &ans, vector<int> &v)
    {
        if (!root)
            return;
        v.push_back(root->data);
        if (isleaf(root))
        {
            ans.push_back(v);
            v.pop_back();
            return;
        }
        solve(root->left, ans, v);
        solve(root->right, ans, v);
        v.pop_back();
    }
    vector<vector<int>> paths(Node *root)
    {
        // code here
        vector<vector<int>> ans;
        vector<int> v;
        solve(root, ans, v);
        return ans;
    }
};
// TC - O(n)  SC - O(n)