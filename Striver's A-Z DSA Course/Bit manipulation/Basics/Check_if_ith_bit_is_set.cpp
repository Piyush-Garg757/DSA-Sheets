// The standard way is using right shift (>>) and bitwise AND (&).

bool isSet(int n, int i)
{
    return (n >> i) & 1;
}

// Alternative (using a mask)

bool isSet(int n, int i)
{
    return (n & (1 << i)) != 0;
}

// TC - O(1)  SC - O(1)

// inmein 0 se count shuru ho raha hai -> bit ke lsb ko 0th bit mana hai