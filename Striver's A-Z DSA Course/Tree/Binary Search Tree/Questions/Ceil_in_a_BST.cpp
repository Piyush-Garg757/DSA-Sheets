/*Ceil in BST

Given a root binary search tree and an integer x , find the Ceil of x in the tree.
Ceil(x) is a number that is either equal to x or is immediately greater than x. If Ceil could not be found, return -1.

Examples:
Input: root = [5, 1, 7, N, 2, N, N, N, 3], x = 3
Output: 3

Explanation: We find 3 in BST, so ceil of 3 is 3.
Input: root = [10, 5, 11, 4, 7, N, N, N, N, N, 8], x = 6
Output: 7
Explanation: We find 7 in BST, so ceil of 6 is 7.*/

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
    int findCeil(Node *root, int x)
    {
        // code here
        int ans = -1;
        while (root != NULL)
        {
            if (root->data > x)
            {
                ans = root->data;
                root = root->left;
            }
            else if (root->data == x)
            {
                ans = root->data;
                break;
            }
            else
            {
                root = root->right;
            }
        }
        return ans;
    }
};
// TC - O(logn)  SC - O(1)