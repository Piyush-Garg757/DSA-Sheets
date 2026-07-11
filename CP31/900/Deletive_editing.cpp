/*Deletive Editing

Daisy loves playing games with words. Recently, she has been playing the following Deletive Editing word game with Daniel.
Daisy picks a word, for example, "DETERMINED". On each game turn, Daniel calls out a letter, for example, 'E', and Daisy removes the first occurrence of this letter from the word, getting "DTERMINED". On the next turn, Daniel calls out a letter again, for example, 'D', and Daisy removes its first occurrence, getting "TERMINED". They continue with 'I', getting "TERMNED", with 'N', getting "TERMED", and with 'D', getting "TERME". Now, if Daniel calls out the letter 'E', Daisy gets "TRME", but there is no way she can get the word "TERM" if they start playing with the word "DETERMINED".
Daisy is curious if she can get the final word of her choice, starting from the given initial word, by playing this game for zero or more turns. Your task is to help her figure this out.

Input
The first line of the input contains an integer n — the number of test cases (1≤10000). The following n lines contain test cases.
Each test case consists of two words s and t separated by a space. Each word consists of at least one and at most 30 uppercase English letters; s is Daisy's initial word for the game; t is the final word that Daisy would like to get at the end of the game.

Output
Output n lines to the output — a single line for each test case. Output "YES" if it is possible for Daisy to get from the initial word s to the final word t by playing the Deletive Editing game. Output "NO" otherwise.

Example

Input
6
DETERMINED TRME
DETERMINED TERM
PSEUDOPSEUDOHYPOPARATHYROIDISM PEPA
DEINSTITUTIONALIZATION DONATION
CONTEST CODE
SOLUTION SOLUTION

Output
YES
NO
NO
YES
NO
YES*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        int n = s1.length(), m = s2.length();
        int i = n - 1, j = m - 1;
        string s = "";
        bool ans = true;
        while (i >= 0 && j >= 0)
        {
            if (s.find(s2[j]) != string::npos)
            {
                ans = false;
                break;
            }
            else
            {
                if (s1[i] == s2[j])
                {
                    i--;
                    j--;
                    continue;
                }
                s += s1[i];
            }
            i--;
        }
        if (j >= 0)
            ans = false;
        if (ans)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}
// TC - O(n)  SC - O(n)