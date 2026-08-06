/*Children Sum in a Binary Tree

Given a binary tree, find if it satisfies the Children Sum Property which has the following rules
Each non-leaf node must have a value equal to the sum of its left and right children's values.
A NULL child is considered to have a value of 0, and all leaf nodes are considered valid by default.

Examples:
Input: root = [35, 20, 15, 15, 5, 10, 5]
Output: True
Explanation: Here, every node is sum of its left and right child.

Input: root = [1, 4, 3, 5]
Output: False
Explanation: Here, 1 is the root node and 4, 3 are its child nodes. 4 + 3 = 7 which is not equal to the value of root node. Hence, this tree does not satisfy the given condition.*/

/* Structure of a Tree Node
class Node {
    public:
    int data;
    Node* left, *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution
{
public:
    bool isSumProperty(Node *root)
    {
        // code here
        if (!root)
            return true;
        if (!root->left && !root->right)
            return true;
        int val = 0;
        if (root->left)
            val += root->left->data;
        if (root->right)
            val += root->right->data;
        if (val == root->data)
            return isSumProperty(root->left) && isSumProperty(root->right);
        else
            return false;
    }
};
// TC - O(n)  SC - O(n)

// What if
/*Given a binary tree, modify the tree so that it satisfies the Children Sum Property.

Children Sum Property:
For every non-leaf node,
node->data = left->data + right->data

Rules:
You are allowed only to increment node values.
You cannot decrement any node's value.
Structure of the tree should remain unchanged.*/

class Solution
{
public:
    void changeTree(Node *root)
    {
        if (root == NULL)
            return;
        int child = 0;
        if (root->left)
            child += root->left->data;
        if (root->right)
            child += root->right->data;
        if (child >= root->data)
            root->data = child;
        else
        {
            if (root->left)
                root->left->data = root->data;
            else if (root->right)
                root->right->data = root->data;
        }
        changeTree(root->left);
        changeTree(root->right);
        int total = 0;
        if (root->left)
            total += root->left->data;
        if (root->right)
            total += root->right->data;
        if (root->left || root->right)
            root->data = total;
    }
};
// TC - O(n)  SC - O(n)
/*Sabse bada intuition
Question me likha hai
Decrease nahi kar sakte. Sirf increase kar sakte ho.
Isi ek line ki wajah se pura algorithm banta hai.
Case 1
Suppose
      10
     /  \
    4    8
Children sum
4+8=12
Parent
10
Already
12>=10
To simply
parent = children sum
Kar do.
Result
      12
     /  \
    4    8
Koi problem nahi.
Case 2
Ab dekho
      20
     /  \
    5    6
Children sum
11
Parent
20
Property fail.
Ab kya kare?
Parent ko
11
Nahi bana sakte.
Kyuki decrease allowed hi nahi.
To option kya bacha?
Children ko bada karo.
Suppose
left=20
Tree
      20
     /  \
   20    6
Ab recursion baad me ise aur fix kar dega.
Isi wajah se code me likha hai
if(root->left)
    root->left->data = root->data;
Top Down

Pehla phase
Parent se children ki taraf.
Purpose?
Kabhi bhi child parent se chhota na rahe.
Code
if(child>=root->data)
    root->data=child;
else
    child=root->data;
Ye sirf tree ko prepare karta hai.
Bottom Up
Recursion ke baad
changeTree(root->left);
changeTree(root->right);
Children already valid ban chuke hain.
Ab
root->data=left+right;*/