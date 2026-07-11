#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number\n";
    cin >> n;
    // for (int i = 1; i <= n / 2; i++)
    // {
    //     if (n % i == 0)
    //         cout << i << " ";
    // }
    // cout<<n;

    // Optimised approach

    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i * i != n)
            {
                cout << n / i << " ";
            }
        }
    }
    // TC - O(sqrt(n))

    // Aise hi prime check karna ho to ismeein ek count laga do count 2 se bada ho to nahi hai prime varna hai
    return 0;
}