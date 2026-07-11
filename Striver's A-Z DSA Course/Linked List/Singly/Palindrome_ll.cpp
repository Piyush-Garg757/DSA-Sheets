/*Palindrome Linked List
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

Example 1:
Input: head = [1,2,2,1]
Output: true

Example 2:
Input: head = [1,2]
Output: false*/

// Brute force to vahi ki stack ka use karke

// Optimal

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
    ListNode *reversell(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head)
        {
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *newhead = reversell(slow->next);
        slow->next = newhead;
        ListNode *first = head;
        ListNode *second = newhead;
        while (second)
        {
            if (first->val != second->val)
            {
                reversell(newhead);
                return false;
            }
            first = first->next;
            second = second->next;
        }
        reversell(newhead);
        return true;
    }
};
// TC - O(n)  SC - O(1)