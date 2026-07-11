#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool comp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second < p2.second)
        return true;
    if (p1.second > p2.second)
        return false;

    if (p1.first > p2.first)
        return true;
    return false;
}
int main()
{
    /*
    sort(a,a+n) isse directly sort ho jayega aur last vala included nahi hai ismein
    sort(v.begin(),v.end())
    sort(a,a+n,greater<int>) to sort in descending order
    */
    // if you wnt to customise sorting according to your way
    pair<int, int> a[] = {{1, 2}, {2, 1}, {4, 1}};
    // sort it according to second element
    // if second element is same them sort accoding to 1st element but in descending order
    sort(a, a + 3, comp);
    for (int i = 0; i < 3; i++)
    {
        cout << a[i].first << " " << a[i].second << "\n";
    }

    int num = 7;
    int cnt = __builtin_popcount(num);
    // ye ye deta hai ki uss number ke binary tepresentation mein kitne 1 hain

    long long num1 = 123456789;
    cnt = __builtin_popcountll(num1); // long long ke naam ka ll lag gaya ismein
    cout << cnt << "\n";

    string s = "123";
    do
    {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end())); // aur ye permutations ascending order mein hoti hain to agar chahtebho ki saari permutations print ho to unn digits se possible sabse chote number pe lagana ise
    // maan lo yahan 231 hota to sort(s.begin(),s.end()) karte fir ye lagate

    // int maxi = *max_element(a, a + n);
    // similarly min
    return 0;
}