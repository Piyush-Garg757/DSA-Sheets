/*Bellman Ford

Given a weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by a 2d array edges[][], where edges[i] = [u, v, w] represents a direct edge from node u to v having w edge weight. You are also given a source vertex src.
Compute the shortest distances from the src to all other vertices. If a vertex is unreachable from the src, its distance should be marked as 108. Additionally, if the graph contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

Examples:
Input: V = 5, edges[][] = [[1, 3, 2], [4, 3, -1], [2, 4, 1], [1, 2, 1], [0, 1, 5]], src = 0
Output: [0, 5, 6, 6, 7]
Explanation: Shortest Paths:
For 0 to 1 minimum distance will be 5. By following path 0 -> 1
For 0 to 2 minimum distance will be 6. By following path 0 -> 1 -> 2
For 0 to 3 minimum distance will be 6. By following path 0 -> 1 -> 2 -> 4 -> 3
For 0 to 4 minimum distance will be 7. By following path 0 -> 1 -> 2 -> 4

Input: V = 4, edges[][] = [[0, 1, 4], [1, 2, -6], [2, 3, 5], [3, 1, -2]], src = 0
Output: [-1]
Explanation: The graph contains a negative weight cycle formed by the path 1 -> 2 -> 3 -> 1, where the total weight of the cycle is negative.*/


// Dijkstras mein infinite loop lag jayega kyuki use har bar chota p[ath dikhea to vo use hi lega to vo use nahi kar sakte
// V-2 times hi kyu ???? - aisa isiliye ki maan lo 1 2 3 nodes hain aur oehla edge 2-3 diya aur dusra 1-2 ro 1st ieration me 2-3 vala to chal hi nahi skata kyuki dono infinite hain to 1-2 vala chalega aur fir dusre me 2-3 vala chal sakta hai to humne dekha max to max v-1 iterations mein agar aisa kcuh hua to vo resolve ho jayega   isiliye v-1 times
// Negative weight cycles kyu - kyuki maan lo ek cycle 1-2-3-1 mein total path length -1 aa rahi hai to jab jab iss cycle me chaloge har baar weight kma hi hoga to infinite loop lag jayega so we check for negative weight cycle aur agar vo mile to shortest path not possible
class Solution
{
public:
    vector<int> bellmanFord(int v, vector<vector<int>> &a, int src)
    {
        vector<int> dist(v, 100000000);
        dist[src] = 0;
        for (int i = 0; i < v - 1; i++)
        {
            for (int j = 0; j < a.size(); j++)
            {
                int u = a[j][0];
                int node = a[j][1];
                int d = a[j][2];
                if (dist[u] == 100000000 || dist[node] <= dist[u] + d)
                    continue;
                dist[node] = dist[u] + d;
            }
        }
        for (int j = 0; j < a.size(); j++)
        {
            int u = a[j][0];
            int node = a[j][1];
            int d = a[j][2];
            if (dist[u] != 100000000 && dist[node] > dist[u] + d)
                return {-1};
        }
        return dist;
    }
};
// TC - O(e*v)  SC - O(v)