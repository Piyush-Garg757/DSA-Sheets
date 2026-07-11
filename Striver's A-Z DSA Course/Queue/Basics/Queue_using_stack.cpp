// Approach 1
/*This is the optimal and interview-preferred solution.
Idea
Maintain:
s1 → for pushing
s2 → for popping
When s2 becomes empty, transfer all elements from s1 to s2.*/
class Queue
{
    stack<int> s1, s2;

public:
    void push(int x)
    {
        s1.push(x);
    }
    void pop()
    {
        if (isEmpty())
            return;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        s2.pop();
    }
    int front()
    {
        if (isEmpty())
            return -1;
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    bool isEmpty()
    {
        return s1.empty() && s2.empty();
    }
    int size()
    {
        return s1.size() + s2.size();
    }
};

// Approach 2
/*Idea
For every push(x):
Move everything from s1 to s2.
Push x into s1.
Move everything back from s2 to s1.
Now the oldest element always remains on the top of s1.*/
class Queue
{
    stack<int> s1, s2;

public:
    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }
    void pop()
    {
        if (!s1.empty())
            s1.pop();
    }
    int front()
    {
        if (s1.empty())
            return -1;

        return s1.top();
    }
    bool isEmpty()
    {
        return s1.empty();
    }
    int size()
    {
        return s1.size();
    }
};