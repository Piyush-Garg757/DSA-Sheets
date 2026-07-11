// ismein nas positive number vala hai

// Brute force - saari subarrays ka sum nikalenge aur check karenge jiska sum match hoga uski length note kart jayenge aur max lngth rakhenge apne paas
#include <iostream>
using namespace std;

int main()
{
    int n, target;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the target sum\n";
    cin >> target;
    int length = 0, sum;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++)
            {
                sum += a[k];
            }
            if (sum == target)
                length = max(length, j - i + 1);
        }
    }
    cout << length;
    cout << "\n";
    return 0;
}
// TC - O(n^3)  SC - O(1)

// Better approach
// humein third loop ki zarurat nahi hai jab hum j ko increment karte hain tabhi sum baar baar update hota rahega us se 2 loop mmein kaam ho jayega
#include <iostream>
using namespace std;

int main()
{
    int n, target;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the target sum\n";
    cin >> target;
    int length = 0, sum;
    for (int i = 0; i < n; i++)
    {
        sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += a[j];
            if (sum == target)
                length = max(length, j - i + 1);
        }
    }
    cout << length;
    cout << "\n";
    return 0;
}
// TC - O(n^2)  SC - O(1)

// Better approach
// hash map use karenge jaise jaise aage badhte jayenge sum krte jeyenge aur hash mein sum aur kis index pe kya sum aa raha hai store karte jayenge agar ssum target ke equal hai to length leke compare karenge aur nahi hai ya bada hai to hash map mmein check karenge ki kya koi aisa number hai jo ismeinn se minus kar dein to target aa jaye  agar aisa hai to iss subarray ki  length nikal lenge aur vapas compae karke max lengh store karenge   nahi hai target ke eqqual to aise hi karte hue aage badh jayenge
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    int n, target;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the target sum\n";
    cin >> target;
    unordered_map<int, int> mpp;
    int sum = 0, maxlength = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum == target)
            maxlength = max(maxlength, i + 1);
        if (mpp.count(sum - target))
            maxlength = max(maxlength, i - mpp[sum - target]);
        if (!mpp.count(sum)) // maan lo 2,0,0,0,3 hai aur 3 target hai to longet subrray chahiye jo ki 3 hoga 0,0,3 but agar ye line nahi use karte hain to sum 2 ke liye map ka index change ho jayega aur latest 0 pe hoga jp ki humairlength 1 dega
            mpp[sum] = i;
    }
    cout << maxlength;
    cout << "\n";
    return 0;
}
// ismein map ya unordered_map dono use kar sakte hain kyuki index by index aage badh rahe hain to sortd ka koi chakkar hi nahi hai
// agar unordered_map use karte hain to TC - O(n) SC - O(n) ho jayega (avg aur best) case mein aur worst case mein O(n^2) ho jayega kyuki hash map mein collision bhi ho sakta hai
// agar map use karte hain to TC - O(nlogn) SC - O(n)

// Optimal solution
// Sliding window approach use karenge
#include <iostream>
using namespace std;

int main()
{
    int n, target;
    cout << "Enter the size of array\n";
    cin >> n;
    int a[n];
    cout << "Enter the elements of the array\n";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << "Enter the target sum\n";
    cin >> target;
    int length = 0, sum = 0, i = 0;
    for (int j = 0; j < n; j++)
    {
        sum += a[j];
        if (sum == target)
            length = max(length, j - i + 1);
        else if (sum > target)
        {
            sum -= a[i];
            i++;
        }
    }
    cout << length;
    cout << "\n";
    return 0;
}
// TC - O(2n) SC - O(1)
// ye sliding window approach bas positive array vale case mein hi lag sakti hai kuki ismein hum ye assume kar rahe hain ki i ko age badahne se sum reduce hoga but negative numberss ke case mein aisa nahi ho sakta


// isi mein agar negative numbers bhi le lein to hash map vala approach hi best hai
// kyuki sliding window approach mein hum assume kar rahe hain ki i ko aage badhane se sum reduce hoga but agar negative numbers hain to aisa nahi ho sakta
// isliye hash map vala approach hi best hai