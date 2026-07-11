/*Counting Sort ek non-comparison sorting algorithm hai.
sort() ya Merge Sort ki tarah elements ko compare nahi karta. Instead, har number kitni baar aaya hai uski frequency count karta hai.
Example:
a = {10, 6, 8, 7, 7, 8};
Frequency:
6  -> 1
7  -> 2
8  -> 2
10 -> 1
Ab frequency ke basis par sorted array bana do:
6 7 7 8 8 10
Dry Run
a = {4, 2, 2, 8, 3, 3, 1};
Step 1: Maximum find karo
maxi = 8;
Step 2: Frequency array
freq[0..8] = {0};
Step 3: Count karo
freq[1] = 1
freq[2] = 2
freq[3] = 2
freq[4] = 1
freq[8] = 1
Step 4: Sorted array banao
1 2 2 3 3 4 8

Usage:
vector<int> a = {10, 6, 8, 7, 7, 8};
countingSort(a);
for (int x : a)
    cout << x << " ";
Output:
6 7 7 8 8 10
Complexity
Let:
n = number of elements
k = maximum value
Time:
O(n + k)
Space:
O(k)
Kab Use Karna Chahiye?
✅ Jab values ki range chhoti ho.
Example:
n = 100000
a[i] ∈ [0, 100]
Bahut fast chalega.
Kab Nahi Karna Chahiye?
a = {1, 1000000000}
Yahan:
vector<int> freq(1000000001);
banana padega 😵
Memory explode ho jayegi.
Isliye Counting Sort tabhi use karte hain jab max value reasonably small ho.*/

void countingSort(vector<int> &a)
{
    int n = a.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, a[i]);
    }
    vector<int> freq(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    int idx = 0;
    for (int i = 0; i <= maxi; i++)
    {

        while (freq[i] > 0)
        {
            a[idx] = i;
            idx++;
            freq[i]--;
        }
    }
}
// TC - O(n+k)  SC - O(k)

/*Stable Counting Sort Kya Hota Hai?
Stable sorting ka matlab:
Agar do elements same value ke hain, to sorted array mein unka relative order preserve rehna chahiye.

Basic Counting Sort Stable Nahi Hota
Tumhara wala:
while(freq[i] > 0) {
    a[idx++] = i;
    freq[i]--;
}
sirf values rakhta hai, original positions ya order yaad nahi rakhta.
Stable Counting Sort Ka Idea
Example:
a = {4, 2, 2, 8, 3, 3, 1};
Step 1: Frequency
value : count
1 : 1
2 : 2
3 : 2
4 : 1
8 : 1
Count array:
0 1 2 2 1 0 0 0 1
Step 2: Prefix Sum
for(int i = 1; i <= maxi; i++)
    freq[i] += freq[i - 1];

Now:
0 1 3 5 6 6 6 6 7
Meaning:
1 ends at index 0
2 ends at index 2
3 ends at index 4
4 ends at index 5
8 ends at index 6
Step 3: Right se Traverse Karo
Ye sabse important step hai.
for(int i = n - 1; i >= 0; i--)
Har element ko uski correct position par rakho.

Interview Point
Basic Counting Sort
Time: O(n + k)
Space: O(k)
Not necessarily stable
Stable Counting Sort
Time: O(n + k)
Space: O(n + k) (output array + frequency)
Used inside Radix Sort because Radix Sort ko stable sorting chahiye hoti hai. Radix Sort*/

void countingSort(vector<int> &a)
{
    int n = a.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, a[i]);
    }
    vector<int> freq(maxi + 1, 0);
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    for (int i = 1; i <= maxi; i++)
    {
        freq[i] += freq[i - 1];
    }
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--)
    {
        ans[freq[a[i]] - 1] = a[i];

        freq[a[i]]--;
    }
    a = ans;
}
// TC - O(n+k)  SC - O(n+k)