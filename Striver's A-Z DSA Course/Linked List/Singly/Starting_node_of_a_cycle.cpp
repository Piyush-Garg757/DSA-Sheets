// Brute force to vahi unordered set mein node store karte chalenge aur fir match hone pe starting node return kar denge

// Optimal sol

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
    ListNode *detectCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        bool check = false;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                check = true;
                break;
            }
        }
        if (!check)
            return nullptr;
        fast = head;
        while (fast != slow)
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
// TC - O(n)  SC - O(1)

/*
two questions arise
    Q1. Why are w esure they will collide ?
    Q2. How are we sure they collide at the starting point?
    
    Distance notation:
head → x → [ LOOP START ] → y → [ MEETING POINT ]
                         ↖────── c ──────↙
x = head se loop start tak
y = loop start se meeting tak
c = loop length
Movement math:
Slow travelled = x + y
Fast travelled = x + y + c
But:
fast = 2 × slow
So:
2(x + y) = x + y + c
x + y = c
x = c − y
🔥 Key insight
Meeting point se loop start tak distance = c − y
Head se loop start tak distance = x
And:
x = c − y
👉 Matlab:
Ek pointer head se chalao
Ek pointer meeting point se
Same speed (1 step)
✅ Dono exactly loop ke starting node pe milenge*/