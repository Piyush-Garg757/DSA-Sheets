https : // codeforces.com/problemset/problem/1373/B
/*01 Game

Alica and Bob are playing a game.
Initially they have a binary string s consisting of only characters 0 and 1.
Alice and Bob make alternating moves: Alice makes the first move, Bob makes the second move, Alice makes the third one, and so on. During each move, the current player must choose two different adjacent characters of string s and delete them. For example, if s=1011001 then the following moves are possible:
• delete s1 and s2:
  1011001 → 11001
• delete s2 and s3:
  1011001 → 11001
• delete s4 and s5:
  1011001 → 10101
• delete s6 and s7:
  1011001 → 10110
If a player can't make any move, they lose. Both players play optimally. You have to determine if Alice can win.

Input
The first line contains one integer t (1≤t≤1000) — the number of test cases.
The only line of each test case contains one string s (1≤|s|≤100), consisting of only characters 0 and 1.

Output
For each test case print the answer in a single line.
If Alice can win print DA (YES in Russian) in any register. Otherwise print NET (NO in Russian) in any register.

Example

Input
3
01
1111
0011

Output
DA
NET
NET

Note
In the first test case, after Alice's move the string s becomes empty and Bob cannot make any move.
In the second test case, Alice cannot make any move initially.
In the third test case, after Alice's move string s turns into 01. Then, after Bob's move string s becomes empty and Alice cannot make any move.*/

#include <bits/stdc++.h>
        using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        stack<char> st;
        int n = s.length(), count = 0;
        for (int i = 0; i < n; i++)
        {
            if (st.empty() || s[i] == st.top())
                st.push(s[i]);
            else
            {
                st.pop();
                count++;
            }
        }
        if (count % 2)
            cout << "DA\n";
        else
            cout << "NET\n";
    }
}
// TC - O(n)  SC - O(n)

// More optimal sol
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        string s; // Binary string for each test case
        cin >> s;

        int count_of_one = 0;  // Counter for '1's in the string
        int count_of_zero = 0; // Counter for '0's in the string

        // Loop through the string to count '0's and '1's
        for (int i = 0; i < s.length(); i++) // n
        {
            if (s[i] == '0')
                count_of_zero++; // Increment zero counter
            else
                count_of_one++; // Increment one counter
        }

        // Calculate the number of operations possible
        int operations = min(count_of_zero, count_of_one);

        // If the number of operations is odd, Alice wins
        if (operations % 2 != 0)
            cout << "DA" << endl;
        else
            cout << "NET" << endl; // If even, Bob wins
    }
    return 0;
}

// Time Complexity (TC): O(n) = O(100)
// Space Complexity (SC): O(n) = O(100)
