#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of lines you want in the pattern\n";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << "\n";
    }

    cout << "\n";
    
    for (int i = 0; i < n * n; i++)
    {
        cout << "*";
        if ((i + 1) % n == 0)
            cout << "\n";
    }
    return 0;
}