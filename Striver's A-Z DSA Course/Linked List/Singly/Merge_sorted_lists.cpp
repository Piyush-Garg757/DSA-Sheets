/*Merge Two Sorted Lists
You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]*/

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
    ListNode *mergeTwoLists(ListNode *a, ListNode *b)
    {
        if (a == nullptr)
            return b;
        if (b == nullptr)
            return a;
        ListNode dummy(-1);
        ListNode *prev = &dummy;
        prev->next = a;
        ListNode *temp1 = a;
        ListNode *temp2 = b;
        while (temp1 && temp2)
        {
            if (temp1->val <= temp2->val)
            {
                prev = temp1;
                temp1 = temp1->next;
            }
            else
            {
                ListNode *node = temp2;
                temp2 = temp2->next;
                prev->next = node;
                node->next = temp1;
                prev = node;
            }
        }
        if (temp2 != nullptr)
        {
            prev->next = temp2;
        }
        return dummy.next;
    }
};
// TC - O(n)  SC - O(1)