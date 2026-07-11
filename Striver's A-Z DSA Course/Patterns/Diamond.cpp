#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of lines you want in the pattern\n";
    cin >> n;
    if (n % 2)
    {
        int u = n / 2 + 1, d = n - u;
        for (int i = 0; i < u; i++)
        {
            for (int j = 0; j < u - 1 - i; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < 2 * (i + 1) - 1; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d - 1 + i; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < 2 * (d - i) - 1; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
    else
    {
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < n / 2 - 1 - i; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < 2 * (i + 1) - 1; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = 0; j < i; j++)
            {
                cout << " ";
            }
            for (int j = 0; j < 2 * (n / 2 - i) - 1; j++)
            {
                cout << "*";
            }
            cout << "\n";
        }
    }
    return 0;
}




#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of lines you want in the pattern\n";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int spaces = abs(n / 2 - i);
        int stars = n - 2 * spaces;

        for (int j = 0; j < spaces; j++) cout << " ";
        for (int j = 0; j < stars; j++) cout << "*";
        cout << "\n";
    }

    return 0;
}
