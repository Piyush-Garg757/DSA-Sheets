class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class Stack
{
    Node *top;
    int cnt;

public:
    Stack()
    {
        top = nullptr;
        cnt = 0;
    }
    void push(int x)
    {
        Node *newNode = new Node(x);
        newNode->next = top;
        top = newNode;
        cnt++;
    }
    void pop()
    {
        if (!top)
            return;
        Node *temp = top;
        top = top->next;
        delete temp;
        cnt--;
    }
    int peek()
    {
        if (!top)
            return -1;
        return top->data;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    int size()
    {
        return cnt;
    }
};