/*Left View of Binary Tree

Given the root of a binary tree. Return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.
Note: If the tree is empty, return an empty list.

Examples :
Input: root = [1, 2, 3, 4, 5, N, N]
Output:[1, 2, 4]
Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

Input: root = [1, 2, 3, N, N, 4, N, N, 5, N, N]
Output: [1, 2, 4, 5]
Explanation: From the left side of the tree, only the nodes 1, 2, 4, and 5 are visible.*/

/* Structure of Binary Tree Node
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
    vector<int> leftView(Node *root)
    {
        // code here
        if (root == nullptr)
            return {};
        queue<Node *> q;
        q.push(root);
        vector<int> ans;
        while (!q.empty())
        {
            int size = q.size();
            int a = 1;
            for (int i = 0; i < size; i++)
            {
                Node *node = q.front();
                if (a == 1)
                {
                    ans.push_back(node->data);
                    a = 0;
                }
                q.pop();
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }
        return ans;
    }
};
