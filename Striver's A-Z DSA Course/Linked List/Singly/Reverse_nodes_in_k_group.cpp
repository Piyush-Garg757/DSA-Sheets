/*Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]*/

// Jo pehli approach mann mein aati hai vahi hai bas use implement karna thoda mushkil hai jo nodes aage chahiye ya [eeche chahiye unhein preserve karna padta hai and thats all
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
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        ListNode *curr = head;
        while (curr)
        {
            ListNode *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    ListNode *find_k(ListNode *head, int k)
    {
        ListNode *temp = head;
        k--;
        while (k)
        {
            if (temp)
            {
                temp = temp->next;
                k--;
            }
            else
                return nullptr;
        }
        return temp;
    }
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        if (!head || !head->next)
            return head;
        ListNode *temp = head;
        ListNode *prev = nullptr;
        while (temp)
        {
            ListNode *kth = find_k(temp, k);
            if (kth)
            {
                ListNode *next = kth->next;
                kth->next = nullptr;
                reverse(temp);
                if (temp == head)
                {
                    head = kth;
                }
                else
                {
                    prev->next = kth;
                }
                prev = temp;
                temp = next;
            }
            else
            {
                if (prev)
                    prev->next = temp;
                break;
            }
        }
        return head;
    }
};
// TC - O(n)  SC - O(1)