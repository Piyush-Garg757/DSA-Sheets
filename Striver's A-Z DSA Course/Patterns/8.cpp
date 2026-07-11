#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << j + 1;
        }
        for (int j = 0; j < (n - i - 1) * 2; j++)
        {
            cout << " ";
        }
        for (int j = i + 1; j > 0; j--)
        {
            cout << j;
        }
        cout << "\n";
    }
    return 0;
}