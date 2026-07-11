// 1. Using bitset (simplest)
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 13;
    cout << bitset<32>(n) << endl;
}

Output : 00000000000000000000000000001101

// 2. Without leading zeros
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 13;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    string ans = "";
    while (n)
    {
        ans += (n % 2) + '0';
        n /= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans;
}
// TC - O(logn)  SC - O(logn)

Output : 1101

// 3. Using bit manipulation (recommended)
#include <bits/stdc++.h>
using namespace std;

void printBinary(int n)
{
    bool started = false;
    for (int i = 31; i >= 0; i--)
    {
        if ((n >> i) & 1)
            started = true;
        if (started)
            cout << ((n >> i) & 1);
    }
    if (!started)
        cout << 0;
    cout << '\n';
}
int main()
{
    printBinary(13);
}

Output : 1101