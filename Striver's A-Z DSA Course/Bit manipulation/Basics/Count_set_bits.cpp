// 1. Brian Kernighan's Algorithm (Recommended)
// This is the most common interview solution.

int countSetBits(int n) {
    int cnt = 0;
    while (n) {
        n &= (n - 1);
        cnt++;
    }
    return cnt;
}
// Iska feel ayega from clearing last set bit
Example
n = 13
1101

1101
1000
0000

Count = 3

Complexity:
Time: O(number of set bits)
Space: O(1)

// 2. Check Every Bit
int countSetBits(int n) {
    int cnt = 0;
    while (n) {
        cnt += (n & 1);
        n >>= 1;
    }
    return cnt;
}

Complexity:
Time: O(log n)
Space: O(1)

// 3. Using Built-in Function (Best for CP)
int cnt = __builtin_popcount(n);          // int
int cnt = __builtin_popcountll(n);        // long long