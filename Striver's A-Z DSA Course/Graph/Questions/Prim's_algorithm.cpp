/*Minimum Spanning Tree

Given a weighted, undirected, and connected graph with V vertices and a 2D array edges[][], where each element edges[i] = [u, v, w] represents an edge between vertices u and v with weight w, return the sum of the weights of all edges in the graph's Minimum Spanning Tree (MST).

Input: V = 3, E = 3, Edges = [[0, 1, 5], [1, 2, 3], [0, 2, 1]]
Output: 4
Explanation:
The Spanning Tree resulting in a weight
of 4 is shown above.

Input: V = 2, E = 1, Edges = [[0 1 5]]
Output: 5
Explanation: Only one Spanning Tree is possible which has a weight of 5.*/

class Solution
{
public:
    int spanningTree(int v, vector<vector<int>> &a)
    {
        // code here
        vector<pair<int, int>> adj[v];
        for (int i = 0; i < a.size(); i++)
        {
            int u = a[i][0];
            int v = a[i][1];
            int d = a[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        vector<int> visited(v, 0);
        int sum = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, 0});
        while (!pq.empty())
        {
            int node = pq.top().second;
            int weight = pq.top().first;
            pq.pop();
            if (!visited[node])
            {
                visited[node] = 1;
                sum += weight;
                for (auto i : adj[node])
                {
                    int n = i.first;
                    int wt = i.second;
                    if (!visited[n])
                    {
                        pq.push({wt, n});
                    }
                }
            }
        }
        return sum;
    }
};
// TC - (eloge)  SC - O(e+v)

// isi me agar mst vali edges return karni ho to
class Solution
{
public:
    int spanningTree(int v, vector<vector<int>> &a)
    {
        // code here
        vector<pair<int, int>> adj[v];
        vector<pair<int, int>> ans;
        for (int i = 0; i < a.size(); i++)
        {
            int u = a[i][0];
            int v = a[i][1];
            int d = a[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        vector<int> visited(v, 0);
        int sum = 0;
        priority_queue << int, pair < int, int >>, vector << int, pair < int, int >>>, greater << int, pair < int, int >>>> pq;
        pq.push({0, {0, -1}}); // third one is for parent
        while (!pq.empty())
        {
            int node = pq.top().second.first;
            int parent = pq.top().second.second;
            int weight = pq.top().first;
            pq.pop();
            if (!visited[node])
            {
                visited[node] = 1;
                sum += weight;
                if (parent != -1)
                    ans.push_back({node, parent});
                for (auto i : adj[node])
                {
                    int n = i.first;
                    int wt = i.second;
                    if (!visited[n])
                    {
                        pq.push(wt, {n, node});
                    }
                }
            }
        }
        return ans;
    }
};
// TC - (eloge)  SC - O(e+v)