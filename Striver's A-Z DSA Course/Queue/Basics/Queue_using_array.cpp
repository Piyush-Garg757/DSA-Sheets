class Queue
{
    int arr[100000];
    int front, rear, cnt;

public:
    Queue()
    {
        front = 0;
        rear = 0;
        cnt = 0;
    }
    void push(int x)
    {
        if (cnt == 100000)
            return; // Queue Overflow
        arr[rear] = x;
        rear = (rear + 1) % 100000;
        cnt++;
    }
    void pop()
    {
        if (cnt == 0)
            return; // Queue Underflow
        front = (front + 1) % 100000;
        cnt--;
    }
    int frontElement()
    {
        if (cnt == 0)
            return -1;
        return arr[front];
    }
    bool isEmpty()
    {
        return cnt == 0;
    }
    int size()
    {
        return cnt;
    }
};