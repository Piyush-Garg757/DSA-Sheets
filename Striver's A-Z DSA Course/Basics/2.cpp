#include <iostream>
#include <string.h>
using namespace std;

void change(string &s) // & use karke pass by reference kar diya varna string mein bhi pass by value hota hai
{
    s[0] = 'r';
    cout << s << "\n";
}
int main()
{
    string s = "Piyush";
    int len = s.size();
    cout << s[len - 1] << "\n";
    change(s);
    cout << s << "\n";
    return 0;
}
// time complexity is never equal to time taken as time taken to run the code depends on the configuration of the machine 
// time complexity - the rate at which time taken increase wrt input size
// space complexity - Auxilary space + input space
// Auxillary space - space that we need to solve the problem
// Input space - space that we need to store the input
