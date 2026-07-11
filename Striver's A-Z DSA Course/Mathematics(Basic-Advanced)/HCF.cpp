#include <iostream>
using namespace std;

int main()
{
    int n1, n2;
    cout << "Enter the numbers\n";
    cin >> n1 >> n2;
    int min = n1;
    if (n2 < n1)
        min = n2;
    for (int i = min; i >= 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            cout << i << "\n";
            break;
        }
    }
    // TC  - O(min(n1,n2))

    // Optimised approach
    // Euclidian algorithm - gcd(a,b) = gcd(a%b,b) where a>b
    // to iss method ko lagate jao jab tak ek number 0 na ban jaye
    // jab aisa hoga to dusra number answer hoga

    while (n1 != 0 && n2 != 0)
    {
        if (n2 > n1)
            n2 %= n1;
        else
            n1 %= n2;
    }
    if (n1)
        cout << n1 << "\n";
    else
        cout << n2 << "\n";
    // TC - O(log(min(n1,n2))) 
    // yahan log ka base phi hai kyuki har baar number change ho raha ahi to hum kuch fixed nahi keh sakte hain
    return 0;
}