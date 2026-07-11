#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> mpp; // <key,value>
    map<int, pair<int, int>> map1;
    map<pair<int, int>, int> map2;

    mpp[1] = 2; // stores {1,2}
    // mpp.emplace({3, 4}); // stores {3,4}
    mpp.insert({5, 6});
    // map stores unique keys in sortd manner

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << "\n";
    }
    cout << "\n";
    cout << mpp[1];
    cout << "\n"
         << mpp[4]; // 4 hai nahi to 0 dega

    auto it = mpp.find(5);

    // lower bound upper bound are there
    // erase size empty swap are same

    // Multimap
    multimap<int, int> mpp;
    // same as map but you can store duplicates and sorted is not there
    // mpp[key] can't be used here

    // Unordered map
    // same as set and unordered set diff.
    // unordered map mein integer,double,charecter,string hi key mein rakh sakte hain jabki map mein koi bhi  data type as a key aa sakta hai jaise pair
    return 0;
}