// Brute force -> traverse karte hue elements stack mein push kar do aur fir se traverse karo aur pop karte jao
// SC - O(n)  TC - O(n)

// Most optimal

Node *reverseDLL(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node *curr = head;
    Node *last = nullptr;

    while (curr)
    {
        last = curr->prev;
        curr->prev = curr->next;
        curr->next = last;
        curr = curr->prev;
    }

    return last ? last->prev : head;
}
// TC - O(n)  SC - O(1)