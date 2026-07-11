#include <iostream>
#include <set>
using namespace std;

int main()
{
    // it stores everything sorted order and stores only unique elements
    set<int> st;
    st.insert(1);
    st.emplace(3);
    st.insert(3);
    st.insert(2);
    // 1,2,3 aise ayega aur ismein bhi linear container nahi hota ye ismein andar tree maintain hota hai

    auto it = st.find(3); // it returns an iterator which points to 3
    // agar uss element ko find  kara jo set mein haihi nahi to end return karega matlabb last element ke just baad ki memory

    st.erase(3);

    int cnt = st.count(1); // iska output 1 ya 0 hi ho sakta hai

    auto it1 = st.find(2);
    auto it2 = st.find(4);
    st.erase(it1, it2);// last one not included
    // lower_bound upper_bound

    // Multiset
    multiset<int>s;
    // ismein unique vala follow nahi hota bas sorted vala follow hota hai
    // kitne bbhi 1 daal sakte ho aur erase karne pe sare 1 erase ho jayenge

    // agar 1 erase karna chahte ho to
    /*ms.earse(ms.find(1))
    ms.erase(ms.find(1),ms.find(1)+2) ismein fir vahi last one not included*/

    //Unordered set
    // ismein unique vala hota hai but sortd vala nahi hota
    // lower_bound aur upper_bound do not work here and complexity is better than set in most cases
    return 0;
}