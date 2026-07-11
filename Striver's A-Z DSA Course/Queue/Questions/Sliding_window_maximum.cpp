/*Sliding Window Maximum

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.
Return the max sliding window.

Example 1:
Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation:
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:
Input: nums = [1], k = 1
Output: [1]*/

// Brute force is pretty obvious O(n*k)

// Here is an optimal version using dequeue
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        deque<int> dq;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++)
        {
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] <= nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

/*Intution - Observation
Window ek step right move karti hai.
[1 3 -1]
↓
[3 -1 -3]
Notice:
Sirf
ek element bahar gaya
ek element andar aaya
To pura maximum dobara calculate karna bewakoofi hai.

Hume previous information use karni chahiye.
Hum kya store kare?
Suppose
1 3 -1 -3 5
Maximum obviously
3
Question:
Kya hume
1
ki zarurat hai?
Nahi.
Kyuki
3 > 1
Aur
3
window me uske baad bhi rahega.
To
1
kabhi maximum ban hi nahi sakta.
Isliye 1 ko delete kar do.

Sabse important intuition
Suppose queue me
5
already hai.
Ab
2
aaya.
Queue
5 2
Banegi.
Kyun?
Kyuki future me agar
5
window se bahar chala gaya,
tab
2
maximum ban sakta hai.
To chhote element ko rakhna padega.
Ab opposite case dekho.
Queue
2
hai.
Ab
5
aaya.
2 5
rakhne ka koi matlab hai?
Bilkul nahi.
Kyun?
Future ki kisi bhi window me
5
rahega
to
2
kabhi maximum ban hi nahi sakta.
Isliye
2
ko turant hata do.
Isi wajah se hum ye likhte hain
while(!dq.empty() && nums[dq.back()] <= nums[i])
    dq.pop_back();

Queue hamesha decreasing rahegi
Example
1
↓
1 3
3 bada hai
1
delete
Queue
3
Next
-1
Queue
3 -1
Next
-3
Queue
3 -1 -3
Next
5
Ab dekho
3 -1 -3
ke sabse peeche se compare
-3 < 5
Delete
3 -1
Again
-1 < 5
Delete
3
Again
3 < 5
Delete
Queue empty.
Ab
5
insert.
Queue
5

Notice
Ek hi iteration me
3
-1
-3
sab delete ho gaye.
Kyuki future me ye kabhi maximum ban hi nahi sakte.

Queue me indices kyu store karte hain?
Ye bahut important interview question hai.
Suppose
nums = [8,5,4]
Window
[8 5]
Queue
8 5
Ab window move hui
[5 4]
Hume pata kaise chalega ki
8
window ke bahar chala gaya?
Sirf value store karoge
8
to uski position nahi pata chalegi.
Isliye indices store karte hain.
Queue
0 1
instead of
8 5
Aur compare karte hain
dq.front() <= i-k
First while loop
while(!dq.empty() && dq.front()<=i-k)
    dq.pop_front();
Ye expired indices hata raha hai.
Example
k=3
Current
i=5
Window
3 4 5
Agar queue front
2
hai
To
2
window ke bahar hai.
Delete.

Second while loop
while(!dq.empty() && nums[dq.back()]<=nums[i])
    dq.pop_back();
Ye useless elements hata raha hai.
Yehi monotonic queue ka heart hai.
Push current index
dq.push_back(i);
Ab current candidate ban gaya future maximum ke liye.
Maximum kaha milega?
Queue hamesha decreasing hai.
Isliye
Front
Largest
hoga.
Bas
nums[dq.front()]
answer hai.

Dry Run
nums=[1,3,-1,-3,5]
i=0
Queue
1
i=1
3>a1
remove 1
Queue
3
i=2
Queue
3 -1
Maximum=3
i=3
Queue
3 -1 -3
Maximum=3
i=4
Remove expired 3
Queue
-1 -3
5 arrives
remove -3
remove -1
Queue
5
Maximum=5

Sabse bada intuition
Deque me window ke saare elements nahi hote.
Sirf wo elements hote hain jo future me maximum ban sakte hain.
Baaki sab ko hum turant delete kar dete hain.
Isi wajah se algorithm O(n) hai.
Rule yaad rakhna
Har naye element ke liye do sawaal pucho:
Kya queue ka front window ke bahar chala gaya?
Haan → pop_front()
Kya current element queue ke back se bada ya equal hai?
Haan → pop_back() (kyunki back wala kabhi future maximum nahi banega)
Current index push karo.
Jab window complete ho (i >= k - 1), to nums[dq.front()] hi us window ka maximum hai.*/