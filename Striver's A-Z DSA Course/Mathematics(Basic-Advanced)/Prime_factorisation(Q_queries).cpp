// ismein q queries hain jinka prime factorisation print karna hai

// Most obvious approach - has number ke liye jaise prime factorisation vala approach dekha tha vo lagao
// TC - O(n*sqrt(n))

// Optimised approach - kya ho agar har number k eliye humein pata lag jaye ki uska smallest prime factor kya hai    to hum iterations usi se shuru karenge na ki har baar 2 se   to is se humare bohot iterations save ho jayenge    to iske liye hum banate hain ke spf table (Smallest prime factor table)  aur kisi bhi particular number ke liye ye table jo bhi value deti hai us se shuru karte hain iterations na ki 2 se    and this is the most optimised approach

// Step 1: Build SPF Table
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000000;
vector<int> spf(MAXN + 1);

void buildSPF()
{
    for (int i = 0; i <= MAXN; i++)
        spf[i] = i;

    for (int i = 2; i * i <= MAXN; i++)
    {
        if (spf[i] == i)
        { // i is prime
            for (int j = i * i; j <= MAXN; j += i)
            {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

// Step 2: Print Prime Factorization
void primeFactorization(int n)
{
    while (n != 1)
    {
        cout << spf[n] << " ";
        n /= spf[n]; // yahan bhi samajhdari lagayi hai   iterations shuur karne ke liye hi nahi ise har baar hi use kar sakte hain jab n ko vhota bana liya to uska spf print kar do and it keeps going while n!=1
    }
    cout << "\n";
}

// Step 3: Answer Q Queries
int main()
{
    buildSPF();
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        primeFactorization(n);
    }
}

// TC - O(q*logn) + O(n*log(log(n)))  SC - O(n)