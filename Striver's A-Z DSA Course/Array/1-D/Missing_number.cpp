// N tak numbers mein se koi ek number gayab hoga use find karna hai
#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter the value of n\n";
    cin >> n;
    int a[n - 1];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a[i];
    }
    int missing_number = n; // Start with the assumption that n is missing
    for (int i = 0; i < n - 1; i++)
    {
        missing_number ^= a[i] ^ (i + 1);
    }
    cout << "The missing number is: " << missing_number << "\n";
    return 0;
}
// yaji most optimal soluton hai kyuki khi nahi kaha hai ki sorted manner mein honge array 
// agar ye kaha hota to normal i+1 se compare karte rehte aur jahan katch nahi hota vahi break karke answer de dete
// ek sum vali approach bhi optimal hai but maan lo 10^5 elements hain to n*(n-1) ye scope se bahar ho jayega 
// isiliye ye best approach hai

// TC - O(n)  SC - O(1) 