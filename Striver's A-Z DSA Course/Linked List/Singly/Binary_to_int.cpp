/*Convert Binary Number in a Linked List to Integer
Given head which is a reference node to a singly-linked list. The value of each node in the linked list is either 0 or 1. The linked list holds the binary representation of a number.
Return the decimal value of the number in the linked list.
The most significant bit is at the head of the linked list.


Example 1:
Input: head = [1,0,1]
Output: 5
Explanation: (101) in base 2 = (5) in base 10

Example 2:
Input: head = [0]
Output: 0*/

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
    ListNode *reverse_list(ListNode *l1)
    {
        ListNode *current = l1;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }
    int getDecimalValue(ListNode *head)
    {
        head = reverse_list(head);
        ListNode *temp = head;
        int p = 1, ans = 0;
        while (temp)
        {
            ans += p * temp->val;
            p *= 2;
            temp = temp->next;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)

// Best approach

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
    int getDecimalValue(ListNode *head)
    {
        int ans = 0;
        while (head)
        {
            ans = (ans << 1) | head->val;
            head = head->next;
        }
        return ans;
    }
};
// TC - O(n)  SC - O(1)