/* ek linked list mein 1 add karna hai */

// Brute force

class Solution
{
public:
    ListNode *reverse(ListNode *head)
    {
        ListNode *prev = nullptr;
        while (head)
        {
            ListNode *nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }
        return prev;
    }

    ListNode *addOne(ListNode *head)
    {
        head = reverse(head);

        ListNode *temp = head;
        int carry = 1;

        while (temp && carry)
        {
            int sum = temp->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;

            if (!temp->next && carry)
            {
                temp->next = new ListNode(carry);
                carry = 0;
            }
            temp = temp->next;
        }

        return reverse(head);
    }
};
// TC - O(3*n)  SC - O(1)

// Optimal sol -> using recurssion backtracking

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *createLinkedList(int arr[], int n)
{
    if (n == 0)
        return NULL;

    Node *head = new Node(arr[0]);
    Node *temp = head;

    for (int i = 1; i < n; i++)
    {
        temp->next = new Node(arr[i]);
        temp = temp->next;
    }
    return head;
}

void printLinkedList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int helper(Node *temp)
{
    if (temp == nullptr)
        return 1;
    int carry = helper(temp->next);
    temp->data += carry;
    if (temp->data >= 10)
    {
        temp->data = 0;
        return 1;
    }
    return 0;
}

Node *add1(Node *head)
{
    int carry = helper(head);
    if (carry)
    {
        Node *newnode = new Node(1);
        newnode->next = head;
        return newnode;
    }
    return head;
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    Node *head = createLinkedList(arr, n);

    cout << "Linked List: ";
    head = add1(head);
    printLinkedList(head);

    return 0;
}
// TC - O(n)  SC - O(n)