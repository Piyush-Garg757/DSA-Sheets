/*Directed Graph Cycle

Given a directed graph with V vertices numbered from 0 to V - 1 and E directed edges. The graph is represented using a 2D array edges[][] of size E, where each entry edges[i] = [u, v] denotes a directed edge from vertex u to vertex v.
Check whether the graph contains any cycle. Return true if there exists at least one cycle in the graph; otherwise, return false.

Examples:
Input: V = 4, edges[][] = [[0, 1], [1, 2], [2, 0], [2, 3]]
Output: true
Explanation: The diagram clearly shows a cycle 0 -> 1 -> 2 -> 0

Input: V = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
Output: false
Explanation: no cycle in the graph*/

class Solution
{
public:
    bool dfs(int node, vector<vector<int>> &a, vector<int> &visited, vector<int> &path_visited)
    {
        visited[node] = 1;
        path_visited[node] = 1;
        for (int i = 0; i < a[node].size(); i++)
        {
            if (!visited[a[node][i]])
            {
                if (dfs(a[node][i], a, visited, path_visited))
                    return true;
            }
            else if (path_visited[a[node][i]])
                return true;
        }
        path_visited[node] = 0;
        return false;
    }
    bool isCyclic(int v, vector<vector<int>> &edges)
    {
        // code here
        vector<vector<int>> a(v);
        for (auto x : edges)
            a[x[0]].push_back(x[1]);
        vector<int> visited(v, 0);
        vector<int> path_visited(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                if (dfs(i, a, visited, path_visited))
                    return true;
            }
        }
        return false;
    }
};
// TC - O(v+e)  SC - O(e)