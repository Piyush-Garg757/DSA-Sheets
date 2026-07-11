/*Sort List

Given the head of a linked list, return the list after sorting it in ascending order.

Example 1:
Input: head = [4,2,1,3]
Output: [1,2,3,4]

Example 2:
Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]

Example 3:
Input: head = []
Output: []*/

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
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        ListNode *dummy = new ListNode(-1);
        ListNode *dummytemp = dummy;
        ListNode *temp = head;
        while (temp)
        {
            pq.push(temp);
            temp = temp->next;
        }
        while (!pq.empty())
        {
            ListNode *n = pq.top();
            pq.pop();
            dummytemp->next = n;
            dummytemp = n;
        }
        if (dummytemp)
            dummytemp->next = nullptr;
        return dummy->next;
    }
};
// TC - O(nlogn)  SC - O(n)

// Most optimal approach - Merge sort
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
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        if (!h1)
            return h2;
        if (!h2)
            return h1;
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                tail->next = h1;
                h1 = h1->next;
            }
            else
            {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }
        tail->next = (h1 ? h1 : h2);
        return dummy.next;
    }
    ListNode *findMiddle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    ListNode *sortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *middle = findMiddle(head);
        ListNode *righthead = middle->next;
        ListNode *lefthead = head;
        middle->next = nullptr;
        lefthead = sortList(lefthead);
        righthead = sortList(righthead);
        return merge(lefthead, righthead);
    }
};
// TC - O(nlogn)  SC - O(logn) recurssion stack