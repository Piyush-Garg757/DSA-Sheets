// Brute force -> ek unordered_set banao aur usmein daalte jao nodes har baar daalne se pehel chehck karo agar alreayd present hai to     aur agar aisa hai to true return kar do varna aage badho    aur end mein false return kar do

// Optimal sol

/*intution
assume karo slow loop ke shuru pe khada hai aur fast aage kahi hai to fast aur slow ke beech mein d nodes hain    ab agli baar slow ek aage adhega aur fast 2   yani fast slow ki taraf do se badha aur slow fast se dur ek se badha to net ye raha ki fast slow ki taraf ek se badha aur d-- ho gaya   to aise hi karte karte har step mein d-- hoga aur kabhi na kabhi d 0 hoga tab ye meet karenge*/

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
    bool hasCycle(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
                return true;
        }
        return false;
    }
};
// TC - O(n)  SC - O(1)