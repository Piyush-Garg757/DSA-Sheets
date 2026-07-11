// 1. Binary as a string(Recommended)
#include <bits/stdc++.h>
using namespace std;

int binaryToDecimal(string s)
{
    int ans = 0;
    for (char c : s)
    {
        ans = ans * 2 + (c - '0');
    }
    return ans;
}
int main()
{
    string s = "1101";
    cout << binaryToDecimal(s);
}
Output: 13
Time : O(n)

// 2. Using stoi()(Very Short)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "1101";
    cout << stoi(s, nullptr, 2);
}
// The third argument (2) tells stoi that the string is in base 2.