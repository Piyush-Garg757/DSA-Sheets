/*N-Repeated Element in Size 2N Array
You are given an integer array nums with the following properties:
nums.length == 2 * n.
nums contains n + 1 unique elements.
Exactly one element of nums is repeated n times.
Return the element that is repeated n times.

Example 1:
Input: nums = [1,2,3,3]
Output: 3

Example 2:
Input: nums = [2,1,2,5,3,2]
Output: 2

Example 3:
Input: nums = [5,1,5,2,5,3,5,4]
Output: 5*/

class Solution
{
public:
    int repeatedNTimes(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n - 2; i++)
        {
            if (nums[i] == nums[i + 1] || nums[i] == nums[i + 2])
                return nums[i];
        }
        return nums[n - 1];
    }
};
// TC - O(n)  SC - O(1)

/*
Claim (jo solution use karta hai)
Repeated element kabhi na kabhi distance ≤ 2 pe mil hi jaayega
Isliye hum check karte hain:
nums[i] == nums[i+1]  OR  nums[i] == nums[i+2]
❓ Ab doubt yahin hota hai:
“Aisa arrangement possible hai kya jisme repeated element har baar ≥ 3 distance pe ho?”
Chal prove karte hain ki impossible hai 👇
🔍 Proof by contradiction (simple version)
Assume kar lo:
Repeated element X kabhi bhi
adjacent nahi hai
aur i+2 distance pe bhi nahi hai
Matlab har do X ke beech at least 2 alag elements hain.
Pattern banega:
X _ _ X _ _ X _ _ X ...
Count karo
X = n times
Har X ke beech ≥ 2 unique elements chahiye
Total unique elements available = n
Required unique elements:
2 × (n - 1) = 2n - 2
Available unique elements:
n
❌ Impossible (2n − 2 > n)*/

/*
✅ Pigeonhole Principle
🔹 Short definition
If you have more items than containers, at least one container must have more than one item.
🔹 Is problem mein kaise apply hota hai?
Total positions = 2n
Repeated element = n times
Baaki unique elements = n
👉 Itni tight arrangement mein
repeated element ko paas-paas aana hi padega
(distance ≤ 2)
Isi wajah se:
nums[i] == nums[i+1] || nums[i] == nums[i+2]
guaranteed kaam karta hai.*/