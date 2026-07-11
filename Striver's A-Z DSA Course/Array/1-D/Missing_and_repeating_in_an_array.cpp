/* ismein kya karna hai 1-n tak numbers honge array mein jismein se ek missing hoga aur ek repeat ho raha hoga to humein vo return karna hai*/

// Brute force -> nested loop vala hi O(n^2) jismein 1-n  har number ke liye iterate karenge array ko aur check karenge

// Better sol -> Hashing using unordered_map

// Optimal sol 1
/*
-> Array ka size n hota hai aur elements 1 se n ke beech hote hain.
-> Ek number repeat hota hai (maan lo R) aur ek number missing hota hai (maan lo M).
-> Array ke saare elements ka actual sum nikaalo → S.
-> 1 se n tak ka expected sum nikaalo
-> SN = n(n+1)/2.
-> Dono ka difference lo:
-> S - SN = R - M
-> (yeh pehli equation hai)
-> Ab array ke elements ka actual sum of squares nikaalo → S2.
-> 1 se n tak ka expected sum of squares nikaalo
-> S2N = n(n+1)(2n+1)/6.
-> Dono ka difference lo:
-> S2 - S2N = R² - M².
-> Identity use karo:
-> R² - M² = (R - M)(R + M).
-> Pehli equation se (R - M) already pata hai, use divide karke (R + M) nikaal lo.
-> Ab do equations mil gayi:
-> R - M
-> R + M
-> Inko solve karo:
-> R = ( (R - M) + (R + M) ) / 2
-> M = R - (R - M)
-> Is tarah bina extra space ke repeating aur missing number mil jaata hai.*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    long long S = 0, S2 = 0;
    long long SN = 1LL * n * (n + 1) / 2;
    long long S2N = 1LL * n * (n + 1) * (2 * n + 1) / 6;
    for (int i = 0; i < n; i++)
    {
        S += a[i];
        S2 += 1LL * a[i] * a[i];
    }
    long long val1 = S - SN;
    long long val2 = S2 - S2N;
    val2 = val2 / val1;
    long long x = (val1 + val2) / 2;
    long long y = x - val1;
    cout << "Repeating number: " << x << "\n";
    cout << "Missing number: " << y << "\n";
    return 0;
}
// TC - O(n)  SC - O(1)

// Optimal sol 2
/*
XOR Method – Steps with Example

Array ke saare elements ka XOR nikaalo
xr = 1 ^ 2 ^ 2 ^ 4

1 se n tak ke numbers ka XOR karo
xr = (1 ^ 2 ^ 2 ^ 4) ^ (1 ^ 2 ^ 3 ^ 4)

Same numbers cancel ho jaate hain
xr = 3 ^ 2
(yaani missing ^ repeating)
xr = 3 ^ 2 = 1

Binary:
3 = 011
2 = 010
xr = 001
xr ka rightmost set bit nikaalo
→ bit = 1

Divide into 2 groups (using that bit)

Group 1 (bit set)
Array elements:
1 (001) ✔
Numbers 1..n:
1 (001) ✔
3 (011) ✔
XOR:
1 ^ 1 ^ 3 = 3

Group 2 (bit not set)
Array elements:
2, 2, 4
Numbers 1..n:
2, 4
XOR:
2 ^ 2 ^ 4 ^ 2 ^ 4 = 2

Result after grouping
Do values milti hain:
3
2

Identify which is missing / repeating
Array check:
2 array me present hai → repeating
3 array me nahi hai → missing

Final Answer
Repeating = 2
Missing = 3

Complexity
Time: O(n)
Space: O(1)*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter size of array\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter elements\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int xr = 0;
    // XOR of array elements
    for (int i = 0; i < n; i++)
    {
        xr ^= a[i];
    }
    // XOR of numbers from 1 to n
    for (int i = 1; i <= n; i++)
    {
        xr ^= i;
    }
    // rightmost set bit
    int bit = xr & (-xr);
    int x = 0, y = 0;
    // divide array elements into two groups
    for (int i = 0; i < n; i++)
    {
        if (a[i] & bit)
            x ^= a[i];
        else
            y ^= a[i];
    }
    // divide numbers 1 to n into two groups
    for (int i = 1; i <= n; i++)
    {
        if (i & bit)
            x ^= i;
        else
            y ^= i;
    }
    // identify repeating and missing
    int repeating, missing;
    bool found = false;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
        {
            repeating = x;
            missing = y;
            found = true;
            break;
        }
    }
    if (!found)
    {
        repeating = y;
        missing = x;
    }
    cout << "Repeating number: " << repeating << "\n";
    cout << "Missing number: " << missing << "\n";
    return 0;
}
