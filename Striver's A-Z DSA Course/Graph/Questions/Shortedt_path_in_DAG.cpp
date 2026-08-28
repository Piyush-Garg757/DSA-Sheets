/*Shortest Path in Directed Acyclic Graph

Given a Directed Acyclic Graph (DAG) with V vertices numbered from 0 to V - 1 and E weighted directed edges represented by a 2D array edges[][], where edges[i] = [u, v, wt] denotes a directed edge from vertex u to vertex v with weight wt, find the shortest distance from the source vertex 0 to every other vertex.
Return an array of size V, where the i-th element represents the shortest distance from the source vertex 0 to vertex i. If a vertex is not reachable from the source, return -1 for that vertex.

Examples :
Input: V = 4, edges = [[0,1,2], [0,2,1]]
Output: [0, 2, 1, -1]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->2 with edge weight 1. There is no way we can reach 3, so it's -1 for 3.

Input: V = 6, edges = [[0,1,2], [0,4,1], [4,5,4], [4,2,2], [1,2,3], [2,3,6], [5,3,1]]
Output: [0, 2, 3, 6, 1, 5]
Explanation: Shortest path from 0 to 1 is 0->1 with edge weight 2. Shortest path from 0 to 2 is 0->4->2 with edge weight 1+2=3. Shortest path from 0 to 3 is 0->4->5->3 with edge weight 1+4+1=6. Shortest path from 0 to 4 is 0->4 with edge weight 1.Shortest path from 0 to 5 is 0->4->5 with edge weight 1+4=5.*/

/*source node koi bhi diya ho, DAG wala approach bilkul same rahega. Bas:

dist[0] = 0;

ki jagah:

dist[source] = 0;

karna hai.

For example source 2 hai:

int source = 2;
vector<int> dist(v, INT_MAX);
dist[source] = 0;

Phir poori topological ordering nikaaloge as usual.

Important point

Maan lo topological order:

0 → 1 → 2 → 3 → 4

aur source = 2.

Distances initially:

0    1    2    3    4
∞    ∞    0    ∞    ∞

Ab stack/topological order mein 0 aur 1 pehle aa sakte hain. Tumhare code mein:

if (dist[node] == INT_MAX)
    continue;

ki wajah se unko skip kar doge.

Jab 2 aayega:

dist[2] = 0

uske baad uske reachable nodes relax honge.*/

//  aur ismein dijkstra vagera bhi ikaam karenge but unki complexity zyada hoti hai   aur DAG ho to ye method works perfectly to isi se kaam karte hain DAG me
class Solution
{
public:
    void dfs(int node, vector<pair<int, int>> adj[], vector<int> &visited, stack<int> &st)
    {
        visited[node] = 1;
        for (auto i : adj[node])
        {
            int n = i.first;
            int weight = i.second;
            if (!visited[n])
            {
                dfs(n, adj, visited, st);
            }
        }
        st.push(node);
    }
    vector<int> shortestPath(int v, vector<vector<int>> &a)
    {
        // code here
        vector<pair<int, int>> adj[v];
        for (int i = 0; i < a.size(); i++)
        {
            adj[a[i][0]].push_back({a[i][1], a[i][2]});
        }
        stack<int> st;
        vector<int> visited(v, 0);
        for (int i = 0; i < v; i++)
        {
            if (!visited[i])
            {
                dfs(i, adj, visited, st);
            }
        }
        vector<int> dist(v, INT_MAX);
        dist[0] = 0;
        while (!st.empty())
        {
            int node = st.top();
            st.pop();
            if (dist[node] == INT_MAX)
                continue;
            for (auto i : adj[node])
            {
                int n = i.first;
                int weight = i.second;
                if (dist[node] + weight < dist[n])
                    dist[n] = dist[node] + weight;
            }
        }
        for (int i = 0; i < v; i++)
            if (dist[i] == INT_MAX)
                dist[i] = -1;
        return dist;
    }
};
// TC - O(e+v)  SC - O(e+v)

