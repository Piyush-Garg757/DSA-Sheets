#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cout << "Enter the number\n";
    cin >> n;
    m = n;
    int new_number = 0;
    while (n != 0)
    {
        new_number *= 10;
        int i = n % 10;
        new_number += i;
        n /= 10;
    }
    cout << (m == new_number);
    return 0;
}