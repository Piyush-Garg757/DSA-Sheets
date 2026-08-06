/*Burning Tree

Given the root of a binary tree and a target node, determine the minimum time required to burn the entire tree if the target node is set on fire. In one second, the fire spreads from a node to its left child, right child, and parent.
Note: The tree contains unique values.

Examples :
Input: root = [1, 2, 3, 4, 5, 6, 7], target = 2
Output: 3
Explanation: Initially 2 is set to fire at 0 sec
At 1 sec: Nodes 4, 5, 1 catches fire.
At 2 sec: Node 3 catches fire.
At 3 sec: Nodes 6, 7 catches fire.
It takes 3s to burn the complete tree.

Input: root = [1, 2, 3, 4, 5, N, 7, 8, N, N, 10], target = 10
Output: 5
Explanation: Initially 10 is set to fire at 0 sec
At 1 sec: Node 5 catches fire.
At 2 sec: Node 2 catches fire.
At 3 sec: Nodes 1 and 4 catches fire.
At 4 sec: Node 3 and 8 catches fire.
At 5 sec: Node 7 catches fire.
It takes 5s to burn the complete tree.*/

/* Structure of binary tree Node
class Node {
    public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; */

class Solution
{
public:
    int minTime(Node *root, int target)
    {
        // code here
        unordered_map<Node *, Node *> parent;
        Node *m = NULL;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            Node *n = q.front();
            if (n->data == target)
                m = n;
            q.pop();
            if (n->left)
            {
                parent[n->left] = n;
                q.push(n->left);
            }
            if (n->right)
            {
                parent[n->right] = n;
                q.push(n->right);
            }
        }
        q.push(m);
        unordered_set<Node *> visited;
        visited.insert(m);
        int curr = 0;
        while (!q.empty())
        {
            int size = q.size();
            while (size--)
            {
                Node *n = q.front();
                q.pop();
                if (parent.count(n) && !visited.count(parent[n]))
                {
                    visited.insert(parent[n]);
                    q.push(parent[n]);
                }
                if (n->left && !visited.count(n->left))
                {
                    visited.insert(n->left);
                    q.push(n->left);
                }
                if (n->right && !visited.count(n->right))
                {
                    visited.insert(n->right);
                    q.push(n->right);
                }
            }
            curr++;
        }
        return curr - 1;
    }
};
// TC - O(n)  SC - O(n)
// Totally inspired from print all nodes at a distance k from target node