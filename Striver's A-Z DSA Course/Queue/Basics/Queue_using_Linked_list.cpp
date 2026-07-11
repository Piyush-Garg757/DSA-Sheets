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
class Queue
{
    Node *front;
    Node *rear;
    int cnt;

public:
    Queue()
    {
        front = nullptr;
        rear = nullptr;
        cnt = 0;
    }
    void push(int x)
    {
        Node *newNode = new Node(x);
        if (!rear)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        cnt++;
    }
    void pop()
    {
        if (!front)
            return;
        Node *temp = front;
        front = front->next;
        delete temp;
        cnt--;
        if (!front)
            rear = nullptr;
    }
    int frontElement()
    {
        if (!front)
            return -1;
        return front->data;
    }
    bool isEmpty()
    {
        return front == nullptr;
    }
    int size()
    {
        return cnt;
    }
};