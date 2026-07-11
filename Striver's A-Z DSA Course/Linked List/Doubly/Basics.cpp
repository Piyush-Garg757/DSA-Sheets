#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *prev = nullptr;
    node *next = nullptr;
};
node *delete_k(node *head, int k)
{
    if (k == 1)
    {
        if (head == nullptr || head->next == nullptr)
            return nullptr;
        node *temp = head;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
    }
    else
    {
        node *temp = head;
        int count = 1;
        while (temp && count < k - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr)
        {
            cout << "K list ke size se bada hai\n";
            return head;
        }
        node *temp3 = temp->next;
        if (temp->next->next != nullptr)
            temp->next->next->prev = temp;
        temp->next = temp->next->next;
        delete temp3;
    }
    return head;
}
node *insert_k(node *head, int k, int data)
{
    if (k == 1)
    {
        node *temp = new node;
        temp->data = data;
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
    else
    {
        node *temp = head;
        int count = 1;
        while (temp && count < k - 1)
        {
            temp = temp->next;
            count++;
        }
        if (temp == nullptr)
        {
            cout << "K list ke size se bada hai\n";
            return head;
        }
        node *newnode = new node;
        newnode->data = data;
        newnode->next = temp->next;
        newnode->prev = temp;
        temp->next = newnode;
        if (temp->next->next)
            temp->next->next->prev = newnode;
    }
    return head;
}
int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    node *head = nullptr;
    node *temp = nullptr;
    for (int i = 0; i < 5; i++)
    {
        if (head == nullptr)
        {
            head = new node;
            head->data = a[i];
            temp = head;
        }
        else
        {
            node *newnode = new node;
            newnode->data = a[i];
            newnode->prev = temp;
            temp->next = newnode;
            temp = newnode;
        }
    }
    temp = head;
    while (temp->next)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << "\n";
    head = delete_k(head, 5);
    temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << "\n";
    head = insert_k(head, 5, 5);
    temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    return 0;
}