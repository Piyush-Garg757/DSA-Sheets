/*Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.
You must implement a solution with a linear runtime complexity and use only constant extra space.

Example 1:
Input: nums = [2,2,3,2]
Output: 3

Example 2:
Input: nums = [0,1,0,1,0,1,99]
Output: 99*/

// Obvious approach is brute force

// Better approach
class Solution
{
public:
    int singleNumber(vector<int> &a)
    {
        int number = 0;
        for (int i = 0; i <= 31; i++)
        {
            int cnt = 0;
            for (int j = 0; j < a.size(); j++)
            {
                if ((a[j] >> i) & 1)
                    cnt++;
            }
            if (cnt % 3 == 1)
                number |= (1 << i);
        }
        return number;
    }
};
// TC - O(n*31)  SC - O(1)

/*Intution - Har integer 32 bits ka hota hai.
Suppose hum sirf 0th bit dekhte hain.
Example
2 = 0010
2 = 0010
2 = 0010
5 = 0101
0th bit
2 -> 0
2 -> 0
2 -> 0
5 -> 1
To ismein total no of ones 1 hain  ab agar repeating vale numbers mein se kisi mein bhi 1 hota to yahan 1 la count 3 ke multiples mein ata na but vo to ek bar a raha hai   to iska matlab hai ki vo akele vale number sse aya hai
Matlab answer ka 0th bit = 1.

Ab 1st bit dekhte hain.
2 -> 1
2 -> 1
2 -> 1
5 -> 0
To answer ka bit
0

2nd bit
2 -> 0
2 -> 0
2 -> 0
5 -> 1
Answer ka bit = 1.

3rd bit
0
0
0
0
Count = 0
Answer ke bits
0101 = 5
Mil gaya.
Ismein 3 se modulo leke 1 ayega ye check isiloye kiya hai ki maan lo sabhi numbers men 1 aa raha hai kisi partiular bitidx pe
tab to count 1 na ayega na   but bit to set hai ans ki   isiliye aise check karte hain*/

// Another better approach
class Solution
{
public:
    int singleNumber(vector<int> &a)
    {
        sort(a.begin(), a.end());
        int n = a.size(), i = 1;
        while (i < n)
        {
            if (a[i] != a[i - 1])
            {
                return a[i - 1];
            }
            i += 3;
        }
        return a[n - 1];
    }
};
// TC - O(nlogn)  SC - O(1)  this is better than n*32 for most of the cases as we have small arrays
/*Intution - Step 1: What does sorting do?
Since every element appears exactly 3 times, after sorting, all equal elements come together.
Example:
Input:
[2,5,2,2,5,5,7]
After sorting:
2 2 2 5 5 5 7
Notice how every repeated number forms a group of 3.

Step 2: Observe the indices
After sorting,
Index
0 1 2 | 3 4 5 | 6
--------
2 2 2 | 5 5 5 | 7
Every valid group starts at
0
3
6
9
...
So instead of checking every element, we can jump directly from one group to the next.
That's why the code does
i += 3;

Step 3: Why compare a[i] with a[i-1]?
Suppose we are at the second element of a group.
Example:
2 2 2
Here
a[i] == a[i-1]
because
2 == 2
Everything is normal.
Now suppose the unique number appears.
Example:
2 2 2 4 5 5 5
Indices:
0 1 2 3 4 5 6
Iteration:
First group
i = 1
a[1] = 2
a[0] = 2
Equal
Move
i = 4
Now
a[4] = 5
a[3] = 4
They are not equal.
That means
4
didn't have three copies before it.
So
return a[i-1];
returns
4  and if the number not found then it will surely be the last one as if it was in the array earlier it must have been found*/

// Most optimal sol - Is approach ka pehle se na pata ho to ise socha nahi ja sakta hai khud se
class Solution
{
public:
    int singleNumber(vector<int> &a)
    {
        int ones = 0, twos = 0;
        for (int i = 0; i < a.size(); i++)
        {
            ones = (a[i] ^ ones) & (~twos);
            twos = (a[i] ^ twos) & (~ones);
        }
        return ones;
    }
};
// TC - O(n)  SC - O(1)
/*Intution - Hum do buckets (ones aur twos) maintain karte hain. Dhyan rahe ye buckets numbers nahi, bits store karti hain.

ones un bits ko store karta hai jo abhi tak 1 mod 3 baar aaye hain.
twos un bits ko store karta hai jo 2 mod 3 baar aaye hain.

Jab koi naya number aata hai, uske bits pehle XOR ki help se respective bucket mein toggle hote hain. Agar koi bit doosri bucket mein already present hai, to & ~otherBucket ki help se usse hata diya jata hai taaki ek bit ek time par sirf ek hi bucket mein rahe.

Is process se har bit ka state automatically

0 → ones → twos → 0

follow karta hai. Isliye jo bits 3 baar aati hain wo remove ho jaati hain, aur end mein ones mein sirf unique number ki bits bachti hain.*/

// Basically ye yaad hi rakhna hai