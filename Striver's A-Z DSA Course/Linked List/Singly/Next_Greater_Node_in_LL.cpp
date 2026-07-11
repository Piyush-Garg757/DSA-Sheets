/*Next Greater Node In Linked List
You are given the head of a linked list with n nodes.
For each node in the list, find the value of the next greater node. That is, for each node, find the value of the first node that is next to it and has a strictly larger value than it.
Return an integer array answer where answer[i] is the value of the next greater node of the ith node (1-indexed). If the ith node does not have a next greater node, set answer[i] = 0.

Example 1:
Input: head = [2,1,5]
Output: [5,5,0]

Example 2:
Input: head = [2,7,4,3,5]
Output: [7,0,5,5,0]*/

// Brute force (First approach that came to my mind)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        int count = 0;
        ListNode *current = head;
        ListNode *next = nullptr;
        ListNode *prev = nullptr;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            count++;
        }
        vector<int> v(count);
        int k = 0;
        v[k] = 0;
        k++;
        ListNode *p = prev;
        prev = prev->next;
        while (prev)
        {
            if (p->val > prev->val)
            {
                v[k] = p->val;
            }
            else
            {
                int a = 0;
                for (int i = k - 1; i >= 0; i--)
                {
                    if (v[i] > prev->val)
                    {
                        v[k] = v[i];
                        a = 1;
                        break;
                    }
                }
                if (!a)
                    v[k] = 0;
            }
            p = prev;
            prev = prev->next;
            k++;
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
// TC - O(n^2)  SC - O(n)

// Optimal sol

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    vector<int> nextLargerNodes(ListNode *head)
    {
        vector<int> a;
        while (head)
        {
            a.push_back(head->val);
            head = head->next;
        }
        int n = a.size();
        vector<int> ans(n, 0);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && a[i] > a[st.top()])
            {
                ans[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)


/*🔁 Step-by-step Logic

1️⃣ Linked list → array
So that:
index access easy ho
right side traversal simple ho
Example:
[9, 7, 6, 7, 6, 9]

2️⃣ Stack ka rule
Stack monotonic decreasing rahegi
(top pe sabse chhota)
Matlab:
Stack (top) ↓
[9]
[7]
[6]

3️⃣ Traverse array left → right
For each a[i]:
🔹 Jab tak:
stack empty nahi
AND a[i] > a[stack.top()]

Matlab:
current element stack ke top ka next greater hai
➡️ answer set karo
➡️ stack se pop karo

🔹 Fir:
stack.push(i)*/


/*🧪 Dry Run 
Array: [9,7,6,7,6,9]
Ans:   [0,0,0,0,0,0]
Stack: empty

i = 0 → 9
stack = [0]

i = 1 → 7
7 < 9 → push
stack = [0,1]

i = 2 → 6
6 < 7 → push
stack = [0,1,2]

i = 3 → 7
7 > 6 → ans[2]=7, pop
7 == 7 → stop
push 3
stack = [0,1,3]

i = 4 → 6
6 < 7 → push
stack = [0,1,3,4]

i = 5 → 9
9 > 6 → ans[4]=9 pop
9 > 7 → ans[3]=9 pop
9 > 7 → ans[1]=9 pop
9 == 9 → stop
push 5

Final:
ans = [0,9,7,9,9,0]
*/