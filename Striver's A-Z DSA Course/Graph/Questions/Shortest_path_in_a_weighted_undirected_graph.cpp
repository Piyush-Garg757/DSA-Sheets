/*Shortest Path in an Undirected Graph

Given a weighted undirected graph with V vertices numbered from 1 to V and E edges, where edges[i] = [u, v, w] denotes an undirected edge between vertices u and v with weight w. We are also given two vertices src and dest, find the shortest path from src to dest.
If multiple shortest paths exist with the same total weight, return the one whose sequence of vertices is lexicographically smallest.
If no path exists between src and dest, return {-1}.
Note: The graph contains no negative-weight edges.

Examples :
Input: V = 5, edges[][] = [[1, 2, 2], [2, 5, 5], [2, 3, 4], [1, 4, 1], [4, 3, 3], [3, 5, 1]], src = 1, dest = 5
Output: [1, 4, 3, 5]
Explanation: The shortest path from vertex 1 to vertex 5 is 1 -> 4 -> 3 -> 5 with a total weight of 5.

Input: V = 6, edges[][] = [[1, 2, 1], [1, 3, 1], [2, 4, 1], [3, 4, 1], [4, 6, 1], [2, 5, 2], [5, 6, 1]], src = 1, dest = 6
Output: [1, 2, 4, 6]
Explanation: There are two shortest paths from 1 to 6 with total weight 3: 1 -> 2 -> 4 -> 6 and 1 -> 3 -> 4 -> 6. Since [1, 2, 4, 6] is lexicographically smaller, it is returned.

Input: V = 5, edges[][] = [[1,2,4], [2,3,2], [4,5,1]], src = 1, dest = 5
Output: [-1]
Explanation: Since there are no edges, so no answer is possible.
*/

class Solution
{
public:
    vector<int> shortestPath(int v, vector<vector<int>> &a, int src, int dest)
    {
        // Code here
        vector<pair<int, int>> adj[v];
        for (int i = 0; i < a.size(); i++)
        {
            int u = a[i][0] - 1;
            int v = a[i][1] - 1;
            int d = a[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        src--;
        dest--;
        vector<int> parent(v, -1);
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;
        parent[src] = src;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, src});
        while (!pq.empty())
        {
            int d = pq.top().first;
            int n = pq.top().second;
            pq.pop();
            if (d > dist[n])
                continue;
            for (auto i : adj[n])
            {
                int node = i.first;
                int weight = i.second;
                if (weight + d < dist[node])
                {
                    dist[node] = weight + d;
                    pq.push({dist[node], node});
                    parent[node] = n;
                }
            }
        }
        if (parent[dest] == -1)
            return {-1};
        vector<int> ans;
        int node = dest;
        while (parent[node] != node)
        {
            ans.push_back(node + 1);
            node = parent[node];
        }
        ans.push_back(src + 1);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// TC - O(elogv)  SC - O(e+v)