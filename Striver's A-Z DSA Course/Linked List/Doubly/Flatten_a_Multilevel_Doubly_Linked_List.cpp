/*Flatten a Multilevel Doubly Linked List

You are given a doubly linked list, which contains nodes that have a next pointer, a previous pointer, and an additional child pointer. This child pointer may or may not point to a separate doubly linked list, also containing these special nodes. These child lists may have one or more children of their own, and so on, to produce a multilevel data structure as shown in the example below.
Given the head of the first level of the list, flatten the list so that all the nodes appear in a single-level, doubly linked list. Let curr be a node with a child list. The nodes in the child list should appear after curr and before curr.next in the flattened list.
Return the head of the flattened list. The nodes in the list must have all of their child pointers set to null.

Example 1:
Input: head = [1,2,3,4,5,6,null,null,null,7,8,9,10,null,null,11,12]
Output: [1,2,3,7,8,11,12,9,10,4,5,6]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 2:
Input: head = [1,2,null,3]
Output: [1,3,2]
Explanation: The multilevel linked list in the input is shown.
After flattening the multilevel linked list it becomes:

Example 3:
Input: head = []
Output: []
Explanation: There could be empty list in the input.*/

// My first approach
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return head;
        Node *dummy = new Node;
        Node *dummytemp = dummy;
        Node *temp = head;
        while (temp)
        {
            dummytemp->next = temp;
            temp->prev = dummytemp;
            dummytemp = temp;
            Node *nxt = temp->next;
            if (temp->child)
            {
                Node *h = flatten(temp->child);
                dummytemp->next = h;
                h->prev = dummytemp;
                dummytemp->child = nullptr;
                while (dummytemp->next)
                    dummytemp = dummytemp->next;
            }
            temp = nxt;
        }
        Node *ans = dummy->next;
        if (ans)
            ans->prev = nullptr;
        return ans;
    }
};
// TC - O(n^2)  SC - O(n)

// Most optimal sol
/*while (dummytemp->next)
                    dummytemp = dummytemp->next;  basically jo hum ye kar rahe hain tail nikalne ke liye usi ki wajah se O(n^2) ho raha hai to humein use hatana hai bas to  ek aisa function likhenge jo tail return kare*/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution
{
public:
    Node *dfs(Node *head)
    {
        Node *temp = head;
        Node *tail = head;
        while (temp)
        {
            Node *nxt = temp->next;
            if (temp->child)
            {
                Node *childHead = temp->child;
                Node *childTail = dfs(childHead);
                temp->next = childHead;
                childHead->prev = temp;
                temp->child = nullptr;
                if (nxt)
                {
                    childTail->next = nxt;
                    nxt->prev = childTail;
                }
                tail = childTail;
            }
            else
            {
                tail = temp;
            }
            temp = nxt;
        }
        return tail;
    }
    Node *flatten(Node *head)
    {
        if (!head)
            return head;
        dfs(head);
        return head;
    }
};
// TC - O(n)  SC - O(n)