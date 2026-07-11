#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    v.push_back(1);
    v.emplace_back(2);
    /*✅ Why emplace is faster:

    1. No temporary object:
    push_back creates a temporary object outside the container, then copies/moves it into the container.
    emplace_back builds the object directly in the container (in-place construction).

    2. Avoids copy/move constructor (if applicable):
    If the class has expensive copy/move constructors, emplace avoids that overhead.*/
    vector<pair<int, int>> v1;
    v1.push_back({1, 3});
    v1.emplace_back(4, 5); // ismein {} lagane zaruri nahi hain push mein hain

    vector<int> v2(5, 100); // {100,100,100,100,100}
    vector<int> v3(5);      // {0,0,0,0,0}
    vector<int> v4(v3);     // it is another container and is a copy of v3

    cout << "--------------------------------------------------------------------------------\n";

    vector<int>::iterator it = v.begin(); // v.begin() points to the adress of 0th element
    it++;
    cout << *(it) << "\n";

    vector<int>::iterator it1 = v.end(); // v.end() last element ko point nahi karta vo last element ke just bahar vvali memory ko point    karta hai matalab jab it-- karke print karoge tab last element print hoga
    cout << *(it1) << "\n";
    cout << *(--it1) << "\n";
    // aaise hi v.rend() aur v.rbegin() hota hai r ka matlab reverse hota hai to vector ko reverse kar lo aur fir normally end aur begin jaise upar bataye vese hi hote hain   aur ye dono bohot kam use hote hain vese

    // v.back() iska matlab last element ko point kar raha hai   jaise iss case mein 2

    // Iterating
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << "\n";
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    cout << "\n";
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *(it) << " ";
    }
    // auto apne aap data type pehchaan leta hai jaise auto i=5 likhoge to aute apne aap samajh jayega ki int hai
    cout << "\n";
    // for-each loop ki help se hum aur easily print kr sakte hain
    for (auto i : v)
    {
        cout << i << " ";
    }
    // iss case mein auto data type iterator nahi int lega

    // Deleting
    /*{10,20,30,40,50}
    v.erase(v.begin()+1) - this deletes 20 {10,30,40,50}
    
    {10,20,30,40,50}
    v.erase(v.begin()+1,v.begin()+4) - this deletes 20 - 50 where 50 is not included {10,50}*/

    // Inserting
    /*{100,100}
    v.insert(v.begin(),300) - {300,100,100}
    v.insert(v.begin()+1,2,10) - {300,10,10,100,100}
    
    vector<int>copy(2,50)
    v.insert(v.begin(),copy.begin(),copy.end()) - {50,50,300,10,10,100,100}*/

    // Other functions
    /* v1 - {10,20}
    v2 - {30,40}
    v1.swap(v2) - v1 and v2 gets swapped*/

    //v.clear() deleted th entire vector
    // v.empty() - returns T or F
    return 0;
}