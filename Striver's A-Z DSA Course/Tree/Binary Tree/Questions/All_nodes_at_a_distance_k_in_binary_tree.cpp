/*All Nodes Distance K in Binary Tree

Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
You can return the answer in any order.

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
Output: [7,4,1]
Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.

Example 2:
Input: root = [1], target = 1, k = 3
Output: []*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
    {
        unordered_map<TreeNode *, TreeNode *> parent;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            TreeNode *n = q.front();
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
        q.push(target);
        unordered_set<TreeNode *> visited;
        visited.insert(target);
        int curr = 0;
        while (!q.empty())
        {
            int size = q.size();
            if (curr++ == k)
                break;
            while (size--)
            {
                TreeNode *n = q.front();
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
        }
        vector<int> ans;
        while (!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)
// Pehle sab nodes ke parents mark kiye  fir ek visited banaya taki check kar sakein ki kahi alread visited node ko vapas to nahi ka rahe itereate   fir uske baad target se parent left right chalte ja rahe hain jab tak curr k ke barabar na ho jaye   fir end mein jo nodes queue mein bache vahi answer hain