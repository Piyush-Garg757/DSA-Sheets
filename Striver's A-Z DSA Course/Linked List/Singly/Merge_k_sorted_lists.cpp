/*Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted linked list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []*/

// My first approach
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
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        if (!h2)
            return h1;
        if (!h1)
            return h2;
        ListNode *dummy = new ListNode(-1);
        ListNode *dummytemp = dummy;
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                dummytemp->next = h1;
                dummytemp = h1;
                h1 = h1->next;
            }
            else
            {
                dummytemp->next = h2;
                dummytemp = h2;
                h2 = h2->next;
            }
        }
        if (h1)
            dummytemp->next = h1;
        else if (h2)
            dummytemp->next = h2;
        return dummy->next;
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        ListNode *merged = nullptr;
        for (int i = 0; i < lists.size(); i++)
        {
            merged = merge(merged, lists[i]);
        }
        return merged;
    }
};
// TC - O(n*k)  SC - O(1)

// Better sol
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
    struct cmp
    {
        bool operator()(ListNode *a, ListNode *b) { return a->val > b->val; }
    };
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pq;
        for (auto node : lists)
            if (node)
                pq.push(node);
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while (!pq.empty())
        {
            ListNode *node = pq.top();
            pq.pop();
            tail->next = node;
            tail = node;
            if (node->next)
                pq.push(node->next);
        }
        return dummy.next;
    }
};
// TC - O(nlogk)  SC - O(k)
/*Step 1: Normal Priority Queue
Normal max heap
priority_queue<int> pq;
Store karta hai
9
7
5
2
1
pq.top()
gives
9

Step 2: Min Heap
C++ by default max heap banata hai.
Min heap ke liye
priority_queue<int, vector<int>, greater<int>> pq;
ab
1
2
5
7
9
Top
1

Step 3
Ab hum ints nahi
ListNode*
store karna chahte hain.
To likhenge
priority_queue<ListNode*>

Problem ye hai ki compiler ko nahi pata
Do nodes ko compare kaise karna hai?
Node ka address compare kare?
Value compare kare?
Isliye comparator banana padta hai.

Step 4 Comparator
struct cmp {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};
Ye function bas itna bol raha hai
Agar
a->val > b->val
to
true
return karo.
Isse priority queue ko pata chal jaata hai ki
small value ko upar rakhna hai.

Step 5
Ab syntax
priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
iska matlab hai
First parameter
ListNode*
Heap kis type ki cheez store karegi?
Answer
ListNode*
Second parameter
vector<ListNode*>
Heap internally kis container ka use karegi?
Usually
vector
Third parameter
cmp
Comparison ka rule.
Ye teeno milke
priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
banate hain.

Dry Run
Suppose
3 lists hain

1->4->8
2->3->7
5->6

Initially hum sirf heads daalte hain.

Heap
1
2
5

Top
1
Pop
Output
1
Ab
1
kis list se aaya?
Pehli list.
Uska next push karo.

Heap
2
4
5
Pop
2
Output
1 2
Push
3

Heap
3
4
5
Pop
3
Push
7

Heap
4
5
7
Pop
4
Push
8

Heap
5
7
8
Continue
Output
1 2 3 4 5 6 7 8

Why does it work?
Har list already sorted hai. To kisi bhi list ka sirf head hi smallest ho sakta hai. Baaki nodes usse bade hi honge. Isliye heap mein sirf current heads rakhna kaafi hai.

Complexity
Suppose
k lists
Total nodes
N
Heap size kabhi bhi
k
se zyada nahi hota.
Har node
push
ek baar.
Har node
pop
ek baar.
Heap operation
O(log k)
Total
N operations
Therefore
O(Nlogk)*/

// Most optimal sol
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
    ListNode *merge(ListNode *h1, ListNode *h2)
    {
        if (!h1)
            return h2;
        if (!h2)
            return h1;
        ListNode dummy(-1);
        ListNode *tail = &dummy;
        while (h1 && h2)
        {
            if (h1->val <= h2->val)
            {
                tail->next = h1;
                h1 = h1->next;
            }
            else
            {
                tail->next = h2;
                h2 = h2->next;
            }
            tail = tail->next;
        }
        tail->next = h1 ? h1 : h2;
        return dummy.next;
    }
    ListNode *solve(vector<ListNode *> &lists, int l, int r)
    {
        if (l == r)
            return lists[l];
        int mid = l + (r - l) / 2;
        ListNode *left = solve(lists, l, mid);
        ListNode *right = solve(lists, mid + 1, r);
        return merge(left, right);
    }
    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        if (lists.empty())
            return nullptr;
        return solve(lists, 0, lists.size() - 1);
    }
};
// TC - O(nlogk)  SC - O(1)