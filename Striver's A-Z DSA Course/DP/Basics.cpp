/*Step 1: DP hota kya hai?
Dynamic Programming = Recursion + Memory
Ya ek aur simple definition:
"Ek hi problem ko baar-baar solve mat karo."
Bas itna hi.
Step 2: Sabse pehle Recursion
Question:
Find nth Fibonacci Number.
Definition
F(0)=0
F(1)=1
F(n)=F(n-1)+F(n-2)
Suppose
n = 5
Recursion
                fib(5)
               /      \
          fib(4)      fib(3)
          /    \      /    \
      fib(3) fib(2) fib(2) fib(1)
      /   \     |      |
 fib(2) fib(1) fib(1) fib(0)
Notice something.
fib(3) kitni baar aaya?
fib(3)
1st time
↓
fib(5)->fib(4)->fib(3)
2nd time
↓
fib(5)->fib(3)
Do baar.
fib(2)
Teen baar.
fib(1)
Paanch baar.
Yehi DP ka janam hai.
Overlapping Subproblems
Definition
Same subproblem baar-baar solve ho rahi ho.
Example
fib(2)
↓
1
↓
again
↓
again
Hum same answer baar-baar nikal rahe hain.
Ye waste hai.
Ek analogy
Suppose teacher poochta hai
2+3?
Tum calculate karte ho
Fir 1 minute baad fir wahi poochta hai.
Fir calculate.
Fir poochta hai.
Fir calculate.
Ye stupidity hai 😂
Ek baar calculate karo.
Likho.
Next time directly dekh lo.
DP bhi wahi karta hai.
Memoization
Idea
Already solve kiya?
↓
Yes
↓
Return
↓
No
↓
Solve
↓
Store
Code
int fib(int n, vector<int>& dp)
{
    if(n<=1)
        return n;
    if(dp[n]!=-1)
        return dp[n];
    return dp[n]=fib(n-1,dp)+fib(n-2,dp);
}
Dry Run
Suppose
fib(5)
Initially
dp
-1 -1 -1 -1 -1 -1
Need
fib(3)
Not present
↓
Calculate
↓
Store
dp[3]=2
Later again need
fib(3)
Now
dp[3]!=-1
Immediately
Return
No recursion.
Why called Memoization?
Because
Memo
=
Memory
Hum answers yaad rakh rahe hain.
Complexity
Without DP
O(2^n)
With Memoization
Har state sirf ek baar solve.
States
0
1
2
...
n
Total
n+1
So
O(n)	​
Space
DP array
O(n)
Recursion stack
O(n)
Total
O(n)
Tabulation
Question
Why recursion?
Answer
Nahi chahiye.
Hum already jaante hain
fib(2)
depends on
fib(1)
fib(0)
To neeche se banana shuru kar dete hain.
dp[0]=0
dp[1]=1
Now
dp[2]
=
dp[1]+dp[0]
Then
dp[3]
=
dp[2]+dp[1]
Then
dp[4]
=
dp[3]+dp[2]
Then
dp[5]
=
dp[4]+dp[3]
Ho gaya.
Code
vector<int> dp(n+1);
dp[0]=0;
dp[1]=1;
for(int i=2;i<=n;i++)
    dp[i]=dp[i-1]+dp[i-2];
return dp[n];
Why called Tabulation?
Because
Hum table bhar rahe hain.
0
1
1
2
3
5
8
13
Complexity
Time
O(n)
Space
O(n)
Ab sabse important cheez
Space Optimization
Observe
dp[i] = dp[i-1]+dp[i-2]

Question
Kya mujhe poora array chahiye?
Suppose
Need
dp[100]
Calculation ke time
Sirf
dp[99]
dp[98]
hi chahiye.
Baaki
dp[0]
dp[1]
...
dp[50]
kabhi use hi nahi honge.
To unhe store kyu kare?
Instead
prev2
prev1
rakho.
Example
Initially
prev2=0
prev1=1
Need
curr=prev1+prev2
=
1
Update
prev2=prev1
prev1=curr
Now
prev2=1
prev1=1
Need next
curr=2
Update
prev2=1
prev1=2
Continue.
Code
int prev2=0;
int prev1=1;
for(int i=2;i<=n;i++)
{
    int curr=prev1+prev2;
    prev2=prev1;
    prev1=curr;
}
return prev1;
Complexity
Time
O(n)
Space
Only
prev1
prev2
curr
Three integers.
O(1)	

Sabko compare karo
Pure Recursion
Time
O(2^n)
Space
O(n)

Memoization
Time
O(n)
Space
O(n)

Tabulation
Time
O(n)
Space
O(n)

Space Optimized
Time
O(n)
Space
O(1)*/