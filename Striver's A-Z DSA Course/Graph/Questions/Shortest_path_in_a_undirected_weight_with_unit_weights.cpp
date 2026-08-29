/*Shortest Path in Unweighted Graph

Given an undirected graph with V vertices numbered from 0 to V-1 and E edges, where edges[i] = [u, v] denotes an undirected edge between vertex u and vertex v, given two vertices src and dest, find the length of the shortest path from src to dest. If there is no path between src and dest, return -1.
Note: All edges have a unit weight of 1.

Examples :
Input: V = 9, edges[][] = [[0, 1], [0, 3], [1, 2], [3, 4], [4, 5], [2, 6], [5, 6], [6, 7], [6, 8], [7, 8]], src = 0, dest = 8
Output: 4
Explanation: One of the shortest paths from vertex 0 to vertex 8 is 0 -> 1 -> 2 -> 6 -> 8, which contains 4 edges.

Input: V = 4, edges[][]= [[0, 3], [1, 3]], src = 3, dest = 2
Output: -1
Explanation: There is no path between vertices 3 and 2.
*/
// DFs se bhi kar sakte hain but usmein bina baat bohot saare paths check karne padenge minimum find karne ke liye jabki bfs se jo pehla path mila vahi answer hai
class Solution
{
public:
    int shortestPath(int v, vector<vector<int>> &a, int src, int dest)
    {
        // code here
        vector<int> adj[v];
        vector<int> visited(v, 0);
        for (int i = 0; i < a.size(); i++)
        {
            int u = a[i][0];
            int v = a[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;
        visited[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, 0});
        while (!q.empty())
        {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();
            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    visited[i] = 1;
                    dist[i] = d + 1;
                    q.push({i, dist[i]});
                }
            }
        }
        if (dist[dest] == INT_MAX)
            return -1;
        return dist[dest];
    }
};
// TC - O(e+v)  SC - O(v)