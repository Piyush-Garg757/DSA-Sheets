#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number\n";
    cin >> n;
    while (n != 0)
    {
        cout << n % 10 << " ";
        n /= 10;
    }
    // TC - O(log10(N))
    return 0;
}