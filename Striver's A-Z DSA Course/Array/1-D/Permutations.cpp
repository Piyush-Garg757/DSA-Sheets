// print all permutations

#include <bits/stdc++.h>
using namespace std;
void print_all_permutations(string s, int index)
{
    if (index >= s.length())
    {
        cout << s << "\n";
        return;
    }
    for (int j = index; j < s.length(); j++)
    {
        swap(s[j], s[index]);
        print_all_permutations(s, index + 1);
        swap(s[j], s[index]); // Backtracking
    }
}
int main()
{
    string s;
    cout << "Enter the number\n";
    cin >> s;
    print_all_permutations(s, 0);
    return 0;
}
// idea ye hai ki swap karte rahenge baar baar
// jaise abc mein a ko a se kiya to abc aya fir aage badhe fi b ko c se kiya to acb aya
// fir abc mein a ko b se kiya to bac aya fir bac mein a ko c se kiya to bca aya
// fir abc mein a ko c se kiya to cba aya fir b ko a se kiya to cab aya

// isi ke liye backtracking zaruri hai kyuki hum initially baar baar original mein swap kar rahe hain shuru mein
// TC - O(n*n!)  SC - O(1)
// n! permutations hain aur har kisi ke liye iterate kar rahe hain

// par ismein do issues hain ek to lexographical order mein nahi hai aur dusra ye ki 112 jaisa hua to repeat ho sakte hain

// better
#include <bits/stdc++.h>
using namespace std;

void print_all_permutations(string &s, int index)
{
    if (index == s.length())
    {
        cout << s << "\n";
        return;
    }
    unordered_set<char> used; // to avoid duplicates at the same index
    for (int j = index; j < s.length(); j++)
    {
        if (used.count(s[j]))
            continue;
        used.insert(s[j]);
        swap(s[j], s[index]);
        print_all_permutations(s, index + 1);
        swap(s[j], s[index]);
    }
}

int main()
{
    string s;
    cout << "Enter the number\n";
    cin >> s;
    print_all_permutations(s, 0);
    return 0;
}
// is se ye ensure hoga ki repeat na ho

// lexographical order mein chahiye to sort kar lo end mein saare vector mein store karne ke baad ya fir to stl use karo direct
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter the number\n";
    cin >> s;

    sort(s.begin(), s.end()); // start with smallest lexicographic permutation
    do
    {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
// TC - O(n*n!)  SC - O(1)

// real question ye hai ab ki ek number de rakha hoga uski next permutation batani hai
// brute force to yahi hai ki saati generate karao fir sort karo fir search karo apne number k eliye aur uska agla print kara do

// optimal
/* first step - peeche se iterate karna shuru karo aur break point dhundo jo ki vo point hoga jab humein aisa number milega jo ki humare peeche se ascending order ko tod raha hoga
take eg 2 1 5 4 3 0 0
0 se chale agla 0 theek hai 3 theek hai 4 theek hai 5 theek hai 1 ne order break kar diya to 1 pe humara break point hai
second step - break point ke pehle vale numbers mein us se just bada number dhundo
to huk peeche se chalenge 0 chota 0 chota 3 bada to 1 ko 3 se swap kar denge to humara ban gaya 2 3 5 4 1 0 0 ab 5 4 1 0 0 ko sorted manner mein place kar do sorted bhui kya
hum jante hi hain ki vo saare sorted hi the to bas 3 tak ke numbers ko reverse kar do
to humari next permutation ban gayi 2 3 0 0 1 4 5*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int index = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            index = i;
            break;
        }
    }
    // agar iss step kle baad index still -1 hai to og array ko reverse karke return kar do
    if (index == -1)
        reverse(a.begin(), a.end());
    else
    {
        for (int i = n - 1; i > index; i--)
        {
            if (a[i] > a[index])
            {
                swap(a[i], a[index]);
                break;
            }
        }
        reverse(a.begin() + index + 1, a.end());
    }
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
    return 0;
}
// TC - O(n)  SC - O(1)