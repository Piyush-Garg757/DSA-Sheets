class Stack
{
    queue<int> q;

public:
    void push(int x)
    {
        q.push(x);
        int sz = q.size();
        while (sz > 1)
        {
            q.push(q.front());
            q.pop();
            sz--;
        }
    }
    void pop()
    {
        if (!q.empty())
            q.pop();
    }
    int top()
    {
        if (q.empty())
            return -1;
        return q.front();
    }
    bool isEmpty()
    {
        return q.empty();
    }
    int size()
    {
        return q.size();
    }
};
/*Idea

After every push(x):

Push x.
Rotate the previous elements to the back.

This keeps the top element always at the front.*/