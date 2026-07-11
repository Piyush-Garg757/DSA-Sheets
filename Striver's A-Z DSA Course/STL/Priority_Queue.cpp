#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // Maximum heap 
    priority_queue<int> pq;
    // pq.push , pq.emplace  , pq.top , pq.pop
    // ismein internally tree data tructuure banta hai aur ismein ascending order ki priority mein arrange hota hai by default matlab bade numeer ki zyada priority
    // agar order aalag karna hai to min heap

    // Minimum heap
    priority_queue<int, vector<int>, greater<int>> pq;
    // ismeein chote ki zada priority hai
    return 0;
}