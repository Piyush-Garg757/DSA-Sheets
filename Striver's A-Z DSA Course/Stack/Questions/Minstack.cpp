/*Min Stack

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
Implement the MinStack class:
MinStack() initializes the stack object.
void push(int value) pushes the element value onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.

Example 1:
Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
Output
[null,null,null,null,-3,null,0,-2]
Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2*/

class MinStack
{
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int value)
    {
        if (st.empty())
            st.push({value, value});
        else
        {
            st.push({value, min(value, st.top().second)});
        }
    }

    void pop()
    {
        st.pop();
    }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// TC - O(1)  SC - O(2*n)

// Optimal sol
class MinStack
{
    stack<long long> st;
    long long mini;

public:
    MinStack() { mini = LONG_MAX; }

    void push(int value)
    {
        if (st.empty())
        {
            mini = value;
            st.push(value);
        }
        else
        {
            if (value < mini)
            {
                st.push(2ll * value - mini);
                mini = value;
            }
            else
            {
                st.push(value);
            }
        }
    }

    void pop()
    {
        if (st.top() < mini)
        {
            mini = 2 * mini - st.top();
        }
        st.pop();
    }

    int top()
    {
        if (mini > st.top())
            return mini;
        return st.top();
    }

    int getMin() { return mini; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */

 /*Intution - 
Instead of pushing 2,
push some encoded number which remembers both
previous minimum
current minimum

That encoded number is
2*value - oldMin

Why this formula?
Suppose
oldMin = 5
newMin = 2
Store
2*2-5 = -1
Instead of
2
Stack becomes
5
-1
and
mini = 2
Notice
-1 < 2
Interesting!

Every encoded value is always smaller than the current minimum.
Proof
Since
value < oldMin
then
2*value-oldMin < value
because
value-oldMin < 0
Hence
encoded < value
and
value = current minimum
Therefore
encoded < current minimum
This becomes our marker.

Detecting encoded values
Whenever
st.top() < mini
we know
"This isn't a real value.
It is an encoded value."
Why does top() return mini?
Suppose stack stores
5
-1
Actual stack should have been
5
2
Top is
-1
But that's fake.
Real top is
mini
Hence
if(st.top()<mini)
    return mini;

Recovering old minimum
Suppose
oldMin = 5
newMin = 2
encoded = -1
Now we pop.
Current
mini =2
top=-1
Need
oldMin=5
We know
encoded=2*newMin-oldMin
Rearrange
oldMin=2*newMin-encoded
Exactly the code
mini=2*mini-st.top();

Done.*/