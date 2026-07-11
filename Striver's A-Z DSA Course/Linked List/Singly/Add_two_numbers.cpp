/*Add Two Numbers
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]
Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]*/

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *tempnode = new ListNode(-1);
        ListNode *curr = tempnode;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int carry = 0;
        while (temp1 || temp2)
        {
            int sum = carry;
            if (temp2)
                sum += temp2->val;
            if (temp1)
                sum += temp1->val;
            ListNode *newnode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = newnode;
            if (temp2)
                temp2 = temp2->next;
            if (temp1)
                temp1 = temp1->next;
        }
        if (carry)
        {
            ListNode *newnode = new ListNode(carry);
            curr->next = newnode;
            curr = newnode;
        }
        return tempnode->next;
    }
};
// TC - O(n)  SC - O(1)

// Ismien dummy node lene se initialisatin vagera mein fayda rehta hai isiliye liya hai  to aage dhyaan rakhn agar alag hi linked list banani hai to dummy node leke karna


/*Add Two Numbers II
You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
Input: l1 = [7,2,4,3], l2 = [5,6,4]
Output: [7,8,0,7]

Example 2:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [8,0,7]

Example 3:
Input: l1 = [0], l2 = [0]
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
    ListNode *addTwoNumbers(ListNode *h1, ListNode *h2)
    {
        ListNode *l1 = reverse_list(h1);
        ListNode *l2 = reverse_list(h2);
        ListNode *tempnode = new ListNode(-1);
        ListNode *curr = tempnode;
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        int carry = 0;
        while (temp1 || temp2)
        {
            int sum = carry;
            if (temp2)
                sum += temp2->val;
            if (temp1)
                sum += temp1->val;
            ListNode *newnode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = newnode;
            if (temp2)
                temp2 = temp2->next;
            if (temp1)
                temp1 = temp1->next;
        }
        if (carry)
        {
            ListNode *newnode = new ListNode(carry);
            curr->next = newnode;
            curr = newnode;
        }
        ListNode *final_node = reverse_list(tempnode->next);
        return final_node;
    }
};
// TC - O(n+m)  SC - O(1)