/*DFS → Topological Sort → Distance Relaxation

Tumhare code ko 3 parts mein samjho.

1. Adjacency list banana

Input:

vector<vector<int>>& a

har edge kuch aisa hai:

u v weight

Tum bana rahe ho:

vector<pair<int, int>> adj[v];

for (int i = 0; i < a.size(); i++) {
    adj[a[i][0]].push_back({a[i][1], a[i][2]});
}

Suppose edges:

0 → 1 (2)
0 → 2 (1)
1 → 3 (3)
2 → 3 (1)

To:

adj[0] = {(1,2), (2,1)}
adj[1] = {(3,3)}
adj[2] = {(3,1)}

Pair mein:

i.first  = neighbour
i.second = weight
2. DFS se Topological Sort

Tumhara DFS:

void dfs(int node, ..., stack<int>& st)
{
    visited[node] = 1;

    for (auto i : adj[node])
    {
        int n = i.first;

        if (!visited[n])
            dfs(n, adj, visited, st);
    }

    st.push(node);
}
Important line:
st.push(node);

DFS complete hone ke baad node stack mein jaata hai.

Example:

0 → 1 → 3
 \→ 2 → 3

DFS ke baad possible stack:

0 2 1 3

Top se pop karoge:

0 → 1 → 2 → 3

Ye topological ordering hai.

Why DFS ke baad push?

Kyuki pehle node ke saare outgoing neighbours process hone chahiye.

For:

0 → 1

DFS:

dfs(0)
   ↓
dfs(1)
   ↓
push(1)
   ↓
push(0)

Stack:

0
1

Top:

1

So pop order:

0 → 1

which respects the edge 0 → 1.

3. Distance initialize karna
vector<int> dist(v, INT_MAX);
dist[0] = 0;

Meaning:

dist[0] = 0

Source node 0 se distance zero.

Baaki:

∞

Example:

dist = [0, ∞, ∞, ∞]
4. Topological order mein nodes process karna

Ab:

while (!st.empty())
{
    int node = st.top();
    st.pop();

Nodes ko topological order mein process kar rahe ho.

Ye DAG shortest path ka main trick hai.

5. Unreachable nodes skip karna

Tumne:

if (dist[node] == INT_MAX)
    continue;

lagaya hai.

Suppose:

0 → 1

2 → 3

2 source 0 se reachable nahi hai.

To:

dist[2] = INT_MAX

Uske edges relax karne ka koi point nahi.

Isliye:

continue;
6. Relaxation

Ye sabse important part:

for (auto i : adj[node])
{
    int n = i.first;
    int weight = i.second;

    if (dist[node] + weight < dist[n])
        dist[n] = dist[node] + weight;
}

Suppose:

0 → 1 (2)
0 → 2 (1)
1 → 3 (3)
2 → 3 (1)

Initially:

dist = [0, ∞, ∞, ∞]
Node 0

Edge:

0 → 1, weight 2

So:

dist[1] = 0 + 2 = 2

Edge:

0 → 2, weight 1

So:

dist[2] = 0 + 1 = 1

Now:

dist = [0, 2, 1, ∞]
Node 1
1 → 3 (3)

So:

dist[3] = 2 + 3 = 5
Node 2
2 → 3 (1)

Now:

1 + 1 = 2

which is smaller than 5.

So:

dist[3] = 2

Final:

[0, 2, 1, 2]
Why Topological Sort is useful?

Normally shortest path mein problem hoti hai ki:

Kis node ko pehle process karein?

DAG mein topological ordering ye problem solve kar deti hai.

Topological order guarantees:

u → v

to u v se pehle process hoga.

Isliye jab hum u ki outgoing edges relax karte hain, u ka shortest distance already finalized/available hota hai.

Pura algorithm ek line mein
Edges
 ↓
Adjacency List
 ↓
DFS
 ↓
Topological Sort
 ↓
dist[0] = 0
 ↓
Topological order mein nodes
 ↓
Relax every outgoing edge
 ↓
INT_MAX → -1*/