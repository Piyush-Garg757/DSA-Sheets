#include <bits/stdc++.h>
using namespace std;
struct node // struct ya class dono hi use kar sakte hain bas class mein members by defautl private hote hain aur strutc mein public
{
public:
    int data;
    node *next = nullptr;
    node(int data /*,node *next*/)
    {
        this->data = data;
        // this->next = next;
    }
};
node *convert(vector<int> &a)
{
    node *head = new node(a[0]);
    node *mover = head;
    for (int i = 1; i < a.size(); i++)
    {
        node *temp = new node(a[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
int main()
{
    // node *y = new node(3, nullptr);
    // cout << y->data;
    vector<int> a{154, 2, 3, 4};
    node *head = convert(a);
    cout << head->data << "\n";
    // Traversal
    node *temp = head;
    while (temp)
    {
        if (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    // head deletion
    node *temp = head;
    head = head->next;
    free(temp);

    // tail deletion
    if (head == nullptr || head->next == nullptr)
        return null;
    else
    {
        node *temp = head;
        while (temp->next->next)
        {
            temp = temp->next;
        }
        free(temp->next);
        temp->next=nullptr;
    }

    // Deleting kth node
    // ismein k=1 ke liye alag case banega head vala baaki ke liye normally count k-1 pe jab hoga to temp->next=temp->next->next aur free(temp->next)

    // similarly for insertion
    return 0;
}