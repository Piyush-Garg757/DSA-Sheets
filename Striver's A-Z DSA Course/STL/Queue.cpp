#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.emplace(2);
    q.back() += 5;
    cout << q.front() << " " << q.back() << "\n";
    q.pop();
    cout << q.front();
    // size swap empty as stack
    return 0;
}