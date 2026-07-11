/*Reverse Pairs

Given an integer array nums, return the number of reverse pairs in the array.
A reverse pair is a pair (i, j) where:
0 <= i < j < nums.length and
nums[i] > 2 * nums[j].

Example 1:
Input: nums = [1,3,2,3,1]
Output: 2
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 3, nums[4] = 1, 3 > 2 * 1

Example 2:
Input: nums = [2,4,3,5,1]
Output: 3
Explanation: The reverse pairs are:
(1, 4) --> nums[1] = 4, nums[4] = 1, 4 > 2 * 1
(2, 4) --> nums[2] = 3, nums[4] = 1, 3 > 2 * 1
(3, 4) --> nums[3] = 5, nums[4] = 1, 5 > 2 * 1*/

class Solution
{
public:
    int merge(vector<int> &a, int low, int mid, int high)
    {
        int cnt = 0;
        // Count reverse pairs
        int j = mid + 1;
        for (int i = low; i <= mid; i++)
        {
            while (j <= high && (long long)a[i] > 2LL * a[j])
            {
                j++;
            }
            cnt += j - (mid + 1);
        }
        // Normal merge
        vector<int> temp;
        int left = low;
        int right = mid + 1;
        while (left <= mid && right <= high)
        {
            if (a[left] <= a[right])
                temp.push_back(a[left++]);
            else
                temp.push_back(a[right++]);
        }
        while (left <= mid)
            temp.push_back(a[left++]);
        while (right <= high)
            temp.push_back(a[right++]);
        for (int i = low; i <= high; i++)
            a[i] = temp[i - low];
        return cnt;
    }
    int merge_sort(vector<int> &a, int low, int high)
    {
        if (low >= high)
            return 0;
        int mid = low + (high - low) / 2;
        int cnt = 0;
        cnt += merge_sort(a, low, mid);
        cnt += merge_sort(a, mid + 1, high);
        cnt += merge(a, low, mid, high);
        return cnt;
    }
    int reversePairs(vector<int> &a)
    {
        return merge_sort(a, 0, a.size() - 1);
    }
};
// TC - O(nlogn)  SC - O(1)

/*Intution - 
Key Observation
Merge Sort already divides array into:
Left Half
Right Half
and both halves become sorted.
Suppose after recursion we have:
Left  = [2, 4, 8]
Right = [1, 2, 3]
Now we only need to count reverse pairs where:
element from Left
element from Right
because pairs completely inside left/right are already counted by recursive calls.
Why Sorting Helps
Consider:
Left  = [2, 4, 8]
Right = [1, 2, 3]
Take:
left[i] = 4
Check right side:
4 > 2*1 = 2  ✓
4 > 2*2 = 4  ✗
Since right array is sorted:
1 2 3
If condition fails at 2, it will fail for all later elements too.
So we don't need to check them again.
This is the entire optimization.
Two Pointer Idea
Let
i -> left half
j -> right half
Initially:
Left  = [2,4,8]
Right = [1,2,3]
i = 0
j = 0
i = 0
2 > 2*1 ?
2 > 2 ?
False
No reverse pairs.
Count += 0
i = 1
4 > 2*1 ?
4 > 2 ?
True
Move j:
j = 1
Now:
4 > 2*2 ?
4 > 4 ?
False
Stop.
How many valid right elements?
j = 1
Meaning only index 0 worked.
Count += 1
i = 2
8 > 2*2 ?
8 > 4 ?
True
Move j.
j = 2
Check:
8 > 2*3 ?
8 > 6 ?
True
Move again.
j = 3
End.
Count += 3
Total:
0 + 1 + 3 = 4
Revese pairs:
(4,1)
(8,1)
(8,2)
(8,3)
Correct.
Why j Never Resets
This is the most important part.
Suppose:
Left = [2,4,8]
We processed:
i = 1
and reached:
j = 1
Now next element is:
8
Since:
8 >= 4
Any right element that worked for 4 will definitely work for 8.
Therefore:
j never moves backward
It only moves forward.
Hence counting step becomes:
O(n)
instead of
O(n²)
Why Count = j - (mid + 1)
Suppose:
Left  = [4]
Right = [1,2,3]
j finally reaches end
That means:
4 > 2*1
4 > 2*2 ? no
Actually only first element worked.
So:
j = mid + 2
Number of valid elements:
(mid+2) - (mid+1)
= 1
Exactly the count we need.
That's why:
cnt += j - (mid + 1);
Complete Merge Sort Logic
For every recursive call:
Count in Left Half
+
Count in Right Half
+
Count Across Halves
i.e.
cnt =
merge_sort(left)
+
merge_sort(right)
+
merge(left,right)
Exactly same philosophy as inversion count.*/