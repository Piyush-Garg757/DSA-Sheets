/*Lowest Common Ancestor of a Binary Tree

Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has both p and q as descendants (where we allow a node to be a descendant of itself).”

Example 1:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 1
Output: 3
Explanation: The LCA of nodes 5 and 1 is 3.

Example 2:
Input: root = [3,5,1,6,2,0,8,null,null,7,4], p = 5, q = 4
Output: 5
Explanation: The LCA of nodes 5 and 4 is 5, since a node can be a descendant of itself according to the LCA definition.

Example 3:
Input: root = [1,2], p = 1, q = 2
Output: 1*/

// My first approach - isoptimal asymptotically but traversing tree 2 times and maintaining 2 arrays and the iterating through them    but did it myself
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
    bool solve(TreeNode *root, TreeNode *node, vector<TreeNode *> &a)
    {
        if (!root)
            return false;
        a.push_back(root);
        if (root == node)
            return true;
        if (solve(root->left, node, a))
            return true;
        if (solve(root->right, node, a))
            return true;
        a.pop_back();
        return false;
    }
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        vector<TreeNode *> path_to_p, path_to_q;
        solve(root, p, path_to_p);
        solve(root, q, path_to_q);
        int i = 0, j = 0, n = path_to_p.size(), m = path_to_q.size();
        TreeNode *a = nullptr;
        while (i < n && j < m)
        {
            if (path_to_p[i] == path_to_q[j])
                a = path_to_p[i];
            i++;
            j++;
        }
        return a;
    }
};
// TC - O(n)  SC - O(h)

// Most Optimal sol
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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || root == p || root == q)
            return root;
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (left == nullptr)
            return right;
        else if (right == nullptr)
            return left;
        return root;
    }
};
// TC - O(n)  SC - O(n)
/*Ye solution samajhne ka sabse important point hai ki recursive function har subtree se ek information return kar raha hai:

"Kya mujhe is subtree me p, q, ya unka LCA mila?"

Isi idea par pura solution based hai.

Step 1: Base Case
if (!root || root == p || root == q)
    return root;

Teen cases hain:

Case 1: root == nullptr
return nullptr;

Matlab is subtree me kuch nahi mila.

Case 2: root == p
    p

Agar current node hi p hai, to p ko return kar do.

Similarly agar current node q hai, to q return karo.

Iska matlab:

"Maine apne subtree me ek target find kar liya."

Step 2: Left aur Right subtree check karo
TreeNode* left = lowestCommonAncestor(root->left, p, q);
TreeNode* right = lowestCommonAncestor(root->right, p, q);

Ab dono subtrees bataenge unhe kya mila.

Possible returns:

nullptr
p
q
LCA
Case 1: Dono side null
      A
     / \
   null null
left = nullptr
right = nullptr

Code:

if(left == nullptr)
    return right;

Right bhi nullptr hai.

return nullptr;

Matlab is subtree me na p mila na q.

Case 2: Left me p mila
      A
     /
    p

Recursive calls:

left = p
right = nullptr

Code:

if(right == nullptr)
    return left;

Return:

p

Matlab:

"Mujhe mere subtree me p mila."

Case 3: Right me q mila
      A
       \
        q

Returns:

left = nullptr
right = q

Code:

if(left == nullptr)
    return right;

Return:

q
Case 4: Ek left me aur ek right me
        A
       / \
      p   q

Returns:

left = p
right = q

Ab dono non-null hain.

Code:

return root;

Matlab

LCA = A*/