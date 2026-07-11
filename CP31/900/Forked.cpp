https : // codeforces.com/problemset/problem/1904/A
/*Forked!

Lunchbox is done with playing chess! His queen and king just got forked again!
In chess, a fork is when a knight attacks two pieces of higher value, commonly the king and the queen. Lunchbox knows that knights can be tricky, and in the version of chess that he is playing, knights are even trickier: instead of moving 1 tile in one direction and 2 tiles in the other, knights in Lunchbox's modified game move a tiles in one direction and b tiles in the other.
Lunchbox is playing chess on an infinite chessboard which contains all cells (x,y) where x and y are (possibly negative) integers. Lunchbox's king and queen are placed on cells (xK,yK) and (xQ,yQ) respectively. Find the number of positions such that if a knight was placed on that cell, it would attack both the king and queen.

Input
Each test contains multiple test cases. The first line contains an integer t (1≤t≤1000) — the number of test cases. The description of the test cases follows.
The first line of each test case contains two integers a and b (1≤a,b≤10^8) — describing the possible moves of the knight.
The second line of each test case contains two integers xK and yK (0≤xK,yK≤10^8) — the position of Lunchbox's king.
The third line in a test case contains xQ and yQ (0≤xQ,yQ≤10^8) — the position of Lunchbox's queen.
It is guaranteed that Lunchbox's queen and king will occupy different cells. That is, (xK,yK) ≠ (xQ,yQ).

Output
For each test case, output the number of positions on an infinite chessboard such that a knight can attack both the king and the queen.

Example
Input
4
2 1
0 0
3 3
1 1
3 1
1 3
4 4
0 0
8 0
4 2
1 4
3 4

Output
2
1
2
0

Note
In the first test case, the knight can move 2 squares in one direction and 1 square in the other (it is essentially the same as the knight in standard chess). A knight placed on (2,1) or (1,2) would attack both the king and queen.
In the second test case, a knight placed on (2,2) would attack both the king and queen.
In the third test case, a knight placed on (4,4) or (4,−4) would attack both the king and queen.
In the fourth test case, there are no positions where the knight can attack both the king and the queen.*/

// My first approach
#include <bits/stdc++.h>
        using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, xk, yk, xq, yq;
        cin >> a >> b >> xk >> yk >> xq >> yq;
        int position = 0;
        int y_diff = abs(yk - yq);
        int x_diff = abs(xk - xq);
        if (xk == xq && (y_diff == 2 * a || y_diff == 2 * b))
            position = 2;
        else if (yk == yq && (x_diff == 2 * a || x_diff == 2 * b))
            position = 2;
        else
        {
            if ((y_diff == 2 * a && x_diff == 2 * b) || (x_diff == 2 * a && y_diff == 2 * b))
                position = 1;
            else if ((x_diff == a + b && y_diff == a + b) || (x_diff == abs(a - b) && y_diff == abs(a - b)) || (x_diff == abs(a - b) && y_diff == a + b) || (x_diff == a + b && y_diff == abs(a - b)))
                position = 2;
        }
        cout << position << "\n";
    }
}
// TC - O(1)  SC - O(1)

// More general approach  - king ke saare attack co ordinated generate karo   same karo queen ke liye    and dono ke kitne intersection aa rahe  hain vo dekho

#include <bits/stdc++.h>
using namespace std;

// Arrays to represent the possible directions a knight can move
int dx[4] = {-1, 1, -1, 1}, dy[4] = {-1, -1, 1, 1};

int main()
{
    int t; // Number of test cases
    cin >> t;
    while (t--)
    {
        long long a, b; // Knight's move parameters
        cin >> a >> b;
        long long x_king, y_king; // Position of the king
        cin >> x_king >> y_king;
        long long x_queen, y_queen; // Position of the queen
        cin >> x_queen >> y_queen;
        // Inputs are read

        // Sets to store positions attacked by the knight when placed to attack king and queen
        set<pair<int, int>> king_hits, queen_hits;

        // Calculate all possible positions that can be attacked by the knight
        for (int j = 0; j < 4; j++)
        {
            // Calculate positions attacked by the knight when placed to attack the king
            king_hits.insert({x_king + dx[j] * a, y_king + dy[j] * b});
            king_hits.insert({x_king + dx[j] * b, y_king + dy[j] * a});

            // Calculate positions attacked by the knight when placed to attack the queen
            queen_hits.insert({x_queen + dx[j] * a, y_queen + dy[j] * b});
            queen_hits.insert({x_queen + dx[j] * b, y_queen + dy[j] * a});
        }

        int ans = 0; // Variable to store the number of positions where the knight can fork the king and queen
        // Check for common positions in both sets
        for (auto position : king_hits)
            if (queen_hits.find(position) != queen_hits.end())
                ans++;

        cout << ans << endl; // Output the result for the current test case
    }
    return 0;
}

// Time Complexity (TC): O(8*log2(8)) = O(8*3) = O(24)
// Space Complexity (SC): O(8)
