#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of lines you want in the pattern\n";
    cin >> n;
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j < n / 2 - i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * i; j++)
        {
            cout << " ";
        }
        for (int j = 0; j < n / 2 - i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    for (int i = 0; i < n / 2; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        for (int j = 0; j < 2 * (n / 2 - i - 1); j++)
        {
            cout << " ";
        }
        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }
    return 0;
}