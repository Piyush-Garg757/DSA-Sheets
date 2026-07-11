#include <iostream>
#include <string>
using namespace std;

void print(string s, int n, int count)
{
    if (count > n)
        return;
    cout << s << "\n";
    print(s, n, count + 1);
}
int main()
{
    string s;
    cout << "Enter the name\n";
    cin >> s;
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    print(s, n, 1);
    // TC - O(N) - SC
    return 0;
}