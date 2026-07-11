#include <bits/stdc++.h>
using namespace std;
void printPrimes(int n)
{
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
            cout << i << " ";
    }
}
int main()
{
    printPrimes(30);
}

/*Intuition - Initially assume every number is prime.
2 3 4 5 6 7 8 9 10 ...
✓ ✓ ✓ ✓ ✓ ✓ ✓ ✓ ✓

Start from 2:
Remove all multiples:
4 6 8 10 12 ...

Then 3:
Remove
6 9 12 15 ...

Then 5:
Remove
10 15 20 ...
Continue till √n.

The numbers still marked true are primes.

Why start from i * i?
For i = 5
5 × 2 = 10
5 × 3 = 15
5 × 4 = 20
These have already been marked when processing 2, 3, and 4.
So the first new multiple is
5 × 5 = 25
Hence
for (int j = i * i; j <= n; j += i)

Complexity
Time: O(n log log n)
Space: O(n)
This is the standard and most efficient algorithm for generating all prime numbers from 1 to n.*/