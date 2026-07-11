// Teen varities hain ismein - ek mein row aur column number dega aur uss location pe jo element ana hoga use print kiarna hoga     dusra ye ki row number de dega uss row ke saare elements ko print karna hoga       aur teesra ye ki n dega to n lines print karni hongi pattren printing ki tarah

// 1st variety mein r aur c given hoga to (r-1)C(c-1) humara answer hoga
// ab ncr nikalne k ewliye factorial vala method bohot bada hoga      us se accha ye kar sakte hain ki maan lo 10c3 hai to 10 se 3 places jao aur neeche bhi 3 hai to 3 hi jao
// 10 * 9 * 8 / 3 * 2 * 1
long long ncr(int r, int c)
{
    long long res = 1;
    for (int i = 0; i < c; i++)
    {
        res = res * (r - i);
        res = res / (i + 1);
    }
    return res;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    cout << "Enter the value of r and c\n";
    cin >> r >> c;
    cout << ncr(r, c);
    return 0;
}

// 2nd variety aise hi ho jayegi ek for loop lagake bas column ki vale change hoti jayegi usmein
// but usmein thoda optimise kar sakte hain
// upar vale sol mein fact ki jis defination se kaam kiya hai use thoda modify karenge to ye logic mil jayega
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, ans = 1;
    cout << "Enter the row number\n";
    cin >> r;
    cout << "1 ";
    for (int i = 1; i < r; i++)
    {
        ans *= (r - i);
        ans /= i;
        cout << ans << " ";
    }
    return 0;
}

// aise hi similar way mein 3rd variety kar sakte hain