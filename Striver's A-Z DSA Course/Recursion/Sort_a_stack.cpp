/*Sort a stack

Given a stack of integers st[]. Sort the stack in ascending order (smallest element at the bottom and largest at the top).
Examples:
Input: st[] = [41, 3, 32, 2, 11]
Output: [41, 32, 11, 3, 2]
Explanation: After sorting, the smallest element (2) is at the bottom and the largest element (41) is at the top.

Input: st[] = [3, 2, 1]
Output: [3, 2, 1]
Explanation: The stack is already sorted in ascending order.
*/

// Most optimal to obviously array mein store kar lo fir array ko sort fir push 
// Using recursion
class Solution
{
public:
    void push_correct(int val, stack<int> &st)
    {
        if (st.empty() || st.top() <= val)
        {
            st.push(val);
            return;
        }
        int data = st.top();
        st.pop();
        push_correct(val, st);
        st.push(data);
    }
    void sortStack(stack<int> &st)
    {
        // code here
        if (st.empty())
            return;
        int data = st.top();
        st.pop();
        sortStack(st);
        push_correct(data, st);
    }
};
// TC - O(n^2)  SC - O(n)