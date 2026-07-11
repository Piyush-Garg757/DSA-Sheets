// ismein ek array diya hoga usmein honge elements jo represent karte hain price of stocks
// humein buy and sell karna hai aisa ki profit maximum ho
// aur obviously sell  buy karne ke baad hi karna hai
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int mini = a[0], profit = 0;
    for (int i = 1; i < n; i++)
    {
        profit = max(profit, a[i] - mini);
        mini = min(a[i], mini);
    }
    cout << profit;
    return 0;
}