// jitne bhi nodes aa rahe hn us value ke unhein delete kar do

Node *deleteAllOccurrences(Node *head, int k)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = temp->next;
            }
            Node *nextNode = temp->next;
            Node *prevNode = temp->prev;
            if (nextNode != NULL)
                nextNode->prev = prevNode;
            if (prevNode != NULL)
                prevNode->next = nextNode;
            free(temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}
// TC - O(n)  SC - O(1)