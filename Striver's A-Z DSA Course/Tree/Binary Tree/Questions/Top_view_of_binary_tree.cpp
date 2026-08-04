/*Top View of Binary Tree

You are given the root of a binary tree, and your task is to return its top view. The top view of a binary tree is the set of nodes visible when the tree is viewed from the top.
Note:

Return the nodes from the leftmost node to the rightmost node.
If multiple nodes overlap at the same horizontal position, only the topmost (closest to the root) node is included in the view.

Examples:
Input: root = [1, 2, 3]
Output: [2, 1, 3]
Explanation: The Green colored nodes represents the top view in the below Binary tree.

Input: root = [10, 20, 30, 40, 60, 90, 100]
Output: [40, 20, 10, 30, 100]
Explanation: The Green colored nodes represents the top view in the below Binary tree.
*/

/*
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution
{
public:
    vector<int> topView(Node *root)
    {
        // code here
        map<int, int> mpp;
        queue<pair<Node *, int>> q;
        vector<int> ans;
        q.push({root, 0});
        while (!q.empty())
        {
            Node *node = q.front().first;
            int x = q.front().second;
            q.pop();
            if (mpp.find(x) == mpp.end())
            {
                if (x < 0)
                    ans.insert(ans.begin(), node->data);
                else
                    ans.push_back(node->data);
            }
            mpp[x] = node->data;
            if (node->left)
                q.push({node->left, x - 1});
            if (node->right)
                q.push({node->right, x + 1});
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)
// Idea is simply inspired from vertical order traversal