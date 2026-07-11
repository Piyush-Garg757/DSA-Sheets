/*Largest Rectangle in Histogram

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4*/

// My first approach
class Solution
{
public:
    vector<int> nextSmallerIndex(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> prevSmallerIndex(vector<int> &arr)
    {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int> &a)
    {
        vector<int> lt = prevSmallerIndex(a);
        vector<int> rt = nextSmallerIndex(a);
        int n = a.size(), ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, (rt[i] - lt[i] - 1) * a[i]);
        }
        return ans;
    }
};
// TC - O(n)  SC - O(n)

// Optimal sol
class Solution
{
public:
    int largestRectangleArea(vector<int> &a)
    {
        stack<int> st;
        int area = 0;
        for (int i = 0; i < a.size(); i++)
        {
            if (st.empty() || a[i] >= a[st.top()])
                st.push(i);
            else
            {
                int nse = i;
                while (!st.empty() && a[st.top()] >= a[i])
                {
                    int height = a[st.top()];
                    st.pop();
                    int pse = -1;
                    if (!st.empty())
                        pse = st.top();
                    area = max(area, height * (nse - pse - 1));
                }
                st.push(i);
            }
        }
        int n = a.size();
        while (!st.empty())
        {
            int height = a[st.top()];
            st.pop();
            int pse = st.empty() ? -1 : st.top();
            area = max(area, height * (n - pse - 1));
        }
        return area;
    }
};
// TC - O(n)  SC - O(n)

/*Intution - Step 1: Hum area kab calculate kar sakte hain?
Suppose
2 1 5 6 2 3
Question:
Rectangle of height 5 kitna extend karega?
Left mein kitna?
Right mein kitna?
Hume dono boundaries chahiye.

Step 2: Kab pata chalega right boundary?
Take
5 6 2
Jab hum
2
dekhte hain tab hi pata chalta hai ki
6
ab aur right nahi badh sakta.
Aur
5
bhi nahi badh sakta.
Isliye
2
dekhte hi hum
6
5
dono ke rectangles calculate kar dete hain.
Isi liye stack use karte hain.

Step 3: Stack mein kya store hota hai?
Indices.
Stack hamesha maintain karta hai
Increasing Heights
Example
2 3 5 6
Stack
2
3
5
6
Indices store hain, heights increasing hain.

Step 4: Naya chhota element aaya
Suppose
2 3 5 6 4
Ab
4
aaya.
Question
Rectangle of
6
khatam?
YES
Rectangle of
5
khatam?
YES
Rectangle of
3
No
Isliye
6
5
pop honge.
Exactly yehi tum karte ho.
while (!st.empty() && a[st.top()] >= a[i])

Step 5: NSE
Jab
4
aaya
to
5
ka
Next Smaller Element
ban gaya
4
iska index
nse = i;
Isliye
int nse = i;

Step 6: PSE
Suppose
Stack
2
3
5
6
Hum
6
pop karte hain.
Stack
2
3
5
ab
Top
5
ban gaya.
Yehi hai
Previous Smaller.
Isliye
pse = st.top();

Step 7: Width
Rectangle
height = 6
Left boundary
pse
Right boundary
nse
Rectangle banega
(pse+1)
...
(nse-1)
Width
nse-pse-1
Exactly
height*(nse-pse-1)*/