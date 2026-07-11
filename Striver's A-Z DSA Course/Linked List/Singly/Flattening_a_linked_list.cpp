/*Flattening a Linked List

Given a linked list containing n head nodes where every node in the linked list contains two pointers:
(i) next points to the next node in the list.
(ii) bottom points to a sub-linked list where the current node is the head.
Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.
Note:
1. ↓ represents the bottom pointer and → represents the next pointer.
2. The flattened list will be printed using the bottom pointer instead of the next pointer.

Examples:

Input:
Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 10 is pointing to 20 and so on.
So, after flattening the linked list the sorted list will be
5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.

Input:
Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50
Explanation:
Bottom pointer of 5 is pointing to 7.
Bottom pointer of 7 is pointing to 8.
Bottom pointer of 8 is pointing to 30 and so on.
So, after flattening the linked list the sorted list will be
5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.*/

// Brute force to vahi ki traverse karte hue array mein push kar do fir array sort karo fir us se ll banao 

// Optimal sol - 2 2 linked list lo aur unhi ke nodes ko use karke merged banate hue chalo
/*
class Node {
    public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = nullptr;
        bottom = nullptr;
    }
}; */

class Solution
{
public:
    Node *merge(Node *h1, Node *h2)
    {
        if (!h1)
            return h2;
        if (!h2)
            return h1;
        Node *dummy = new Node(-1);
        Node *dummytemp = dummy;
        dummytemp->next = nullptr;
        while (h1 && h2)
        {
            if (h1->data <= h2->data)
            {
                dummytemp->bottom = h1;
                dummytemp = h1;
                h1 = h1->bottom;
            }
            else
            {
                dummytemp->bottom = h2;
                dummytemp = h2;
                h2 = h2->bottom;
            }
            dummytemp->next = nullptr;
        }
        if (h1)
            dummytemp->bottom = h1;
        else if (h2)
            dummytemp->bottom = h2;
        dummytemp->next = nullptr;
        return dummy->bottom;
    }
    Node *flatten(Node *head)
    {
        // code here
        if (!head || !head->next)
            return head;
        Node *temp = head;
        Node *merged = nullptr;
        while (temp)
        {
            Node *nxt = temp->next;
            merged = merge(merged, temp);
            temp = nxt;
        }
        return merged;
    }
};

// TC - O(n*m)  SC - O(1)