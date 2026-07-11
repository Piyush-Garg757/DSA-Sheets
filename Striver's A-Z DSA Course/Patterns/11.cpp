#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << (char)(j + 1 + 64);
        }
        for (int j = i; j > 0; j--)
        {
            cout << (char)(j + 64);
        }
        cout << "\n";
    }
    return 0;
}