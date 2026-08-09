/*Construct Binary Search Tree from Preorder Traversal

Given an array of integers preorder, which represents the preorder traversal of a BST (i.e., binary search tree), construct the tree and return its root.
It is guaranteed that there is always possible to find a binary search tree with the given requirements for the given test cases.
A binary search tree is a binary tree where for every node, any descendant of Node.left has a value strictly less than Node.val, and any descendant of Node.right has a value strictly greater than Node.val.
A preorder traversal of a binary tree displays the value of the node first, then traverses Node.left, then traverses Node.right.

Example 1:
Input: preorder = [8,5,1,7,10,12]
Output: [8,5,10,1,7,null,12]

Example 2:
Input: preorder = [1,3]
Output: [1,null,3]*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *solve(vector<int> &pre, int pre_start, int pre_end)
    {
        if (pre_start > pre_end)
            return nullptr;
        TreeNode *root = new TreeNode(pre[pre_start]);
        int i = pre_start + 1;
        while (i <= pre_end && pre[i] < root->val)
            i++;
        root->left = solve(pre, pre_start + 1, i - 1);
        root->right = solve(pre, i, pre_end);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &pre)
    {
        TreeNode *root = solve(pre, 0, pre.size() - 1);
        return root;
    }
};
// TC - O(n)  SC - O(n)  this can give O(n^2)  in worst case

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution
{
public:
    TreeNode *solve(vector<int> &pre, int &idx, int bound)
    {
        if (idx >= pre.size() || pre[idx] > bound)
            return nullptr;
        TreeNode *root = new TreeNode(pre[idx++]);
        root->left = solve(pre, idx, root->val);
        root->right = solve(pre, idx, bound);
        return root;
    }
    TreeNode *bstFromPreorder(vector<int> &pre)
    {
        int idx = 0;
        TreeNode *root = solve(pre, idx, INT_MAX);
        return root;
    }
};
// TC - O(n)  SC - O(n)
/*TreeNode* solve(vector<int>& pre, int& idx, int bound)

Hum har recursive call mein do cheezein maintain karenge:

idx

Abhi preorder mein kaunsa element process karna hai.

bound

Current subtree mein maximum allowed value kya hai.

Bas ye dono concepts samajh lo.

4. idx ko reference kyun banaya?
int& idx

Preorder ek single sequence hai.

Example:

8 5 1 7 10
^
idx

8 process kiya:

8 5 1 7 10
  ^
  idx

5 process kiya:

8 5 1 7 10
    ^
    idx

1 process kiya:

8 5 1 7 10
      ^
      idx

Hume chahiye ki saari recursive calls same idx share karein.

Isliye:

int& idx

Agar:

int idx

hota, toh har recursive call ko idx ki copy milti.

5. Ab sabse important concept: bound

Consider:

        8
       / \
      5   10
     / \
    1   7

Root 8 hai.

Iske left subtree mein kya aa sakta hai?

< 8

Isliye:

root->left = solve(pre, idx, root->val);

Yahan:

bound = 8
Left subtree of 8

Current value:

5

5 < 8

So 5 valid hai.

Ab 5 ka left subtree:

< 5

So:

solve(pre, idx, 5)

Current value:

1

1 < 5

Valid.

6. Ab 1 ke baad 7 aa gaya

Ye part bahut important hai.

Tree:

        8
       /
      5
     /
    1

Preorder:

8 5 1 7 10
      ^
      idx

1 ka bound kya hai?

5

Because 1 is inside left subtree of 5.

Ab next value:

7

Check:

pre[idx] > bound
7 > 1

True.

So:

return nullptr;

But dhyaan dena: hum idx++ nahi karte.

Isliye idx abhi bhi 7 par hi hai.

This is the magic.

7. Why returning NULL doesn't mean 7 is invalid globally

7 1 ka child nahi ban sakta.

But kya 7 completely invalid hai?

No.

7 actually:

    5
     \
      7

mein jaana chahiye.

So 1 bolta hai:

"7 mere subtree mein nahi aa sakta."

Therefore:

return nullptr;

Lekin idx ko consume nahi karta.

Ab control wapas 5 par.

8. 5 ka right subtree

5 ke right subtree ke liye bound kya hai?

5 khud 8 ke left subtree mein hai.

So 5 ke right mein values:

5 < value < 8

Hum function mein sirf upper bound pass kar rahe hain:

root->right = solve(pre, idx, bound);

Yahan 5 ke bound mein 8 already stored hai.

So:

solve(pre, idx, 8)

Current:

7

Check:

7 > 8 ?
No

So 7 valid hai.

Hence:

    5
   / \
  1   7
9. Ab 10

After processing 7:

8 5 1 7 10
        ^
        idx

7 ka subtree complete.

Eventually control root 8 par wapas aata hai.

Root 8 ka right subtree:

root->right = solve(pre, idx, bound);

Root ka bound initially:

INT_MAX

So:

10 < INT_MAX

10 valid.

Hence:

        8
       / \
      5   10
     / \
    1   7

Done.

10. Ab condition ko deeply samjho

Code:

if (idx >= pre.size() || pre[idx] > bound)
    return nullptr;

Iska meaning:

Case 1
idx >= pre.size()

Preorder khatam.

Toh subtree bhi khatam.

return nullptr;
Case 2
pre[idx] > bound

Current value current subtree mein fit nahi hoti.

Toh current subtree khatam.

return nullptr;

Important: is case mein idx increment nahi hota.

Because current value kisi upar wale subtree mein belong kar sakti hai.

11. Node create karna
TreeNode* root = new TreeNode(pre[idx++]);

Suppose:

pre[idx] = 5

Then:

new TreeNode(5)

and immediately:

idx++;

So ab next preorder element process hoga.

12. Left subtree
root->left = solve(pre, idx, root->val);

Current node ke left mein:

value < root->val

isliye upper bound:

root->val

Example:

root = 8

Then:

solve(pre, idx, 8)
13. Right subtree
root->right = solve(pre, idx, bound);

Yahan current node ka value upper bound nahi banega.

Kyun?

Suppose:

        8
       /
      5
       \
        7

7 ko sirf:

7 > 5

hona chahiye.

But upper limit abhi bhi:

8

hai.

So 5 ka right subtree:

(5, 8)

Conceptually hai.

Function mein lower bound separately store nahi kar rahe because preorder + previous structure se woh condition naturally maintain ho rahi hai.*/