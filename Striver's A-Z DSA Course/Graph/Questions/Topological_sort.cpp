/*Topological Sort

Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E directed edges represented by a 2D array edges[][], where edges[i] = [u, v] denotes a directed edge from vertex u to vertex v, return a topological ordering of all the vertices.
A topological ordering is a linear ordering of the vertices such that for every directed edge u -> v, vertex u appears before vertex v in the ordering.
Note: As there are multiple Topological orders possible, you may return any of them. If your returned Topological sort is correct then the output will be true else false.

Examples:
Input: V = 4, E = 3, edges[][] = [[3, 0], [1, 0], [2, 0]]
Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the given graph are:
[3, 2, 1, 0]
[1, 2, 3, 0]
[2, 3, 1, 0]

Input: V = 6, E = 6, edges[][] = [[1, 3], [2, 3], [4, 1], [4, 0], [5, 0], [5, 2]]
Output: true
Explanation: The output true denotes that the order is valid. Few valid Topological orders for the graph are:
[4, 5, 0, 1, 2, 3]
[5, 2, 4, 0, 1, 3]*/


// Bas DAG - Directed Acyclic Graph ke liye hota hai ye
class Solution
{
public:
    void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> topoSort(int v, vector<vector<int>> &a)
    {
        // code here
        vector<int> adj[v];
        for (int i = 0; i < a.size(); i++)
        {
            adj[a[i][0]].push_back(a[i][1]);
        }
        vector<int> visited(v, 0);
        vector<int> ans;
        stack<int> st;
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
// TC - O(v+e)  SC - O(e)