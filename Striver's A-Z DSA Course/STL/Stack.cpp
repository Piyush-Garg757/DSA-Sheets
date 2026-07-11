#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> s;
    s.push(1);
    s.emplace(2);
    s.pop();
    s.top();
    s.size();
    s.empty();
    // st1.swap(st2);
    return 0;
}