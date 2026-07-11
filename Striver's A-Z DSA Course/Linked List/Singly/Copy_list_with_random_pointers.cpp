/*Copy List with Random Pointer

A linked list of length n is given such that each node contains an additional random pointer, which could point to any node in the list, or null.
Construct a deep copy of the list. The deep copy should consist of exactly n brand new nodes, where each new node has its value set to the value of its corresponding original node. Both the next and random pointer of the new nodes should point to new nodes in the copied list such that the pointers in the original list and copied list represent the same list state. None of the pointers in the new list should point to nodes in the original list.
For example, if there are two nodes X and Y in the original list, where X.random --> Y, then for the corresponding two nodes x and y in the copied list, x.random --> y.
Return the head of the copied linked list.
The linked list is represented in the input/output as a list of n nodes. Each node is represented as a pair of [val, random_index] where:
val: an integer representing Node.val
random_index: the index of the node (range from 0 to n-1) that the random pointer points to, or null if it does not point to any node.
Your code will only be given the head of the original linked list.

Example 1:
Input: head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
Output: [[7,null],[13,0],[11,4],[10,2],[1,0]]

Example 2:
Input: head = [[1,1],[2,1]]
Output: [[1,1],[2,1]]

Example 3:
Input: head = [[3,null],[3,0],[3,null]]
Output: [[3,null],[3,0],[3,null]]*/

// Brute force approach
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        unordered_map<Node *, Node *> mpp;
        Node *temp = head;
        while (temp)
        {
            Node *newnode = new Node(temp->val);
            mpp[temp] = newnode;
            temp = temp->next;
        }
        temp = head;
        while (temp)
        {
            if (temp->next)
            {
                mpp[temp]->next = mpp[temp->next];
            }
            else
                mpp[temp]->next = nullptr;
            if (temp->random)
            {
                mpp[temp]->random = mpp[temp->random];
            }
            else
                mpp[temp]->random = nullptr;
            temp = temp->next;
        }
        return mpp[head];
    }
};
// TC - O(n)  SC - O(n)

// Optimal approach - Jo naye nodes bana rahe ho unko originl nodes ke just baad hi add kar do jaise 1->2->3 ka 1->1->2->2->3->3  aise  fir next iteration mein random pointers ko connect karo   fir next oteration mein next pointers ko 
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        while (temp)
        {
            Node *newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = newnode->next;
        }
        temp = head;
        while (temp)
        {
            if (temp->random != nullptr)
                temp->next->random = temp->random->next;
            else
                temp->next->random = nullptr;
            temp = temp->next->next;
        }
        Node *dummy = new Node(-1);
        Node *dummytemp = dummy;
        temp = head;
        while (temp)
        {
            dummytemp->next = temp->next;
            dummytemp = temp->next;
            temp->next = dummytemp->next;
            temp = temp->next;
        }
        return dummy->next;
    }
};
// TC - O(n)  SC - O(1)