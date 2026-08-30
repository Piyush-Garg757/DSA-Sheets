/*Dijkstra Algorithm

Given an undirected, weighted graph with V vertices numbered from 0 to V-1 and E edges, represented by 2d array edges[][], where edges[i]=[u, v, w] represents the edge between the nodes u and v having w weight.
Find the shortest distance of all the vertices from the source vertex src, and return an array of integers where the ith element denotes the shortest distance between ith node and source vertex src.
Note: The Graph is connected and doesn't contain any negative weight edge.
It is guaranteed that all the shortest distance will fit in a 32-bit integer.

Examples:
Input: V = 3, edges[][] = [[0, 1, 1], [1, 2, 3], [0, 2, 6]], src = 2
Output: [4, 3, 0]
Explanation:
Shortest Paths:
For 2 to 0 minimum distance will be 4. By following path 2 -> 1 -> 0
For 2 to 1 minimum distance will be 3. By following path 2 -> 1
For 2 to 2 minimum distance will be 0. By following path 2 -> 2

Input: V = 5, edges[][] = [[0, 1, 4], [0, 2, 8], [1, 4, 6], [2, 3, 2], [3, 4, 10]], src = 0
Output: [0, 4, 8, 10, 10]
Explanation:
Shortest Paths:
For 0 to 1 minimum distance will be 4. By following path 0 -> 1
For 0 to 2 minimum distance will be 8. By following path 0 -> 2
For 0 to 3 minimum distance will be 10. By following path 0 -> 2 -> 3
For 0 to 4 minimum distance will be 10. By following path 0 -> 1 -> 4*/

// First sol is using priority queue  and it will not work for negative weight cycles because usmein har baar weight kam hota jayega aur chota path milta jayega aur infinite loop ban jayega
// priority_queue< TYPE, CONTAINER, COMPARATOR > pq;
/*1. Normal priority_queue kya hota hai?
Normally:
priority_queue<int> pq;
Ye max heap banata hai.
pq.push(5);
pq.push(2);
pq.push(10);
top():
10
kyunki largest element sabse upar.
2. Min heap kaise banate hain?
Humein Dijkstra mein smallest distance pehle chahiye.
Isliye:
priority_queue<int, vector<int>, greater<int>> pq;*/
class Solution
{
public:
    vector<int> dijkstra(int v, vector<vector<int>> &a, int src)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>> adj[v];
        for (int i = 0; i < a.size(); i++)
        {
            int u = a[i][0];
            int v = a[i][1];
            int d = a[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        while (!pq.empty())
        {
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            if (d > dist[node])
                continue;
            for (auto i : adj[node])
            {
                int n = i.first;
                int w = i.second;
                if (d + w < dist[n])
                {
                    dist[n] = d + w;
                    pq.push({dist[n], n});
                }
            }
        }
        return dist;
    }
};
// TC - O((e+v)logv)  SC - O(e+v)

// Using set
class Solution
{
public:
    vector<int> dijkstra(int v, vector<vector<int>> &a, int src)
    {
        // Code here
        set<pair<int, int>> st;
        vector<pair<int, int>> adj[v];
        for (int i = 0; i < a.size(); i++)
        {
            int u = a[i][0];
            int v = a[i][1];
            int d = a[i][2];
            adj[u].push_back({v, d});
            adj[v].push_back({u, d});
        }
        vector<int> dist(v, INT_MAX);
        dist[src] = 0;
        st.insert({0, src});
        while (!st.empty())
        {
            int d = st.begin()->first;
            int node = st.begin()->second;
            st.erase({d, node});
            for (auto i : adj[node])
            {
                int n = i.first;
                int w = i.second;
                if (d + w < dist[n])
                {
                    if (dist[n] != INT_MAX)
                        st.erase({dist[n], n});
                    dist[n] = d + w;
                    st.insert({dist[n], n});
                }
            }
        }
        return dist;
    }
};
// TC - O((e+v)logv)  SC - O(e+v)
/*Why set is useful
Suppose:
node 5 has distance 10
Set:
{10, 5}
Later we find distance 6.
With set, we can do:
st.erase({10, 5});
st.insert({6, 5});
So only the latest distance remains.
This is conceptually similar to a decrease-key operation.*/

// Priority queue version is generally faster
// WE can get anwer using normal queue too but that would take a ot of time because it is not tking in distance on each iteration