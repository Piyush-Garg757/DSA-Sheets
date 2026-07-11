/*subarray aur sequence mein ye farak hota hai ki sequence mein contiguous nahi hota hai kahi se bhi element le sakte hain apna kaam banane ke liye
102 4 100 1 101 3 2 1 1
ismein length of longets subsequence hoga 4 i.e 1 2 3 4*/

// brute force
/*simple length 1 se shuru karenge aur iterate karte hue aage badhenge
102 aya to 103 ke liye search karenge   nahi mila   to aage badhenge 4 aya to 5 ke liye aise hi karte karte 1 2 3 4 banega aur length 4 ho jayegi*/
#include <bits/stdc++.h>
using namespace std;
int search(int a[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == k)
            return 1;
    }
    return 0;
}
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
    int length = 1;
    for (int i = 0; i < n; i++)
    {
        int curr_length = 1;
        int x = a[i];
        while (search(a, n, x + 1))
        {
            x++;
            curr_length++;
        }
        length = max(length, curr_length);
    }
    cout << length;
    return 0;
}
// TC - O(n^2)  SC - O(1)

// Better approach
/*pehle array ko sort kar lo fir teen variables banao curr_count,longest aur last_min jab tak a[i] last min ke equal ho tab tak aage badho kuch change nahi hoga jab a[i] last min se just bada ho to last min ko a[i] kar do aur curr_count kpo 2 kar do aise hi chalte raho   jab aisa number aaye jo last min se alag to ho but us se just bada na ho to curr_count ko 1 kar do aur last_min ko a[i] aur longest = max(longest,curr_count)*/
/*for eg
1 1 1 2 2 2 3 3 4 100 101 101 102 103*/
/*ismein 1 2 3 4 aate rahenge tab tak longest 4 ho gaya fir 100 aya to last_min 100 hua aur longest 4 ho gaya curr_count 1 ho gaya vapas
fir aage chaklega aise hi ar 100 101 102 103 ka bhi 4 ayega to end mein answer 4 porint hoga*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int longest = 1, last_min = a[0], curr_count = 1;
    for (int i = 1; i < n; i++)
    {
        if (a[i] - last_min == 1)
        {
            last_min = a[i];
            curr_count++;
        }
        else if (a[i] - last_min > 1)
        {
            longest = max(longest, curr_count);
            last_min = a[i];
            curr_count = 1;
        }
    }
    cout << longest;
    return 0;
}
// TC - O(nlog(n))  SC - O(1)

// optimised solution
// unordered set use karenge   agar koi element aya aur us se just pehle vala exist karta hai to aage badh jayenge kyuki vo starting element nahi hai     hum iss aproach mein strting element dhundhte hain    to agar vo starting element hai to aage agle ke liye check karte rehte hain aur longest badhate rehte hain
// ismeinvbenefir ye hai ki unordered set mein insertion aue search ke liye O(1) ;lagega to humara O(n) mein kaam ho jayega
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the size of array\n";
    cin >> n;
    vector<int> a(n);
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    unordered_set<int> s(a.begin(), a.end()); // Insert all elements
    int longest = 0;

    for (int num : a)
    {
        // Check if it is the start of a sequence
        if (s.find(num - 1) == s.end())
        {
            // s.find(num - 1) == s.end()    agar nahi paya jata to vo s.end() return karta hai isiliye ye check lagaya hai
            int curr = num;
            int length = 1;

            while (s.find(curr + 1) != s.end())
            {
                curr++;
                length++;
            }

            longest = max(longest, length);
        }
    }

    cout << "Longest consecutive sequence length: " << longest;
    return 0;
}
// TC - O(n)  SC - O(n)