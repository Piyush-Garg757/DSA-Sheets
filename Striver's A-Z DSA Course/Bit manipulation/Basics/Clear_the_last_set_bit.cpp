// Last set bit matlab rightmost set bit ki baat ho rahi hai
n &= (n - 1);
// TC - O(1)  SC - O(1)

// Intution - n-1 mein jo bhi rightmost set bit thi n mein   uske right vali saari bit 1 ho jayengi jo ki n mein 0 thi  aur rightmost set bit 0 ho jayegi n-1 mein   ab agar hum n-1 se & kar dete hain to rightmost set bit 0 ho jayegi   uske right vala sara 0 ho jayega  aur uske left vala saar same rahega kyuki a&a=a