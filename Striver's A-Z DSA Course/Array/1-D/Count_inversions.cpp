/*Count Inversions

Given an array of integers arr[]. You have to find the Inversion Count of the array.
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].
Examples:
Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.*/

// Most optimal sol
class Solution
{
public:
    int merge(vector<int> &a, int low, int mid, int high)
    {
        int cnt = 0;
        int n1 = mid - low + 1;
        int n2 = high - mid;
        vector<int> right(n2), left(n1);
        for (int i = 0; i < n1; i++)
        {
            left[i] = a[i + low];
        }
        for (int i = 0; i < n2; i++)
        {
            right[i] = a[i + 1 + mid];
        }
        int k = low;
        int i = 0, j = 0;
        while (i < n1 && j < n2)
        {
            if (left[i] <= right[j])
            {
                a[k++] = left[i++];
            }
            else
            {
                cnt += (n1 - i);
                a[k++] = right[j++];
            }
        }
        while (i < n1)
        {
            a[k++] = left[i++];
        }
        while (j < n2)
        {
            a[k++] = right[j++];
        }
        return cnt;
    }
    int merge_sort(vector<int> &a, int low, int high)
    {
        int cnt = 0;
        if (low < high)
        {
            int mid = low + (high - low) / 2;
            cnt += merge_sort(a, low, mid);
            cnt += merge_sort(a, mid + 1, high);
            cnt += merge(a, low, mid, high);
        }
        return cnt;
    }
    int inversionCount(vector<int> &a)
    {
        // Code Here
        return merge_sort(a, 0, a.size() - 1);
    }
};
// TC - O(nlogn)  SC - O(1)

/*Intution - 
Merge Sort ki Observation
Merge Sort array ko recursively sort karta hai.
Suppose merge ke time hamare paas:
Left  = [2, 5, 8]
Right = [3, 6, 7]
Dono halves already sorted hain.
Ab compare karte hain:
2 vs 3
2 chhota hai ⇒ koi inversion nahi.
Next:
5 vs 3
Yahan
5 > 3
aur kyunki left sorted hai,
5, 8
dono 3 se bade hain.
To ek hi baar mein pata chal gaya:
(5,3)
(8,3)
2 inversions.
Count:
n1 - i
where
i = current index in left array
Why n1 - i ?
Example:
Left  = [2, 5, 8]
          ↑
          i
Right = [3, 6, 7]
         ↑
         j
Since:
5 > 3
and left sorted hai,
8 > 3
bhi guaranteed hai.
To current left element se lekar end tak sab inversions banayenge.
Count = left_size - i
      = 3 - 1
      = 2
Complete Idea
Har merge ke time inversions 3 types ke ho sakte hain:
1. Left half ke andar
2. Right half ke andar
3. Cross inversions
   (left element > right element)
Recursive calls count kar dete hain:
1 and 2
Merge step count kar deta hai:
3
Isliye:
total =
left inversions
+ right inversions
+ cross inversions*/