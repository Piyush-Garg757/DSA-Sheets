/*All Prime Factors in Any Order

You are given a positive integer n, return its prime factors in any order.  A prime number is a natural number greater than 1 that has no positive divisors other than 1 and itself.

Examples:
Input: n = 18
Output: [2, 3, 3]
Explanation: Prime Factorization of 18 is 2 * 32.

Input: n = 25
Output: [5, 5]
Explanation: Prime Factorization of 25 is 52.*/

// One sol would be to run a loop and then check if every number is prime or not before adding   this is not optimal sol at all    the optimal sol is like we used to do in school whiile witing prime factorisation of a number
// Most optimal sol
class Solution
{
public:
    vector<int> primeFactors(int n)
    {
        // code here
        vector<int> ans;
        for (int i = 2; i * i <= n; i++)
        {
            while (n % i == 0)
            {
                ans.push_back(i);
                n /= i;
            }
        }
        if (n > 1)
            ans.push_back(n);
        return ans;
    }
};
// TC - O(sqrt(n))  SC - O(1)

// Slightly better version
while (n % 2 == 0)
{
    ans.push_back(2);
    n /= 2;
}
for (int i = 3; i * i <= n; i += 2)
{
    while (n % i == 0)
    {
        ans.push_back(i);
        n /= i;
    }
}
if (n > 1)
    ans.push_back(n);

// This is slightly better sinnce we are skipping all even numbers 