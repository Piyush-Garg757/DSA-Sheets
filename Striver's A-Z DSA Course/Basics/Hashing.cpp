// ismein basically ye hota hai ki hum ek array auur bana lete hain jismein OG array mein koi element kitni baar aa raha hai vo rakhte hain
// jab hum array define karte hain tab usmein garbage values dali jati hain initially agar main ke andar kar rahe ho to 
// aur main ke bahar yani globallyy define kar rahe ho to saare elements 0 define hote hain
#include <iostream>
#include <map>
#include<unordered_map>
using namespace std;

int main()
{
    int n, m, k;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the max limit\n";
    cin >> m;
    int hash[m + 1] = {0}; // m+1 isiliye kiya kyuki agar 12 tak max rakhna hai to 13 ka define karna padega na taki 12 tak aa sakein
    for (int i = 0; i < n; i++)
    {
        hash[a[i]]++;
    }
    cout << "Enter the number whose number of occurences you want to know\n";
    cin >> k;
    cout << hash[k] << "\n";
    // agar max INT_MAX ho to hum hash[max+1] nahi kar payenge main ke andar to iss case mein globally define karna padta hai aur globally define karrenge to 0 ke equal rkahne ki need bhi nahi hai kyuki usmein sab 0 hi define hota hai
    // main mein 10^6 tak ja sakte hain aur globally 10^7 tak

    // aise hi agar string ke liye hashing karna hai to total 256 chare ters hote hain to 256 size ka array le lenge aur accordibgly cheezein map karte jayennge
    // agar constraint ho ki bas lower case ya uppar case alphabets honge to 26 size ki array le sakte hain aur a(97) ya A(65) ki ascii values - karkee store kar sakte hain

    // space kam lage iske liye hum map use karte hain
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[a[i]]++;
    }
    for (auto i : mpp)
    {
        cout << i.first << "->" << i.second << "\n";
    }
    // is se jo jo elementts hain bas unka hi map bannega aur humari space save hogi aur ye sorted order mein deta hai
    // aur ye mpp[a[i]]++ cin>>a[i] ke just neeche bhi laga sakte hain
    // mapp mein storing aur fetching mein TC hoti hain log(n) in all the cases where n is number of elements in the map
    // isi ki jagah hum unordered_map use karein to usmein order fixed nahi hota jaise ismein sorted hota hai order usmein kuch bhi ho sakta hai but usmein best aur avg case mein TC is O(1) and in worst case it is O(n) so using it is much more helpful 
    // aur iska ye worst case ana bohot bohot bohot rare hota hai to firts priority pe ise hi use karo agar TLE aa raha hai tab map use karo

    // ye jo worst case hota hai ye extremely rare hota hai aur vo collision ke case mein hota hai

    // Collision :-
    /*Hashing ke  3 types hote hain - Diviison method  Folding method  Mid square method
    ismein se bas division humare kaam ka hai baaki 2 nahi hain
    to division mein ye hota hai ki 10 se % kar lete hain aur jo remainder ata hai us se hash karte hain
    jaise [2,4,8,29] aur maan lo hum 10 se chote hi store kar sakte hain to hum 10 se % le lete hain to [2,3,8,9] iss form mein store karte hain aur hash karte hain is se ye fayda hota hai ki 30 size ka array define nahi karna padega 
    
    to ismein problem tab aa sakti hai jab do teen number ek hi  digit se end hone vale aa jayyein jaise 8,18,28  
    aise aa jayein to ek chain form hoti hai linked list type ki aur accordingly hashing hoti hai
    
    
    Collision vo condition hoti hai jismein saare hi input elements same digit se end hone vale aa jayein [8,18,28,38,48,58,68,788,88,98]
    to ye hai worst case jismein O(n) hoti hai aur ye bohot rare hai*/
    return 0;
}