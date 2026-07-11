// ismein brute force to vahi nested loop approach hai
// better approach hai hashing approach jismein hum har element ke liye chek karte hain ki map mein koi aisa index hai kya jisko add karne se target aa jaye agar hai yo dono ke idex returnkar dete hain aur nahi hai to iss element ko map mein store karte hain
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
    int target;
    cout << "Enter the target sum\n";
    cin >> target;
    for (int i = 0; i < n; i++)
    {
        if (mpp.count(target - a[i]))
        {
            cout << mpp[target - a[i]] << " " << i << "\n";
            return 0;
        }
        else
        {
            mpp[a[i]] = i;
        }
    }
    return 0;
}
// TC - O(n) or O(n^2) SC - O(n)
// optimal vahi 2 pointer approach hai jo sliding window approach kehlata hai but vo tab hai jab ya to array sorted ho ya fir array sorted nahi hai to bas yes ya no pucha ho index ouche honge to dikkat hai kuki sort karna pdega iss approach mein aur us se index galat ho jayenge to dupllicate array banani padegi to vo opimal nahi rahega