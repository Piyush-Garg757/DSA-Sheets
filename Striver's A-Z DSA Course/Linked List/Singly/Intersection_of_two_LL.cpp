/*Intersection of Two Linked Lists
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
For example, the following two linked lists begin to intersect at node c1:
The test cases are generated such that there are no cycles anywhere in the entire linked structure
Note that the linked lists must retain their original structure after the function returns.
Custom Judge:
The inputs to the judge are given as follows (your program is not given these inputs):
intersectVal - The value of the node where the intersection occurs. This is 0 if there is no intersected node.
listA - The first linked list.
listB - The second linked list.
skipA - The number of nodes to skip ahead in listA (starting from the head) to get to the intersected node.
skipB - The number of nodes to skip ahead in listB (starting from the head) to get to the intersected node.
The judge will then create the linked structure based on these inputs and pass the two heads, headA and headB to your program. If you correctly return the intersected node, then your solution will be accepted.

Example 1:
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Intersected at '8'
Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; There are 3 nodes before the intersected node in B.
- Note that the intersected node's value is not 1 because the nodes with value 1 in A and B (2nd node in A and 3rd node in B) are different node references. In other words, they point to two different locations in memory, while the nodes with value 8 in A and B (3rd node in A and 4th node in B) point to the same location in memory.


Example 2:
Input: intersectVal = 2, listA = [1,9,1,2,4], listB = [3,2,4], skipA = 3, skipB = 1
Output: Intersected at '2'
Explanation: The intersected node's value is 2 (note that this must not be 0 if the two lists intersect).
From the head of A, it reads as [1,9,1,2,4]. From the head of B, it reads as [3,2,4]. There are 3 nodes before the intersected node in A; There are 1 node before the intersected node in B.


Example 3:
Input: intersectVal = 0, listA = [2,6,4], listB = [1,5], skipA = 3, skipB = 2
Output: No intersection
Explanation: From the head of A, it reads as [2,6,4]. From the head of B, it reads as [1,5]. Since the two lists do not intersect, intersectVal must be 0, while skipA and skipB can be arbitrary values.
Explanation: The two lists do not intersect, so return null.*/

// Brute force

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        unordered_set<ListNode *> st;
        while (head1)
        {
            st.insert(head1);
            head1 = head1->next;
        }
        while (head2)
        {
            if (st.count(head2))
            {
                return head2;
            }
            head2 = head2->next;
        }
        return nullptr;
    }
};
// TC - O(n+m)  SC - O(n)\

// Better sol - > karenge kya ki dono mein se jiski length badi hogi uspe temp rakhke aage badha denge jab tak uski length choti vali ke equal na ho jaye   fir jab dono temp same node pe honge to hum compare kar lenge normally

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        if (!head1 || !head2)
            return nullptr;
        int c1 = 0, c2 = 0;
        ListNode *t1 = head1;
        ListNode *t2 = head2;
        while (t1)
        {
            c1++;
            t1 = t1->next;
        }
        while (t2)
        {
            c2++;
            t2 = t2->next;
        }
        t1 = head1;
        t2 = head2;
        if (c1 > c2)
        {
            while (c1-- > c2)
                t1 = t1->next;
        }
        else
        {
            while (c2-- > c1)
                t2 = t2->next;
        }
        while (t1 && t2)
        {
            if (t1 == t2)
                return t1;
            t1 = t1->next;
            t2 = t2->next;
        }
        return nullptr;
    }
};
// TC - O(n1+2*n2)  SC - O(1)

// Optimal sol -> temp1 khatam hote hi use head 2 se shuru kara do ar aise hi temp2 khatam hote hi use temp1 se shuru kara do aur jab tak dono ek saath null na ho loop chalne do

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2)
    {
        ListNode *temp1 = head1;
        ListNode *temp2 = head2;
        while (temp1 && temp2)
        {
            if (temp1 == temp2)
                return temp2;
            temp1 = temp1->next;
            temp2 = temp2->next;
            if (temp1 == nullptr)
                temp1 = head2;
            else if (temp2 == nullptr)
                temp2 = head1;
        }
        return nullptr;
    }
};
// TC - O(n+m)  SC - O(1)