https : // codeforces.com/problemset/problem/1883/B
/*Chemistry

You are given a string s of length n, consisting of lowercase Latin letters, and an integer k.
You need to check if it is possible to remove exactly k characters from the string s in such a way that the remaining characters can be rearranged to form a palindrome. Note that you can reorder the remaining characters in any way.
A palindrome is a string that reads the same forwards and backwards. For example, the strings "z", "aaa", "aba", "abccba" are palindromes, while the strings "codeforces", "reality", "ab" are not.

Input
Each test consists of multiple test cases. The first line contains a single integer t (1≤t≤10^4) — the number of the test cases. This is followed by their description.
The first line of each test case contains two integers n and k (0≤k<n≤10^5) — the length of the string s and the number of characters to be deleted.
The second line of each test case contains a string s of length n, consisting of lowercase Latin letters.
It is guaranteed that the sum of n over all test cases does not exceed 2⋅10^5.

Output
For each test case, output "YES" if it is possible to remove exactly k characters from the string s in such a way that the remaining characters can be rearranged to form a palindrome, and "NO" otherwise.
You can output the answer in any case (uppercase or lowercase). For example, the strings "yEs", "yes", "Yes", and "YES" will be recognized as positive answers.

Example
Input
14
1 0
a
2 0
ab
2 1
ba
3 1
abb
3 2
abc
6 2
bacacd
6 2
fagbza
6 2
zwaafa
7 2
taagaak
14 3
ttrraakkttoorr
5 3
debdb
5 4
ecadc
5 3
debca
5 3
abaac

Output
YES
NO
YES
YES
YES
YES
NO
NO
YES
YES
YES
YES
NO
YES

Note
In the first test case, nothing can be removed, and the string "a" is a palindrome.
In the second test case, nothing can be removed, but the strings "ab" and "ba" are not palindromes.
In the third test case, any character can be removed, and the resulting string will be a palindrome.
In the fourth test case, one occurrence of the character "a" can be removed, resulting in the string "bb", which is a palindrome.
In the sixth test case, one occurrence of the characters "b" and "d" can be removed, resulting in the string "acac", which can be rearranged to the string "acca".
In the ninth test case, one occurrence of the characters "t" and "k" can be removed, resulting in the string "aagaa", which is a palindrome.*/

// My first approach
#include <bits/stdc++.h>
        using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        vector<int> hashmap(26, 0);
        for (int i = 0; i < n; i++)
        {
            hashmap[s[i] - 'a']++;
        }
        bool first_odd_occurennce = false;
        bool all_even = true;
        for (int i = 0; i < 26; i++)
        {
            if (hashmap[i] % 2 != 0)
            {
                all_even = false;
                if (first_odd_occurennce == false)
                {
                    first_odd_occurennce = true;
                }
                else
                    k--;
            }
        }
        if (all_even)
            cout << "Yes\n";
        else if (k <= 1 && k >= 0 && first_odd_occurennce == true)
            cout << "Yes\n";
        else if (k < 0)
            cout << "No\n";
        else
            cout << "Yes\n";
    }
}
// TC - O(n)  SC - O(26)

// Slightly better and dimaag lagaya hua
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t; // Read the number of test cases
    while (t--)
    {
        long long n, k;
        cin >> n >> k; // Read the length of the string and the number of characters to remove
        string s;
        cin >> s; // Read the string
        // Create a vector to store the frequency of each character ('a' to 'z')
        vector<int> frequency_of_characters(26, 0);
        for (int i = 0; i < n; i++)                          // Iterate over the string
            frequency_of_characters[s[i] - 'a']++;           // Increment the frequency of the current character
        long long odd_frequency = 0;                         // Variable to count characters with odd frequency
        for (int i = 0; i < 26; i++)                         // Check each character's frequency
            odd_frequency += frequency_of_characters[i] % 2; // Count characters with odd frequency
        // If the number of odd frequency characters is greater than k + 1, it's not possible
        if (odd_frequency > k + 1)
            cout << "NO" << endl; // Output NO if not possible
        else
            cout << "YES" << endl; // Output YES if possible
    }
    return 0;
}

// Time Complexity (TC): O(n)
// Space Complexity (SC): O(n)

/*Key Observation
Suppose there are odd_frequency = x.
To make a palindrome, we need at most 1 odd frequency.
Each removed character can reduce the number of odd frequencies by 1.
So minimum removals needed:
x - 1
Therefore:
x - 1 <= k
which becomes:
x <= k + 1
That's exactly what the code checks:
if (odd_frequency > k + 1)
    cout << "NO";
else
    cout << "YES";*/