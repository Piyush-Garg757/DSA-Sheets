/*Remove Nodes From Linked List

You are given the head of a linked list.
Remove every node which has a node with a greater value anywhere to the right side of it.
Return the head of the modified linked list.

Example 1:
Input: head = [5,2,13,3,8]
Output: [13,8]
Explanation: The nodes that should be removed are 5, 2 and 3.
- Node 13 is to the right of node 5.
- Node 13 is to the right of node 2.
- Node 8 is to the right of node 3.

Example 2:
Input: head = [1,1,1,1]
Output: [1,1,1,1]
Explanation: Every node has value 1, so no nodes are removed.*/

// My first approach
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *solve(ListNode *head, stack<ListNode *> &st)
    {
        if (!head->next)
        {
            st.push(head);
            return head;
        }
        ListNode *rightmost = solve(head->next, st);
        if (head->val >= rightmost->val)
        {
            st.push(head);
            return head;
        }
        return rightmost;
    }
    ListNode *removeNodes(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        stack<ListNode *> st;
        solve(head, st);
        ListNode *dummy = new ListNode(-1);
        ListNode *dummytemp = dummy;
        while (!st.empty())
        {
            dummytemp->next = st.top();
            dummytemp = dummytemp->next;
            st.pop();
        }
        return dummy->next;
    }
};
// TC - O(n)  SC - O(n)

// Without using stack
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *solve(ListNode *head, ListNode *prev)
    {
        if (!head->next)
        {
            return head;
        }
        ListNode *rightmost = solve(head->next, head);
        if (head->val < rightmost->val)
        {
            prev->next = rightmost;
            return rightmost;
        }
        return head;
    }
    ListNode *removeNodes(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *dummy = new ListNode(-1);
        ListNode *dummytemp = dummy;
        dummy->next = head;
        solve(head, dummy);
        return dummy->next;
    }
};
// TC - O(n)  SC - O(n)