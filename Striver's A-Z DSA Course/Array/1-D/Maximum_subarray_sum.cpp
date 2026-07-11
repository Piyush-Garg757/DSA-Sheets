// maximum sum nikalna hai our of all the subarrays
// brute force to vahui ki sabka sum nikalte jao aur max rakhte jao
// better ey ki third loop nahi lagega j ke andar sum nikal lenge
// Most optimal approach is kadane's algorithm
/* -2 -3 4 -1 -2 1 5 -3
ismein ek max leke chalenge aur ek sum aur jab bhi sum<0 hoga to use 0 kar lege kyuki negative leke chalne mein koi fayda nahi hai kyuki vo sum ko ghatayega hi
to humne shuru kiya -2 aya sum to humne sum 0 kar diya fir aage -3 aya fir fir 0 kar diya fir aage 4 aya to max update kiy aaur aage badhe fir -1 aya to sum 3 ho gaya but abhi bhi negtive nahi hua hai to hum ue leke chal rahe hain fi aage sum 1 hua fir aage 2 hua fir aage 7 hua to mx update kiya fir aage 4 hua aur end mein max return kar diya */

// ek zaruri baat iss question mein humein uye bola gayahai ki find the max sm including empty subarray to agar saare elements negative hain to max 0 hi hoga
// agar empty subarray nahi lena hai to max ko INT_MIN se initialize karna padega
// agar empty subarray lena hai to max ko 0 se initialize karna padega
#include <iostream>
#include <climits>
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
    int max = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum < 0)
            sum = 0;
        else if (sum > max)
            max = sum;
    }
    cout << max << "\n";
    return 0;
}

// TC - O(n)  SC - O(1)

// ishi mein agar hum chahte hain ki starting index aur ending index bhi mile to ek aur variable start le lenge aur jab bhi sum 0 hoga to start ko i+1 kar denge aur max update karte waqt end ko i set kar denge
/*int max = 0, sum = 0,startidx=-1, endidx=-1,start=0;
    for (int i = 0; i < n; i++)
    {
    if(sum==0) start = i;
        sum += a[i];

        if (sum < 0)
            sum = 0;
        else if (sum > max)
            max = sum;
            startidx = start;
            endidx = i;
    }*/