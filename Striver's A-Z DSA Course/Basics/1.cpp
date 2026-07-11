#include <iostream>
// #include<bits/stdc++.h> ise include karne se saari libraries include ho jati hain alag se include nahi karni padti
#include <string.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << s;
    cout << "\n";
    // Isse bas pehla word hi ayega chahe kitni bhi badi string de do input space se pehle pehle vala lega
    string s1, s2;
    cin >> s1 >> s2;
    cout << s1 << " " << s2;
    // Agar humein puri string chahiye to
    string s3;
    getline(cin, s3); // ye bhi tab tak lega jab tak enter na kar dein
    cout << s3;
    return 0;
}