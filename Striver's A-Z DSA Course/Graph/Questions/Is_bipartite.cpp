/*Is Graph Bipartite?

There is an undirected graph with n nodes, where each node is numbered between 0 and n - 1. You are given a 2D array graph, where graph[u] is an array of nodes that node u is adjacent to. More formally, for each v in graph[u], there is an undirected edge between node u and node v. The graph has the following properties:
There are no self-edges (graph[u] does not contain u).
There are no parallel edges (graph[u] does not contain duplicate values).
If v is in graph[u], then u is in graph[v] (the graph is undirected).
The graph may not be connected, meaning there may be two nodes u and v such that there is no path between them.
A graph is bipartite if the nodes can be partitioned into two independent sets A and B such that every edge in the graph connects a node in set A and a node in set B.
Return true if and only if it is bipartite.

Example 1:
Input: graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
Output: false
Explanation: There is no way to partition the nodes into two independent sets such that every edge connects a node in one and a node in the other.

Example 2:
Input: graph = [[1,3],[0,2],[1,3],[0,2]]
Output: true
Explanation: We can partition the nodes into two sets: {0, 2} and {1, 3}.*/

// Using bfs
class Solution
{
public:
    bool isBipartite(vector<vector<int>> &a)
    {
        int n = a.size();
        vector<int> color(n, -1);
        for (int start = 0; start < n; start++)
        {
            if (color[start] != -1)
                continue;
            color[start] = 0;
            queue<pair<int, int>> q;
            q.push({start, 0});
            while (!q.empty())
            {
                int node = q.front().first;
                int col = q.front().second, docol = 0;
                if (col == 0)
                    docol = 1;
                q.pop();
                for (int i = 0; i < a[node].size(); i++)
                {
                    int curr_col = color[a[node][i]];
                    if (curr_col == col)
                        return false;
                    else if (curr_col == -1)
                    {
                        q.push({a[node][i], docol});
                        color[a[node][i]] = docol;
                    }
                }
            }
        }
        return true;
    }
};
// TC - O(v+e)  SC - O(v)

// Using dfs
class Solution
{
public:
    bool dfs(vector<vector<int>> &a, vector<int> &color, int start)
    {
        int col = color[start];
        int docol = 0;
        if (col == 0)
            docol = 1;
        for (int i = 0; i < a[start].size(); i++)
        {
            int curr_col = color[a[start][i]];
            if (curr_col == col)
                return false;
            else if (curr_col == -1)
            {
                color[a[start][i]] = docol;
                if (dfs(a, color, a[start][i]) == false)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>> &a)
    {
        int n = a.size();
        vector<int> color(n, -1);
        for (int start = 0; start < n; start++)
        {
            if (color[start] != -1)
                continue;
            color[start] = 0;
            if (dfs(a, color, start) == false)
                return false;
        }
        return true;
    }
};
// TC - O(v+e)  SC - O(v)