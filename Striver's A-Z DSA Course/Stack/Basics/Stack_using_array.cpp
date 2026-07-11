class Stack
{
    int arr[100000];
    int top;

public:
    Stack()
    {
        top = -1;
    }
    void push(int x)
    {
        if (top != 100000 - 1)
            arr[++top] = x;
    }
    void pop()
    {
        if (top != -1)
            top--;
    }
    int peek()
    {
        if (top == -1)
            return -1;
        return arr[top];
    }
    bool isEmpty()
    {
        return top == -1;
    }
    int size()
    {
        return top + 1;
    }
};