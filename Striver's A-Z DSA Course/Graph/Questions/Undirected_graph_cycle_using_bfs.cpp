/*Undirected Graph Cycle

Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not.
Note: The graph can have multiple component.

Examples:
Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: true
Explanation:
1 -> 2 -> 0 -> 1 is a cycle.

Input: V = 4, E = 3, edges[][] = [[0, 1], [1, 2], [2, 3]]
Output: false
Explanation:
No cycle in the graph.*/

class Solution
{
public:
    bool bfs(int node, vector<int> adj[], vector<int> &visited)
    {
        queue<pair<int, int>> q;
        q.push({node, -1});
        visited[node] = 1;
        while (!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto i : adj[node])
            {
                if (!visited[i])
                {
                    q.push({i, node});
                    visited[i] = 1;
                }
                else if (i != parent)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int v, vector<vector<int>> &a)
    {
        // Code here
        vector<int> adj[v];
        for (int i = 0; i < a.size(); i++)
        {
            adj[a[i][0]].push_back(a[i][1]);
            adj[a[i][1]].push_back(a[i][0]);
        }
        vector<int> visited(v, 0);
        for (int i = 0; i < v; i++) // Connected components ho sakte hian   to uske luye aise kiya
        {
            if (!visited[i])
            {
                if (bfs(i, adj, visited) == true)
                    return true;
            }
        }
        return false;
    }
};
// TC - O(n)  SC - O(n)