/*Minimum in BST

Given the root of a Binary Search Tree, find the minimum element in this given BST.

Examples

Input: root = [5, 4, 6, 3, N, N, 7, 1]
ex-1
Output: 1
Explanation: The minimum element in the given BST is 1.

Input: root = [10, 5, 20, 2]
ex-2
Output: 2
Explanation: The minimum element in the given BST is 2.

Input: root = []
Output: -1
Explanation: The root of the BST is NULL.*/

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
    int minValue(Node *root)
    {
        // code here
        if (!root)
            return 0;
        if (root->left)
            return minValue(root->left);
        return root->data;
    }
};
// TC - O(logn)  SC - O(logn)