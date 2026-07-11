/*Remove Nth Node From End of List
Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]*/

// Brute force kyuki ismein do baar iterate karenge
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *temp = head;
        int size = 0;
        while (temp)
        {
            size++;
            temp = temp->next;
        }
        if (size == n)
        {
            ListNode *newnode = head;
            head = head->next;
            delete newnode;
            return head;
        }
        int steps = size - n - 1;
        temp = head;
        while (steps--)
        {
            temp = temp->next;
        }
        ListNode *newnode = temp->next;
        temp->next = temp->next->next;
        delete newnode;
        return head;
    }
};
// TC - O(n)  SC - O(1)

// Optimal  ismein ek hi baar iterate hoga
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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        for (int i = 0; i < n; i++)
            fast = fast->next;
        if (fast == nullptr)
        {
            ListNode *newnode = head;
            head = head->next;
            delete newnode;
            return head;
        }
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
        ListNode *newnode = slow->next;
        slow->next = slow->next->next;
        delete newnode;
        return head;
    }
};
// TC - O(n)  SC - O(1)