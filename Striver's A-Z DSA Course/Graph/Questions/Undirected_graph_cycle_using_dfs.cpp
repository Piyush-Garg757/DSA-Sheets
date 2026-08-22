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
    bool dfs(int node, vector<int> adj[], vector<int> &visited, int parent)
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, node))
                    return true;
            }
            else if (i != parent)
                return true;
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
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, adj, visited, -1) == true)
                    return true;
            }
        }
        return false;
    }
};
// TC - O(n)  SC - O(n)