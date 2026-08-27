/*Safe States

Given a directed graph with V vertices numbered from 0 to V-1 and E directed edges, represented as a 2D array edges[][], where edges[i] = [u, v] represents a directed edge from vertex u to vertex v.
A vertex with no outgoing edges is called a terminal node. A vertex is considered safe if every possible path starting from that vertex eventually reaches a terminal node.
Return all the safe nodes of the graph.

Examples:
Input: V = 5, E = 6, edges[][] = [[1, 0], [1, 2], [1, 3], [1, 4], [2, 3], [3, 4]]
Output: [0, 1, 2, 3, 4]
Explanation: Nodes 0 and 4 have no outgoing edges, so they are terminal nodes. All paths starting from nodes 1, 2, and 3 eventually reach terminal node 4. Therefore, all nodes are safe.

Input: V = 4, E = 3, edges[][] = [[1, 2], [2, 3], [3, 2]]
Output: [0]
Explanation: Node 0 is a terminal node. Nodes 2 and 3 form a cycle, so they are not safe. Node 1 leads to the cycle, making it unsafe. Hence, only node 0 is a safe node.*/


// Direct intution from cyclw deteciron in directed using dfs
class Solution
{
public:
    bool dfs(int node, vector<int> adj[], vector<int> &visited, vector<int> &path_visited, vector<int> &check)
    {
        visited[node] = 1;
        path_visited[node] = 1;
        for (int i = 0; i < adj[node].size(); i++)
        {
            if (!visited[adj[node][i]])
            {
                if (dfs(adj[node][i], adj, visited, path_visited, check))
                {
                    return true;
                }
            }
            else if (path_visited[adj[node][i]])
                return true;
        }
        path_visited[node] = 0;
        check[node] = 1;
        return false;
    }
    vector<int> safeNodes(int v, vector<vector<int>> &a)
    {
        // Code here
        vector<int> adj[v];
        for (int i = 0; i < a.size(); i++)
        {
            adj[a[i][0]].push_back(a[i][1]);
        }
        vector<int> visited(v, 0);
        vector<int> path_visited(v, 0);
        vector<int> check(v, 0);
        vector<int> ans;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, path_visited, check);
            }
        }
        for (int i = 0; i < v; i++)
        {
            if (check[i])
                ans.push_back(i);
        }
        return ans;
    }
};
// TC - O(e+v)  SC - O(e)