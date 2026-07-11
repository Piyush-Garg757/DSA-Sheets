https : // codeforces.com/problemset/problem/1679/A
/*AvtoBus

Spring has come, and the management of the AvtoBus bus fleet has given the order to replace winter tires with summer tires on all buses.
You own a small bus service business and you have just received an order to replace n tires. You know that the bus fleet owns two types of buses: with two axles (these buses have 4 wheels) and with three axles (these buses have 6 wheels).
You don't know how many buses of which type the AvtoBus bus fleet owns, so you wonder how many buses the fleet might have. You have to determine the minimum and the maximum number of buses that can be in the fleet if you know that the total number of wheels for all buses is n.

Input
The first line contains an integer t (1≤t≤1000) — the number of test cases. The following lines contain description of test cases.
The only line of each test case contains one integer n (1≤n≤10^18) — the total number of wheels for all buses.

Output
For each test case print the answer in a single line using the following format.
Print two integers x and y (1≤x≤y) — the minimum and the maximum possible number of buses that can be in the bus fleet.
If there is no suitable number of buses for the given n, print the number −1 as the answer.

Example

Input
4
4
7
24
998244353998244352

Output
1 1
-1
4 6
166374058999707392 249561088499561088

Note
In the first test case the total number of wheels is 4. It means that there is the only one bus with two axles in the bus fleet.
In the second test case it's easy to show that there is no suitable number of buses with 7 wheels in total.
In the third test case the total number of wheels is 24. The following options are possible:
• Four buses with three axles.
• Three buses with two axles and two buses with three axles.
• Six buses with two axles.
So the minimum number of buses is 4 and the maximum number of buses is 6.*/

// My sol
#include <bits/stdc++.h>
        using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n < 4 || n % 2 != 0)
            cout << "-1\n";
        else if (n <= 10)
        {
            if (n == 4 || n == 6)
                cout << "1 1\n";
            else
                cout << "2 2\n";
        }
        else
        {
            long long mini = -1, maxi = -1;
            int m6 = n % 6;
            if (m6 == 0)
                mini = n / 6;
            else
                mini = n / 6 + 1;
            maxi = n / 4;
            cout << mini << " " << maxi << "\n";
        }
    }
}
// TC - O(1)  SC - O(1)

// More cleaner sol
#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t;
    cin >> t; // Read the number of test cases

    while (t--)
    {
        long long n;
        cin >> n; // Read the total number of wheels for the current test case

        // If the number of wheels is less than 4 or odd, it's impossible to form buses
        if (n < 4 || n % 2 == 1)
            cout << -1 << '\n'; // Output -1 indicating no valid configuration
        else
        {
            // Using a different formula for ceil to avoid floating point operations
            // in C++20 (GCC 13-64) version

            // Calculate the minimum number of buses using 6-wheel buses
            long long min_buses = (n + 5) / 6; // integer ceil of n/6

            // Calculate the maximum number of buses using 4-wheel buses
            long long max_buses = n / 4; // integer floor of n/4

            // Output the minimum and maximum number of buses
            cout << min_buses << " " << max_buses << '\n';
        }
    }

    return 0;
}

// Time Complexity (TC): O(1)
// Space Complexity (SC): O(1)
