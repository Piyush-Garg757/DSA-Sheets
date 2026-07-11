/*Rotate List
Given the head of a linked list, rotate the list to the right by k places.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [4,5,1,2,3]

Example 2:
Input: head = [0,1,2], k = 4
Output: [2,0,1]*/

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
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!head || !head->next || k == 0)
            return head;
        ListNode *temp = head;
        int size = 1;
        while (temp->next)
        {
            temp = temp->next;
            size++;
        }
        temp->next = head;
        k = k % size;
        int steps = size - k;
        while (steps--)
        {
            temp = temp->next;
        }
        ListNode *newhead = temp->next;
        temp->next = nullptr;
        return newhead;
    }
};
// TC - O(n)  SC - O(1)