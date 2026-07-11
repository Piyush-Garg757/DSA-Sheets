// jis bhi element ki frequence n/2 se zyada ho usse return kar do
// brute force to vahi O(N^2)
// Better approach hashing
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }
    for (auto i : mpp)
    {
        if (i.second > n / 2)
        {
            cout << "Element with frequency greater than n/2: " << i.first << endl;
        }
    }
    return 0;
}
// Time Complexity: O(N)+O(logN)  SC - O(N)

// Optimal
// Moore's Voting Algorithm
// ismein kya karte hain ki 1st element ko ek candidate mana aur aage iterate karte karte ek count maintain karenge jaise hi uss element ke alava koi aur element aata hai to count ko decrease karte rahenge aur avhi aya to count ++ karte rahenge
// agar count 0 ho gaya to candidate change karte rahenge kyuki jo n/2 se zyada ayega uska count 0 o naahi ho  sakta to aise karte karte last mein jo candidae bachega uska count kuch to hoga but hum sure nahi hain ki vahji answer hai kuyuki uska count n/2 se zyada ho bhi sakta hai ya nahi to ek baar fir array ko iterate karenge aur uska count n/2 se zyada hai ya nahi check karenge agar nahi hua to kisi ki bhi frequency n/2 se zyada nahi hai to -1 return karenge

// eg - 7 7 5 7 5 1   5 7   5 5 7 7   5 5 5 5
// ismein 7 ko candidate mana aur iterate karte gaye  aur 7 7 5 7 5 1 hote hi 7bbka count 0 ho gaya to candidate ab agla element yani 5 ban jayega jiska count 5 7  hote hi khatam ho jayega fir naya candidate liya 5 jiska count 5 5 7 7 hote hi khatam ho jayega fir naya candidate liya 5 jiska count 5 5 5 5 hote hi 4 hoga
// ab maan lo 1 1 1 1 hota to end mein 1 ka count 4 hoga but 1 n/2 se zyada nahi hai to -1 return karte
// isliye ismein end mein jo element baccha vo potential answer hai
// array ko ek naar aur iterate karke check karna padega agar uska count n/2 se zyada hai to use return karenge nahi to -1
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cd, count = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
        {
            cd = a[i];
            count = 1;
        }
        else if (a[i] == cd)
        {
            count++;
        }
        else
        {
            count--;
        }
    }
    count = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == cd)
        {
            count++;
        }
    }
    if (count > n / 2)
    {
        cout << "Element with frequency greater than n/2: " << cd << endl;
    }
    else
    {
        cout << "No element with frequency greater than n/2" << endl;
    }
    return 0;
}
// Time Complexity: O(N) + O(N) = O(N)  SC - O(1)

// Ishi mein ek variety ki jitne bhi number floor(n/3) se zyada times aaye unhein print karna hai
// to ye at max 2 aa sakte hain ek array mein
/*for eg 1 1 1 2 2 3 3 3
floor(n/3) yani floor(8/3)  yani 2
to aise elements jo min 3 times aaye to clearly ismein 2 hi ho sakte hain

To brute force to yahi ki o(n^2) har number ke liye check karenge kitni baar aa raha hai aur uske according answer nikalenge*/

// Better sol -> hashing through map

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    unordered_map<int, int> mpp;
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mpp[a[i]]++;
    }
    int check = n / 3;
    for (auto it : mpp)
    {
        if (it.second > check)
            cout << it.first << " ";
    }
    return 0;
}
// TC - O(n)  SC - O(n)

// Optimal sol -> Moore's Voting Algo hi
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int cnt1 = 0, cnt2 = 0;
    int el1 = 0, el2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == el1)
            cnt1++;
        else if (a[i] == el2)
            cnt2++;
        else if (cnt1 == 0)
        {
            el1 = a[i];
            cnt1 = 1;
        }
        else if (cnt2 == 0)
        {
            el2 = a[i];
            cnt2 = 1;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    cnt1 = cnt2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == el1)
            cnt1++;
        else if (a[i] == el2)
            cnt2++;
    }
    cout << "Majority elements (> n/3):\n";
    if (cnt1 > n / 3)
        cout << el1 << " ";
    if (cnt2 > n / 3)
        cout << el2 << " ";
    return 0;
}
// TC - O(n)  SC - O(1)