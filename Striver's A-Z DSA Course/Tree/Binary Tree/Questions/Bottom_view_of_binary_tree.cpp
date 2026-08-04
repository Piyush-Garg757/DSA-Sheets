/*Bottom View of Binary Tree

You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.
Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

Examples :
Input: root = [1, 2, 3, 4, 5, N, 6]
Output: [4, 2, 5, 3, 6]
Explanation: The Green nodes represent the bottom view of below binary tree.

Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]
Output: [5, 10, 4, 28, 25]
Explanation: The Green nodes represent the bottom view of below binary tree.
*/

/*
Definition for Node
class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution
{
public:
    vector<int> bottomView(Node *root)
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
            mpp[x] = node->data;
            if (node->left)
                q.push({node->left, x - 1});
            if (node->right)
                q.push({node->right, x + 1});
        }
        for (auto i : mpp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)