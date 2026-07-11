#include <iostream>
using namespace std;

int sum_N(int n)
{
    if (n == 0)
        return 0;
    return sum_N(n - 1) + n;
}
int main()
{
    int n;
    cout << "Enter n \n";
    cin >> n;
    cout << sum_N(n);
    return 0;
}