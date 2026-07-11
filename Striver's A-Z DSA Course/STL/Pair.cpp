#include <iostream>
using namespace std;

int main()
{
    pair<int, int> p = {1, 3};
    cout << p.first << " " << p.second << "\n";

    pair<int, pair<int, int>> p1 = {1, {4, 5}};
    cout << p1.first << " " << p1.second.first << " " << p1.second.second << "\n";

    pair<int, int> arr[] = {{1, 2}, {3, 4}, {5, 6}};
    cout << arr[1].second << "\n";
    return 0;
}