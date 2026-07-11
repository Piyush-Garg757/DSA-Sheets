/*Tree Boundary Traversal

Given a root of a Binary Tree, return its boundary traversal in the following order:
Left Boundary: Nodes from the root to the leftmost non-leaf node, preferring the left child over the right and excluding leaves.
Leaf Nodes: All leaf nodes from left to right, covering every leaf in the tree.
Reverse Right Boundary: Nodes from the root to the rightmost non-leaf node, preferring the right child over the left, excluding leaves, and added in reverse order.
Note: The root is included once, leaves are added separately to avoid repetition, and the right boundary follows traversal preference not the path from the rightmost leaf.
Examples:
Input: root = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
Output: [1, 2, 4, 8, 9, 6, 7, 3]

Input: root = [1, N, 2, N, 3, N, 4, N, N]
Output: [1, 4, 3, 2]

Left boundary: [1] (as there is no left subtree)
Leaf nodes: [4]
Right boundary: [3, 2] (in reverse order)
Final traversal: [1, 4, 3, 2]*/

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

// Simple idea - pehle left ke nodes traverse karo   fir leaf nodes traverse karo fir right ke nodes traverse karo
class Solution
{
public:
    bool isLeaf(Node *root)
    {
        if (root->left == nullptr && root->right == nullptr)
            return true;
        return false;
    }
    void traverse_left(Node *root, vector<int> &res)
    {
        Node *temp = root->left;
        while (temp)
        {
            if (!isLeaf(temp))
                res.push_back(temp->data);
            if (temp->left)
                temp = temp->left;
            else
                temp = temp->right;
        }
    }
    void traverse_leaf(Node *root, vector<int> &res)
    {
        if (!root)
            return;
        if (isLeaf(root))
        {
            res.push_back(root->data);
            return;
        }
        traverse_leaf(root->left, res);
        traverse_leaf(root->right, res);
    }
    void traverse_right(Node *root, vector<int> &res)
    {
        Node *temp = root->right;
        stack<int> st;
        while (temp)
        {
            if (!isLeaf(temp))
                st.push(temp->data);
            if (temp->right)
                temp = temp->right;
            else
                temp = temp->left;
        }
        while (!st.empty())
        {
            res.push_back(st.top());
            st.pop();
        }
    }
    vector<int> boundaryTraversal(Node *root)
    {
        // code here
        vector<int> res;
        if (!root)
            return res;
        if (!isLeaf(root))
            res.push_back(root->data);
        traverse_left(root, res);
        traverse_leaf(root, res);
        traverse_right(root, res);
        return res;
    }
};
// TC - O(n)  SC - O(n)