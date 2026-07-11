https://codeforces.com/problemset/problem/1858/A
/*Buttons
Anna and Katie ended up in a secret laboratory.
There are a + b + c buttons in the laboratory. It turned out that:
- a buttons can only be pressed by Anna,
- b buttons can only be pressed by Katie,
- c buttons can be pressed by either of them.
Anna and Katie decided to play a game, taking turns pressing these buttons. Anna makes the first turn.
Each button can be pressed at most once, so at some point, one of the girls will not be able to make her turn.
The girl who cannot press a button loses.
Determine who will win if both girls play optimally.

Input
The first line contains a single integer t (1 ≤ t ≤ 10^4) — the number of test cases.
Each test case consists of three integers a, b, and c (1 ≤ a, b, c ≤ 10^9) — the number of buttons that can only be pressed by Anna, the number of buttons that can only be pressed by Katie, and the number of buttons that can be pressed by either of them, respectively.

Output
For each test case, output:
- "First" if Anna wins, or
- "Second" if Katie wins.
Example

Input
5
1 1 1
9 3 3
1 2 3
6 6 9
2 2 8

Output
First
First
Second
First
Second

Note

For the simplicity of the explanation, we will numerate the buttons by the numbers from 1 to a + b + c:
- the first a buttons can only be pressed by Anna,
- the next b buttons can only be pressed by Katie,
- the last c buttons can be pressed by either of them.

In the first test case:
- Anna can press the 3rd button on the first turn.
- Then Katie will press the 2nd button (since it is the only possible turn for her).
- Then Anna will press the 1st button.
- Katie won't have a button to press, so Anna will win.

In the second test case:
- Anna can press the first nine buttons in some order on her turns.
- No matter what buttons Katie will press, all the buttons from the 10th to the 15th will be pressed after 12 turns.
- On the 13th turn, Anna will press one of the first nine buttons and Katie will not have a button to press on her turn.
Thus, Anna will win.

In the third test case, the game can proceed as follows:
- On the 1st turn Anna presses the 5th button.
- On the 2nd turn Katie presses the 4th button.
- On the 3rd turn Anna presses the 6th button.
- On the 4th turn Katie presses the 3rd button.
- On the 5th turn Anna presses the 1st button.
- On the 6th turn Katie presses the 2nd button.
Anna cannot make the turn, so Katie wins.
It can be shown that Katie can win no matter what moves Anna takes.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            cout << "First\n";
        else if (b > a)
            cout << "Second\n";
        else {
            if (c % 2 == 0)
                cout << "Second\n";
            else
                cout << "First\n";
        }
    }
}
// TC - O(1)  SC - O(1)