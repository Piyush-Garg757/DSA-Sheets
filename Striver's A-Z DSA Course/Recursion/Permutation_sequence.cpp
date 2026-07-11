/*Permutation Sequence
The set [1, 2, 3, ..., n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"

Example 3:
Input: n = 3, k = 1
Output: "123"*/

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        vector<int> a;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact *= i;
            a.push_back(i);
        }
        a.push_back(n);
        string ans = "";
        k--;
        while (true)
        {
            ans += to_string(a[k / fact]);
            a.erase(a.begin() + k / fact);
            if (a.size() == 0)
                break;
            k %= fact;
            fact /= a.size();
        }
        return ans;
    }
};
// TC - O(n^2)  SC - O(n)
/*Sabse pehle ek observation
Suppose
1 2 3
Total permutations
3!
=
6
List
123
132
213
231
312
321
Notice.
Starting with 1
123
132
Total
2
=
2!
Starting with 2
213
231
Again
2!
Starting with 3
312
321
Again
2!
Conclusion
Every first digit occupies
(n−1)!
permutations.
For n=4
Numbers
1 2 3 4
Total
4!
=
24
Each first digit contributes
3!
=
6
permutations.
Like
Starts with 1
1xxxx
6 permutations
Starts with 2
2xxxx
6 permutations
Starts with 3
3xxxx
6 permutations
Starts with 4
4xxxx
6 permutations
Example
Find
17th
Permutation.
Code
k--;
Why?
Because indexing starts from
0
Now
k=16
Current numbers
1 2 3 4
Each block
6
large.
0-5
↓
Starts with 1
6-11
↓
Starts with 2
12-17
↓
Starts with 3
18-23
↓
Starts with 4
Now
16
lies here
12-17
↓
Starts with 3
How to know?
k/fact
16/6
=
2
Index
2
Vector
1 2 3 4
0 1 2 3
Index
2
↓
3
So answer starts with
3
Code
ans+=to_string(a[k/fact]);
becomes
ans="3"
Remove
3
Remaining
1 2 4
Now
Inside
3*****
which permutation?
We already skipped
12
permutations.
Need only
16%6
=
4
Code
k%=fact;
Now
Remaining digits
1 2 4
Each second digit occupies
2!
=
2
permutations.
So
fact/=a.size();
Previously
6
Remaining numbers
3
Hence
6/3
=
2
Exactly
2!
Current
k=4
fact=2
Index
4/2
=
2
Remaining vector
1 2 4
Index
2
↓
4
Answer
34
Remove
4
Remaining
1 2
Update
k
=
4%2
=
0
Update factorial
2/2
=
1
Current
1 2
Each block
1
Permutation.
Index
0/1
=
0
Choose
1
Answer
341
Remaining
2
Finally
Only
2
left.
Answer
3412
Which is indeed the
17th
permutation.
Now your code

Step 1
vector<int> a;
Stores
1 2 3 ... n
Available numbers.

Step 2
fact=(n-1)!
Why?
Because
Every first digit owns exactly
(n−1)!
permutations.

Step 3
k--;
Because vector indexing starts from
0
Instead of
1

Step 4
k/fact
This tells
which block we are in.

Step 5
erase()
Chosen digit cannot appear again.

Step 6
k%=fact;
Moves us inside that selected block.

Step 7
fact/=a.size();
Now one digit is fixed.
Remaining digits
m
Each next digit owns
(m−1)!
permutations.
Since
Current
fact=m!
Dividing by
m
gives
(m-1)!*/