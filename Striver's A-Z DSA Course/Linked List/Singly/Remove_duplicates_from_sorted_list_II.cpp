/*Remove Duplicates from Sorted List II

Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]

Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]*/

// My first approach - Optimal but we are mmodifying ll  which is not right
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return head;
        ListNode *temp = head;
        bool chain = false;
        while (temp->next)
        {
            if (temp->val == temp->next->val)
            {
                temp->val = -101;
                chain = true;
            }
            else
            {
                if (chain)
                    temp->val = -101;
                chain = false;
            }
            temp = temp->next;
        }
        if (chain)
            temp->val = -101;
        temp = head;
        ListNode *newhead = nullptr;
        ListNode *newtemp = nullptr;
        while (temp)
        {
            if (temp->val != -101)
            {
                if (!newhead)
                {
                    newhead = temp;
                    newtemp = newhead;
                }
                else
                {
                    newtemp->next = temp;
                    newtemp = temp;
                }
            }
            temp = temp->next;
        }
        if (newtemp)
            newtemp->next = nullptr;
        return newhead;
    }
};
// TC - O(n)  SC - O(1)

// My second approach
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
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        ListNode *newhead = nullptr;
        ListNode *newtemp = nullptr;
        bool chain = false;
        while (temp->next)
        {
            if (temp->val == temp->next->val)
            {
                chain = true;
            }
            else
            {
                if (!chain)
                {
                    if (!newhead)
                    {
                        newhead = temp;
                        newtemp = newhead;
                    }
                    else
                    {
                        newtemp->next = temp;
                        newtemp = temp;
                    }
                }
                chain = false;
            }
            temp = temp->next;
        }
        if (!chain)
        {
            if (!newhead)
            {
                newhead = temp;
                newtemp = newhead;
            }
            else
            {
                newtemp->next = temp;
                newtemp = temp;
            }
        }
        if (newtemp)
            newtemp->next = nullptr;
        return newhead;
    }
};
// TC - O(n)  SC - O(1)